#pragma once
#include <vector>

struct Connection {
    double weight;
};

class Neuron;
typedef std::vector<Neuron> Layer;

class Neuron {
public:
    Neuron(unsigned numInputs);
    void setOutputVal(double val);
    double getOutputVal() const;
    void computeOutput(const Layer &prevLayer);
    void setWeight(unsigned inputIndex, double weight);

    double netInput = 0.0;

private:
    std::vector<Connection> m_inputConnections;
    double m_outputVal = 0.0;
    static double activationFunction(double x);
};

class Net {
public:
    void initialize();
    void feedForward();
    void printResults() const;

private:
    std::vector<Layer> m_layers;
};

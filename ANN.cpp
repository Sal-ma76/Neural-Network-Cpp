#include "ANN.h"
#include <iostream>
#include <cmath>
using namespace std;

// Neuron implementation
Neuron::Neuron(unsigned numInputs) {
    for (unsigned i = 0; i < numInputs; ++i) {
        m_inputConnections.push_back({0.0});
    }
}

void Neuron::setOutputVal(double val) {
    m_outputVal = val;
}

double Neuron::getOutputVal() const {
    return m_outputVal;
}

void Neuron::setWeight(unsigned inputIndex, double weight) {
    if (inputIndex < m_inputConnections.size()) {
        m_inputConnections[inputIndex].weight = weight;
    }
}

double Neuron::activationFunction(double x) {
    return 1.0 / (1.0 + exp(-x));
}

void Neuron::computeOutput(const Layer &prevLayer) {
    netInput = 0.0;
    for (unsigned i = 0; i < prevLayer.size(); ++i) {
        netInput += prevLayer[i].getOutputVal() * m_inputConnections[i].weight;
    }
    m_outputVal = activationFunction(netInput);
}

// Net implementation
void Net::initialize() {
    int numLayers;
    cout << "Enter number of layers: ";
    cin >> numLayers;

    m_layers.resize(numLayers);

    for (int i = 0; i < numLayers; ++i) {
        int numNeurons;
        cout << "Enter number of neurons in layer " << i << ": ";
        cin >> numNeurons;

        unsigned numInputs = (i == 0) ? 0 : m_layers[i - 1].size();
        for (int j = 0; j < numNeurons; ++j) {
            m_layers[i].push_back(Neuron(numInputs));
        }
    }

    cout << "Enter input values for layer 0:\n";
    for (Neuron &neuron : m_layers[0]) {
        double val;
        cin >> val;
        neuron.setOutputVal(val);
    }

    for (size_t layerNum = 1; layerNum < m_layers.size(); ++layerNum) {
        for (size_t neuronNum = 0; neuronNum < m_layers[layerNum].size(); ++neuronNum) {
            cout << "Enter " << m_layers[layerNum - 1].size()
                 << " weights for neuron " << neuronNum
                 << " in layer " << layerNum << ": ";
            for (size_t conn = 0; conn < m_layers[layerNum - 1].size(); ++conn) {
                double w;
                cin >> w;
                m_layers[layerNum][neuronNum].setWeight(conn, w);
            }
        }
    }
}

void Net::feedForward() {
    for (size_t layerNum = 1; layerNum < m_layers.size(); ++layerNum) {
        Layer &prevLayer = m_layers[layerNum - 1];
        for (Neuron &neuron : m_layers[layerNum]) {
            neuron.computeOutput(prevLayer);
        }
    }
}

void Net::printResults() const {
    for (size_t layerNum = 1; layerNum < m_layers.size(); ++layerNum) {
        cout << "\nLayer " << layerNum << ":\n";
        for (size_t neuronNum = 0; neuronNum < m_layers[layerNum].size(); ++neuronNum) {
            const Neuron &neuron = m_layers[layerNum][neuronNum];
            cout << " Neuron " << neuronNum
                 << " | Net input = " << neuron.netInput
                 << " | Activation = " << neuron.getOutputVal() << "\n";
        }
    }
}

# Exercise 4 – PyTorch Layer Parser

## Overview
This task implements a Python parser that loads a PyTorch model, detects specific neural network layers, extracts their parameters, and returns them in a structured format for further use in ROOT TMVA SOFIE.

## Supported Layers
ELU  
MaxPool2D  
BatchNorm2D  
RNN  
LSTM  
GRU  

## How It Works
1. Load a PyTorch model.
2. Traverse the model using `model.named_modules()`.
3. Identify supported layer types.
4. Extract relevant parameters.
5. Return the layer information as dictionaries.

Example output:
{'type': 'ELU', 'alpha': 1.0}  
{'type': 'MaxPool2D', 'kernel_size': 2, 'stride': 2}  
{'type': 'BatchNorm2D', 'num_features': 3}  
{'type': 'RNN', 'input_size': 10, 'hidden_size': 20}  
{'type': 'LSTM', 'input_size': 20, 'hidden_size': 30}  
{'type': 'GRU', 'input_size': 30, 'hidden_size': 40}  

## Run
python3 test_model.py  
python3 main.py
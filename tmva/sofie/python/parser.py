import torch.nn as nn

from layers.elu import parse_elu
from layers.maxpool2d import parse_maxpool2d
from layers.batchnorm2d import parse_batchnorm2d
from layers.rnn import parse_rnn
from layers.lstm import parse_lstm
from layers.gru import parse_gru

def parse_model(model):

    parsed_layers = []

    for name, layer in model.named_modules():

        if isinstance(layer, nn.ELU):
            parsed_layers.append(parse_elu(layer))

        elif isinstance(layer, nn.MaxPool2d):
            parsed_layers.append(parse_maxpool2d(layer))

        elif isinstance(layer, nn.BatchNorm2d):
            parsed_layers.append(parse_batchnorm2d(layer))

        elif isinstance(layer, nn.RNN):
            parsed_layers.append(parse_rnn(layer))

        elif isinstance(layer, nn.LSTM):
            parsed_layers.append(parse_lstm(layer))

        elif isinstance(layer, nn.GRU):
            parsed_layers.append(parse_gru(layer))

    return parsed_layers
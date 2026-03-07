def parse_rnn(layer):

    return {
        "type": "RNN",
        "input_size": layer.input_size,
        "hidden_size": layer.hidden_size,
        "num_layers": layer.num_layers,
        "bidirectional": layer.bidirectional
    }
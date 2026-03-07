def parse_elu(layer):

    return {
        "type": "ELU",
        "alpha": layer.alpha,
        "inplace": layer.inplace
    }
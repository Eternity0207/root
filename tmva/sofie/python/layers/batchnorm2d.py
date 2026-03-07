def parse_batchnorm2d(layer):

    return {
        "type": "BatchNorm2D",
        "num_features": layer.num_features,
        "eps": layer.eps,
        "momentum": layer.momentum
    }
def parse_maxpool2d(layer):

    return {
        "type": "MaxPool2D",
        "kernel_size": layer.kernel_size,
        "stride": layer.stride,
        "padding": layer.padding
    }
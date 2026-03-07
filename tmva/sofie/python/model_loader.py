import torch

def load_model(path):
    model = torch.load(path, map_location="cpu", weights_only=False)
    model.eval()
    return model
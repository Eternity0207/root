from test_model import TestModel
from model_loader import load_model
from parser import parse_model

model = load_model("model.pth")

layers = parse_model(model)

for l in layers:
    print(l)
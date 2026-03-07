import torch
import torch.nn as nn

model = nn.Linear(16,16)

dummy = torch.randn(1,16)

torch.onnx.export(model,dummy,"outputs/pytorch_linear.onnx")

print("ONNX exported")
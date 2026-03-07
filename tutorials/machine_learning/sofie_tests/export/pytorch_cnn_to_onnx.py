import torch
import torch.nn as nn

class CNN(nn.Module):
    def __init__(self):
        super().__init__()
        self.conv = nn.Conv2d(1,4,3)
        self.relu = nn.ReLU()
        self.fc = nn.Linear(4*26*26,10)

    def forward(self,x):
        x = self.conv(x)
        x = self.relu(x)
        x = x.view(x.size(0),-1)
        x = self.fc(x)
        return x

model = CNN()

dummy = torch.randn(1,1,28,28)

torch.onnx.export(
    model,
    dummy,
    "outputs/pytorch_cnn.onnx",
    input_names=["input"],
    output_names=["output"],
    opset_version=11
)

print("CNN ONNX exported")
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

torch.save(model,"outputs/pytorch_cnn.pt")
import torch
import torch.nn as nn

class TestModel(nn.Module):

    def __init__(self):
        super().__init__()

        self.pool = nn.MaxPool2d(2)
        self.bn = nn.BatchNorm2d(3)
        self.elu = nn.ELU()

        self.rnn = nn.RNN(10, 20, batch_first=True)
        self.lstm = nn.LSTM(20, 30, batch_first=True)
        self.gru = nn.GRU(30, 40, batch_first=True)

    def forward(self, x):
        return x

model = TestModel()

torch.save(model, "model.pth")
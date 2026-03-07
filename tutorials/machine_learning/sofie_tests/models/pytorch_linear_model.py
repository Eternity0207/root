import torch
import torch.nn as nn

model = nn.Linear(16,16)

torch.save(model,"outputs/pytorch_linear.pt")

print("PyTorch linear model saved")
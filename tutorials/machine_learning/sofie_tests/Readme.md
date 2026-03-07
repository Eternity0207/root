# TMVA SOFIE Exercise

This project demonstrates how to convert machine learning models into C++ inference code using TMVA SOFIE.

Models implemented:
- PyTorch Linear Network
- PyTorch CNN
- Keras Dense Network
- Keras CNN

Workflow:

1. Train or define model in Python
2. Export model to ONNX
3. Parse ONNX model using TMVA SOFIE
4. Generate C++ inference code (.hxx) and weights (.dat)

Example command:

root -l -q 'parse/parse_model.C("outputs/pytorch_linear.onnx")'

Generated files:

- `.hxx` : C++ inference code
- `.dat` : trained model weights
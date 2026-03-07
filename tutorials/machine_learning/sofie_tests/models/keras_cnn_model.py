import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers

model = keras.Sequential([
    layers.Input(shape=(28,28,1)),
    layers.Conv2D(4,3,activation="relu"),
    layers.Flatten(),
    layers.Dense(10)
])

model.save("outputs/keras_cnn.h5")

print("Keras CNN saved")
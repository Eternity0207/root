import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers

model = keras.Sequential([
    layers.Input(shape=(16,)),
    layers.Dense(32,activation="relu"),
    layers.Dense(16)
])

model.save("outputs/keras_dense_model.h5")

print("Keras dense saved")
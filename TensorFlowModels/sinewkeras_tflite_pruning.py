
import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2' 
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

import tensorflow as tf

from tensorflow import keras
from tensorflow.keras import layers
import tensorflow_model_optimization as tfmot


x=np.linspace(0,2*np.pi,360)

y=np.sin(x)


model = keras.Sequential([layers.Dense(units=4, input_shape=[1])])
model.add(layers.Dense(units=3)) #hidden layer
model.add(layers.Dense(units=1))


opt = keras.optimizers.Adam(learning_rate=0.0001)
model.compile(loss='mean_squared_error', optimizer='SGD', metrics=['mean_squared_error'])

history = model.fit(x,y,batch_size=len(x),  epochs=500)
epochs=2
num_features = y.shape[0]
begin_step = 1000
end_step = 5000

pruning_params = {
      'pruning_schedule': tfmot.sparsity.keras.PolynomialDecay(initial_sparsity=0.0,final_sparsity=0.9,begin_step=begin_step,end_step=end_step)
}


model_for_pruning.compile(loss='mean_squared_error', optimizer='SGD', metrics=['mean_squared_error'])
model_for_pruning.compile(
    loss="mse",
    optimizer=tf.keras.optimizers.Adam(learning_rate=0.001)
)


batch_size=len(x)

callbacks = [
  tfmot.sparsity.keras.UpdatePruningStep(),
]


history2=model_for_pruning.fit(x,y,batch_size=len(x), callbacks=callbacks, epochs=200)



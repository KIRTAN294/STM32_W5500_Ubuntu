import pandas as pd
import matplotlib.pyplot as plt
import numpy as np 

df = pd.read_csv('New_001.csv')

plt.hist(df['Final_Time'],bins=10,edgecolor='black')
plt.xticks(ticks=np.arange(0,3,0.2)) 


plt.xlabel('Sr.no')
plt.ylabel('Time')
plt.title('Scatter Plot of X vs Y')

plt.show()
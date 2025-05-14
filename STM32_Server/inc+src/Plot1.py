import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('New_001.csv')

plt.scatter(df['sr.no'], df['Final_Time'])
# plt.plot(df['sr.no'], df['Final_Time'],linestyle='-',label='Line')

plt.xlabel('Sr.no')
plt.ylabel('Time')
plt.title('Scatter Plot of X vs Y')

plt.show()
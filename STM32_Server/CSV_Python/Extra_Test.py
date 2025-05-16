import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns

df = pd.read_csv('New_Extra_02.csv')


expected_interval = 2.5
df["Final_Time"] = (df["Time"].diff())*1000
plt.figure(figsize=(13,7))
df ['jitter'] = df['Final_Time'].fillna(2.5)-2.5
# df.insert(0, 'sr.no', range(1, len(df) + 1))
# df = df.drop (columns=["Source","Destination","Protocol","Length","Info"])
# df = df.drop (columns=["Sr.No"])
df.to_csv("New_Extra_02.csv",index=False)
print(df)

# sns.boxplot(x="sr.no", y="Final_Time", data=df)
maxvlaue = df['Final_Time'].max()
minvalue = df['Final_Time'].min()
print(maxvlaue)
print(minvalue)

plt.subplot(1,2,1)
plt.hist(df['Final_Time'],bins=np.arange(0,3.2,0.2),edgecolor='black')
plt.xticks(ticks=np.arange(0,3.2,0.2)) 
plt.xlabel('Final_Time')
plt.ylabel('Frequency')
plt.grid(True)
plt.legend()

print(df.head())

plt.subplot(1,2,2)
plt.plot (df['sr.no'].values,df['Final_Time'].values,color='blue',marker='o',linestyle='-')
plt.axhline(y=expected_interval,color='red',linestyle='--')
plt.xlabel('Sr.no')
plt.ylabel('Time')
plt.legend()
plt.title('Xsens(400Hz-2.5ms) Jitter Plot')
plt.grid(True)
plt.show()
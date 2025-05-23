import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

df = pd.read_csv('Normal_Data_01.csv')

# df.insert(0, 'sr.no', range(1, len(df) + 1))
expected_interval = 1

plt.figure(figsize=(13,7))
# df ['jitter'] = df['Final_Time'].fillna(1)-1
# df = df.drop (columns=["Source","Destination","Protocol","Length","Info"])
# df = df.drop (columns=["Sr.No"])
# df["Final_Time"] = (df["Time"].diff())*1000
df.to_csv("Normal_Data_01.csv",index=False)
print(df)

# sns.boxplot(x="sr.no", y="Final_Time", data=df)
maxvlaue = df['F_Time'].max()
minvalue = df['F_Time'].min()
print(maxvlaue)
print(minvalue)

# plt.subplot(1,2,1)
plt.hist(df['F_Time'],bins=np.arange(0,4.6,0.2),color='red',edgecolor='black')
plt.xticks(ticks=np.arange(0,4.6,0.2)) 
plt.xlabel('Sr.no(Total_Packet)')
plt.ylabel('Data_Frequency(Range)')
plt.grid(True)
plt.legend()

print(df.head())

# plt.subplot(1,2,2)
# plt.plot (df['sr.no'].values,df['Final_Time'].values,color='blue',marker='o',linestyle='-')
# plt.axhline(y=expected_interval,color='red',linestyle='--')
# plt.xlabel('Sr.no(Total_Packet)')
# plt.ylabel('Time(ms)')
# plt.legend()
# plt.title('YDX-Packet timing In Normal Cond.(1ms/1000Hz)')
plt.grid(True)
plt.show()

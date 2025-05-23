import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

df_Stress = pd.read_csv('Stressed_Data_01.csv')
df_Normal = pd.read_csv('Normal_Data_01.csv')

# df.insert(0, 'sr.no', range(1, len(df) + 1))
expected_interval = 1
# df_Stress["Final_Time"] = (df["Time"].diff())*1000
plt.figure(figsize=(13,7))
# df ['jitter'] = df['Final_Time'].fillna(1)-1
# df = df.drop (columns=["Source","Destination","Protocol","Length","Info"])
# # df = df.drop (columns=["Sr.No"])
# df_Normal.to_csv('Normal_Data_01.csv',index=False)
print(df_Stress)

# sns.boxplot(x="sr.no", y="Final_Time", data=df)
maxvlaue = df_Stress['Final_Time'].max()
minvalue = df_Stress['Final_Time'].min()
print(maxvlaue)
print(minvalue)
print(df_Stress.head())


plt.hist(df_Stress['Final_Time'],bins=np.arange(0,5.2,0.2),color='blue',alpha=0.6, label='Stressed',edgecolor='black')
plt.hist(df_Normal['F_Time'],bins=np.arange(0,4.6,0.2),color='red',alpha=0.6, label='Normal',edgecolor='black')
plt.xlabel('Final Time (ms)')
plt.ylabel('Frequency')
plt.title('Overlapping Histograms: Stressed vs Normal')
plt.xticks(ticks=np.arange(0, 5.2, 0.2))
plt.grid(True)
plt.legend()
plt.show()


# plt.plot (df['sr.no'].values,df['Final_Time'].values,color='blue',marker='o',linestyle='-')
# plt.axhline(y=expected_interval,color='red',linestyle='--')
# plt.xlabel('Sr.no(Total_Packet)')
# plt.ylabel('Time(ms)')
# plt.legend()
# plt.title('YDX-Packet timing In Stress Cond.(1ms/1000Hz)')

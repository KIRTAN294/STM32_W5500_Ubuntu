# Compiler and flags
CC = gcc
CFLAGS = -Wall -IInc

# Source files
SRCS = Src/IMU_BMS_Deserialization.c Src/bms_can.c 

# Output executable name
TARGET = IMU_BMS_Deserialization

# Build rule
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Clean rule to remove build files
clean:
	rm -f $(TARGET)

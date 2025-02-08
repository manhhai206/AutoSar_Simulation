# Compiler and flags
CC = gcc
CFLAGS = -Wall -g -I./BSW/ECU_Abstraction -I./BSW/MCAL -I./BSW/service -I./RTE -I./SWC

# Object directory
OBJDIR = bin

# Executable
TARGET = $(OBJDIR)/ecu

# Source files
SRC = ./Main.c \
      ./RTE/Rte_TorqueControl.c \
      ./SWC/Torque_Control.c \
      ./BSW/ECU_Abstraction/TorqueSensor.c \
	  ./BSW/ECU_Abstraction/LoadSensor.c \
	  ./BSW/ECU_Abstraction/MotorDriver.c \
	  ./BSW/ECU_Abstraction/SpeedSensor.c \
	  ./BSW/ECU_Abstraction/ThrottleSensor.c \
      ./BSW/MCAL/Adc_M.c \
      ./BSW/MCAL/Dio.c \
      ./BSW/MCAL/Pwm.c

# Object files
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

# Build executable
$(TARGET): $(OBJ)
	@echo "Linking all objects to create $(TARGET)..."
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)
	@echo "Build successful!"

# Compile object files
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

# Clean up
.PHONY: clean
clean:
	@echo "Cleaning up..."
	rm -rf $(OBJDIR)
	@echo "Clean done!"

# Run program
.PHONY: run
run: $(TARGET)
	@echo "Running program..."
	$(TARGET)

CC := gcc
CFLAGS := -g -Wall -Werror -O0
LDFLAGS := -pthread
SRC_DIR := src
BIN_DIR := bin

# Source files and object file paths
SOURCES := $(wildcard $(SRC_DIR)/*.c)
OBJECTS := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%, $(SOURCES))

all: no_mutexes 

no_mutexes: CFLAGS += -DMUTEXES=0 
no_mutexes: $(BIN_DIR) $(OBJECTS)

mutexes: CFLAGS += -DMUTEXES=1
mutexes: $(BIN_DIR) $(OBJECTS)

# Create bin directory
$(BIN_DIR):
	@mkdir -p $@

# Compile src files to binary
$(BIN_DIR)/%: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

# Clean bin folder 
clean:
	@rm -rf $(BIN_DIR)

.PHONY: all clean


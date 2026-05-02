# Project Settings
PROJECT_NAME = my_game
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Detect Operating System
ifeq ($(OS),Windows_NT)
    PLATFORM_OS = WINDOWS
    CC = g++
    EXT = .exe
    # Relative paths for Windows (assumes raylib is in your project root)
    RAYLIB_PATH = .
    LDFLAGS = -L$(RAYLIB_PATH)/lib -lraylib -lopengl32 -lgdi32 -lwinmm
    CFLAGS_PLATFORM = -I$(RAYLIB_PATH)/include
    RM = del /Q
    FIX_PATH = $(subst /,\,$1)
    MKDIR = if not exist $(call FIX_PATH,$1) mkdir $(call FIX_PATH,$1)
else
    PLATFORM_OS = LINUX
    CC = g++
    EXT =
    # Linux typically uses system libraries
    LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
    CFLAGS_PLATFORM = 
    RM = rm -f
    FIX_PATH = $1
    MKDIR = mkdir -p $1
endif

# Compilation Flags
CXXFLAGS = -Wall -std=c++17 -Iinclude $(CFLAGS_PLATFORM)

# Source and Object files
# Ensure your .cpp files are inside the 'src' folder
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
TARGET = $(BIN_DIR)/$(PROJECT_NAME)$(EXT)

# --- Rules ---

# Run everything: make
all: build run

# Build the project
build: $(TARGET)

$(TARGET): $(OBJECTS)
	@$(call MKDIR,$(BIN_DIR))
	$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(call MKDIR,$(OBJ_DIR))
	$(CC) $(CXXFLAGS) -c $< -o $@

# Execute the program
run:
	@$(call FIX_PATH,$(TARGET))

# Clean build artifacts
clean:
	$(RM) $(call FIX_PATH,$(OBJ_DIR)/*.o)
	$(RM) $(call FIX_PATH,$(TARGET))

.PHONY: all build run clean

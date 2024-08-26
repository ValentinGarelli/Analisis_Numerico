# Compilador
CC = g++

# Opciones de compilación
CFLAGS = -Wall -g

# Directorios
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Archivos fuente y objetos
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))
TARGET = $(BIN_DIR)/main.exe

# Reglas
all: $(TARGET)

$(TARGET): $(OBJ_FILES) | $(BIN_DIR)
		$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
		$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
		mkdir -p $@

clean:
		rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean
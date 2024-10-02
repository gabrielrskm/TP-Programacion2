# Variables
CXX = g++
CXXFLAGS = -Wall -g -Iinclude
TARGET = bin/Debug/TP_Programacion2  # Ruta del ejecutable
SRC = main.cpp $(wildcard src/*.cpp)
OBJ = $(patsubst %.cpp, obj/Debug/%.o, $(SRC))  # Ruta de los archivos objeto
DEPS = $(wildcard include/*.h)

# Regla para compilar el proyecto
all: $(TARGET)

# Reglas de dependencias
$(TARGET): $(OBJ)
	@echo "Linking: $@"
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

# Regla general para compilar archivos .cpp a .o
obj/Debug/%.o: %.cpp $(DEPS)
	@echo "Compiling: $< -> $@"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar archivos binarios
clean:
	@echo "Cleaning up..."
	rm -f $(TARGET) $(OBJ)
	rm -rf bin/Debug obj/Debug  # Elimina los directorios de salida
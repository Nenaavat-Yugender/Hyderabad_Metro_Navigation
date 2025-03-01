CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
SRC_DIR = src
INCLUDE_DIR = include
DATA_DIR = data

OBJ = $(SRC_DIR)/stations.o $(SRC_DIR)/connections.o $(SRC_DIR)/main.o
TARGET = metro

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

$(SRC_DIR)/stations.o: $(SRC_DIR)/stations.cpp $(INCLUDE_DIR)/stations.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/stations.cpp -o $(SRC_DIR)/stations.o

$(SRC_DIR)/connections.o: $(SRC_DIR)/connections.cpp $(INCLUDE_DIR)/connections.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/connections.cpp -o $(SRC_DIR)/connections.o

$(SRC_DIR)/main.o: $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/stations.h $(INCLUDE_DIR)/connections.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/main.cpp -o $(SRC_DIR)/main.o

clean:
	rm -f $(SRC_DIR)/*.o $(TARGET)

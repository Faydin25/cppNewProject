# Ferhat Yiğit Aydın
# 05.07.2025

CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2
TARGET = main
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

fclean:
	rm -f $(TARGET) *.o

re: fclean all 
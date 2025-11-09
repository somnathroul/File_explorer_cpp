CC = g++
CFLAGS = -Wall -std=c++17
TARGET = file_explorer

all:
	$(CC) $(CFLAGS) src/file_explorer.cpp -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)

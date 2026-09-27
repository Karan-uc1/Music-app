CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2
TARGET = song_hashing

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

output: $(TARGET)
	./$(TARGET) > output.txt

clean:
	rm -f $(TARGET)

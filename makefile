CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SOURCES = cips.c cipus.c matrix.c
HEADERS = cipus.h matrix.h
TARGET = cips.exe

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	.\$(TARGET)

.PHONY: all run
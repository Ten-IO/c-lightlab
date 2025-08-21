CC = gcc
CFLAGS = -std=c11 -Wall -Wextra
TARGET = file_processor
SOURCE = main.c file_io.c string_utils.c
OBJ = $(SOURCE:.c=.o)
HEADERS = file_io.h string_utils.h config.h

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean

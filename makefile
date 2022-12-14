CC = gcc
CFLAGS = -Wall -std=c99
LDFLAGS= -L.

INC = include/
SRC = src/
BIN = bin/
ID3V1_SRC_FILES = $(wildcard src/id3v1*.c)
ID3V1_OBJ_FILES = $(patsubst src/id3v1%.c,bin/id3v1%.o,$(ID3V1_SRC_FILES))


sharedParser: $(BIN)libid3v1.so

staticParser: $(ID3V1_OBJ_FILES) $(INC)id3v1*.h
	$(CC) $(CFLAGS) -I$(INC) $(ID3V1_OBJ_FILES) -lm -c -o $(BIN)libid3v1.o

main: main.c $(ID3V1_OBJ_FILES) $(INC)id3v1*.h
	$(CC) $(CFLAGS) main.c $(ID3V1_OBJ_FILES) -I$(INC) -o main -lm

$(BIN)libid3v1.so: $(ID3V1_OBJ_FILES)
	$(CC) -shared -o $(BIN)libid3v1.so $(ID3V1_OBJ_FILES) -lm

$(BIN)id3v1%.o: $(SRC)id3v1%.c $(INC)id3v1.h
	$(CC) $(CFLAGS) -I$(INC) -c -fpic $< -o $@

clean:
	rm -rf $(BIN)*.o $(BIN)*.so main *.out
###################################################################################################

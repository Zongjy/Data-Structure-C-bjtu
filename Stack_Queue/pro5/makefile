CFLAGS		+=-Wall -g -D_FILE_OFFSET_BITS=64
CC			=gcc
TARGET		=fibonacci
SRC	 		=fibonacci.c

$(TARGET):$(SRC)
	$(CC) $(SRC) main.c $(CFLAGS) -o $@

clean:
	-rm -f $(TARGET)

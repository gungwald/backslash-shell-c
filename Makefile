CC=gcc
TARGET=cmd
OBJS=main.o String.o ArrayListOfString.o StringBuilder.o Tokenizer.o
CFLAGS=-Wall -g

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o cmd $(OBJS) -lreadline -lgc

clean:
	rm $(OBJS) $(TARGET)


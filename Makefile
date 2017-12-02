
TARGET=cmd
OBJS=main.o ArrayListOfString.o StringBuilder.o Tokenizer.o
CFLAGS=-Wall

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o cmd $(OBJS) -lreadline -lgc

clean:
	rm $(OBJS) $(TARGET)


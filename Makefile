CC = gcc
CFLAGS = -W -Wall
TARGET = productMenu
DTARGET = productMenu_debug
OBJECTS = main.c product.o manager.o function.o

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^

clean:
	rm *.o $(TARGET) $(DTARGET)


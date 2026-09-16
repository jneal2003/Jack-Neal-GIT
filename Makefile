CC = gcc
CFLAGS = -g
TARGET = myls
OBJS = main.o linked_list.o
DIST = myls.tar.gz
SOURCES = main.c linked_list.c linked_list.h Makefile

.PHONY: all clean dist

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c linked_list.h
	$(CC) $(CFLAGS) -c main.c

linked_list.o: linked_list.c linked_list.h
	$(CC) $(CFLAGS) -include stdio.h -c linked_list.c

dist: $(SOURCES)
	tar -czf $(DIST) $(SOURCES)

clean:
	rm -f $(TARGET) $(OBJS) $(DIST)

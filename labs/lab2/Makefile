TARGET = app
.PHONY: all clean run
all: $(TARGET)
clean:
	rm $(TARGET) *.o
run: $(TARGET)
	./$(TARGET)
main.o: main.c
	gcc -c main.c
bin.o: main.c
	gcc -c bin.c
oct.o: main.c
	gcc -c oct.c
hex.o: main.c
	gcc -c hex.c
funcs.o: main.c
	gcc -c funcs.c
$(TARGET): main.o bin.o oct.o hex.o funcs.o
	gcc main.o bin.o oct.o hex.o funcs.o -o $(TARGET)
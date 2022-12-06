TARGET = app
.PHONY: all clean run
all: $(TARGET)
clean:
	rm $(TARGET) *.o
run: $(TARGET)
	./$(TARGET)
main.o: main.c
	gcc -c main.c
funcs.o: main.c
	gcc -c funcs.c
$(TARGET): main.o funcs.o
	gcc main.o funcs.o -o $(TARGET)

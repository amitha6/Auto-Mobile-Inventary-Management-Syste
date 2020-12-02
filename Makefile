cc = gcc
TARGET = main
all:main.o view.o modify.o search.o delete.o add.o sorting_price.o quantity.o warranty.o
	$(cc) main.c view.c modify.c search.c delete.c add.c sorting_price.c quantity.c warranty.c -o $(TARGET)

clean:
	rm -f *.o

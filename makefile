flags = -Wall -ggdb
unittest = unittest/unittest.c unittest/unittest.h


.PHONY: all
all: array/test.exe list/test.exe


# List
.PHONY: listTests
listTests: list/test.exe
	list/test.exe

list/test.exe: list/test.c list/doubleList.o unittest/unittest.o
	gcc $(flags) -o list/test.exe list/test.c list/doubleList.o unittest/unittest.o


list/doubleList.o: list/doubleList.c list/doubleList.h list/listbase.c list/listbase.h
	gcc $(flags) -c -o list/doubleList.o list/doubleList.c


# Array
.PHONY: arrayTests
arrayTests: array/test.exe
	array/test.exe

array/test.exe: array/test.c array/array.o unittest/unittest.o
	gcc $(flags) -o array/test.exe array/test.c array/array.o unittest/unittest.o


array/array.o: array/array.c array/array.h
	gcc $(flags) -c -o array/array.o array/array.c


# Unit test
unittest/unittest.o: $(unittest)
	gcc $(flags) -c -o unittest/unittest.o unittest/unittest.c

array = array/test.c array/array.c array/array.h
unittest = unittest/unittest.c unittest/unittest.h

runtests: array/test.exe
	array/test.exe

array/test.exe: array/array.o unittest/unittest.o
	gcc -Wall -o array/test.exe array/test.c array/array.o unittest/unittest.o


array/array.o: $(array)
	gcc -Wall -c -o array/array.o array/array.c


unittest/unittest.o: $(unittest)
	gcc -Wall -c -o unittest/unittest.o unittest/unittest.c

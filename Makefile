flags = -Wall
all: bin build bin/prog bin/test

bin/prog: build/main.o build/function.o build/check.o
	gcc $(flags) build/main.o build/function.o build/check.o -o bin/prog -lncurses

build/main.o: src/main.c
	gcc $(flags) -c src/main.c -o build/main.o

build/function.o: src/function.c
	gcc $(flags) -c src/function.c -o build/function.o
	
build/check.o: src/check.c
	gcc $(flags) -c src/check.c -o build/check.o
bin:
	mkdir -p bin

build:
	mkdir -p build	
	
bin/test: build/test.o build/check.o build/ctest.o 
	gcc -Wall build/test.o build/check.o build/ctest.o  -o bin/test 

build/test.o: test/test.c
	gcc -Wall -c test/test.c -o build/test.o -Ithirdparty -Isrc

build/ctest.o: test/ctest.c
	gcc -Wall -c test/ctest.c -o build/ctest.o -Ithirdparty

test: bin/test
	bin/test


.PHONY: clean

clean:
	rm -rf build bin

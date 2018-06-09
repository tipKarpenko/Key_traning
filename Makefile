flags = -Wall
all: bin build bin/prog

bin/prog: build/main.o build/function.o 
	gcc $(flags) build/main.o build/function.o -o bin/prog -lncursesw

build/main.o: src/main.c
	gcc $(flags) -c src/main.c -o build/main.o

build/function.o: src/function.c
	gcc $(flags) -c src/function.c -o build/function.o


bin:
	mkdir -p bin

build:
	mkdir -p build

.PHONY: clean

clean:
	rm -rf build bin
all: build run clean

build:
	$(CC) main.c -g -o hello_world

run:
	./hello_world

clean:
	rm -rf hello_world

debug: build
	gdb ./hello_world

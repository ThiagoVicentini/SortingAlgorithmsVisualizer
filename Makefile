flags = -lglut -lGLU -lGL -Wall

all: build

run: build
	./bin/main

build: main.o

main.o: main.cpp
	@g++ main.cpp -o ./bin/main $(flags)

clean:
	@rm bin/main*

CC=g++
FLAGS=-g -std=c++17 -Wall -Werror -fsanitize=address -Wextra
test: main.o matrix.o
	$(CC) $(FLAGS) main.o matrix.o -o test

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -c

matrix.o: matrix.cpp
	$(CC) $(FLAGS) matrix.cpp -c
clean:
	rm -f *.o test

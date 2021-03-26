CC=g++
FLAGS=-std=c++17 -Wall -Werror -fsanitize=address -Wextra
test: test1.o allocator.o
	$(CC) $(FLAGS) test1.o allocator.o -o test

test1.o: test1.cpp
	$(CC) $(FLAGS) test1.cpp -c

allocator.o: allocator.cpp
	$(CC) $(FLAGS) allocator.cpp -c
clean:
	rm -f *.o test1

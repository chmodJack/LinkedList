all:
	@g++ main.cpp -std=c++11 -o list
	@./list
clean:
	@rm list -f a.out

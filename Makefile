all:
	@g++ main.cpp -std=c++17 -o list
	@./list
clean:
	@rm list -f a.out

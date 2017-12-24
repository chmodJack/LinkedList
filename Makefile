all:
	@g++ main.cpp -std=c++17 -o main -DDEBUG=1 -Ofast
	@./main main.cpp
clean:
	@rm list -f main

all:
	g++ -Wall -Wextra -o sorting_emporium sort.cpp

run-cpp: all
	./sorting_emporium

clean:
	rm -f sorting_emporium

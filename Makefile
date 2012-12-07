CPP = g++
CPPFLAGS = -Wall -Wextra -Werror

main: main.cpp
	$(CPP) $(CPPFLAGS) -o main main.cpp

clean:
	rm -f main

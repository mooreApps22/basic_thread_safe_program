CCT = cc -Wall -Wextra -Werror -fsanitize=thread
CCG = valgrind --tool=helgrind cc -Wall -Wextra -Werror -g
SRC = $(wildcard *.c)

all:
	$(CCT) $(SRC)
debug:
	$(CCG) $(SRC)
clean:
	rm a.out	

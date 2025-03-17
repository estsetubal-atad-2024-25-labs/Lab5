default:
	gcc -Wall -o prog main.c input.c arrays.c
debug:
	gcc -Wall -o prog -g main.c input.c arrays.c
clean:
	rm -f prog

# Call all to build the script
all: src/main.c lexer.o
	gcc src/main.c lexer.o -o build

lexer.o: src/lexer.c
	gcc -c src/lexer.c -I src/headers -o lexer.o

# clean all the tmp files
clean:
	rm -rf *.o
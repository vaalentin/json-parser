# Call all to build the script
# -c don't link
# -I header path
# -o output
all: src/main.c lexer.o Buffer.o Tokenlist.o Token.o
	gcc -I src/headers src/main.c Buffer.o lexer.o Tokenlist.o Token.o -o build

lexer.o: src/lexer.c
	gcc -c src/lexer.c -I src/headers -o lexer.o

Buffer.o: src/Buffer.c
	gcc -c src/Buffer.c -I src/headers -o Buffer.o

Tokenlist.o: src/Tokenlist.c
	gcc -c src/Tokenlist.c -I src/headers -o Tokenlist.o

Token.o: src/Token.c
	gcc -c src/Token.c -I src/headers -o Token.o

# clean all the tmp files
clean:
	rm -rf *.o
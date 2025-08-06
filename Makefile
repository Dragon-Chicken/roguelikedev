build:
	gcc -Wall *.c -o game -lncurses
run:
	./game
clean:
	rm game

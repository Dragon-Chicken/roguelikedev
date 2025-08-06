build:
	gcc -Wall src/*.c -o game -lncurses
run:
	./game
clean:
	rm game

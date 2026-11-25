run: strcmp.c
	gcc strcmp.c -o run

clean:
	rm -f run

.PHONY: clean

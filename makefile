all: controlla.c
	@gcc -o out controlla.c

clean:
	@rm *.o
	@rm *~

run: all
	@./out -c 4
	@./out -v
	@./out -c 3
	@./out -v
	@./out -r

CC = gcc

shop: main.c product.o
	gcc -o shop main.c product.o
product.o: product.c product.h
	gcc -c product.c -o product.o 
clean:
	rm *.o shop


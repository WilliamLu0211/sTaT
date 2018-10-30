all: stat_driver.o
	gcc stat_driver.o

stat_driver.o: stat_driver.c
	gcc -c stat_driver.c

run:
	./a.out

clean:
	rm *.o

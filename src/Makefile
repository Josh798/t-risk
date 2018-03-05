all: risk

risk: risk.o printEmptyMap.o game_components.h
	gcc risk.o printEmptyMap.o -o ../bin/risk -lncursesw

risk.o: Risk.c kernel.h game_components.h
	gcc -c -o risk.o Risk.c -lncursesw

printEmptyMap.o: printEmptyMap.c kernel.h
	gcc -c printEmptyMap.c -lncursesw

clean:
	rm -rf *.o risk

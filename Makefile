all: risk

risk: risk.o printEmptyMap.o game_components.h
	gcc src/risk.o src/printEmptyMap.o -o risk -lncursesw

risk.o: Risk.c kernel.h game_components.h
	gcc -c -o src/risk.o src/Risk.c -lncursesw

printEmptyMap.o: printEmptyMap.c kernel.h
	gcc -c src/printEmptyMap.c -lncursesw

clean:
	rm -rf *.o risk


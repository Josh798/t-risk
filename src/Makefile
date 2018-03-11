all: risk

risk: risk.o printEmptyMap.o GeneralIO.o GameSetup.o GameManager.o game_components.h
	gcc -g risk.o printEmptyMap.o GeneralIO.o GameSetup.o GameManager.o -o ../bin/risk -lncursesw

risk.o: Risk.c kernel.h game_components.h
	gcc -c -g -o risk.o Risk.c -lncursesw

printEmptyMap.o: printEmptyMap.c kernel.h
	gcc -c -g printEmptyMap.c -lncursesw

GeneralIO.o: GeneralIO.c kernel.h
	gcc -c -g GeneralIO.c -lncursesw

GameSetup.o: GameSetup.c kernel.h
	gcc -c -g GameSetup.c -lncursesw

GameManager.o: GameManager.c kernel.h
	gcc -c -g GameManager.c -lncursesw

clean:
	rm -rf *.o risk

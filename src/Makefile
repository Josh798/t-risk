all: risk

risk: risk.o printEmptyMap.o GeneralIO.o GameSetup.o GameManager.o game_components.h
	gcc risk.o printEmptyMap.o GeneralIO.o GameSetup.o GameManager.o -o ../bin/risk -lncursesw -g

risk.o: Risk.c kernel.h game_components.h
	gcc -c -o risk.o Risk.c -lncursesw-g

printEmptyMap.o: printEmptyMap.c kernel.h
	gcc -c printEmptyMap.c -lncursesw -g

GeneralIO.o: GeneralIO.c kernel.h
	gcc -c GeneralIO.c -lncursesw -g

GameSetup.o: GameSetup.c kernel.h
	gcc -c GameSetup.c -lncursesw -g

GameManager.o: GameManager.c kernel.h
	gcc -c GameManager.c -lncursesw -g

clean:
	rm -rf *.o risk

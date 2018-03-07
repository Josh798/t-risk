all: risk

risk: risk.o printEmptyMap.o GeneralIO.o game_components.h
	gcc risk.o printEmptyMap.o GeneralIO.o -o ../bin/risk -lncursesw

risk.o: Risk.c kernel.h game_components.h
	gcc -c -o risk.o Risk.c -lncursesw

printEmptyMap.o: printEmptyMap.c kernel.h
	gcc -c printEmptyMap.c -lncursesw

GeneralIO.o: GeneralIO.c kernel.h
	gcc -c GeneralIO.c -lncursesw

clean:
	rm -rf *.o risk

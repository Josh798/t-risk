all: t-risk

t-risk:
	cd src && $(MAKE)

clean:
	rm -rf *.o

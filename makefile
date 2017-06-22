all: prueba

prueba: libmilista.so -lm pruebaLista.o
	gcc pruebaLista.o -Llib/ -lmilista -Wl,-rpath,./lib -lm -o prueba

libmilista.so: libmilista.o -lm
	gcc -shared libmilista.o -lm -o lib/libmilista.so

libmilista.o: src/libmilista.c include/miLista.h
	gcc -c -fPIC -Wall -I./include/ src/libmilista.c

pruebaLista.o: src/pruebaLista.c include/miLista.h
	gcc -c -fPIC -Wall -I./include/ src/pruebaLista.c

clean: 
	rm prueba libmilista.o pruebaLista.o lib/libmilista.so


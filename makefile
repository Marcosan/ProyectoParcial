all: prueba

prueba: libmilista.so -lm pruebaLista.o
	gcc -g -Wall obj/pruebaLista.o -Llib/ -lmilista -Wl,-rpath,./lib -lm -o prueba

libmilista.so: libmilista.o -lm
	gcc -Wall -shared -g obj/libmilista.o -lm -o lib/libmilista.so

libmilista.o: src/libmilista.c include/miLista.h
	gcc -c -fPIC -g -Wall -I./include/ src/libmilista.c -o obj/libmilista.o

pruebaLista.o: src/pruebaLista.c include/miLista.h
	gcc -c -fPIC -g -Wall -I./include/ src/pruebaLista.c -o obj/pruebaLista.o

clean: 
	rm  prueba obj/libmilista.o obj/pruebaLista.o lib/libmilista.so
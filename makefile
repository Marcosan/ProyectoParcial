all: prueba

dinamico: libdatos.so -lm main.o
	gcc main.o -L./ -ldatos -lm -o dinamico

estatico: libdatos.a -lm main.o
	gcc main.o libdatos.a -lm -o estatico

libdatos.a: calcularAguaCorporal.o calcularBMI.o calcularRitmoCarRes.o calcularTasaMetabolica.o mostrar_nombre.o
	ar rcs libdatos.a calcularAguaCorporal.o calcularBMI.o calcularRitmoCarRes.o calcularTasaMetabolica.o mostrar_nombre.o

libdatos.so: calcularAguaCorporal.o calcularBMI.o calcularRitmoCarRes.o calcularTasaMetabolica.o mostrar_nombre.o -lm
	gcc -shared calcularAguaCorporal.o calcularBMI.o calcularRitmoCarRes.o calcularTasaMetabolica.o mostrar_nombre.o -lm -o libdatos.so

main.o: main.c
	gcc -c -fPIC -Wall main.c

calcularAguaCorporal.o: calcularAguaCorporal.c
	gcc -c -fPIC -Wall calcularAguaCorporal.c

calcularBMI.o: calcularBMI.c
	gcc -c -fPIC -Wall calcularBMI.c

calcularRitmoCarRes.o: calcularRitmoCarRes.c
	gcc -c -fPIC -Wall calcularRitmoCarRes.c

calcularTasaMetabolica.o: calcularTasaMetabolica.c
	gcc -c -fPIC -Wall calcularTasaMetabolica.c

mostrar_nombre.o: mostrar_nombre.c
	gcc -c -fPIC -Wall mostrar_nombre.c

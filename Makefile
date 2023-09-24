br:clean compilar ejecutar

compilar:src/main.cpp
	g++ src/main.cpp -o bin/code -I include

ejecutar:bin/code
	./bin/code

clean:bin/code
	rm bin/code
make:	babble.cpp
	g++ babble.cpp -o inJava

run: 	inJava
	./inJava

install:	inJava 
	sudo binstall inJava

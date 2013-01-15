make:	babble.cpp
	g++ babble.cpp -o injavac

run: 	injavac
	@./injavac

install:	injavac 
	sudo binstall injavac

all: compile link

compile:
	g++ -I src/include -c main.cpp ball.cpp
link: 
	g++ main.o ball.o  -o main -L src/lib -l sfml-graphics -l sfml-window -l sfml-system
Tum: derleme calistirma

derleme:
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include/ -o ./lib/AvlNode.o -c ./src/AvlNode.cpp
	g++ -I ./include/ -o ./lib/StackNode.o -c ./src/StackNode.cpp
	g++ -I ./include/ -o ./lib/AvlTree.o -c ./src/AvlTree.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Stack.o ./lib/AvlNode.o ./lib/StackNode.o ./lib/AvlTree.o ./src/Test.cpp


calistirma:
	./bin/Test
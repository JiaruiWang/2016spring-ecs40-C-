all : BST.out BST2.out

BST.out : main.o
	g++ -Wall -ansi -g -o BST.out main.o

main.o : main.cpp BinarySearchTree.cpp BinarySearchTree.h
	g++ -D NDEBUG -Wall -ansi -g -c main.cpp

BST2.out : main2.o
	g++ -Wall -ansi -g -o BST2.out main2.o

main2.o : main.cpp BinarySearchTree.cpp BinarySearchTree.h
	g++ -Wall -ansi -g -c main.cpp -o main2.o

clean :
	rm -f main.o BST.out
all: show_node count_nodes alphatoe

show_node: show_node.o	ttt1.o	ttt2.o
	gcc -std=c99 -Wall -pedantic show_node.o  ttt1.o   ttt2.o -o show_node

show_node.o: show_node.c ttt.h
	gcc -std=c99 -Wall -pedantic -c show_node.c -o show_node.o

count_nodes: count_nodes.o	ttt1.o	ttt2.o
	gcc -std=c99 -Wall -pedantic count_nodes.o  ttt1.o   ttt2.o -o count_nodes

count_nodes.o: count_nodes.c ttt.h
	gcc -std=c99 -Wall -pedantic -c count_nodes.c -o count_nodes.o
	

alphatoe: alphatoe.o  ttt1.o	ttt2.o
	gcc -std=c99 -Wall -pedantic alphatoe.o  ttt1.o   ttt2.o -o alphatoe

alphatoe.o: alphatoe.c ttt.h
	gcc -std=c99 -Wall -pedantic -c alphatoe.c -o alphatoe.o
	
ttt1.o: ttt1.c	ttt.h
		gcc -std=c99 -Wall -pedantic -c ttt1.c -o ttt1.o

ttt2.o: ttt2.c	ttt.h
		gcc -std=c99 -Wall -pedantic -c ttt2.c -o ttt2.o


clean:
		rm show_node show_node.o count_nodes count_nodes.o alphatoe alphatoe.o ttt1.o ttt2.o

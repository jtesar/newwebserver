mysebserver: mywebserver.cc control_loop.o
	g++ -o mywebserver mywebserver.cc control_loop.o

control_loop.o: control_loop.cc
	g++ -c control_loop.cc

install:
	cp mywebserver /usr/bin
clean:
	rm -f mywebserver *.o


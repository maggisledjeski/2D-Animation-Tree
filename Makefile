LDLIBS = -lglut -lGL -lGLU -lX11 -lm
OBJS = myinit.o display.o #put object files here put a space to separate

run_fast: main.o
	c++ main.o $(LDLIBS) $(OBJS)

main.o: main.cpp $(OBJS)
	c++ -c main.cpp

myinit.o: myinit.cpp
	c++ -c myinit.cpp

display.o: display.cpp
	c++ -c display.cpp

clean:
	rm *.o
	rm a.out

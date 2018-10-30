LDLIBS = -lglut -lGL -lGLU -lX11 -lm
OBJS = myinit.o display.o drawtree.o rotate.o keyboardmouse.o drawcircle.o #put object files here put a space to separate

run_fast: main.o
	c++ -o run main.o $(LDLIBS) $(OBJS)

main.o: main.cpp $(OBJS)
	c++ -c main.cpp

myinit.o: myinit.cpp
	c++ -c myinit.cpp

display.o: display.cpp
	c++ -c display.cpp

drawtree.o: drawtree.cpp
	c++ -c drawtree.cpp

rotate.o: rotate.cpp
	c++ -c rotate.cpp

keyboardmouse.o: keyboardmouse.cpp
	c++ -c keyboardmouse.cpp

drawcircle.o: drawcircle.cpp
	c++ -c drawcircle.cpp

clean:
	rm *.o
	rm run

CFLAGS = -g
LDLIBS = -lglut -lGL -lGLU -lX11 -lm
OBJS = myinit.o display.o drawtree.o rotate.o keyboardmouse.o transform.o scale.o \
       reflect.o clip.o tess.o pipe.o drawcircle.o #sh.o drawcircle.o #put object files here put a space to separate

run_fast: main.o
	c++ $(CFLAGS) -o run main.o $(LDLIBS) $(OBJS)

main.o: main.cpp $(OBJS)
	c++ $(CFLAGS) -c main.cpp

myinit.o: myinit.cpp
	c++ $(CFLAGS) -c myinit.cpp

display.o: display.cpp
	c++ $(CFLAGS) -c display.cpp

drawtree.o: drawtree.cpp
	c++ $(CFLAGS) -c drawtree.cpp

rotate.o: rotate.cpp
	c++ $(CFLAGS) -c rotate.cpp

keyboardmouse.o: keyboardmouse.cpp
	c++ $(CFLAGS) -c keyboardmouse.cpp

transform.o: transform.cpp
	c++ $(CFLAGS) -c transform.cpp

scale.o: scale.cpp
	c++ $(CFLAGS) -c scale.cpp

reflect.o: reflect.cpp
	c++ $(CFLAGS) -c reflect.cpp

clip.o: clip.cpp
	c++ $(CFLAGS) -c clip.cpp

tess.o: tess.cpp
	c++ $(CFLAGS) -c tess.cpp

pipe.o: pipe.cpp
	c++ $(CFLAGS) -c pipe.cpp

#sh.o: sh.cpp
#	c++ $(CFLAGS) -c sh.cpp

drawcircle.o: drawcircle.cpp
	c++ $(CFLAGS) -c drawcircle.cpp

clean:
	rm *.o
	rm run

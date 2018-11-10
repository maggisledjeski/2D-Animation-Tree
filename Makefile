CC = c++ 
CFLAGS = -g
LDLIBS = -L/usr/lib64 -lGL -lGLU -lglut -lX11 -lm
OBJS = myinit.o display.o drawtree.o rotate.o keyboardmouse.o transform.o scale.o \
       reflect.o clip.o tess.o pipe.o drawcircle.o #put object files here put a space to separate

run: main.o 
	$(CC) $(CFLAGS) -o run main.o $(OBJS) $(LDLIBS) 

main.o: main.cpp $(OBJS)
	$(CC) $(CFLAGS) -c main.cpp

myinit.o: myinit.cpp
	$(CC) $(CFLAGS) -c myinit.cpp

display.o: display.cpp
	$(CC) $(CFLAGS) -c display.cpp

drawtree.o: drawtree.cpp
	$(CC) $(CFLAGS) -c drawtree.cpp

rotate.o: rotate.cpp
	$(CC) $(CFLAGS) -c rotate.cpp

keyboardmouse.o: keyboardmouse.cpp
	$(CC) $(CFLAGS) -c keyboardmouse.cpp

transform.o: transform.cpp
	$(CC) $(CFLAGS) -c transform.cpp

scale.o: scale.cpp
	$(CC) $(CFLAGS) -c scale.cpp

reflect.o: reflect.cpp
	$(CC) $(CFLAGS) -c reflect.cpp

clip.o: clip.cpp
	$(CC) $(CFLAGS) -c clip.cpp

tess.o: tess.cpp
	$(CC) $(CFLAGS) -c tess.cpp

pipe.o: pipe.cpp
	$(CC) $(CFLAGS) -c pipe.cpp

drawcircle.o: drawcircle.cpp
	$(CC) $(CFLAGS) -c drawcircle.cpp

clean:
	rm *.o
	rm run

CC = g++

src = $(wildcard src/*.cpp)
obj = $(src:.cpp=.o)

LDFLAGS = -lsdl2 -lsdl2main

ifeq ($(shell uname -s), Darwin) #  Platform detection test
    #libgl = -framework OpenGL -framework GLUT
else
    #libgl = -lGL -lglut
endif

game: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) game
CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD
LDFLAGS= -lsfml-graphics -lsfml-window -lsfml-system
EXEC = main
OBJECTS = main.o controller.o display.o board.o player.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -g ${LDFLAGS}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

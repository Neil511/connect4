CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD -g
LDFLAGS= -lsfml-graphics -lsfml-window -lsfml-system
EXEC = main
OBJECTS = main.o controller.o display.o board.o player.o cpu.o human.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -g ${LDFLAGS}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = main -lsfml-graphics -lsfml-window -lsfml-system
OBJECTS = main.o controller.o display.o board.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -g

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC[0]} ${DEPENDS}

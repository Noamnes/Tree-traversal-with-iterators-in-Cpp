 # noam sayada
 # noamsayada1@gmail.com
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g
SFML = -lsfml-graphics -lsfml-window -lsfml-system
SRC = Demo.cpp Complex.cpp TestCounter.cpp Test.cpp
OBJ = $(SRC:.cpp=.o)

tree: demo
	./$^

demo: Demo.o Complex.o
	$(CXX) $(CXXFLAGS) $^ -o demo $(SFML)

test: TestCounter.o Test.o Complex.o
	$(CXX) $(CXXFLAGS) $^ -o test

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o demo test

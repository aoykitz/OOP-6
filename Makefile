CXX      = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -O2
SRCS     = $(wildcard src/*.cpp)
OBJS     = $(SRCS:.cpp=.o)
TARGET   = OOP6

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	-rm -f $(OBJS) $(TARGET) $(TARGET).exe

run: all
	./$(TARGET)

docs:
	doxygen Doxyfile

.PHONY: all clean run docs
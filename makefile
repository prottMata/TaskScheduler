CXX=g++

CXXFLAGS=-Wall -g

TARGET=Main

TARGET_DEL=Main

SRCS=Main.cpp TaskScheduler.cpp

OBJS=$(SRCS:.cpp=.o)

all: $(TARGET) run

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm $(TARGET_DEL) $(OBJS)

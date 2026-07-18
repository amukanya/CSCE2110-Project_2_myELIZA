CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
TARGET = myELIZA
SOURCES = main.cpp Eliza.cpp ConversationHistory.cpp GenericResponses.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

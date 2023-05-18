CXX = g++
TARGET = bin/main.exe
OBJ = obj/main.o obj/LinkedList.o 
CXXFLAGS = -c -Wall -g

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

obj/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean_obj:
	del obj\*

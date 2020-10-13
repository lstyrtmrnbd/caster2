CXX = clang

DEVCFLAGS =  -ggdb -Wall -Wextra -Werror -Wpedantic -std=c++14

LIBS = -lstdc++ -lpng
OLDLIBS = -lstdc++ -lsfml-graphics -lsfml-window -lsfml-system
TESTLIBS = -lstdc++ -lm

#---- primary target
OBJECTS = build/main.o

caster2: $(OBJECTS)
	$(CXX) $(DEVCFLAGS) -o $@ $^ $(LIBS)

build/%.o : src/%.cpp
	$(CXX) $(DEVCFLAGS) -c $< -o $@

#---- tests target
tests: tests.bin

TESTOBJ = build/tests.o

tests.bin: $(TESTOBJ)
	$(CXX) $(DEVCFLAGS) -o $@ $^ $(TESTLIBS)

build/%.o : tests/%.cpp
	$(CXX) $(DEVCFLAGS) -c $< -o $@

#---- clean
clean:
	rm $(OBJECTS) $(TESTOBJ)

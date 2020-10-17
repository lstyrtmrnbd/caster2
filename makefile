CXX = clang

DEVCFLAGS =  -ggdb -Wall -Wextra -Werror -Wpedantic -std=c++20

LIBS = -lstdc++ -lm -lpng
TESTLIBS = -lstdc++ -lm

#---- primary target
OBJ = build/main.o

caster2: $(OBJ)
	$(CXX) $(DEVCFLAGS) -o $@ $^ $(LIBS)

$(OBJ): build/%.o : src/%.cpp
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
	rm $(OBJ) $(TESTOBJ)

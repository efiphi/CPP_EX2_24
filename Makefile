CXX = clang++
CXXFLAGS = -std=c++11 -Werror -Wsign-conversion
VALGRIND_FLAGS = -v --leak-check=full --show-leak-kinds=all --error-exitcode=99

# Define source files for each target
SOURCES_DEMO = Demo.cpp Graph.cpp Algorithms.cpp
SOURCES_TEST = TestCounter.cpp Test.cpp Graph.cpp Algorithms.cpp

# Define object files for each target
OBJECTS_DEMO = $(SOURCES_DEMO:.cpp=.o)
OBJECTS_TEST = $(SOURCES_TEST:.cpp=.o)

# Default rule
all: demo test

# Rule to build demo
demo: $(OBJECTS_DEMO)
	$(CXX) $(CXXFLAGS) $^ -o demo

# Rule to build test
test: $(OBJECTS_TEST)
	$(CXX) $(CXXFLAGS) $^ -o test

# Rule to run demo
run: demo
	./demo

# Rule to run clang-tidy
tidy:
	clang++-tidy $(SOURCES_DEMO) $(SOURCES_TEST) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

# Rule to run valgrind
valgrind: demo test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

# Rule to clean up generated files
clean:
	rm -f *.o demo test

# Define compiler and flags
CXX = g++
CXXFLAGS = -Wall -g -std=c++11

# Define directories
BINDIR = bin

# Define the executable to build
EXEC = $(BINDIR)/listen_up

# List all object files here, prefixed with the bin directory
OBJS = $(BINDIR)/listen_up.o $(BINDIR)/CommandManager.o $(BINDIR)/Song.o $(BINDIR)/BST.o $(BINDIR)/Heap.o

# Default target
all: $(EXEC)

# Ensure the bin directory exists
$(shell mkdir -p $(BINDIR))

# Linking the executable
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)

# Compiling source files into object files
$(BINDIR)/listen_up.o: listen_up.cpp CommandManager.h
	$(CXX) $(CXXFLAGS) -c listen_up.cpp -o $(BINDIR)/listen_up.o

$(BINDIR)/CommandManager.o: CommandManager.cpp CommandManager.h Song.h Array.h BST.h Heap.h
	$(CXX) $(CXXFLAGS) -c CommandManager.cpp -o $(BINDIR)/CommandManager.o

$(BINDIR)/Song.o: Song.cpp Song.h
	$(CXX) $(CXXFLAGS) -c Song.cpp -o $(BINDIR)/Song.o

$(BINDIR)/BST.o: BST.cpp BST.h Node.h
	$(CXX) $(CXXFLAGS) -c BST.cpp -o $(BINDIR)/BST.o

$(BINDIR)/Heap.o: Heap.cpp Heap.h
	$(CXX) $(CXXFLAGS) -c Heap.cpp -o $(BINDIR)/Heap.o

# Clean up
clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean

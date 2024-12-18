# Specifiy the target
all: listen

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
listen: Listen.o Song.o SongCollection.o
	g++ Listen.o Song.o SongCollection.o -o listen

# Specify how the object files should be created from source files
Song.o: Song.cpp Song.h
	g++ -c -g Song.cpp

SongCollection.o: SongCollection.cpp SongCollection.h Song.h
	g++ -c -g SongCollection.cpp
	
Listen.o: Listen.cpp SongCollection.h Song.h
	g++ -c -g Listen.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o listen

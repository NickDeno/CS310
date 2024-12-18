all: SongMenu

SongMenu: SongMenu.o 
	g++ SongMenu.o -o SongMenu

SongMenu.o: SongMenu.cpp
	g++ -c -g SongMenu.cpp
	
clean:
	rm -f *.o SongMenu

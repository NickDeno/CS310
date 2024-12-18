all: cp2_songs

cp2_songs: cp2_songs.o Song.o Playlist.o PlaylistCollection.o
	g++ cp2_songs.o -o cp2_songs Song.o Playlist.o PlaylistCollection.o

cp2_songs.o: cp2_songs.cpp
	g++ -c -g cp2_songs.cpp

PlaylistCollection.o: PlaylistCollection.cpp PlaylistCollection.h
	g++ -c -g PlaylistCollection.cpp

Playlist.o: Playlist.cpp Playlist.h
	g++ -c -g Playlist.cpp

Song.o: Song.cpp Song.h
	g++ -c -g Song.cpp

clean:
	rm -f *.o cp2_songs
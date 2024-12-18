#include "Song.h"
#include "SongCollection.h"

int main(int argc, char *argv[]) {
   Song one;
   Song *two = new Song("In Your Eyes", 1986, "Peter Gabriel");
   one.show();
   two->show();
   delete(two);

   Song mySong("Firework", 2010, "Katie Perry");
   SongCollection collection(mySong);
   collection.show();
}

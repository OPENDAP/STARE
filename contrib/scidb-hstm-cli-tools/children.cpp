/*

  Print to stdout the children of SciDB indexes read from stdin.

  Originally developed for NASA's DERECHOS project in 2017.

  Michael L. Rilee
  mike@rilee.net
  2017-0724
*/

#include "EmbeddedLevelNameEncoding.h"

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
  bool hexp = false;
  if( argc > 1) {
    hexp = string(argv[1]) == "--hex";
  }
  string str; size_t sz;
  long long int i;
  EmbeddedLevelNameEncoding ljSci, parent, child;
  while( getline(cin, str) && str.length() ) {
    i = stoll(str,&sz,0);
    ljSci.setIdFromSciDBLeftJustifiedFormat(i);
    if(hexp) cout << hex;
    // cout << ljSci.getSciDBLeftJustifiedFormat() << endl;
    parent = ljSci.atLevel(ljSci.getLevel()); // It's just me...
    parent = parent.clearDeeperThanLevel(parent.getLevel());
    // cout << parent.getSciDBLeftJustifiedFormat() << endl;
    child  = parent.atLevel(parent.getLevel()+1);
    cout << child.getSciDBLeftJustifiedFormat() << endl;
    for(int k=1; k<4; ++k){
      child.setId(child.increment(child.getId(),parent.getLevel()+1));
      cout << child.getSciDBLeftJustifiedFormat() << endl;
    }
  }
  return 0;
}


/* Write your test code for the ULListStr in this file */

#include "ulliststr.h"
#include <iostream>
using namespace std;


void printList(const ULListStr& dat) {
  cout << "List with " << dat.size() << " items" << endl;
  for(size_t i = 0; i < dat.size(); ++i) {
    cout << dat.get(i) << " ";
  }
  cout << endl;
}

int main(int argc, char* argv[])
{
  ULListStr dat;
  dat.push_back("7");
  dat.push_front("8");
  dat.push_back("9");
  printList(dat);
  return 0;
}

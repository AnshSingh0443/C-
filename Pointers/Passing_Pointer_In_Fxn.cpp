#include <iostream>
using namespace std;

void util(int* p )
{
    //copy pointer p is created which also points to a
    // p = p + 1;->updates the address of copy pointer p 
    *p = *p + 1;
}

int main() {
  int a = 5;

  int* p = &a;

  cout << "before" << endl;
  cout << a << endl;
  cout << p << endl;
  cout << *p << endl;

  util(p);

  cout << endl << "after" << endl;
  cout << a << endl;
  cout << p << endl;
  cout << *p << endl;
  return 0;
}
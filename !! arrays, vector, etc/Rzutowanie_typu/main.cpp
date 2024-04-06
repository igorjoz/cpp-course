#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
  for (unsigned int i=32; i<256; ++i)
  {
      cout <<i<<". "<<"'"<< (char) i<<"'"<<" ";
      if ((i+1)%5 == 0) cout<<endl;
  }

  cout <<endl<<"Nacisnij ENTER aby zakonczyc"<<endl;
  getchar();
  return 0;
}

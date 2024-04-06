#include <iostream>       // cout
#include <string>         // string

using namespace std;

int main ()
{
  string napis ("There are two needles in this haystack with needles.");
  string str2 ("needle");

  // different member versions of find in the same order as above:
  size_t found = napis.find(str2);
  if (found!=string::npos)
    cout<<"first \"needle\" found at: "<<found<<endl;

  found=napis.find("needles are small",found+1,6);
  if (found!=string::npos)
    cout<<"second \"needle\" found at: "<<found<<endl;

  found=napis.find("haystack");
  if (found!=string::npos)
    cout<<"\"haystack\" also found at: "<<found<<endl;

  found=napis.find('.');
  if (found!=string::npos)
    cout<<"Period found at: "<<found<<endl;

  // let's replace the first "needle":
  napis.replace(napis.find(str2),str2.length(),"preposition");
  cout<<napis<<endl;

  return 0;
}

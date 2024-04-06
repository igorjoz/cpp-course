#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
  int pierwsza, druga;

  cout<<"Podaj pierwsza liczbe: ";
  cin>>pierwsza;

  cout<<"Podaj druga liczbe: ";
  cin>>druga;

  cout<<endl<<"Liczby bez zmiany:"<<endl;
  cout<<"Pierwsza: "<<pierwsza<<endl;
  cout<<"Druga: "<<druga<<endl<<endl;

  // Uzyskanie wartosci bezwzglednej z podanych liczb
  pierws50za=abs(pierwsza);
  druga=abs(druga);

  cout<<endl<<"Wartosc bezwzgledna z podanych liczb:"<<endl;
  cout<<"Pierwsza: "<<pierwsza<<endl;
  cout<<"Druga: "<<druga;

  cout<<endl<<endl;
  return 0;
}

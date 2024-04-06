#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    /*
   string str = "1337 1.337 13.37 1337";

   istringstream istr(str);

   int liczba1, liczba4;
   float liczba2;
   double liczba3;

   istr >> liczba1 >> liczba2 >> liczba3 >> liczba4;

   cout<<"Liczby po konwersji\n";
   cout<<liczba1<<"\t";
   cout<<liczba2<<"\t";
   cout<<liczba3<<"\t";
   cout<<liczba4<<"\t";

   cout<<"\n\n";
   */

   string liczby;
   int t[5];

   cout<<"Podaj 5 liczb, oddzielone tylko spacja; enter tylko na koncu:\n";
   getline(cin, liczby);

   istringstream conv(liczby);

       conv>>t[0]>>t[1]>>t[2]>>t[3]>>t[4];

       for (int i=0; i<5; i++)
       {
           cout<<t[i]<<"\t";
       }

       /*
       int t[5];

       string napis="1 2 5 8 9";

       istringstream istr(napis);

       istr>>t[0]>>t[1]>>t[2]>>t[3]>>t[4];

       for (int i=0; i<5; i++)
       {
           cout<<t[i]<<"\t";
       }
       */

       return 0;
}

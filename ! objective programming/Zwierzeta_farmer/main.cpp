#include <iostream>

using namespace std;

class Zwierze
{
    public:

    /* ATRYBUTY */
  string gatunek;
  string imie;
  int wiek;

  /* METODY */
  void dodaj_zwierze ()
  {
      cout<<"Dodawanie nowego zwierzecia do bazy"<<endl;

      cout<<"Podaj gatunek: ";
      cin>>gatunek;

      cout<<"Podaj imie: ";
      cin>>imie;

      cout<<"Podaj wiek: ";
      cin>>wiek;
  }

  void daj_glos ()
  {
      cout<<endl;

      if (gatunek=="kot") cout<<imie<<" lat "<<wiek<<" MIAU xd";
      else if (gatunek=="koza") cout<<imie<<" lat "<<wiek<<" BEEE xd";
      else if (gatunek=="krowa") cout<<imie<<" lat "<<wiek<<" MUUU xd";
      else if (gatunek=="slon") cout<<imie<<" lat "<<wiek<<" PIUUM xd";
      else cout<<"Nieznany gatunek, prawdopodobnie GMO, ktorego nie ma w bazie danych";
  }

};

int main()
{
    Zwierze z1;
    Zwierze z2;

    z1.dodaj_zwierze();



    z2.dodaj_zwierze();

    z1.daj_glos();

    cout<<endl<<endl;
    return 0;
}

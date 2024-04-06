#include <iostream>

using namespace std;

int main()
{
    int r1, r2, m1, m2, d1, d2;
    cout << "Podaj rok pierwszej daty: ";
    cin>>r1;

    cout << "Podaj miesiac pierwszej daty (numerem): ";
    cin>>m1;

    cout << "Podaj dzien pierwszej daty (numerem): ";
    cin>>d1;

    cout<<"\n";
    cout << "Podaj rok drugiej daty: ";
    cin>>r2;

    cout << "Podaj miesiac drugiej daty (numerem): ";
    cin>>m2;

    cout << "Podaj dzien pierwszej daty (numerem): ";
    cin>>d2;

    cout<<"\n\n";

    if (r1>=r2 || r1<=r2)
    {
              if (r1==r2 && m1==m2 && d1==d2)
              {
                  cout<<"Podane daty sa takie same";
              }
              if (r1>r2)
              {
                  cout<<"Pierwsza data("<<d1<<"."<<m1<<"."<<r1<<" r.) jest mlodsza od drugiej daty ("<<d2<<"."<<m2<<"."<<r2<<" r.).";
              }
              if (r1==r2 && m1>m2)
              {
                  cout<<"Pierwsza data("<<d1<<"."<<m1<<"."<<r1<<" r.) jest mlodsza od drugiej daty ("<<d2<<"."<<m2<<"."<<r2<<" r.).";
              }
              if (r1==r2 && m1==m2 &&d1>d2)
              {
                  cout<<"Pierwsza data("<<d1<<"."<<m1<<"."<<r1<<" r.) jest mlodsza od drugiej daty ("<<d2<<"."<<m2<<"."<<r2<<" r.).";
              }
    }

    if (r1<r2 || r1==r2 && m1<m2 || r1==r2 && m1==m2 && d1<d2)
    {
        cout<<"Druga data("<<d2<<"."<<m2<<"."<<r2<<" r.) jest mlodsza od pierwszej daty ("<<d1<<"."<<m1<<"."<<r1<<" r.).";
    }

    cout<<"\n\n";
    return 0;
}

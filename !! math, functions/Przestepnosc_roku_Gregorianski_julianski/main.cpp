#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int rok;
bool julianski, gregorianski;
string czy_przestepny_greg, czy_przestepny_jul;

bool f_julianski (int rok, bool julianski)
{
    if (rok%4==0)
    {
        julianski=true;
    }
    if (rok%4!=0)
    {
        julianski=false;
    }
    return julianski;
}

bool f_gregorianski (int rok, bool gregorianski)
{
    if (rok%4==0)
    {
        gregorianski=true;
    }
    if (rok%100==0 && rok%400!=0)
    {
        gregorianski=false;
    }
    if (rok%4!=0)
    {
        gregorianski=false;
    }
    return gregorianski;
}

int main()
{
    cout<<"Podaj rok, a program odpowie Ci, czy jest on przestepny w kalendarzu gregorianskim i julianskim"<<endl;
    cout<<"Rok: ";
    cin>>rok;

    if (f_julianski(rok, julianski)==true)
    {
        czy_przestepny_jul="PRZESTEPNY";
    }
    if (f_julianski(rok, julianski)==false)
    {
        czy_przestepny_jul="NIEPRZESTEPNY";
    }

    if (f_gregorianski(rok, gregorianski)==true)
    {
        czy_przestepny_greg="PRZESTEPNY";
    }
    if (f_gregorianski(rok, gregorianski)==false)
    {
        czy_przestepny_greg="NIEPRZESTEPNY";
    }

    cout<<"\n\n";
    cout<<"Rok "<<rok<<" w kalendarzu JULIANSKIM jest "<<czy_przestepny_jul<<"\n";
    cout<<"\n";

    cout<<"Rok "<<rok<<" w kalendarzu GREGORIANSKIM jest "<<czy_przestepny_greg<<"\n";

    cout<<"\n\n";

    //cout<<"Nacisnij ENTER, aby kontynuowac...\n\n";
    //getchar();
    return 0;
}

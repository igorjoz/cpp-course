#include <iostream>

using namespace std;
int wiek;

int main()
{
    cout << "Witaj w programie, ktory, po wprowadzeniu danych, powie Ci, czy jestes pelnoletni i czy mozesz zostac POSLEM, SENATOREM lub PREZYDENTEM\n";
    cout<<"\nPodaj swoj swoj wiek: ";
    cin>>wiek;

    cout<<"\n";

    {
    if (wiek<18) cout<<"\n\nNie jestes pelnoletni. Nie mozesz zostac ani POSLEM, ani SENATOREM, ani PREZYDENTEM";

    else
    if (wiek<21) cout<<"\n\nJestes pelnoletni, ale nie mozesz zostac ani POSLEM, ani SENATOREM, ani PREZYDENTEM";

    else
    if (wiek<30) cout<<"\n\nJestes pelnoletni i mozesz zostac POSLEM, ale nie mozesz zostac ani SENATOREM, ani PREZYDENTEM";

    else
    if (wiek<35) cout<<"\n\nJestes pelnoletni i mozesz zostac POSLEM i SENATOREM, ale nie mozesz zostac PREZYDENTEM";

    else
    if (wiek>=35) cout<<"\n\nJestes pelnoletni i mozesz zostac POSLEM, SENATOREM i PREZYDENTEM";
    }

    cout<<"\n\n";

    return 0;
}

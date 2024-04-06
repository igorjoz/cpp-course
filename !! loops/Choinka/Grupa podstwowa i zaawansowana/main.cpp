#include <iostream>

using namespace std;

int punkty;

int main()
{
    cout << "Podaj liczbe uzyskanych punktow: ";
    cin>>punkty;

    {
    if (punkty<=30) cout<<"Zaliczasz sie do grupy podstwowej";
    if (punkty>30) cout<<"Zaliczasz sie do grupy zaawansowanej";
    }
    cout<<"\n";

    return 0;
}

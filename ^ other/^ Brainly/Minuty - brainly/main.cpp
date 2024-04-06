#include <iostream>

using namespace std;

int main()
{
    int minuty, kopia_minuty;
    int godziny=0;

    cout<<"Podaj minuty: ";
    cin>>minuty;
    kopia_minuty = minuty;

    while (minuty>60)
    {
        minuty-=60;
        godziny++;
    }

    cout<<endl<<kopia_minuty<<" minutes = "<<godziny<<" h "<<minuty<<" minutes";

    return 0;
}

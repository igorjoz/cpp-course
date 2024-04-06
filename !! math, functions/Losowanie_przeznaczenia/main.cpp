#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stddef.h>

using namespace std;

int const n=22;
string zawody[n];
int wylosowana;

int main()
{
    cout<<"Program przewidujacy twoja przyszlosc!";

    zawody[n]={"piekarzem", "pilkarzem", "chlebem", "naukowcem", "informatykiem", "ekonomista", "nikim", "szamanem", "prezesem","koniem", "woznym", "artysta", "adwokatem", "architektem", "politykiem", "sekretarzem", "prezydentem", "sedzia", "fizykiem", "cukiernikiem", "dyrektorem finansow", "energetykiem"};

    /*
    zawody[0]="piekarzem";
    zawody[1]="pilkarzem";
    zawody[2]="chlebem";
    zawody[3]="naukowcem";
    zawody[4]="informatykiem";
    zawody[5]="ekonomista";
    zawody[6]="nikim";
    zawody[7]="szamanem";
    zawody[8]="prezesem";
    zawody[9]="koniem";
    zawody[10]="woznym";
    zawody[11]="artysta";
    zawody[12]="adwokatem";
    zawody[13]="architektem";
    zawody[14]="politykiem";
    zawody[15]="sekretarzem";
    zawody[16]="prezydentem";
    zawody[17]="sedzia";
    zawody[18]="fizykiem";
    zawody[19]="cukiernikiem";
    zawody[20]="dyrektorem finansow";
    zawody[21]="energetykiem";
    */

    srand((unsigned)time(NULL));

    wylosowana=rand()%n;

    cout<<endl<<endl<<"W przyszlosci zostaniesz: ";
    cout<<zawody[wylosowana]<<".";

    cout<<"\n\n";
    return 0;
}

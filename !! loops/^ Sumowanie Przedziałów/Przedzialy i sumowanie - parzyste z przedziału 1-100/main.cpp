/* Przedzialy i sumowanie v3 */

#include <iostream>

using namespace std;

int i, suma;

int main()

{
    cout<<"Sumowanie liczb parzystych z przedzialu 100-200\n\n";
        for(i=100;i<=200; i++)
        {
            if(i%2==0) suma=suma+i;
        }

        cout<<"Suma liczb z przedzialu od 100 do 200 wynosi: " << suma<<"\n\n";

    return 0;
}

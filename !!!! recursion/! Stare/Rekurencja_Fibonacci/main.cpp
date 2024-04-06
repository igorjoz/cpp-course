#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

int liczba;

clock_t start1, stop1, start2, stop2;
float czas1, czas2;

long int fib(int liczba)
{
    if (liczba==1 || liczba==2) return 1;
    else return fib(liczba-1)+fib(liczba-2);
}

long int fib_petla(int liczba);

int main()
{
    cout<<"Ktora liczbe ciagu Fibonnaciego chcesz poznac: ";
    cin>>liczba;

    start1=clock();

    cout<<endl<<endl<<"Ciag fibonacciego - REKURENCJA: ";
    cout<<fib(liczba);

    stop1=clock();
    czas1=(double) (stop1-start1) / CLOCKS_PER_SEC;
    cout<<endl<<"Czas (1) wykonania: "<<czas1;



    start2=clock();

    cout<<endl<<endl<<"Ciag fibonacciego - PETLA: ";
    cout<<fib_petla(liczba);

    stop2=clock();
    czas2=(double) (stop2-start2) / CLOCKS_PER_SEC;
    cout<<endl<<"Czas (2) wykonania: "<<czas2;

    cout<<endl<<endl;
    return 0;
}

long int fib_petla(int liczba)
{
    int fib[liczba];
    fib[0]=1;
    fib[1]=1;

    for (int i=2; i<liczba; i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }

    return fib[liczba-1];
}

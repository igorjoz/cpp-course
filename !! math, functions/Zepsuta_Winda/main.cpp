#include <iostream>

using namespace std;

int main()
{
    int klienci, max_pietra;
    int current=0, gdzie_isc, total=0;

    cin>>klienci>>max_pietra;

    for (int i=0; i<klienci; i++)
    {
        cin>>gdzie_isc;
        if (current-gdzie_isc < 0)
        {
            total+=current-gdzie_isc;
        }

        current=gdzie_isc;
    }
    total=-total;
    cout<<total;

    return 0;
}

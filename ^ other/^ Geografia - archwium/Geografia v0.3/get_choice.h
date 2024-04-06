#ifndef __Get_Choice__H__
#define __Get_Choice__H__

#include <iostream>

using namespace std;

class GetChoice
{
private:
    bool error;  // potwierdzenie wystapienia bledu z powodu uzytkownika --> decyzja, czy zapytac uzytkownika o zamkniecie programu

public:
    int choice;  // Drugi wybor, czyli dokladne okreslenie sytuacji uzytkownika

    void wybor_walidacja(int kiedy_wyjscie, string file_name);

    void reset_counting(int time);
};

#endif

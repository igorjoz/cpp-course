#pragma once
class Temp {
public:
	static const inline std::string txt{ "TRE�� STA�A" };
};
inline Temp global_object;

/*
 Je�eli ten plik b�dzie do��czony w wielu plikach .cpp, i nie b�dzie zawiera� s�owa -inline-
 w�wczas etap linkowania zako�czy�by si� niepowodzeniem.
 
 O co chodzi?

 Normalnie program mo�e mie� wiele plik�w .cpp, kt�re zazwyczaj kompilowane s� pojedy�czo 
 do obiekt�w (pliki .o). Potem wszystkie pliki modu��w/obiekt�w s� linkowane w celu wygenerowania
 jednego pliku wykonywalnego lub biblioteki statycznej lub wsp�dzielonej.
 Gdy jest to linkowanie i definicja jakiego� symbolu powt�rzy si�, pojawia si� b��d.
 (Np. gdy jest funkcja int f(); i co najmniej dwa obiekty/mody�y definiuj� tak� sam� funkcj�.)
 B��d wynika z tego, i� nie wiadomo, kt�ra jest prawid�owa. Z�amana jest regu�a ODR (regu�a pojedy�czej definicji).

Od C++17 z pomoc� przychodzi s�owo kluczowe inline.
Je�eli linker znajdzie wiele symboli o takiej samej sygnaturze, ale zadeklarowanych jako osadzone (inline), w�wczas wybierze pierwszy a pozosta�e nie zmieni� definicji. Programista musi jednak zadba�, by ta niezmienno�� definicji by�a faktycznie porz�dana !



*/


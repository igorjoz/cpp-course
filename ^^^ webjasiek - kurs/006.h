#pragma once
class Temp {
public:
	static const inline std::string txt{ "TREŒÆ STA£A" };
};
inline Temp global_object;

/*
 Je¿eli ten plik bêdzie do³¹czony w wielu plikach .cpp, i nie bêdzie zawiera³ s³owa -inline-
 wówczas etap linkowania zakoñczy³by siê niepowodzeniem.
 
 O co chodzi?

 Normalnie program mo¿e mieæ wiele plików .cpp, które zazwyczaj kompilowane s¹ pojedyñczo 
 do obiektów (pliki .o). Potem wszystkie pliki modu³ów/obiektów s¹ linkowane w celu wygenerowania
 jednego pliku wykonywalnego lub biblioteki statycznej lub wspó³dzielonej.
 Gdy jest to linkowanie i definicja jakiegoœ symbolu powtórzy siê, pojawia siê b³¹d.
 (Np. gdy jest funkcja int f(); i co najmniej dwa obiekty/mody³y definiuj¹ tak¹ sam¹ funkcjê.)
 B³¹d wynika z tego, i¿ nie wiadomo, która jest prawid³owa. Z³amana jest regu³a ODR (regu³a pojedyñczej definicji).

Od C++17 z pomoc¹ przychodzi s³owo kluczowe inline.
Je¿eli linker znajdzie wiele symboli o takiej samej sygnaturze, ale zadeklarowanych jako osadzone (inline), wówczas wybierze pierwszy a pozosta³e nie zmieni¹ definicji. Programista musi jednak zadbaæ, by ta niezmiennoœæ definicji by³a faktycznie porz¹dana !



*/


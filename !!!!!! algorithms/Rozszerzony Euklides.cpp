#include <iostream>
#include <cmath>

int main() {
    int a, b;

    //Pobranie danych
    std::cout << "Podaj a ";
    std::cin >> a;
    std::cout << "\nPodaj b ";
    std::cin >> b;
    if ((a < 0) || (b < 0)) {
        std::cout << "Wartosci a i b powinny byc wieksze od zera\n";
        exit(1);
    }

    //zachowanie pierwotnych wartosci
    int a0 = a, b0 = b;

    //Zapewnia spelnienie niezmiennika p*a0 + q*b0 = a oraz r*a0 + s*b0 = b
    int p = 1, q = 0, r = 0, s = 1;
    int c, quot, new_r, new_s;

    //algorytm
    while (b != 0) {
        c = a % b;
        quot = lrint(floor(a / b));
        a = b;
        b = c;
        new_r = p - quot * r;
        new_s = q - quot * s;
        p = r; q = s;
        r = new_r; s = new_s;
    }
    std::cout << "NWD(a,b) = a * p + b * q\n"
        << "NWD(" << a0 << "," << b0 << ") = "
        << a0 << " * " << p << " + "
        << b0 << " * " << q << '\n';
}
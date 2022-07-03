#include <iostream>
#include <math.h>

class Figura
{
public:
    virtual double oblicz_pole() = 0;
};

class Trojkat : public Figura
{
    double a, h;
public:
    Trojkat(double a, double h)
    {
        this->a = a;
        this->h = h;
    }

    double oblicz_pole()
    {
        return (a * h) / 2;
    };
};

class Kwadrat : public Figura
{
protected:
    double a;
public:
    Kwadrat(double a) : a(a){};
    double oblicz_pole()
    { 
        return pow(a, 2); 
    };
};

class Kolo : public Figura
{
    double r;
public:
    Kolo(double r) : r(r) {};
    double oblicz_pole()
    {
        return 3.14 * pow(r, 2);
    };
};

double sumuj_pola(Figura* figury[], int size)
{
    double suma = 0;
    for (int i = 0; i < size; ++i)
    {
        suma += figury[i]->oblicz_pole();
    }

    return suma;
}

int main()
{
    Trojkat t1(3, 4);
    Kwadrat kw1(2);
    Kolo k1(1);

    Figura* figury[3];
    figury[0] = &t1;
    figury[1] = &kw1;
    figury[2] = &k1;

    std::cout << "Funkcja sumujaca: " << sumuj_pola(figury, 3) << "\n";

    return 0;
}
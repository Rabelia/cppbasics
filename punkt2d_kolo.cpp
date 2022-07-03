#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

class punkt2d
{
    public:
        int x, y;

        // Konstruktor Domyslny
        punkt2d()
        {
            this->x = 0;
            this->y = 0;
            cout<<"Konstruktor Domyslny punkt2d : Tworzy punkt o wspolrzednych (0,0)"<<endl;
        }

        // Konstruktor Parametrowy
        punkt2d(int x, int y)
        {
            this->x = x;
            this->y = y;
            cout<<"Konstruktor Parametrowy punkt2d : Tworzy punkt o wspolrzednych ("<<x<<","<<y<<")"<<endl;
        }

        //Konstruktor Kopiujacy
        punkt2d(const punkt2d & punkt2dkopia)
        {
            x = punkt2dkopia.x;
            y = punkt2dkopia.y;
            cout<<"Konstruktor Kopiujacy punkt2d : Kopiuje punkt " << x << " " << y << endl;
        }

        //Destruktor
        ~punkt2d()
        {
            cout<<"Destruktor punkt2d : Usuwa punkt"<<endl;
        }
};

class kolo
{
private:
    punkt2d srodek;
    int r;
public:
    // konstruktor domyœlny
    kolo()
    {
        cout << "Konstruktor Domyslny Kolo"<<endl;
        this->r = 1;
    }
    //konstruktor parametrowy 3 arg
    kolo(int x, int y, int r)
    {
        cout << "Konsruktor Parametrowy 3 arg (x, y, r) kolo"<<endl;
        this->srodek.x = x; 
		this->srodek.y = y;
        this->r = r;
    }
    //konrtruktor parametrowy punkt 2D + promieñ
    kolo(punkt2d _srodek, int r) : srodek(_srodek)
    {
        cout << "Konsruktor Parametrowy 2 arg(punkt2d, r) kolo"<<endl;
        this->r = r;
    }
    //konstruktor kopiujacy
    kolo(kolo& kolo1)
    {
        cout << "Konstruktor Kopiujacy kolo"<<endl;
        srodek = kolo1.srodek;
        r = kolo1.r;
    }
    //destruktor
    ~kolo()
    {
        cout<<"Usuwa kolo"<<endl;
    }

    double pole(kolo kolo)
    {
        double pk= M_PI*r*r;
        return pk;
    }

    double obwod(kolo kolo)
    {
        double ok= 2*M_PI*r;
        return ok;
    }
};

int main()
{
    cout << "Tworze punkt p3" << endl;
    punkt2d p3(2, 3);
    cout << "Tworze kolo koloC" << endl;
    kolo koloc(p3, 2);

    return 0;
}

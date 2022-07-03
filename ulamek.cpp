#include <iostream>
#include <string>

class Produkt
{
    std::string producent;
    std::string nazwa;
    int* cena;
public:
    Produkt(std::string producent, std::string nazwa, int cena)
    {
        this->producent = producent;
        this->nazwa = nazwa;
        this->cena = new int(cena);
    }

    Produkt(const Produkt& Product_1)
    {
        producent = Product_1.producent;
        nazwa = Product_1.nazwa;
        cena = new int(*Product_1.cena);
    }

    void ustaw_cene(int nowa_cena)
    {
        if (nowa_cena >= 0)
        {
            *cena = nowa_cena;
        }
    }

    int zwroc_cene()
    {
        return *cena;
    }

    Produkt& operator=(const Produkt& x);

    ~Produkt()
    {
        delete cena;
    };

    Produkt& operator=(const Produkt& x)
    {
        if (&x != this)
        {
            producent = x.producent;
            nazwa = x.nazwa;
            delete cena;
            cena = new int(*x.cena);
        }
        return *this;
    }
};

int main()
{
    {
        Produkt myszka_rvm("Razer", "Viper Mini", 199);
        Produkt myszka_rvm_przecena(myszka_rvm);
        myszka_rvm_przecena.ustaw_cene(159);
        std::cout << "Cena Razer Viper Mini bez przeceny: " << myszka_rvm.zwroc_cene() << "\n";
        std::cout << "Cena Razer Viper Mini po przecenie: " << myszka_rvm_przecena.zwroc_cene() << "\n";
    }

    {
        Produkt myszka_lg100("Logitech", "G100", 1119);
        Produkt myszka_lg100s("Logitech", "G100s", 99);
        myszka_lg100 = myszka_lg100s;
        std::cout << "Cena Logotech G100: " << myszka_lg100.zwroc_cene() << "\n";
    }
}
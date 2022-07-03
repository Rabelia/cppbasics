#include <iostream>
#include <string>





class Pracownik

{

protected:

	std::string nazwisko;

	int godziny;

	int stawka; 

public:



	Pracownik(std::string na = "NAZWISKO ", int ig = 0, int sg = 0) : nazwisko(na), godziny(ig), stawka(sg)

	{

		std::cout << "Kontruktor Pracownik \n";

	};



	void wypisz()

	{

		std::cout << "nazwisko= " << nazwisko << "\n";

		std::cout << "godziny= " << godziny << "\n";

		std::cout << "stawka= " << stawka << "\n";

	};



	~Pracownik()

	{

		std::cout << "Destruktor Pracownik\n";

	};

};



class Stazysta : public Pracownik

{

private:

	int dl_stazu;



public:



	Stazysta(std::string na = "NAZWISKO ", int ig = 0, int sg = 15, int ds = 0) : Pracownik(na, ig, sg), dl_stazu(ds)

	{	

		if (sg >= 15) stawka = 15;

		std::cout << "Konstruktor Stazysta \n";

	};



	void wypisz_dls()

	{

		std::cout << "Dlugosc stazu to: " << dl_stazu << "\n";

	};



	void wypisz()

	{

		Pracownik::wypisz();

		wypisz_dls();

	};



	~Stazysta()

	{

		std::cout << "Destruktor Stazysta\n";

	};

};



int main()

{

	{

		std::cout << "Pracownik:\n";

		Pracownik x("Kowalski", 60, 18);

		x.wypisz();

	}



	std::cout << "\n";



	{

		std::cout << "Stazysta:\n";

		Stazysta y("Anna", 12, 16, 6);

		y.wypisz();

	}



	return 0;

}





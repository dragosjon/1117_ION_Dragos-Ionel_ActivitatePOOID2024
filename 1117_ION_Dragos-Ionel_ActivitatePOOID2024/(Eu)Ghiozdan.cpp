//
//1.Să se creeze un proiect în Microsoft Visual Studio care să nu genereze erori de compilare(1 p).
//
//2. Să se definească clasa Ghiozdan care are câmpurile :
//
//idGhiozdan– întreg constant – nu se va putea modifica;
//nrBuzunare – întreg – numărul de buzunare din ghiozdan;
//latimeBuzunare – vector alocat dinamic reprezentând latimile buzunarelor din ghiozdan(int* / float*).
//un atribut la alegere.Explicați prin comentariu utilitatea atributului adăugat.Acesta trebuie să aibă legătura cu clasa ghiozdan.
//Atributele clasei se definesc în zona privată a clasei(1 punct).
//
//3. Să se definească pentru clasa Ghiozdan constructor fără parametri, constructor cu parametri și destructor.Constructorul cu parametri conține validări pentru parametrii primiți.(2 puncte)
//
//4. Să se definească pentru clasa Ghiozdan constructorul de copiere și metode accesor(get si set) pentru doua atribute la alegere.Testați în funcția main(). (1 punct)
//
//5. Să se supraîncarce pentru clasa Ghiozdan operatorul = (de atribuire) fără a genera memory leaks și să nu permită auto - atribuirea.Testați în funcția main(). (1 punct)
//
//6. Să se supraîncarce operatorul << pentru afișarea obiectelor de tipul Ghiozdan.Elementele sunt afișate pe aceeași linie despărțite prin punct și virgula și spațiu(; ).Testați în funcția main(). (1 punct)
//
//7. Să se definească metoda getLatimeMaxima() care determină și returnează lățimea maximă din vector.Testați în funcția main(). (1 punct)
//
//8. Să se supraîncarce operator> care compară două ghiozdane după numărul de buzunare.Testați în main() (1 punct)
//
//9. Să se supraîncarce operator+= care va aduna numărul de buzunare ale celor două ghiozdane, în primul(aveți grija la vector).Testați în funcția main() (1 punct)

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Ghiozdan {
private:
	const int idGhiozdan;
	int nrBuzunare;
	float* latimeBuzunare;
	bool areToarta;
public:
	
	Ghiozdan() : idGhiozdan() {
		this->nrBuzunare = 0;
		this->latimeBuzunare = nullptr;
		this->areToarta = false;
	}

	Ghiozdan(int nrBuzunare, float* latimeBuzunare, bool areToarta) : idGhiozdan() {
		this->nrBuzunare = nrBuzunare;
		this->latimeBuzunare = new float[nrBuzunare];
		for (int i = 0; i < nrBuzunare; i++) {
			this->latimeBuzunare[i] = latimeBuzunare[i];
		}
		this->areToarta = areToarta;
	}

	Ghiozdan(const Ghiozdan& g) : idGhiozdan() {
		this->nrBuzunare = g.nrBuzunare;
		this->latimeBuzunare = new float[g.nrBuzunare];
		for (int i = 0; i < g.nrBuzunare; i++) {
			this->latimeBuzunare[i] = g.latimeBuzunare[i];
		}
		this->areToarta = g.areToarta;
	}

	int getNrBuzunare() {
		return this->nrBuzunare;
	}

	void setNrBuzunare(int nrBuzunare) {
		this->nrBuzunare = nrBuzunare;
	}

	bool getAreToarta() {
		return this->areToarta;
	}

	void setAreToarta(bool areToarta) {
		this->areToarta = areToarta;
	}

	Ghiozdan operator=(const Ghiozdan& g) {
		if(this != &g)
		{
			this->nrBuzunare = g.nrBuzunare;
			if (latimeBuzunare != nullptr) {
				delete[]latimeBuzunare;
			}
			this->latimeBuzunare = new float[g.nrBuzunare];
			for (int i = 0; i < g.nrBuzunare; i++) {
				this->latimeBuzunare[i] = g.latimeBuzunare[i];
			}
			this->areToarta = g.areToarta;
		}
		return *this;
	}

	//Să se definească metoda getLatimeMaxima() care determină și returnează lățimea maximă din vector.Testați în funcția main(). (1 punct)
	float getLatimeMaxima() {
		float latimeMaxima = 0;
		for (int i = 0; i < nrBuzunare; i++) {
			if (latimeBuzunare[i] > latimeMaxima)
			{
				latimeMaxima = latimeBuzunare[i];
			}
		}
		return latimeMaxima;
	}

	//8. Să se supraîncarce operator> care compară două ghiozdane după numărul de buzunare.Testați în main() (1 punct)
	int operator>(const Ghiozdan& g) {
		return nrBuzunare > g.nrBuzunare;
	}

	//sa se supraincarce operator de indexare[]
	float& operator[](int index) {
		if (index >= 0 && index < nrBuzunare) {
			return latimeBuzunare[index];
		}
		else {
			throw "Invalid Index";
		}
	}

	void afisare() {
		cout << "Id: " << this->idGhiozdan << "/ ";
		cout << "NrBuzunare: " << this->nrBuzunare << "/ ";
		cout << "LatimeBuzunare: ";
		for (int i = 0; i < nrBuzunare; i++) {
			cout << "; " << this->latimeBuzunare[i];
		}
		cout <<"/ " << "AreToarta:"  << this->areToarta << endl;
	}

	~Ghiozdan() {
		if (latimeBuzunare != nullptr) {
			delete[]latimeBuzunare;
		}
	}

};

int main() {
	Ghiozdan g1;
	g1.afisare();

	Ghiozdan g2(2, new float [2] {10, 20}, true);
	g2.afisare();

	Ghiozdan g3(3, new float [4] {20, 60, 40}, false);
	g3.afisare();

	Ghiozdan g4 = g2;
	g4.afisare();
	
	Ghiozdan g5;
	g5 = g1;
	g5.afisare();

	cout << endl; 
	cout << g3.getLatimeMaxima();


	//operator>
	if (g3 > g2) {
		cout << "g3 mai mare";
	}
	else {
		cout << "g2 mai mare";
	}
	cout << endl;

	//operator[]
	cout << g3[0] << endl;
	g3[0] = 90;
	cout << g3[0] << endl;


}
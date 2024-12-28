/* 1.Sa se def clasa Corabie care are campurile :
-nrCorabii - intreg static - contorizeaza automat numarul corabiilor create
- capacitate - intreg numar de persoane imbarcate
- nrPersoaneImbarcate - intreg - numarul de persoane aflate la bord.Nu poate fi mai maire decat capacitatea corabiei
- varstaPasageri - vector alocat dinamic reprezentand varstele pasagerilor de pe corabie(int*)
- un atribut la alegere ce are legatura cu corabia
Atributele se definesc in zona privata.
3.Pt clasa Corabie def constructorul fara parametri, constructor cu parametri si destructor(cu validari)
4.Constructor copiere si metode accesor(get si set) pentru doua atribute la alegere testate in main
5.Sa se supraincarce operatorul = fara a genera memory leak si sa nu permita auto - atribuirea
6.Sa se supra incarce operatorul << pentru obiectele aflate in tipul corabie.Elementele sunt afisate pe aceeasi linie despartite prin cratima si spatiu.testai in main
7.sa se def metoda calculareVarstaMedie() care calculeaza si returneaza media varstelor pasagerilor.Testati in main
8. sa se supraincarce  operatorul() functie care determina numarul de persoane care mai pot fi imbarcate pana la atingerea capacitatii maxime a corabiei.Testati in main
9.Sa se supra incarce operatorul[] care va indexa vectorul de varste ale pasagerilor.Implementare permite si modificarea acestei varste.Testati in main.*/


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

class Corabie {
private:
	static int nrCorabii;
	int capacitate;
	int nrPersoaneImbarcate;
	int* varstaPasageri;
	char* numeCorabie;
	bool areMotor;

public:
	Corabie() {
		this->nrCorabii = 0;
		this->capacitate = 0;
		this->nrPersoaneImbarcate = 0;
		this->varstaPasageri = nullptr;
		this->numeCorabie = new char[strlen("Necunoscut") + 1];
		strcpy(this->numeCorabie, "Necunoscut");
		this->areMotor = false;
	}

	Corabie(int capacitate, int nrPersoaneImbarcate, int* varstaPasageri,const char* numeCorabie, bool areMotor) {
		this->nrCorabii++;
		this->capacitate = capacitate;
		this->nrPersoaneImbarcate = nrPersoaneImbarcate;
		this->varstaPasageri = new int[nrPersoaneImbarcate];
		for (int i = 0; i < nrPersoaneImbarcate; i++) {
			this->varstaPasageri[i] = varstaPasageri[i];
		}
		this->numeCorabie = new char[strlen(numeCorabie) + 1];
		strcpy(this->numeCorabie, numeCorabie);
		this->areMotor = areMotor;
	}

	Corabie(const Corabie& c) {
		this->capacitate = c.capacitate;
		this->nrPersoaneImbarcate = c.nrPersoaneImbarcate;
		this->varstaPasageri = new int[c.nrPersoaneImbarcate];
		for (int i = 0; i < c.nrPersoaneImbarcate; i++) {
			this->varstaPasageri[i] = c.varstaPasageri[i];
		}
		this->numeCorabie = new char[strlen(c.numeCorabie) + 1];
		strcpy(this->numeCorabie, c.numeCorabie);
		this->areMotor = c.areMotor;
	}

	int getCapacitate() {
		return this->capacitate;
	}

	void setCapacitate(int capacitate) {
		this->capacitate = capacitate;
	}

	int getNrPersoaneImbarcate() {
		return this->nrPersoaneImbarcate;
	}

	void setNrPersoaneImbarcate(int nrPersoaneImbarcate) {
		this->nrPersoaneImbarcate = nrPersoaneImbarcate;
	}

	Corabie operator=(const Corabie& c) {
		if(this != &c)
		{
			this->capacitate = c.capacitate;
			this->nrPersoaneImbarcate = c.nrPersoaneImbarcate;
			if (this->varstaPasageri != nullptr) {
				delete[]this->varstaPasageri;
			}
			this->varstaPasageri = new int[c.nrPersoaneImbarcate];
			for (int i = 0; i < c.nrPersoaneImbarcate; i++) {
				this->varstaPasageri[i] = c.varstaPasageri[i];
			}
			if (this->numeCorabie != nullptr) {
				delete[]this->numeCorabie;
			}
			this->numeCorabie = new char[strlen(c.numeCorabie) + 1];
			strcpy(this->numeCorabie, c.numeCorabie);
			this->areMotor = c.areMotor;
		}
		return *this;
	}

	//sa se def metoda calculareVarstaMedie() care calculeaza si returneaza media varstelor pasagerilor
	int calculareVarstaMedie() {
		int varstaMedie = 0;
		for (int i = 0; i < nrPersoaneImbarcate; i++) {
			varstaMedie += varstaPasageri[i] / nrPersoaneImbarcate;
		}
		return varstaMedie;
	}

	//operator unar postfixat++
	Corabie operator++(int) {
		Corabie copie = *this;
		this->capacitate++;
		return copie;
	}

	//operator unar prefixat++
	Corabie operator++() {
		this->capacitate++;
		return *this;
	}
	

	////SITUATIA 1
	//operatorul functie() -- este asemanator metodei --  functie care determina numarul de persoane care mai pot fi imbarcate pana la atingerea capacitatii maxime
	/*int operator()() {
		return capacitate - nrPersoaneImbarcate;
	}*/
	//SITUATIA 2
	//operator functie() -- varsta totala a pasagerilor
	int operator()() {
		int suma = 0;
		for (int i = 0; i < nrPersoaneImbarcate; i++) {
			suma += varstaPasageri[i];
		}
		return suma;
	}

	//operator de cast sau de conversie la int (la fel si pentru float) -- returneaza capacitatea corabiei
	operator int() {
		return this->capacitate;
	}

	//operator de indexare[]
	int& operator[](int index) {
		if (index >= 0 && index < nrPersoaneImbarcate) {
			return this->varstaPasageri[index];
		}
		else {
			throw "Index Invalid";
		}
	}

	//operator de comparatie >
	bool operator>(const Corabie& c) {
		return this->capacitate > c.capacitate;
	}

	//operator de egalitate==
	bool operator==(const Corabie& c) {
		return this->capacitate == c.capacitate;
	}

	//operator !
	bool operator!=(const Corabie& c) {
		return this->areMotor != c.areMotor;
	}


	void afisare() {
		cout << "NrCorabii: " << this->nrCorabii << "; ";
		cout << "Capacitate: " << this->capacitate << "; ";
		cout << "NrPersoaneImbarcate: ";
		if (nrPersoaneImbarcate > capacitate) {
			cout << "Capacitatea depasita ";
		}
		else {
			cout << this->nrPersoaneImbarcate;
		}
		cout << "VarstePasageri: ";
		for (int i = 0; i < nrPersoaneImbarcate; i++) {
			cout << varstaPasageri[i] << ";";
		}
		cout << "NumeCorabie: " << this->numeCorabie << endl;
		cout << "AreMotor: " << this->areMotor << endl;
 	}

	~Corabie() {
		if (this->varstaPasageri != nullptr) {
			delete[]this->varstaPasageri;
		}
		if (this->numeCorabie != nullptr) {
			delete[]this->numeCorabie;
		}
	}
	
};

int Corabie::nrCorabii = 0;

int main() {
	Corabie c1;
	c1.afisare();

	Corabie c2(3, 3, new int[3] {24, 26, 30}, "BlackBetty", true);
	c2.afisare();

	Corabie c3(4, 4, new int[4] {50, 60, 40, 20}, "Swan", true);
	c3.afisare();

	Corabie c4 = c3;
	c4.afisare();

	Corabie c5;
	c5 = c2;
	c5.afisare();

	//metoda calculareVarstaMedie()
	cout << c2.calculareVarstaMedie() << endl;

	//operator de indexare []
	try {
		cout << c3[1] << endl;
		c3[1] = 55;
		cout << c3[1] << endl;
	}
	catch (const char* mesaj) {
		cout << mesaj << endl;
	}

	//operator >
	if (c3 > c2) {
		cout << "C3 mai mare" << endl;
	}
	else {
		cout << "C2 mai mare" << endl;
	}

	//operator ==
	if (c4 == c3) {
		cout << "Capacitati egale" << endl;
	}
	else {
		cout << "Invalid" << endl;
	}

	//operator ()
	cout << c2() << endl;

	//operator ()
	cout << c3() << endl;

	//operator de cast(explicit)
	int capacitate = int(c2);
	cout << capacitate << endl;

	//operator de cast(implicit)
	int capacitate2 = c2;
	cout << capacitate2 << endl;

	//operator unar postfixat++
	c2++;
	c2.afisare();

	//operator unar prefixat++
	++c2;
	c2.afisare();

	//operator !=
	if (c2 != c3) {
		cout << "Diferite" << endl;
	}
	else {
		cout << "Acelasi" << endl;
	}


}
/*1.Sa se def clasa Corabie care are campurile:
-nrCorabii - intreg static - contorizeaza automat numarul corabiilor create
-capacitate - intreg numar de persoane imbarcate
-nrPersoaneImbarcate - intreg - numarul de persoane aflate la bord . Nu poate fi mai maire decat capacitatea corabiei
-varstaPasageri-vector alocat dinamic reprezentand varstele pasagerilor de pe corabie(int*)
-un atribut la alegere ce are legatura cu corabia
Atributele se definesc in zona privata.
3.Pt clasa Corabie def constructorul fara parametri, constructor cu parametri si destructor(cu validari)
4.Constructor copiere si metode accesor(get si set) pentru doua atribute la alegere testate in main
5.Sa se supraincarce operatorul= fara a genera memory leak si sa nu permita auto-atribuirea
6.Sa se supra incarce operatorul<< pentru obiectele aflate in tipul corabie. Elementele sunt afisate pe aceeasi linie despartite prin cratima si spatiu. testai in main
7.sa se def metoda calculareVarstaMedie() care calculeaza si returneaza media varstelor pasagerilor. Testati in main
8. sa se supraincarce  operatorul () functie care determina numarul de persoane care mai pot fi imbarcate pana la atingerea capacitatii maxime a corabiei. Testati in main
9.Sa se supra incarce operatorul [] care va indexa vectorul de varste ale pasagerilor. Implementare permite si modificarea acestei varste. Testati in main.*/

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
	string numeCorabie;
public:

	Corabie() {
		this->nrCorabii = 0;
		this->capacitate = 0;
		this->nrPersoaneImbarcate = 0;
		this->varstaPasageri = nullptr;
		this->numeCorabie = "NoName";
	}

	Corabie(int capacitate, int nrPersoaneImbarcate, int* varstaPasageri, string numeCorabie){
		this->nrCorabii++;
		this->capacitate = capacitate;
		this->nrPersoaneImbarcate = nrPersoaneImbarcate;
		this->varstaPasageri = new int[nrPersoaneImbarcate];
		for (int i = 0; i < nrPersoaneImbarcate; i++) {
			this->varstaPasageri[i] = varstaPasageri[i];
		}
		this->numeCorabie = numeCorabie;
	}

	Corabie(const Corabie& c) {
		this->nrCorabii++;
		this->capacitate = c.capacitate;
		this->nrPersoaneImbarcate = c.nrPersoaneImbarcate;
		this->varstaPasageri = new int[c.nrPersoaneImbarcate];
		for (int i = 0; i < c.nrPersoaneImbarcate; i++) {
			this->varstaPasageri[i] = c.varstaPasageri[i];
		}
		this->numeCorabie = c.numeCorabie;
	}

	int getCapacitate() {
		return this->capacitate;
	}

	void setCapacitate(int capacitate) {
		this->capacitate = capacitate;
	}

	string getNumeCorabie() {
		return this->numeCorabie;
	}

	void setNumeCorabie(string numeCorabie) {
		this->numeCorabie = numeCorabie;
	}

	Corabie operator=(const Corabie& c) {
		if (this != &c)
		{
			
			this->nrCorabii = c.nrCorabii;
			this->capacitate = c.capacitate;
			this->nrPersoaneImbarcate = c.nrPersoaneImbarcate;
			if (this->varstaPasageri != nullptr) {
				delete[]varstaPasageri;
			}
			this->varstaPasageri = new int[c.nrPersoaneImbarcate];
			for (int i = 0; i < c.nrPersoaneImbarcate; i++) {
				this->varstaPasageri[i] = c.varstaPasageri[i];
			}
			this->numeCorabie = c.numeCorabie;
		}
		return *this;
	}

	//sa se def metoda calculareVarstaMedie() care calculeaza si returneaza media varstelor pasagerilor. Testati in main

	int calculareVarstaMedie() {
		int suma = 0;
		for (int i = 0; i < nrPersoaneImbarcate; i++) {
			suma += varstaPasageri[i] / nrPersoaneImbarcate;
		}
		return suma;
	}

	// sa se supraincarce operatorul [] care va indexa vectorul de varste ale pasagerilor
	int& operator[](int index) {
		if (index >= 0 && index < nrPersoaneImbarcate) {
			return varstaPasageri[index];
		}
		else {
			throw "Index Invalid";
		}
	}

	//sa se supraincarce  operatorul () functie care determina numarul de persoane care mai pot fi imbarcate pana la atingerea capacitatii maxime a corabiei. Testati in main
	int operator()(){
		return capacitate - nrPersoaneImbarcate;
	}


	void afisare() {
		cout << "NrCorabie: " << this->nrCorabii << "/ ";
		cout << "Capacitate: " << this->capacitate << "/ ";
		cout << "NrPersoaneImbarcate: " << this->nrPersoaneImbarcate << "/ ";
		cout << "VarstePasageri: "; 
		for (int i = 0; i < nrPersoaneImbarcate; i++) {
			cout << "/ " << this->varstaPasageri[i];
		}
		cout << "NumeCorabie: " << this->numeCorabie << endl;
	}

	~Corabie() {
		if (varstaPasageri != nullptr) {
			delete[]varstaPasageri;
		}
	}
};

int Corabie::nrCorabii = 0;

int main() {
	Corabie c1;
	c1.afisare();

	Corabie c2(2, 2, new int [2] {30, 40}, "BlueSea");
	c2.afisare();

	Corabie c5(5, 3, new int [3] {10, 20, 25}, "BlackSea");

	//copy constructor
	Corabie c3 = c2;
	c3.afisare();

	//operator=
	Corabie c4;
	c4 = c1;
	c4.afisare();

	cout << "VarstaMedie: " << c2.calculareVarstaMedie() << "; ";

	//operator[]

	try {
		cout << c2[0] << endl;
		c2[0] = 100;
		cout << c2[0] << endl;
	}
	catch (const char* mesaj) {
		cout << mesaj;
	}

	//operator ()
	cout << "; " << c5() << endl;

	//getter si setter
	cout << c5.getCapacitate()<< endl;
	c5.setCapacitate(6); 
	cout << c5.getCapacitate();
};
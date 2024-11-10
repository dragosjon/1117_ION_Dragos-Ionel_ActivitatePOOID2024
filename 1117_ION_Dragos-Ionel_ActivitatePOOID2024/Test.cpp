#include <iostream>
#include <string>

using namespace std;

class Scoala {
private:
	const int numarScoala;
	int numarClase;
	int* numarEleviDinClasa;
	static string numeDirector;

public:

	//constructor default 
	Scoala() : numarScoala(2) {
		this->numarClase = 0;
		this->numarEleviDinClasa = nullptr;
	}

	//constructori cu toti parametrii
	Scoala(int numarClase, int* numarEleviDinClasa, int numarScoala) : numarScoala(numarScoala) {
		this->numarClase = numarClase;
		this->numarEleviDinClasa = new int;
		*(this->numarEleviDinClasa) = *numarEleviDinClasa;
	}

	//constructor de copiere

	Scoala(const Scoala& s) :numarScoala(s.numarScoala) {
		this->numarClase = s.numarClase;
		this->numarEleviDinClasa = new int;
		*(this->numarEleviDinClasa) = *s.numarEleviDinClasa;
	}

	//getter si setter
	int getNumarClase() {
		return this->numarClase;
	}
	
	void setNumarClase(int numarClase) {
		this->numarClase = numarClase;
	}

	int* getNumarEleviDinClasa() {
		return this->numarEleviDinClasa;
	}

	void setNumarEleviDinClasa(int* elevi) {
		delete[]numarEleviDinClasa;
		this->numarEleviDinClasa = new int(*elevi);
	}

	//afisare
	void afisareScoala() {
		cout << "Numar Scoala: " << numarScoala << endl;
		cout << "Numar Clase: " << numarClase << endl;
		cout << "Numar Elevi din Clase: " << *numarEleviDinClasa << endl;
		cout << "Nume Director: " << numeDirector << endl;
 	}

	//destructor
	~Scoala() {
		delete[]this->numarEleviDinClasa;
	}
};

	string Scoala::numeDirector = "Luminita";

int main() {
	Scoala scoala1;


	Scoala scoala2(2, new int(40), 10);
	scoala2.afisareScoala();


}
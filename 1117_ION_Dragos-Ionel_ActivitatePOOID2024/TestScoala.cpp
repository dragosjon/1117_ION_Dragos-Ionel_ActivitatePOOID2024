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
		this->numarEleviDinClasa = new int[numarClase];
		for (int i = 0; i < numarClase; i++) {
			this->numarEleviDinClasa[i] = numarEleviDinClasa[i];
		}
		
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

	//supraincarca operatorul <<
	friend ostream& operator<<(ostream& out, const Scoala& s) {
		out << "Numarul de clase este: " << s.numarClase << endl;
		out << "Numarul de elevi din clasa este: ";
		for (int i = 0; i < s.numarClase; i++) {
			out << s.numarEleviDinClasa[i] << " ";
		}
		out << endl;
		out << "Numele directorului este: " << numeDirector << endl;
		return out;
	}


	//destructor
	~Scoala() {
		delete[]this->numarEleviDinClasa;
	}
};

	string Scoala::numeDirector = "Luminita";

int main() {
	Scoala scoala1;
	
	Scoala scoala2(2, new int[2] { 10, 20}, 10);
	//afiseaza scoala2
	cout << scoala2 << endl;

}
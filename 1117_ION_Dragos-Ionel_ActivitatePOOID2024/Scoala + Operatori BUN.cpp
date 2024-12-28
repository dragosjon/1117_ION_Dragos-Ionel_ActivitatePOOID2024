
#include <iostream>
#include <string>

using namespace std;

class Scoala {
private:
	const int nrScoala;
	static int id;
	int nrClase;
	int* nrEleviDinClasa;
public:
	Scoala() : nrScoala(++id) {
		this->nrClase = 0;
		this->nrEleviDinClasa = nullptr;
	}

	Scoala(int nrClase, int* nrEleviDinClasa) : nrScoala(++id) {
		this->nrClase = nrClase;
		this->nrEleviDinClasa = new int[nrClase];
		for (int i = 0; i < nrClase; i++) {
			this->nrEleviDinClasa[i] = nrEleviDinClasa[i];
		}
	}

	Scoala(const Scoala& s) : nrScoala(++s.id) {
		this->nrClase = s.nrClase;
		this->nrEleviDinClasa = new int[s.nrClase];
		for (int i = 0; i < s.nrClase; i++) {
			this->nrEleviDinClasa[i] = s.nrEleviDinClasa[i];
		}
	}

	int getNrClase() {
		return this->nrClase;
	}

	void setNrClase(int nrClase) {
		this->nrClase = nrClase;
	}

	Scoala operator=(const Scoala& s) {
		if (this != &s)
		{
			this->nrClase = s.nrClase;
			if (nrEleviDinClasa != nullptr) {
				delete[]this->nrEleviDinClasa;
			}
			this->nrEleviDinClasa = new int[s.nrClase];
			for (int i = 0; i < s.nrClase; i++) {
				this->nrEleviDinClasa[i] = s.nrEleviDinClasa[i];
			}
		}
		return *this;
	}

	int getNumarTotalElevi() {
		int total = 0;
		for (int i = 0; i < nrClase; i++) {
			total += nrEleviDinClasa[i];
		}
		return total;
	}

	//operator de indexare[]

	int& operator[](int index) {
		if (index >= 0 && index < nrClase) {
			return this->nrEleviDinClasa[index];
		}
		else {
			throw "Index Invalid";
		}

	}

	//oprator de cast la int
	operator int() {
		return this->nrClase;
	}

	//operator ()
	int operator()() {
		return nrClase;
	}

	//OPERATOR>
	bool operator>(const Scoala& s) {
		return nrClase > s.nrClase;
	}

	//operator < 
	bool operator<(const Scoala& s) {
		return nrClase < s.nrClase;
	}

	//operator +=
	bool operator+=(const Scoala& s) {
		return this->nrClase += s.nrClase;
	}

	//operator ==
	bool operator==(const Scoala& s) {
		return nrClase == s.nrClase;
	}

	//operator != 
	bool operator!=(const Scoala& s) {
		return nrClase != s.nrClase;
	}

	void afisare() {
		cout << "NrScoala: " << this->nrScoala << "; ";
		cout << "NrClase: " << this->nrClase << "; ";
		cout << "NrElevinDinClasa: ";
		for (int i = 0; i < nrClase; i++) {
			cout << ";" << this->nrEleviDinClasa[i];
		}
		cout << endl;
	}

	~Scoala() {
		if (nrEleviDinClasa != nullptr) {
			delete[]this->nrEleviDinClasa;
		}
	}
};

int Scoala::id = 0;

int main() {
	Scoala s1;
	s1.afisare();

	Scoala s2(2, new int[2] {10, 20});
	s2.afisare();

	Scoala s3 = s2;
	s3.afisare();

	Scoala s4;
	s4 = s1;
	s4.afisare();
	cout << endl;

	Scoala s5(5, new int[5] {20, 30, 10, 40, 50});
	
	cout << endl;

	cout << s2.getNumarTotalElevi();

	cout << endl;

	try {
		cout << s5[0] << endl;
		s5[6] = 10;
		cout << s5[0] << endl;
	}
	catch (const char* mesaj){
		cout << mesaj << endl;
	}

	
	if (s5 > s2) {
		cout << "Scoala 5 mai mare decat Scoala2" << endl;
	}
	else {
		cout << "Scoala 2 mai mare decat Scoala5" << endl;
	}

	s5 += s2;
	s5.afisare();
	
	cout << endl;

	//operator !=
	if (s3 != s2) {
		cout << "Scoala 5 diferita de Scoala 2" << endl;
	}
	else {
		cout << "Scoala 5 egala cu Scoala 2" << endl;
	}

	//operator ()
	cout << s5() << endl;

	//operator de cast la int
	int nrClase = (int)s2;
	cout << nrClase << endl;
}
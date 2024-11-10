#include <iostream>
#include <string>

using namespace std;

class Ghiozdan {
private:
	const int idGhiozdan;
	int nrBuzunare;
	float* latimeBuzunare;
	string numeGhiozdan;
public:

	//constructor default
	Ghiozdan() : idGhiozdan(0) {
		this->nrBuzunare = 0;
		this->latimeBuzunare = nullptr;
		this->numeGhiozdan = "NoName";
	}
	//constructor cu parametrii

	Ghiozdan(int nrBuzunare, float* latimeBuzunare, string numeGhiozdan, int idGhiozdan) : idGhiozdan(idGhiozdan) {
		this->nrBuzunare = nrBuzunare;
        this->latimeBuzunare = new float[nrBuzunare];
        for (int i = 0; i < nrBuzunare; i++) {
        this->latimeBuzunare[i] = latimeBuzunare[i];
        }
		this->numeGhiozdan = numeGhiozdan;
	}

	//constructor de copiere
	Ghiozdan(const Ghiozdan& g) : idGhiozdan(g.idGhiozdan) {
		this->nrBuzunare = g.nrBuzunare;
		this->latimeBuzunare = new float[g.nrBuzunare];
		for (int i = 0; i < g.nrBuzunare; i++) {
			this->latimeBuzunare[i] = g.latimeBuzunare[i];
		}
		this->numeGhiozdan = g.numeGhiozdan;
	}

	//get si set
	int getNrBuzunare() {
		return this->nrBuzunare;
	}

	void setNrBuzunare(int nrBuzunare) {
			this->nrBuzunare = nrBuzunare;
	}

	string getNumeGhiozdan() {
		return this->numeGhiozdan;
	}

	void setNumeGhiozdan(string numeGhiozdan) {
		this->numeGhiozdan = numeGhiozdan;
	}

    //supraincarcare operator =
    Ghiozdan& operator=(const Ghiozdan& g) {
					if (this != &g) {
						delete[] latimeBuzunare;
						this->nrBuzunare = g.nrBuzunare;
						this->latimeBuzunare = new float[g.nrBuzunare];
						for (int i = 0; i < g.nrBuzunare; i++) {
							this->latimeBuzunare[i] = g.latimeBuzunare[i];
						}
						this->numeGhiozdan = g.numeGhiozdan;
					}
					return *this;
    }

	//Să se supraîncarce operator> care compară două ghiozdane după numărul de buzunare

	bool operator>(Ghiozdan& g) {
		return this->nrBuzunare > g.nrBuzunare;
	}

	//Să se supraîncarce operator += care va aduna numărul de buzunare ale celor două ghiozdane, în primul(aveți grija la vector)

	Ghiozdan& operator+=(Ghiozdan& g) {
		this->nrBuzunare += g.nrBuzunare;
		float* newLatimeBuzunare = new float[this->nrBuzunare];
		for (int i = 0; i < this->nrBuzunare; i++) {
			if (i < this->nrBuzunare - g.nrBuzunare) {
				newLatimeBuzunare[i] = this->latimeBuzunare[i];
			}
			else {
				newLatimeBuzunare[i] = g.latimeBuzunare[i - this->nrBuzunare];
			}
		}
		delete[] this->latimeBuzunare;
		this->latimeBuzunare = newLatimeBuzunare;
		return *this;
	}




	//Afisare
	void afisare() {
		cout << "Id: " << this->idGhiozdan << "; ";
		cout << "Nume: " << this->numeGhiozdan << "; ";
		cout << "Numar buzunare: " << this->nrBuzunare << "; ";
		cout << "Latime buzunare: ";
		if (this->latimeBuzunare != nullptr) {
			for (int i = 0; i < nrBuzunare; i++) {
				cout << " " << this->latimeBuzunare[i] << ";";
			}
		}
		cout << endl;

	}

	//destructor
	~Ghiozdan() {
		if (this->latimeBuzunare != nullptr) {
			delete[]this->latimeBuzunare;
		}
	}
	
};

int main() {
	Ghiozdan ghiozdan1;
	ghiozdan1.afisare();


	Ghiozdan ghiozdan2(2, new float[3] {20, 30, 49}, "Nike", 1);
	ghiozdan2.afisare();

	Ghiozdan ghiozdan3(3, new float[3] {20, 30, 49}, "Adidas", 2);

	/*ghiozdan2.setNrBuzunare(1);
	ghiozdan2.setNumeGhiozdan("Dr");

	cout << "Nr Buzunare: " << ghiozdan2.getNrBuzunare();
	cout << "Nume Ghiozdan: " << ghiozdan2.getNumeGhiozdan();*/

	//constructor de copiere 
	Ghiozdan ghiozdan4 = ghiozdan2;
	ghiozdan4.afisare();

	//supraincarcare operator =
	
	Ghiozdan ghiozdan5;
	ghiozdan5 = ghiozdan1;
	ghiozdan5.afisare();


	//supraincarcare operator >
	cout << (ghiozdan2 > ghiozdan3) << endl;

	//supraincarcare operator +=

	ghiozdan2 += ghiozdan3;
	cout << "Ghiozdan 2 dupa adunare: " << ghiozdan2.getNrBuzunare() << endl;
}
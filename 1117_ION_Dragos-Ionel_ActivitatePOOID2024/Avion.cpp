//1.	Să se definească clasa Avion care are câmpurile :
// id - contor
//•	nrAvioane - întreg static - contorizează automat numărul avioanelor create
//•	capacitate - întreg - numărul de pasageri care pot fi îmbarcați
//•	nrPasageriImbarcati - int* - numărul de pasageri aflați la bord.Nu poate fi mai mare decât capacitatea avionului
//•	greutateBagaje - vector alocat dinamic reprezentând greutățile bagajelor pasagerilor(float*)
//•	numePasageri - vector alocat dinamic reprezentând numele pasagerilor(char**)
//•	varstaPasageri - vector alocat dinamic reprezentând vârstele pasagerilor(int*)
//•	un atribut la alegere ce are legătură cu avionul
//Atributele se definesc în zona privată.
//2.	Pentru clasa Avion se definesc :
//•	Constructorul fără parametri
//•	Constructorul cu parametri
//•	Destructorul(cu validări)


#include <iostream>
#include <string>

using namespace std;

class Avion {
private:
	const int id;
	static int nrAvioane;
	int capacitate;
	int* nrPasageri;
	float* varstaPasageri;
	char* numePasageri;

public:
	Avion() : id(++nrAvioane) {
		this->capacitate = 0;
		this->nrPasageri = nullptr;
		this->varstaPasageri = nullptr;
		this->numePasageri = new char[strlen("Necunoscut") + 1];
		strcpy(this->numePasageri, "Necunoscut");
	}


	//constructor cu parametrii
	Avion(int capacitate, int* nrPasageri, float* varstaPasageri,const char* numePasageri) : id(++nrAvioane) {
		this->capacitate = capacitate;
		this->nrPasageri = new int[capacitate];
		for (int i = 0; i < capacitate; i++) {
			this->nrPasageri[i] = nrPasageri[i];
		}
		this->varstaPasageri = new float[capacitate];
		for (int i = 0; i < capacitate; i++) {
			this->varstaPasageri[i] = varstaPasageri[i];
		}
		this->numePasageri = new char[strlen(numePasageri) + 1];
		strcpy(this->numePasageri, numePasageri);
	}

	//constructor de copiere
	Avion(const Avion& a) : id(++a.nrAvioane) {
		this->capacitate = a.capacitate;
		this->nrPasageri = new int[a.capacitate];
		for (int i = 0; i < a.capacitate; i++) {
			this->nrPasageri[i] = a.nrPasageri[i];
		}
		this->varstaPasageri = new float[a.capacitate];
		for (int i = 0; i < a.capacitate; i++) {
			this->varstaPasageri[i] = a.varstaPasageri[i];
		}
		this->numePasageri = new char[strlen(a.numePasageri) + 1];
		strcpy(this->numePasageri, a.numePasageri);
	}
	
	//suopraincarcare operator egal =
	Avion operator=(const Avion& a) {
		if (this != &a) {
			this->capacitate = a.capacitate;
			delete[]this->nrPasageri;
			this->nrPasageri = new int[a.capacitate];
			for (int i = 0; i < a.capacitate; i++) {
				this->nrPasageri[i] = a.nrPasageri[i];
			}
			delete[]this->varstaPasageri;
			this->varstaPasageri = new float[a.capacitate];
			for (int i = 0; i < a.capacitate; i++) {
				this->varstaPasageri[i] = a.varstaPasageri[i];
			}
			delete[]this->numePasageri;
			this->numePasageri = new char[strlen(a.numePasageri) + 1];
			strcpy(this->numePasageri, a.numePasageri);
		}
		return *this;
	}

	//Sa se supraincarce operatorul [] care va indexa vectorul de varste ale pasagerilor. Implementare permite si modificarea acestei varste. 
	float& operator[](int index) {
		if (index >= 0 && index < capacitate) {
			return varstaPasageri[index];
		}
		else {
			throw "Index invalid";
		}
	}

	//supraincarcare operator !=
	bool operator!=(Avion a) {
		if (this->capacitate != a.capacitate) {
			return true;
		}
		else {
			return false;
		}
	}
	


	//afisare

	void afisare() {
		cout << "Id: " << this->id << endl;
		cout << "Capacitate: " << this->capacitate << endl;
		cout << "NrPasageri: ";
		if (nrPasageri != nullptr) {
			for (int i = 0; i < capacitate; i++) {
				cout << nrPasageri[i] << ";";
			}
		}
		cout << "VarstaPasageri: ";
		if (varstaPasageri != nullptr) {
			for (int i = 0; i < capacitate; i++) {
				cout << varstaPasageri[i] << ";";
			}
		}
		cout << "NumePasageri: " << this->numePasageri << endl;
		
		
	}

	~Avion() {
		delete[]nrPasageri;
		delete[]varstaPasageri;
		delete[]numePasageri;
	}
};

 int Avion::nrAvioane = 0;


int main() {
	Avion avion1;
	avion1.afisare();

	/*Avion avion2(1, new int(4), new float[4] {20, 30, 40, 50}, "Gigel, Costel, Dragos,Ionel");
	avion2.afisare();*/

	//avion3

	Avion avion3(2, new int[3] {2, 3, 4}, new float[3] {20, 30, 40}, "Gigel, Costel");
	avion3.afisare();
	
	//constructor de copiere
	Avion avion4 = avion3;
	avion4.afisare();

	//operator =
	Avion avion5;
	avion5 = avion1;
	avion5.afisare();


	//operator []

	try {
		cout << avion3[0] << endl;
		avion3[0] = 100;
		cout << avion3[0] << endl;
	}
	catch (const char* mesaj) {
		cout << mesaj << endl;
	}

	//operator !=
	if (avion3 != avion4) {
		cout << "Avioanele sunt diferite" << endl;
	}
	else {
		cout << "Avioanele sunt la fel" << endl;
	}



}
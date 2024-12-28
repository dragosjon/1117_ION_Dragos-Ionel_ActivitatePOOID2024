#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Farmacie {
private:
	const int CODUnic;
	static int id;
	char* adresa;
	int nrMedicamente;
	float* preturiMedicamente;
public:
	Farmacie() : CODUnic(++id) {
		this->adresa = new char[strlen("Necunoscut") + 1];
		strcpy(this->adresa, "");
		this->nrMedicamente = 0;
		this->preturiMedicamente = nullptr;
	}

	Farmacie(const char* adresa, int nrMedicamente, float* preturiMedicamente) : CODUnic(++id) {
		this->adresa = new char[strlen(adresa) + 1];
		strcpy(this->adresa, adresa);
		this->nrMedicamente = nrMedicamente;
		this->preturiMedicamente = new float[nrMedicamente];
		for (int i = 0; i < nrMedicamente; i++) {
			this->preturiMedicamente[i] = preturiMedicamente[i];
		 }
		
	}

	Farmacie(const Farmacie& f): CODUnic(++f.id){
		this->adresa = new char[strlen(f.adresa) + 1];
		strcpy(this->adresa, f.adresa);
		this->nrMedicamente = f.nrMedicamente;
		this->preturiMedicamente = new float[f.nrMedicamente];
		for (int i = 0; i < f.nrMedicamente; i++) {
			this->preturiMedicamente[i] = f.preturiMedicamente[i];
		}
	}

	int getCODUnic() {
		return this->CODUnic;
	}

	int getNrMedicamente() {
		return this->nrMedicamente;
	}

	void setNrMedicamente(int nrMedicamente) {
		this->nrMedicamente = nrMedicamente;
	}

	Farmacie operator=(const Farmacie& f) {
		if (this != &f)
		{
			if (this->adresa != nullptr) {
				delete[]this->adresa;
			}
			this->adresa = new char[strlen(f.adresa) + 1];
			strcpy(this->adresa, f.adresa);
			this->nrMedicamente = f.nrMedicamente;
			if (this->preturiMedicamente != nullptr) {
				delete[]this->preturiMedicamente;
			}
			this->preturiMedicamente = new float[f.nrMedicamente];
			for (int i = 0; i < f.nrMedicamente; i++) {
				this->preturiMedicamente[i] = f.preturiMedicamente[i];
			}
		}
		return *this;
	}

	//primeste o valoarea si returneaza cate medicamente au pretul mai mic decat valoarea primita
	float getNrMedicamenteIeftine() {
		int valoarea = 10;
		float nr = 0;
		for (int i = 0; i < nrMedicamente; i++) {
			if (preturiMedicamente[i] < valoarea)
				nr++;
		}
		return nr;
	}

	//operator>
	bool operator>(const Farmacie& f) {
		return this->nrMedicamente > f.nrMedicamente;
	}

	void afisare() {
		cout << "ID: " << this->CODUnic << "/ ";
		cout << "Adresa: " << this->adresa << "/ ";
		cout << "NrMedicamente: " << this->nrMedicamente << "; ";
		cout << "Preturi: ";
		for (int i = 0; i < nrMedicamente; i++) {
			cout << "; " << this->preturiMedicamente[i];
		}
		cout << endl;
	}


	//indexare

	float& operator[](int index) {
		if (index >= 0 && index < nrMedicamente){
			return preturiMedicamente[index];
		}
		else {
			throw "Index Invalid";
		}
	}

	//Să se definească metoda getPretMaxim() care determină și returnează pret maxim din vector
	float getPretMaxim() {
		float pretMaxim = 0;
		for (int i = 0; i < nrMedicamente; i++) {
			if (preturiMedicamente[i] > pretMaxim) {
				pretMaxim = preturiMedicamente[i];
			}
		}
		return pretMaxim;
	}

	~Farmacie() {
		if (this->adresa != nullptr) {
			delete[]this->adresa;
		}
		if (this->preturiMedicamente != nullptr) {
			delete[]this->preturiMedicamente;
		}
	}
};

int Farmacie::id = 0;

int main() {
	Farmacie f1;
	f1.afisare();

	Farmacie f2("Bucuresti", 3, new float[3] {5, 60, 24});
	f2.afisare();

	Farmacie f3("Buzau", 2, new float[2] {10, 15});
	f3.afisare();

	Farmacie f4 = f3;
	f4.afisare();

	Farmacie f5;
	f5 = f1;
	f5.afisare();

	cout << f2.getNrMedicamenteIeftine();
	cout << endl;


	if (f2 > f3) {
		cout << "F2 are mai multe medicamente";
	}
	else {
		cout << "F3 are mai multe medicamente";
	}
	cout << endl;

	try{
		cout << f2[0] << endl;
		f2[0] = 9;
		cout << f2[0];
	}
	catch(const char* mesaj) {
		 mesaj;
	}

	cout << f2.getPretMaxim();
}
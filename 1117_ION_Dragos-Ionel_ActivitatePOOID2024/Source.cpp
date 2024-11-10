#include <string>
#include <iostream>

using namespace std;

class Farmacie {
private:
	const int codUnic;
	char* adresa;
	int nrMedicamente;
	float* preturiMedicamente;
public:
	Farmacie() : codUnic(0) {
		this->adresa = new char[strlen("Necunoscuta") + 1];
		strcpy(this->adresa, "Necunoscuta");
		this->nrMedicamente = 0;
		this->preturiMedicamente = nullptr;
	}

	Farmacie(const char* adresa, int nrMedicamente, float* preturiMedicamente, int codUnic) : codUnic(codUnic) {
		this->adresa = new char[strlen(adresa) + 1];
		strcpy(this->adresa, adresa);
		this->nrMedicamente = nrMedicamente;
		this->preturiMedicamente = new float[nrMedicamente];
		for (int i = 0; i < nrMedicamente; i++) {
			this->preturiMedicamente[i] = preturiMedicamente[i];
		}
	}

	void afisare() {
		cout << "Cod: " << this->codUnic << "; ";
		cout << "Adresa: " << this->adresa << ";";
		cout << "NrMedicamente: " << this->nrMedicamente << ";";
		cout << "PreturiMedicamente: ";
		if (preturiMedicamente != nullptr) {
			for (int i = 0; i < nrMedicamente; i++) {
				cout << preturiMedicamente[i] << ";";
			}
		}

	}

	//constructor de copiere

	Farmacie(const Farmacie& f) : codUnic(f.codUnic){
		this->adresa = new char[strlen(f.adresa) + 1];
		strcpy(this->adresa, f.adresa);
		this->nrMedicamente = f.nrMedicamente;
		this->preturiMedicamente = new float[nrMedicamente];
		for (int i = 0; i < nrMedicamente; i++) {
			this->preturiMedicamente[i] = f.preturiMedicamente[i];
		}

	}

	//getteri si seeteri

	
	~Farmacie() {
		delete[]this->adresa;
		delete[]this->preturiMedicamente;
	}
};

int main() {
	Farmacie farmacie1;
	farmacie1.afisare();

	Farmacie farmacie2("Strada X", 3, new float[3] { 10, 20, 30 }, 1);
	farmacie2.afisare();

	//constructor de copiere

	Farmacie farmacie3 = farmacie2;
	farmacie3.afisare();

}
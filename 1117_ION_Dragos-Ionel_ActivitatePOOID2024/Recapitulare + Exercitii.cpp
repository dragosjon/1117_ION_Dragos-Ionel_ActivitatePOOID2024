#include <iostream>
#include <string>

using namespace std;

/* in interiorul unei clase se afla atribute

zone de securitate din clasa : public , protected , private
by default zona este private

atributele din private nu le pot accesa

Atributele : constante si statice

Transmiterea  parametrilor : prin valoare, prin referinta, prin pointer

Diferenta dintre functie si metoda. Metoda se ataseaza de obiect si se afla in interiorul claselor  iar functiile in exteriorul lor.

Principiile OOP : 1. Incapsulare - definim mai multe atribute in zona private si le accesam  cu getter si setter
*/


class Masina {
private:
	const int id;
	static int nrMasini;
	string marca;
	int nrComponente;
	float* preturi;


public:
	//Constructor default

	Masina() : id(++nrMasini) { // prima oara se modifica numarul masinii si apoi al id-ului

		this->marca = "Necunoscuta";
		this->nrComponente = 0;
		this->preturi = nullptr; //initializare vector cu NULL
	}


	//Constructori cu toti parametrii
	Masina(string marca, int nrComponente, float* preturi) : id(++nrMasini) {
		this->marca = marca;
		this->nrComponente = nrComponente;
		//this->preturi = preturi -> shallow copy

		//deep copy
		this->preturi = new float[nrComponente];
		for (int i = 0; i < nrComponente; i++) {
			this->preturi[i] = preturi[i];
		}

		//dezalocare vector
		delete[]preturi;
	}

	//getteri si setteri pe tip de date primitiv
	//getter
	int getNrComponente() {
		return this->nrComponente;
	}

	//setter
	//void se foloseste cand nu avem nimic de returnat
	void setNrComponente(int nrComponente) {
		if (nrComponente > 0) { //am facut nrComponente sa fie mai mare decat 0 pentru ca nu avem cum sa avem componente mai putine de 0
			this->nrComponente = nrComponente;
		}
	}

	//getteri si setteri pe tip de date pointer petrun vectorul preturi
	//getter 
	float* getPreturi() {
		float* vectorPreturi = new float[this->nrComponente];
		for (int i = 0; i < this->nrComponente; i++) {
			vectorPreturi[i] = this->preturi[i];
		}
		return vectorPreturi;
	}

	//setter (actualizam dimensiunea vectorului)
	void setPreturi(float* noulVectorPreturi, int nouaDimensiune) {
		setNrComponente(nouaDimensiune); //setam noua dimensiune a vectorului
		if (this->preturi != nullptr) { //stergem preturile vechi
			delete[]this->preturi;
		}
		this->preturi = new float[nouaDimensiune]; //setam valorile
		for (int i = 0; i < nouaDimensiune; i++) {
			this->preturi[i] = noulVectorPreturi[i];
		}
		delete[]noulVectorPreturi;
	}


	//destructor(se apeleaza automat la final de compilator)
	~Masina() {
		if (this->preturi != nullptr)
			delete[]this->preturi;
	}


	//metoda de afisare 
	void afisareMasina() {
		cout << this->id << ". Masina cu marca " << this->marca;
		if (this->nrComponente > 0)
			cout << " are " << this->nrComponente << " componente cu urmatoarele preturi:";
		if (this->preturi != nullptr) {
			for (int i = 0; i < this->nrComponente; i++) {
				cout << " " << this->preturi[i];
			}
		}
		cout << endl;
	}



};

int Masina::nrMasini = 0;

int main() {
	Masina masina1; //apelam constructor default


	masina1.setNrComponente(1);
	cout << "Noua valoare este: " << masina1.getNrComponente() << endl;

	Masina masina2("Renault", 4, new float[4] {23.5, 50.0, 60.7, 3.5});

	masina1.afisareMasina();
	masina2.afisareMasina();

	masina2.setPreturi(new float[2] {10.5, 14.7}, 2);

	float* vectorPreturi = masina2.getPreturi();
	for (int i = 0; i < masina2.getNrComponente(); i++) {
		cout << " " << vectorPreturi[i];
	}
}
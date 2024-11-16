
#include <iostream>
#include <string>

using namespace std;

class Autobuz {
private:
	static int nrAutobuze;
	const int idAutobuz;
	int capacitate;
	int nrPersoaneImbarcate;
	char* producator;
public:

	//constructor default
	Autobuz() : idAutobuz(++nrAutobuze) {
		this->capacitate = 0;
		this->nrPersoaneImbarcate = 0;
		this->producator = new char[strlen("Necunoscut") + 1];
		strcpy(this->producator, "Necunosctu");
	}

	//constructor cu toti parametrii
	Autobuz(int capacitate, int nrPersoaneImbarcate,const char* producator) : idAutobuz(++nrAutobuze) {
		this->capacitate = capacitate;
		this->nrPersoaneImbarcate = nrPersoaneImbarcate;
		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);
	}

	//constructor de copiere
	 Autobuz (const Autobuz& a) : idAutobuz(++a.nrAutobuze) {
		 this->capacitate = a.capacitate;
		 this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
		 this->producator = new char[strlen(a.producator) + 1];
		 strcpy(this->producator, a.producator);
	}


	 //getteri si setteri
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
	 

	 //operatorul=
	 Autobuz operator=(const Autobuz& a) {
		 if (this != &a)
		 {
			 this->capacitate = a.capacitate;
			 this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
			 if (this->producator != nullptr) {
				 delete[]this->producator;
			 }
			 this->producator = new char[strlen(a.producator) + 1];
			 strcpy(this->producator, a.producator);
		 }
		 return *this;
	 }

	 //metoda getNumarLocuriLibere()
	 
	  int getNumarLocuriLibere() {
		 return capacitate - nrPersoaneImbarcate;
	 }


	 /*static int getNumarLocuriLibere() {
		 for (int i = 0; capacitate - nrPersoaneImbarcate; i++) {
			 return nrLocuri;
			}
	 }*/	  
	  
	  //operator de cast la int
	  operator int() const {
		  return nrPersoaneImbarcate;
	  }
	  
	  //supraincarcare operator >

	  bool operator>(const Autobuz& a) {
		  return this->capacitate > a.capacitate;
	  }
	  

	 //afisare
	 void afisare() {
		 cout << "Id: " << this->idAutobuz << "; ";
		 cout << "Capacitate: " << this->capacitate << "; ";
		 cout << "NrPersoaneImbarcate :"; 
		 if (nrPersoaneImbarcate > capacitate)
			 cout << "Numarul de persoane a depasit capacitatea autobuzului" << "; ";
		 cout << this->nrPersoaneImbarcate << ";";
		 cout << "Producator: " << this->producator << "; " << endl;
	 }

	//destructor
	~Autobuz() {
		if(this->producator != nullptr)
		delete[]this->producator;
	}
};

int Autobuz:: nrAutobuze = 0;


int main() {
	Autobuz autobuz1;
	autobuz1.afisare();

	Autobuz autobuz2(10, 5, "Mercedes");
	autobuz2.afisare();

	Autobuz autobuz3(10, 12, "Orio");
	autobuz3.afisare();

	//testare constructor de copiere
	Autobuz autobuz4 = autobuz1;
	autobuz4.afisare();

	//testare operator egal
	Autobuz autobuz5;
	autobuz5 = autobuz2;
	autobuz5.afisare();

	//testare getter si setter
	cout << "Capacitatea autobuzului selectate: " << autobuz3.getCapacitate() << "; ";
	autobuz3.setCapacitate(16);
	autobuz3.afisare();

	//testare numar locuri libere
	cout << "Numar locuri libere: " << autobuz4.getNumarLocuriLibere() << "; " << endl;

	//testare operator de cast la int
	int nrPersoaneImbarcate = autobuz3;
	cout << "Numarul de persoane imbarcate este: " << nrPersoaneImbarcate << "; " << endl;

	//testare supraincarcarea operatorului >
	//testare capacitate mai mica
	autobuz3.setCapacitate(5);
	if (autobuz3 > autobuz2) {
		cout << "Autobuzul: 3 are capacitatea mai mare decat autobuzul: 2" << endl;
	}
	else {
		cout << "Autobuzul: 3 are capacitatea mai mica decat autobuzul: 2" << endl;
	}

	//testare capacitate mai mare
	autobuz3.setCapacitate(15);
	if (autobuz3 > autobuz2) {
		cout << "Autobuzul: 3 are capacitatea mai mare decat autobuzul: 2" << endl;
	}
	else {
		cout << "Autobuzul: 3 are capacitatea mai mica decat autobuzul: 2" << endl;
	}
	
}
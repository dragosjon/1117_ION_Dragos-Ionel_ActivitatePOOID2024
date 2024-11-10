#include<iostream>

using namespace std;

enum ModEliberare {
	cuReteta, faraReteta, Gratis, Compensat
};

class Farmacie {
private:
	string nume;
	const int anInfiintare;
	//protected:
	int nrAngajati;
	float* salarii;
	ModEliberare modEliberare;
	static float salariuMinim;

	//contructorul NU are tip returnat (nici destrucorul) -- singurele doua
	//contructorul va avea acelasi nume cu clasa si este case sensitive
	//cnstrutor implicit vs. constructor default
	//constantele suntem obligati sa le initializam in lista de initializari a constructorului
public:


	class Farmacist {
	public:
		string nume;
		Farmacist() {
			this->nume = "NoName";
		}
	};
	Farmacie() : anInfiintare(2023) {
		this->nume = "Noname";
		this->nrAngajati = 0;
		this->salarii = NULL; //se poate folosi si nullptr (null pointer)
		this->modEliberare = Gratis;
	}

	Farmacie(string nume, ModEliberare modEliberare) : anInfiintare(2023) {
		this->nume = nume;
		this->nrAngajati = 0;
		this->salarii = NULL;
		this->modEliberare = modEliberare;
	}

	Farmacie(string nume, int anInfiintareNou, int nrAngajati, float* salarii, ModEliberare modEliberare) : anInfiintare(anInfiintareNou) {
		//da click pe fiecare anInfiintare si anInfiintareNou sa vezi diferenta
		this->nume = nume;
		this->nrAngajati = nrAngajati;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = salarii[i];
		}
		this->modEliberare = modEliberare;
	};
	//de evitat constructorul default

	//Constructor de copiere
	Farmacie(const Farmacie& f) : anInfiintare(f.anInfiintare) {
		this->nume = f.nume;
		this->nrAngajati = f.nrAngajati;
		this->salarii = new float[f.nrAngajati];
		for (int i = 0; i < f.nrAngajati; i++) {
			this->salarii[i] = f.salarii[i];
		}
		this->modEliberare = f.modEliberare;


	}

	// operator =

	Farmacie operator=(const Farmacie& f) {
		if (this != &f) {
			this->nume = f.nume;
			this->nrAngajati = f.nrAngajati;
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[f.nrAngajati];
			for (int i = 0; i < f.nrAngajati; i++) {
				this->salarii[i] = f.salarii[i];
			}
			this->modEliberare = f.modEliberare;

		}

		return *this;
	}

	// operator +


	Farmacie operator+(float adaosSalarial) const {

		Farmacie aux = *this;
		for (int i = 0; i < this->nrAngajati; i++) {
			aux.salarii[i] += adaosSalarial;
		}
		return *this;
	}

	friend Farmacie operator+(int adaosSalarial, Farmacie f) {

		Farmacie aux = f;
		for (int i = 0; i < aux.nrAngajati; i++) {
			aux.salarii[i] += adaosSalarial;
		}
		return aux;
	}


	string getNume() {
		return this->nume;
	}

	int getAnInfiintare() {
		return this->anInfiintare;
	}

	void setNume(string nume) {

		if (nume.length() > 2) {
			this->nume = nume;
		}

	}

	int getNrAngajati() {
		return this->nrAngajati;
	}

	// seter Compus pentru ca cati angajati ai, atatea salarii trb sa ai in vector
	//Seter compus pentru doua atribute
	void setNrAngajati(int nr, float* salarii) {
		if (nr > 0) {
			this->nrAngajati = nr;
			//NU ASA this->salarii = salarii;

			if (this->salarii != NULL) {
				delete[]this->salarii;
			}

			this->salarii = new float[nr];
			for (int i = 0; i < nr; i++) {
				this->salarii[i] = salarii[i];
			}
		}
	}

	float* getSalarii() {

		return this->salarii;
	}

	float getSalariu(int pozitie) {
		return this->salarii[pozitie];
	}


	void afisare() { //afisare(Farmacie + this)
		//cout << "Nume: " << nume << "; "; //merge si asa si ca mai jos dar se recomanda cu sagetuta
		//this este un pointer si retine o adresa a obiectului pentru care a fost apelata metoda respectiva
		//this este doar in metode
		//diferenta dintre o metoda si functie este pointerul this
		//prin interiorul metodelor se realizeaza comunicarea obiectului cu exteriorul
		cout << "Nume: " << this->nume << "; ";
		cout << "Nr. angajati: " << nrAngajati << "; ";
		cout << "Mod eliberare: " << modEliberare << "; ";
		cout << "Salariul minim: " << salariuMinim << "; ";
		cout << "Salariile angajatilor: ";
		for (int i = 0; i < nrAngajati; i++) {
			cout << salarii[i] << ", ";
		}
		cout << endl;

	}

	//destructor
	~Farmacie() {
		if (this->salarii != NULL) {
			delete[]this->salarii;
		}

	}

	static void marireSalariuMinim(int procent) {
		//this->nume daca decomentezi o sa ai eroare
		//nrAngajati++; daca decomentezi o sa ai eroare
		salariuMinim += salariuMinim * (procent / 100.0f);
	}

	static float getSalariuMinim()
	{
		return salariuMinim;
	}

	static void setSalariuMinim(float salariuMinim) {

		if (salariuMinim > 10) {
			Farmacie::salariuMinim = salariuMinim;
		}

	}

	friend class DistribuitorMedicamente;

	friend void functiePrietena(Farmacie& f) {
		f.nume = "Donna";
	}
};



float Farmacie::salariuMinim = 1950; //se recomanda sa fie initializat imediat dupa clasa

void functie(Farmacie f) {

}


Farmacie functie2() {
	Farmacie f;
	return f;
}


class DistribuitorMedicamente {
private:
	string nume;
	Farmacie farmacie;
public:
	string getNume() {
		return nume;
	}
	void setNume(string nume) {
		if (nume.length() > 0) {
			this->nume = nume;
		}
	}
	Farmacie getFarmacie() {
		return this->farmacie;
	}

	void setFarmacie(Farmacie f) {
		this->farmacie = f;
	}
	void modificaModEliberare() {
		this->farmacie.modEliberare = cuReteta;
	}
};

void main() {
	Farmacie f;
	//f.nume = "HelpNet";
	f.setNume("HelpNet");
	//f.nrAngajati = 2;
	float* salariiBrute = new float[3] {3000, 5000, 4000}; //vector initializat inline
	f.setNrAngajati(3, salariiBrute);

	for (int i = 0; i < 3; i++) {
		cout << f.getSalarii()[i]; //[1] inseamna indexare;
		cout << f.getSalariu(i);
	}

	Farmacie f2; //apelez constructorul in mod implicit

	f2.afisare();

	float* salarii = new float[2];
	salarii[0] = 1950;
	salarii[1] = 2300;


	Farmacie f3("Catena", 2000, 2, salarii, cuReteta); //apelez constructorul in mod explicit, cu parametri
	{
		//aici avem 3 obiecte in memorie
		Farmacie f4("Tei", faraReteta);
		//aici avem 4 obiecte in memorie
	}

	//aici avem 3 obiecte in memorie
	f3.afisare();
	cout << endl << Farmacie::getSalariuMinim() << endl;

	f3.marireSalariuMinim(10);
	cout << endl << Farmacie::getSalariuMinim() << endl;

	Farmacie::marireSalariuMinim(10);
	cout << endl << Farmacie::getSalariuMinim() << endl;

	Farmacie* farmacii = new Farmacie[5]; //alocam memorie in heap


	delete[]salarii;
	delete[]farmacii; //se va apela automat pentru toate cele 5 farmacii
	Farmacie f8 = f3;
	functie(f3);

	//dupa operator =

	functie2();

	f8 = f3;
	f8.afisare();


	int a = 10;
	int b = 3;
	b = a + 30;

	f8 = f3 + 200;
	f8.afisare();


	/*Farmacie f9 = 100 + f3;
	f9.afisare();*/

	//nested class;

	Farmacie::Farmacist farmacist;
	farmacist.nume = "Zamfiroiu";
}



//functii speciale
//constructori => prin intermediul lor construim obiecte
//constructori vs. constructori de copiere vs. destructor
//functia statica nu primeste this
//poate fi apelata fara oobiect ca are pointerul this

//exista un singur destructor
//destructorul nu are parametri
//este apelat automat


//noi o sa folosim doar functie inline
//cand declaram functia o si implementam

//deep copy vs. shallow copy

//un obiect va fi apelat o singura data prin intermediul unui singur constructor

//functia statica se afla intr o clasa fata de functia globala care e stocata in memorie

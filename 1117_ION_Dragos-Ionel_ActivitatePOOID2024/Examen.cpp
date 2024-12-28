//Să se creeze un proiect în Microsoft Visual Studio care să nu genereze erori de compilare(1 p).
//
//2. Să se definească clasa Ghiozdan care are câmpurile :
//
//idGhiozdan– întreg constant – nu se va putea modifica;
//nrBuzunare – întreg – numărul de buzunare din ghiozdan;
//latimeBuzunare – vector alocat dinamic reprezentând latimile buzunarelor din ghiozdan(int* / float*).
//un atribut la alegere.Explicați prin comentariu utilitatea atributului adăugat.Acesta trebuie să aibă legătura cu clasa ghiozdan.
//Atributele clasei se definesc în zona privată a clasei(1 punct).
//
//3. Să se definească pentru clasa Ghiozdan constructor fără parametri, constructor cu parametri și destructor.Constructorul cu parametri conține validări pentru parametrii primiți.(2 puncte)
//
//4. Să se definească pentru clasa Ghiozdan constructorul de copiere și metode accesor(get si set) pentru doua atribute la alegere.Testați în funcția main(). (1 punct)
//
//5. Să se supraîncarce pentru clasa Ghiozdan operatorul = (de atribuire) fără a genera memory leaks și să nu permită auto - atribuirea.Testați în funcția main(). (1 punct)
//
//6. Să se supraîncarce operatorul << pentru afișarea obiectelor de tipul Ghiozdan.Elementele sunt afișate pe aceeași linie despărțite prin punct și virgula și spațiu(; ).Testați în funcția main(). (1 punct)
//
//7. Să se definească metoda getLatimeMaxima() care determină și returnează lățimea maximă din vector.Testați în funcția main(). (1 punct)
//
//8. Să se supraîncarce operator> care compară două ghiozdane după numărul de buzunare.Testați în main() (1 punct)
//
//9. Să se supraîncarce operator+= care va aduna numărul de buzunare ale celor două ghiozdane, în primul(aveți grija la vector).Testați în funcția main() (1 punct)


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

class Examen {
private:
	const int idExamen;
	static int id;
	char* materie;
	string profesor;
	int nota;
	int nrSubiecte;
	float* punctajePerSubiect;
	bool promovat;
public: 
	
	Examen() : idExamen(++id) {
		this->materie = new char[strlen("Necunoscut") + 1];
		strcpy(this->materie, "Necunoscut");
		this->profesor = "NoName";
		this->nota = 0;
		this->nrSubiecte = 0;
		this->punctajePerSubiect = nullptr;
		this->promovat = false;
	}

	Examen(const char* materie, string profesor, int nota, int nrSubiecte, float* punctajePerSubiect, bool promovat) : idExamen(++id) {
		this->materie = new char[strlen(materie) + 1];
		strcpy(this->materie, materie);
		this->profesor = profesor;
		this->nota = nota;
		this->nrSubiecte = nrSubiecte;
		this->punctajePerSubiect = new float[nrSubiecte];
		for (int i = 0; i < nrSubiecte; i++) {
			this->punctajePerSubiect[i] = punctajePerSubiect[i];
		}
		this->promovat = promovat;
	}

	Examen(const Examen& e): idExamen(++e.id) {
		this->materie = new char[strlen(e.materie) + 1];
		strcpy(this->materie, e.materie);
		this->profesor = e.profesor;
		this->nota = e.nota;
		this->nrSubiecte = e.nrSubiecte;
		this->punctajePerSubiect = new float[e.nrSubiecte];
		for (int i = 0; i < e.nrSubiecte; i++) {
			this->punctajePerSubiect[i] = e.punctajePerSubiect[i];
		}
		this->promovat = e.promovat;
	}

	Examen operator=(const Examen& e) {
		if(this != &e)
		{
			if (materie != nullptr) {
				delete[]this->materie;
			}
			this->materie = new char[strlen(e.materie) + 1];
			strcpy(this->materie, e.materie);
			this->profesor = e.profesor;
			this->nota = e.nota;
			this->nrSubiecte = e.nrSubiecte;
			if (punctajePerSubiect != nullptr) {
				delete[]this->punctajePerSubiect;
			}
			this->punctajePerSubiect = new float[e.nrSubiecte];
			for (int i = 0; i < e.nrSubiecte; i++) {
				this->punctajePerSubiect[i] = e.punctajePerSubiect[i];
			}
			this->promovat = e.promovat;
		}
		return *this;
	}

	string getProfesor() {
		return this->profesor;
	}

	void setProfesor(string profesor) {
		this->profesor = profesor;
	}

	bool getPromovat() {
		return this->promovat;
	}

	void setPromovat(bool promovat) {
		this->promovat = promovat;
	}

	//metoda
	float getPunctajMaxim() {
		float max = 0;
		for (int i = 0; i < nrSubiecte; i++) {
			max += punctajePerSubiect[i];
		}
		return max;
	}

	//metoda
	float getPunctajMediu() {
		float mediu = 0;
		for (int i = 0; i < nrSubiecte; i++) {
			mediu += punctajePerSubiect[i] / nrSubiecte;
		}
		return mediu;
	}

	//metoda 
	
	float getNrSubiecteMici() {
		float suma = 3;
		float nr = 0;
		for (int i = 0; i < nrSubiecte; i++) {
			if (punctajePerSubiect[i] < suma)
				nr++;
		}
		return nr;
	}
	
	//metoda

	float getMinPunctaje() {
		float min = this->punctajePerSubiect[0];
		for (int i = 0; i < this->nrSubiecte; i++) {
			if (min > this->punctajePerSubiect[i]) {
				min = this->punctajePerSubiect[i];
			}
		}
		return min;
	}


	//metoda 
	float getMaxPunctaje() {
		float max = punctajePerSubiect[0];
		for (int i = 0; i < nrSubiecte; i++) {
			if (max < punctajePerSubiect[i]) {
				max = punctajePerSubiect[i];
			}
		}
		return max;
	}

	//operator indexare []
	float& operator[](int index) {
		if (index >= 0 && index < nrSubiecte) {
			return punctajePerSubiect[index];
		}
		else {
			throw "Index Invalid";
		}
	}

	// operator de < care compara doua examene dupa nr de subiecte
	bool operator<(const Examen& e) {
		return this->nrSubiecte < e.nrSubiecte;
	}

	
	bool areRestanta() {
		return this->nota < 5;
	}

	// operator-- pentru a sterge ultima valoare din vector
	// simplifica codul si fa-l mai usor de inteles
	Examen operator--() {
		if (nrSubiecte > 0) {
			float* aux = new float[nrSubiecte - 1];
			for (int i = 0; i < nrSubiecte - 1; i++) {
				aux[i] = punctajePerSubiect[i];
			}
			delete[]punctajePerSubiect;
			punctajePerSubiect = aux;
			nrSubiecte--;
		}
		return *this;
	}

	//opeartor++ pentru a adauga o valoare in vector

	Examen operator++() {
		float* aux = new float[nrSubiecte + 1];
		for (int i = 0; i < nrSubiecte; i++) {
			aux[i] = punctajePerSubiect[i];
		}
		delete[]punctajePerSubiect;
		punctajePerSubiect = aux;
		nrSubiecte++;
		return *this;
	}

	//supraincarcare operator <<
	friend ostream& operator<<(ostream& out, Examen& e) {
		out << "ID: " << e.idExamen << "; ";
		out << "Materie: " << e.materie << "; ";
		out << "Prof: " << e.profesor << "; ";
		out << "Nota: " << e.nota << "; ";
		out << "NrSubiecte: " << e.nrSubiecte << "; ";
		out << "Punctaje: ";
		for (int i = 0; i < e.nrSubiecte; i++) {
			out << e.punctajePerSubiect[i] << "; ";
		}
		out << "Promovat: " << e.promovat << endl;
		return out;
	}

	void afisare() {
		cout << "ID: " << this->idExamen << "; ";
		cout << "Materie: " << this->materie << "; ";
		cout << "Prof: " << this->profesor << "; ";
		cout << "Nota: " << this->nota << "; ";
		cout << "NrSubiecte: " << this->nrSubiecte << "; ";
		cout << "Punctaje: ";
		for (int i = 0; i < nrSubiecte; i++) {
			cout << this->punctajePerSubiect[i] << "; ";
		}
		cout << "Promovat: " << this->promovat << endl;
	}

	~Examen() {
		if (materie != nullptr) {
			delete[]materie;
		}
		if (punctajePerSubiect != nullptr) {
			delete[]punctajePerSubiect;
		}
	}
};

int Examen::id = 0;

int main() {
	Examen e1;
	e1.afisare();

	Examen e2("Mate", "Dragos", 7, 4, new float [4] {1, 2, 3, 4}, true);
	e2.afisare();

	Examen e3("Geografie", "Andrei", 2 , 3, new float [3] {10, 20, 40}, false);
	e3.afisare();

	Examen e4 = e2;
	e4.afisare();

	Examen e5;
	e5 = e1;
	e5.afisare();
	cout << endl;

	//metoda
	cout << "Punctaj maxim: "<< e3.getPunctajMaxim() << endl;

	//operator []
	try {
		cout << e2[0] << endl;
		e2[0] = 5;
		cout << e2[0] << endl;
	}
	catch (const char* mesaj) {
		cout << mesaj << endl;
	}

	//operator<
	if (e3 < e4) {
		cout << "Examen 4 are mai multe subiecte." << endl;
	}
	else {
		cout << "Examen 3 are mai multe subiecte." << endl;
	}

	//metoda 
	cout << "Punctaj mediu: " << e3.getPunctajMediu() << endl;

	//metoda 
	cout << "Subiecte cu punctaj mai mic de 3 puncte: " << e3.getNrSubiecteMici() << endl;

	//metoda
	cout << "Punctaj minim: " << e3.getMinPunctaje() << endl;

	//metoda
	cout << "Punctaj maxim: " << e2.getMaxPunctaje() << endl;

	//metoda
	cout << "Are restanta: " << e3.areRestanta() << endl;

	//operator--
	--e3;
	e3.afisare();

	//operator++
	++e3;
	e3.afisare();

}
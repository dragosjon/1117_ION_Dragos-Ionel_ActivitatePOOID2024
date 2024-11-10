#include <iostream>
#include <string>

using namespace std;

class Ghiozdan {
private:
	const int idGhiozdan;
	int* nrBuzunare;
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

	Ghiozdan(int* nrBuzunare, float* latimeBuzunare, string numeGhiozdan, int idGhiozdan) : idGhiozdan(idGhiozdan) {
		this->nrBuzunare = new int[idGhiozdan];
		for (int i = 0; i < idGhiozdan; i++) {
			this->nrBuzunare[i] = nrBuzunare[i];
		}
        this->latimeBuzunare = new float[*nrBuzunare];
        for (int i = 0; i < *nrBuzunare; i++) {
        this->latimeBuzunare[i] = latimeBuzunare[i];
        }
		this->numeGhiozdan = numeGhiozdan;
	}

	//Afisare
	void afisare() {
		cout << "Id: " << this->idGhiozdan << "; ";
		cout << "Nume: " << this->numeGhiozdan << "; ";
		cout << "Numar buzunare: ";
		if (this->nrBuzunare != nullptr) {
			for (int i = 0; i < idGhiozdan; i++) {
				cout << " " << this->nrBuzunare[i] << ";";
			}
		}
		cout << "Latime buzunare: ";
		if (this->latimeBuzunare != nullptr) {
			for (int i = 0; i < *nrBuzunare; i++) {
				cout << " " << this->latimeBuzunare[i] << ";";
			}
		}
		cout << endl;

	}

	//Să se supraîncarce operatorul << pentru afișarea obiectelor de tipul Ghiozdan.Elementele sunt afișate pe aceeași linie despărțite prin punct și virgula și spațiu(; )
	/*friend ostream& operator<<(ostream& out, Ghiozdan& ghiozdan) {
		out << "Id: " << ghiozdan.idGhiozdan << "; ";
		out << "Nume: " << ghiozdan.numeGhiozdan << "; ";
		out << "Numar buzunare: ";
		if (ghiozdan.nrBuzunare != nullptr) {
			for (int i = 0; i < ghiozdan.idGhiozdan; i++) {
				out << " " << ghiozdan.nrBuzunare[i] << ";";
			}
		}
		out << "Latime buzunare: ";
		if (ghiozdan.latimeBuzunare != nullptr) {
			for (int i = 0; i < *ghiozdan.nrBuzunare; i++) {
				out << " " << ghiozdan.latimeBuzunare[i] << ";";
			}
		}
		out << endl;
		return out;
	}*/

	//destructor
	~Ghiozdan() {
		delete[]this->latimeBuzunare;
	}
};

int main() {
	Ghiozdan ghiozdan1;
	ghiozdan1.afisare();

	Ghiozdan ghiozdan2(new int(3), new float[3] {20, 30, 49}, "Nike", 1);
	ghiozdan2.afisare();

	cout << ghiozdan2;
}
#include <iostream>

using namespace std;

class Casa {
public:
	int nrCamere;
	float suprafata;
	const int idCasa;
	static int nrCasa;
	string* tipCamera;

	static int getnrCasa() {
		return nrCasa;
	}

	Casa(int nrCamere, float suprafata, string* tipCamera) :idCasa(nrCasa) {
		nrCasa++;
		this->nrCamere = nrCamere;
		this->suprafata = suprafata;
		this->tipCamera = new string[nrCamere];
		for (int i = 0; i < nrCamere; i++) {
			this->tipCamera[i] = tipCamera[i];
		}

	}
	Casa() :idCasa(nrCasa++) {
		this->nrCamere =nrCamere ;
		this->suprafata = 520.6;
		this->tipCamera = NULL;
			
	}
	Casa(int nrCamere,  string* tipCamera) :idCasa(nrCasa) {
		nrCasa++;
		this->nrCamere = nrCamere;
		this->suprafata = 720.5;
		this->tipCamera = new  string[nrCamere];
		for (int i = 0; i < nrCamere; i++) {
			this->tipCamera[i] = tipCamera[i];
		}
		cout << endl;
	}
	~Casa() {
		if (this->tipCamera != NULL) {
			delete[]this->tipCamera;
		}
			
	}
	void afisareCasa() {
		cout << "Casa cu idul " << idCasa << " are o suprafata de " << suprafata << " mp si are " << nrCamere << " camere,respectiv: " << endl;
		if (nrCamere > 0) {
			for (int i = 0; i < nrCamere; i++) {
				cout << tipCamera[i] << " ";
			}

		}
		else
			cout << "Casa nu are camere" << endl;
	}
};

int Casa::nrCasa = 0;
class Curte {
public:
	int nrAnimale;
	string* Animale;
	float lungime;
	const int idCurte;
	static int nrCurte;
	bool fantana;

	static int getnrCurte() {
		return nrCurte;
	}


	Curte(int nrAnimale,string* Animale) :idCurte(nrCurte) {
		nrCurte++;
		this->nrAnimale = nrAnimale;
		this->fantana = true;
		this->lungime = 30;
		this->Animale = new string[nrAnimale];
		for (int i = 0; i < nrAnimale; i++) {
			this->Animale[i] = Animale[i];
		}

	}
	Curte() :idCurte(nrCurte++) {
		this->lungime = 30;
		this->nrAnimale = 0;
		this->fantana = false;
		this->Animale = NULL;
	}
	Curte(bool fantana,float lungime,int nrAnimale, string* Animale) :idCurte(nrCurte) {
		nrCurte++;
		this->fantana = fantana;
		this->lungime = lungime;
		this->nrAnimale = nrAnimale;
		this->Animale = new string[nrAnimale];
		for (int i = 0; i < nrAnimale; i++) {
			this->Animale[i] = Animale[i];
		}

	}
	~Curte() {
		if (this->Animale != NULL) {
			delete[]this->Animale;
		}
	}
	void afisareCurte() {
		cout <<"Curtea cu idul "<<idCurte<<" are o lungime de " << lungime << " m si are un numar de " <<nrAnimale<<" animale:";
		if (nrAnimale > 0) {
			for (int i = 0; i < nrAnimale; i++) {
				cout << Animale[i] << " ";
			}
			cout << endl;
		}
		else
			cout << " 0,Deci curtea nu are animale" << endl;

		if (fantana == true) {
			cout << "Curtea are fantana" << endl;
		}
		else
			cout << "Curtea nu are fantana" << endl;
	}

};
int Curte::nrCurte = 0;
class Camara {
public:
	int nrBorcane;
	float latime;
	string* tipBorcan;
	const int idCamara;
	static int nrCamara;

	static int getnrCamara() {
		return nrCamara;
	}

	Camara(int nrBorcane, string* tipBorcan) :idCamara(nrCamara) {
		nrCamara++;
		this->nrBorcane = nrBorcane;
		this->latime = 4;
		this->tipBorcan = new string[nrBorcane];
		for (int i = 0; i < nrBorcane; i++) {
			this->tipBorcan[i] = tipBorcan[i];
		}
	}
	Camara(int nrBorcane, float latime, string* tipBorcan) :idCamara(nrCamara) {
		nrCamara++;
		this->nrBorcane = nrBorcane;
		this->latime = latime;
		this->tipBorcan = new string[nrBorcane];
		for (int i = 0; i < nrBorcane; i++) {
			this->tipBorcan[i] = tipBorcan[i];
		}
	}
	Camara() :idCamara(nrCamara++) {
		this->nrBorcane = 0;
		this->latime = 5;
		this->tipBorcan = NULL;
	}
	~Camara() {
		if (this->tipBorcan != NULL) {
			delete[]this->tipBorcan;
		}
	}
	void afisareCamara() {
		cout << "Camara cu idul " << idCamara << " are o latime de " << latime << " m,si un numar de borcane egal cu " << nrBorcane<<" respectiv: ";
		if (nrBorcane > 0) {
			for (int i = 0; i < nrBorcane; i++) {
				cout << tipBorcan[i] << " ";
			}
			cout << endl;
		}
		else
			cout << "Camara nu are borcane" << endl;
		
			
		
	}
};
int Camara:: nrCamara = 0;
void main() {
	string* tipcamera = new string[4];
	tipcamera[0] = "Dormitor";
	tipcamera[1] = "Bucatarie";
	tipcamera[2] = "Baie";
	tipcamera[3] = "Hol";

	Casa casa1;
	casa1.afisareCasa();
	Casa casa2(3, tipcamera);
	casa2.afisareCasa();
	cout << endl;
	Casa casa3(4, 678.5, tipcamera);
	casa3.afisareCasa();
	cout << "Au fost inregistrate " << Casa::getnrCasa() << " case";
	cout << endl;


	string* Animale = new string[3];
	Animale[0] = "Gaini";
	Animale[1] = "Rate";
	Animale[2] = "Iepuri";
	
	Curte curte1(3, Animale);
	curte1.afisareCurte();
	Curte curte2;
	curte2.afisareCurte();
	Curte curte3(true, 45.7,2, Animale);
	curte3.afisareCurte();
	cout << "Au fost inregistrate " << Curte::getnrCurte() << " curti";
	cout << endl;

	string* tipBorcan = new string[3];
	tipBorcan[0] = "Gem";
	tipBorcan[1] = "Zacusca";
	tipBorcan[2] = "Muraturi";

	Camara camara1(2, tipBorcan);
	camara1.afisareCamara();
	Camara camara2(3, 3.6, tipBorcan);
	camara2.afisareCamara();
	Camara camara3;
	camara3.afisareCamara();
	cout << "Au fost inregistrate " << Camara::getnrCamara() << " camari";


}
	
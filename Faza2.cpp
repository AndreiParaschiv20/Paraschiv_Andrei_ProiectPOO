#include <iostream>

using namespace std;

class Casa {
private:
	int nrCamere;
	float suprafata;
	const int idCasa;
	static int nrCasa;
	string* tipCamera;
public:
	//getteri
	static int getnrCasa() {
		return nrCasa;
	}
	int getnrCamere() {
		return nrCamere;
	}
	float getsuprafata() {
		return suprafata;
	}
	string* gettipCamera() {
		return tipCamera;
	}
	//setteri
	void setsuprafata(float suprafata) {
		this->suprafata = suprafata;
	}
	void settipCamera(string* tipCamera, const int nrCamere) {
		if (nrCamere > 0) {
			if (this->tipCamera != NULL) {
				delete[]this->tipCamera;
			}
			this->nrCamere = nrCamere;
			this->tipCamera = new string[nrCamere];
			for (int i = 0; i < nrCamere; i++) {
				this->tipCamera[i] = tipCamera[i];
			}
		}
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
		this->nrCamere = nrCamere;
		this->suprafata = 520.6;
		this->tipCamera = NULL;

	}
	Casa(int nrCamere, string* tipCamera) :idCasa(nrCasa) {
		nrCasa++;
		this->nrCamere = nrCamere;
		this->suprafata = 720.5;
		this->tipCamera = new  string[nrCamere];
		for (int i = 0; i < nrCamere; i++) {
			this->tipCamera[i] = tipCamera[i];
		}
		cout << endl;
	}

	Casa(const Casa& c) :idCasa(nrCasa++) {
		this->nrCamere = c.nrCamere;
		this->suprafata = c.suprafata;
		this->tipCamera = new string[c.nrCamere];
		for (int i = 0; i < c.nrCamere; i++) {
			this->tipCamera[i] = c.tipCamera[i];
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
	friend string gettipCamera(const Casa& g);
};

string gettipCamera(const Casa& g) {
	string aux = " ";
	for (int i = 0; i < g.nrCamere; i++) {
		aux += g.tipCamera[i] + ", ";
	}
	cout << "Camerele pentru casa " << g.idCasa + 1 << " sunt: " << endl;
	return aux;
}



int Casa::nrCasa = 0;
class Curte {
private:
	int nrAnimale;
	string* Animale;
	float lungime;
	const int idCurte;
	static int nrCurte;
	bool fantana;
public:
	//getteri
	static int getnrCurte() {
		return nrCurte;
	}
	int getnrAnimale() {
		return nrAnimale;
	}
	string* getAnimale() {
		return Animale;
	}
	float getlungime() {
		return lungime;
	}
	bool getfantana() {
		return fantana;
	}

	//setteri
	void setlungime(float lungime) {
		this->lungime = lungime;
	}
	void setfantana(bool fantana) {
		this->fantana = fantana;
	}
	void setAnimale(string* Animale, const int nrAnimale) {
		if (nrAnimale > 0) {
			if (this->Animale != NULL) {
				delete[]this->Animale;
			}
			this->nrAnimale = nrAnimale;
			this->Animale = new string[nrAnimale];
			for (int i = 0; i < nrAnimale; i++) {
				this->Animale[i] = Animale[i];
			}
		}
	}


	Curte(int nrAnimale, string* Animale) :idCurte(nrCurte) {
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
	Curte(bool fantana, float lungime, int nrAnimale, string* Animale) :idCurte(nrCurte) {
		nrCurte++;
		this->fantana = fantana;
		this->lungime = lungime;
		this->nrAnimale = nrAnimale;
		this->Animale = new string[nrAnimale];
		for (int i = 0; i < nrAnimale; i++) {
			this->Animale[i] = Animale[i];
		}

	}

	Curte(const Curte& u) : idCurte(nrCurte++) {
		this->nrAnimale = u.nrAnimale;
		this->lungime = u.lungime;
		this->Animale = new string[u.nrAnimale];
		for (int i = 0; i < u.nrAnimale; i++) {
			this->Animale[i] = u.Animale[i];
		}
		cout << endl;
	}
	~Curte() {
		if (this->Animale != NULL) {
			delete[]this->Animale;
		}
	}
	void afisareCurte() {
		cout << "Curtea cu idul " << idCurte << " are o lungime de " << lungime << " m si are un numar de " << nrAnimale << " animale:";
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
	friend string getAnimale(const Curte& c);
};
string getAnimale(const Curte& c) {
	string aux1 = " ";
	for (int i = 0; i < c.nrAnimale; i++) {
		aux1 += c.Animale[i] + ", ";
	}
	cout << "Animalele pentru curtea " << c.idCurte + 1 << " sunt: " << endl;
	return aux1;
}
int Curte::nrCurte = 0;
class Camara {
private:
	int nrBorcane;
	float latime;
	string* tipBorcan;
	const int idCamara;
	static int nrCamara;
public:
	//getteri
	static int getnrCamara() {
		return nrCamara;
	}
	int getnrBorcane() {
		return nrBorcane;
	}
	float getlatime() {
		return latime;
	}
	string* gettipBorcan() {
		return tipBorcan;
	}
	//setteri
	void setlatime(float latime) {
		this->latime = latime;
	}
	void settipBorcan(string* tipBorcan, const int nrBorcane) {
		if (nrBorcane > 0) {
			if (this->tipBorcan != NULL) {
				delete[]this->tipBorcan;
			}
			this->nrBorcane = nrBorcane;
			this->tipBorcan = new string[nrBorcane];
			for (int i = 0; i < nrBorcane; i++) {
				this->tipBorcan[i] = tipBorcan[i];
			}
		}
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
	Camara(const Camara& r) :idCamara(nrCamara++) {
		this->nrBorcane = r.nrBorcane;
		this->latime = r.latime;
		this->tipBorcan= new string[r.nrBorcane];
		for (int i = 0; i < r.nrBorcane; i++) {
			this->tipBorcan[i] = r.tipBorcan[i];
		}
		cout << endl;
	}
	~Camara() {
		if (this->tipBorcan != NULL) {
			delete[]this->tipBorcan;
		}
	}
	void afisareCamara() {
		cout << "Camara cu idul " << idCamara << " are o latime de " << latime << " m,si un numar de borcane egal cu " << nrBorcane << " respectiv: ";
		if (nrBorcane > 0) {
			for (int i = 0; i < nrBorcane; i++) {
				cout << tipBorcan[i] << " ";
			}
			cout << endl;
		}
		else
			cout << "Camara nu are borcane" << endl;



	}
	friend string gettipBorcan(const Camara& b);
};
string gettipBorcan(const Camara& b) {
	string aux2 = " ";
	for (int i = 0; i < b.nrBorcane; i++) {
		aux2 += b.tipBorcan[i] + ", ";
	}
	cout << "Borcanele din camara " << b.idCamara + 1 << " sunt: " << endl;
	return aux2;
}



int Camara::nrCamara = 0;
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
	Casa casa4 = casa3;
	casa4.afisareCasa();
	cout << endl;
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
	Curte curte3(true, 45.7, 2, Animale);
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
	cout << "Au fost inregistrate " << Camara::getnrCamara() << " camari" << endl;

	cout << gettipCamera(casa3) << endl;
	cout << gettipBorcan(camara2) << endl;
	cout << getAnimale(curte1) << endl;

	cout << casa2.getnrCasa() << endl << casa2.getnrCamere() << endl << casa2.getsuprafata() << endl;
	int auxCasa = casa2.getnrCamere();
	int j = 0;
	while (j < auxCasa) {
		cout << *(casa2.gettipCamera() + j) << endl;
		j++;
	}

	cout << curte3.getnrCurte() << endl << curte3.getnrAnimale() << endl << "Daca este 1, curtea are fanatana,daca este 0 ,curtea nu are fantana: " << curte3.getfantana() << endl << curte3.getlungime() << endl;
	int auxCurte = curte3.getnrAnimale();
	int c = 0;
	while (c < auxCurte) {
		cout << *(curte3.getAnimale() + c) << endl;
		c++;
	}

	cout << camara1.getnrCamara() << endl << camara1.getlatime() << endl << camara1.getnrCamara() << endl;
	int auxCamara = camara1.getnrBorcane();
	int b = 0;
	while (b < auxCamara) {
		cout << *(camara1.gettipBorcan() + b) << endl;
		b++;
	}
	
	curte3.setfantana(0);
	curte3.setAnimale(Animale, 3);
	curte3.setlungime(74.5);
	curte3.afisareCurte();
	curte3.afisareCurte();

	casa2.setsuprafata(505.6);
	casa2.settipCamera(tipcamera,2);
	casa2.afisareCasa();

	camara1.setlatime(56);
	camara1.settipBorcan(tipBorcan,2);
	camara1.afisareCamara();
	
}


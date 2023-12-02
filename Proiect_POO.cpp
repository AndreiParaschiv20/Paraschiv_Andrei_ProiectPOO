#include <iostream>
#include<fstream>

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
	void settipCamera(string* tipCamera,const int nrCamere) {
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
		cout << endl;

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

	Casa operator=(const Casa& c) {
		if (this != &c) {
			this->suprafata = c.suprafata;
			this->nrCamere = c.nrCamere;
			if (this->tipCamera != NULL) {
				delete[]this->tipCamera;
			}
			this->tipCamera = new string[c.nrCamere];
			for (int i = 0; i < c.nrCamere; i++) {
				this->tipCamera[i] = c.tipCamera[i];
			}
		}
		return *this;
	}

	Casa operator+=(const Casa& f) {
		int auxnrCamere = this->nrCamere + f.nrCamere;
		this->suprafata += f.suprafata;
		string* auxtipCamera = new string[auxnrCamere];
		for (int i = 0; i < this->nrCamere; i++) {
			auxtipCamera[i] = this->tipCamera[i];
		}
		for (int i = this->nrCamere; i < auxnrCamere; i++) {
			auxtipCamera[i] = f.tipCamera[i - this->nrCamere];
		}
		this->nrCamere = auxnrCamere;
		if (this->tipCamera != NULL) {
			delete[]this->tipCamera;
		}
		this->tipCamera = auxtipCamera;
		return *this;
	}

	Casa operator+(Casa c) {
		Casa aux = *this;
		aux.suprafata = this->suprafata + c.suprafata;
		aux.nrCamere = this->nrCamere + c.nrCamere;
		if (aux.tipCamera != NULL) {
			delete[]aux.tipCamera;
		}
		aux.tipCamera = new string[aux.nrCamere];
		for (int i = 0; i < this->nrCamere; i++) {
			aux.tipCamera[i] = this->tipCamera[i];
		}
		for (int i = this->nrCamere; i < aux.nrCamere; i++) {
			aux.tipCamera[i] = c.tipCamera[i - this->nrCamere];
		}
		return aux;

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
	friend ostream& operator<<(ostream& afis, const Casa& o);
	friend istream& operator>>(istream& cit, Casa& casa);
};


ostream& operator<<(ostream& afis, const Casa& o) {
	afis << "Casa cu idul " << o.idCasa << " are o suprafata de " << o.suprafata << " si un numar de " << o.nrCamere << " camere: ";
	if (o.nrCamere > 0) {
		for (int i = 0; i < o.nrCamere; i++) {
			afis << o.tipCamera[i] << " ";
		}
	}
	else {
		afis << "NA";
	}
	afis << endl;
	return afis;
}

istream& operator>>(istream& cit, Casa& casa) {
	cout << "Suprafata casei: ";
	cit >> casa.suprafata;
	cout << "Numarul de camere din casa: ";
	cit >> casa.nrCamere;
	if (casa.tipCamera != NULL) {
		delete[]casa.tipCamera;
	}
	cout << "Camerele sunt: ";
	casa.tipCamera = new string[casa.nrCamere];
	for (int i = 0; i < casa.nrCamere; i++) {
		cit >> casa.tipCamera[i];
		cout << casa.tipCamera[i];
	}
	
	return cit;
}


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
		this->fantana = u.fantana;
		this->Animale = new string[u.nrAnimale];
		for (int i = 0; i < u.nrAnimale; i++) {
			this->Animale[i] = u.Animale[i];
		}
		cout << endl;
	}

	Curte operator=(const Curte& u) {
		if (this != &u) {
			this->lungime = u.lungime;
			this->nrAnimale = u.nrAnimale;
			this->fantana = u.fantana;
			if (this->Animale != NULL) {
				delete[]this->Animale;
			}
			this->Animale = new string[u.nrAnimale];
			for (int i = 0; i < u.nrAnimale; i++) {
				this->Animale[i] = u.Animale[i];
			}
		}
		return *this;
	}

	bool operator!=(Curte& cr) {
		return this->lungime != cr.lungime && this->nrAnimale != cr.nrAnimale;
	}

	~Curte() {
		if (this->Animale != NULL) {
			delete[]this->Animale;
		}
	}

	string& operator[](int i) {
		if (i >= 0 && i < nrAnimale) {
			return Animale[i];
		}
	}

	Curte operator+=(const Curte& cr) {
		int auxnrAnimale = this->nrAnimale + cr.nrAnimale;
		this->lungime += cr.lungime;
		string* auxAnimale = new string[auxnrAnimale];
		for (int i = 0; i < this->nrAnimale; i++) {
			auxAnimale[i] = this->Animale[i];
		}
		for (int i = this->nrAnimale; i < auxnrAnimale; i++) {
			auxAnimale[i] = cr.Animale[i - this->nrAnimale];
		}
		this->nrAnimale = auxnrAnimale;
		if (this->Animale != NULL) {
			delete[]this->Animale;
		}
		this->Animale = auxAnimale;
		return *this;
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
	friend ostream& operator<<(ostream& afis, const Curte& o);
};

ostream& operator<<(ostream& afis, const Curte& o) {
	afis << "Curtea cu idul " << o.idCurte << " are o lungime de " << o.lungime << " m si are un numar de " << o.nrAnimale << " animale:";
	if (o.nrAnimale > 0) {
		for (int i = 0; i < o.nrAnimale; i++) {
			afis << o.Animale[i] << " ";
		}
		afis << endl;
	}
	else
		afis << " 0, Deci curtea nu are animale" << endl;

	if (o.fantana == true) {
		afis << "Curtea are fantana" << endl;
	}
	else
		afis << "Curtea nu are fantana" << endl;

	return afis;
}



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
		this->tipBorcan = new string[r.nrBorcane];
		for (int i = 0; i < r.nrBorcane; i++) {
			this->tipBorcan[i] = r.tipBorcan[i];
		}
		cout << endl;
	}
	Camara operator=(const Camara& r) {
		if (this != &r) {
			this->latime = r.latime;
			this->nrBorcane = r.nrBorcane;
			if (this->tipBorcan != NULL) {
				delete[]this->tipBorcan;
			}
			this->tipBorcan = new string[r.nrBorcane];
			for (int i = 0; i < r.nrBorcane; i++) {
				this->tipBorcan[i] = r.tipBorcan[i];
			}
		}
		return *this;
	}



	~Camara() {
		if (this->tipBorcan != NULL) {
			delete[]this->tipBorcan;
		}
	}

	friend istream& operator>>(istream& citire, Camara& cam) {
		cout << "Numarul de borcane din camara: ";
		citire >> cam.nrBorcane;

		cout << "Latimea camerei: ";
		citire >> cam.latime;

		cout << "Tipurile de borcane (separate prin spatii): ";
		if (cam.tipBorcan != nullptr) {
			delete[] cam.tipBorcan;
		}
		cam.tipBorcan = new string[cam.nrBorcane];
		for (int i = 0; i < cam.nrBorcane; i++) {
			citire >> cam.tipBorcan[i];
		}

		return citire;
	}



	friend  bool operator==(const Camara& c2, const Camara& c3) {
		if (c2.nrBorcane != c3.nrBorcane) {
			return false;
		}

		if (c2.latime != c3.latime) {
			return false;
		}

		for (int i = 0; i < c2.nrBorcane; i++) {
			if (c2.tipBorcan[i] != c3.tipBorcan[i]) {
				return false;
			}
		}

		return true;
	}

	string& operator[](int i) {
		if (i >= 0 && i < nrBorcane) {
			return tipBorcan[i];
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
	friend ostream& operator <<(ostream& afis, const Camara& o);
};

class Strada {
private:
	string nume;
	int nrCase;
	Casa casa;
public:
	Strada() {
		this->nume = "Pravat";
		this->nrCase = 30;

	}
	Strada(string nume, int nrCase, Casa& casa) {
		this->nume = nume;
		this->nrCase = nrCase;
		this->casa = casa;
	}
	Strada(Casa& casa) {
		this->nume = "Strandului";
		this->nrCase = 40;
		this->casa = casa;
	}
	
	void afisareStrada() {
		cout << "Numele strazii este: " << nume << " si are " << nrCase << " case" << endl;
		casa.afisareCasa();
	}
	void setnrCase(int nrCase) {
		this->nrCase = nrCase;
	}
	void setNume(string nume) {
		this->nume = nume;
	}
	string getNume() {
		return nume;
	}
	int getnrCase() {
		return nrCase;
	}
	int getStrada() {
		cout << "Casa " << casa.getnrCasa() << "se afla pe strada " << nume << " ,strada cu un numar de case egal cu ";
		return nrCase;
	}
	void setStrada(Casa& casa) {
		this->casa = casa;
	}

	//supraincarcarea operatorului =
	Strada operator=(const Strada& str) {
		this->nume = str.nume;
		this->nrCase = str.nrCase;
		this->casa = str.casa;
		return *this;
	}

	//supraincarcarea operatorului <<
	friend ostream& operator<<(ostream& afisare, const Strada& st) {
		afisare << "Numele strazii este " << st.nume << endl;
		afisare << "Strada are multe case,respectiv: " << st.nrCase << endl;
		afisare << "Informatii legate de o casa: " << st.casa << endl;
		return afisare;
	}
	//supraincarcarea operatorului >>
	friend istream& operator>>(istream& citire, Strada& stra) {
		cout << "Numele strazii: ";
		citire >> stra.nume;
		cout << "Numarul de case de pe strada: ";
		citire >> stra.nrCase;
		cout << "Casa de pe strada: ";
		citire >> stra.casa;
		return citire;
	}

};

ostream& operator<<(ostream& afis, const Camara& o) {
	afis << "Camara cu idul " << o.idCamara << " are o latime de " << o.latime << " m, si un numar de borcane egal cu " << o.nrBorcane << " respectiv: ";
	if (o.nrBorcane > 0) {
		for (int i = 0; i < o.nrBorcane; i++) {
			afis << o.tipBorcan[i] << " ";
		}
		afis << endl;
	}
	else
		afis << "Camara nu are borcane" << endl;

	return afis;
}

string gettipBorcan(const Camara& b) {
	string aux2 = " ";
	for (int i = 0; i < b.nrBorcane; i++) {
		aux2 += b.tipBorcan[i] + ", ";
	}
	cout << "Borcanele din camara " << b.idCamara + 1 << " sunt: " << endl;
	return aux2;
}
int Camara::nrCamara = 0;

class Rulota :public Casa {
private:
	char* marca;
	float inaltimeRulota;
public:
	Rulota() :Casa() {
		this->inaltimeRulota = 2.6;
		this->marca = new char[strlen("Mercedes") + 1];
		strcpy_s(this->marca, strlen("Mercedes") + 1, "Mercedes");

	}
	Rulota(const char* marca, float inaltimeRulota) :Casa() {
		this->inaltimeRulota = inaltimeRulota;
		this->marca = new char[strlen(marca) + 1];
		strcpy_s(this->marca, strlen(marca) + 1, marca);
	}
	Rulota(const Rulota& r) :Casa(r) {
		this->inaltimeRulota = r.inaltimeRulota;
		this->marca = new char[strlen(r.marca) + 1];
		strcpy_s(this->marca, strlen(r.marca) + 1, r.marca);
	}
	~Rulota() {
		if (this->marca) {
			delete[]this->marca;
		}
	}

	Rulota operator=(const Rulota& r) {
		if (this != &r) {
			Casa::operator=(r);
			this->inaltimeRulota = r.inaltimeRulota;
			if (this->marca) {
				delete[]this->marca;
			}
			this->marca = new char[strlen(r.marca) + 1];
			strcpy_s(this->marca, strlen(r.marca) + 1, r.marca);
		}
		return *this;
	}
	friend ostream& operator<<(ostream& rul, const Rulota& r) {
		rul << (Casa)r;
		rul << r.marca << " ";
		rul << r.inaltimeRulota << endl;
		return rul;
	}

	friend istream& operator>>(istream& rl,  Rulota& r) {
		rl >> (Casa&)r;
		cout << "Inaltimea rulotei este: ";
		rl >> r.inaltimeRulota;
		if (r.marca) {
			delete[]r.marca;
		}
		cout << "Marca rulotei este: ";
		char buffer[20];
		rl >> buffer;
		r.marca = new char[strlen(buffer) + 1];
		strcpy_s(r.marca, strlen(buffer) + 1, buffer);
		return rl;
		

	}

   };

class Beci :public Camara {
private:
	float adancime;
	int nrRafturi;
	char* culoareRaft;
public:
	Beci() :Camara() {
		this->adancime = 2.1;
		this->nrRafturi = 30;
		this->culoareRaft = new char[strlen("Maro") + 1];
		strcpy_s(this->culoareRaft, strlen("Maro") + 1, "Maro");

	}
	Beci(const char* culoareRaft, float adancime,int nrRafturi) :Camara() {
		this->adancime = adancime;
		this->nrRafturi = nrRafturi;
		this->culoareRaft = new char[strlen(culoareRaft) + 1];
		strcpy_s(this->culoareRaft, strlen(culoareRaft) + 1, culoareRaft);
	}
	Beci(const Beci& b) : Camara(b) {
		this->adancime = b.adancime;
		this->nrRafturi = b.nrRafturi;
		this->culoareRaft = new char[strlen(b.culoareRaft) + 1];
		strcpy_s(this->culoareRaft, strlen(b.culoareRaft) + 1, b.culoareRaft);
	}
	~Beci() {
		if (this->culoareRaft) {
			delete[]this->culoareRaft;
		}
	}

	Beci operator=(const Beci& b) {
		if (this != &b) {
			Camara::operator=(b);
			this->adancime = b.adancime;
			this->nrRafturi = b.nrRafturi;
			if (this->culoareRaft) {
				delete[]this->culoareRaft;
			}
			this->culoareRaft = new char[strlen(b.culoareRaft) + 1];
			strcpy_s(this->culoareRaft, strlen(b.culoareRaft) + 1, b.culoareRaft);
		}
		return *this;
	}
	friend ostream& operator<<(ostream& geam, const Beci& bc) {
		geam << (Camara)bc;
		geam << bc.adancime << " ";
		geam << bc.nrRafturi << " ";
		geam << bc.culoareRaft << endl;
		return geam;
	}

	friend istream& operator>>(istream& usa, Beci& be) {
		usa >> (Camara&)be;
		cout << "Adancimea la care se afla beciul: ";
		usa >> be.adancime;
		cout << "Nr de rafturi din cama este: ";
		usa >> be.nrRafturi;
		if (be.culoareRaft) {
			delete[]be.culoareRaft;
		}
		cout << "Culoarea raftului: ";
		char buffer[20];
		usa >> buffer;
		be.culoareRaft = new char[strlen(buffer) + 1];
		strcpy_s(be.culoareRaft, strlen(buffer) + 1, buffer);
		return usa;


	}
};



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
	casa2.settipCamera(tipcamera, 2);
	casa2.afisareCasa();

	camara1.setlatime(56);
	camara1.settipBorcan(tipBorcan, 2);
	camara1.afisareCamara();


	Casa c1 = casa1;
	c1.afisareCasa();
	casa1 += casa2;
	casa1.afisareCasa();
	cout << casa3;
	Casa c4;
	c4 = casa1 + casa2;
	c4.afisareCasa();

	Curte u1 = curte2;
	u1.afisareCurte();
	if (curte1 != curte2) {
		cout << "Cele doua curti sunt diferite" << endl;
	}
	else
		cout << "Cele doua curti sunt identice" << endl;

	curte3[2] = "Curca";
	cout << curte3[2] << endl;
	curte3.afisareCurte();
	curte2 += curte3;
	curte2.afisareCurte();


	Camara r1 = camara3;
	r1.afisareCamara();
	if (camara1 == camara2) {
		cout << "Cele doua camari sunt identice." << endl;
	}
	else {
		cout << "Cele doua camari nu sunt identice." << endl;
	}

	camara2[1] = "Dulceata";
	cout << camara2[1] << endl;
	camara2.afisareCamara();


	Strada strada("Pravat", 35, casa2);
	Strada strada2(casa1);
	Strada strada3(casa3);
	Strada strada4(casa4);
	Strada strada5;
	strada5 = strada;
	strada.afisareStrada();
	strada2.getNume();
	cout << strada.getStrada() << endl;
	strada.afisareStrada();
	strada3.afisareStrada();
	cout << endl;
	cout << strada3;
	cin >> strada4;
	cout << strada4;





	//// Vector de obiecte de tip Casa
	//Casa* vectorCase = new Casa[3];
	//for (int i = 0; i < 3; i++) {
	//	cout << "Introduceti informatii pentru casa " << i + 1 << ":" << endl;
	//	int nrCamere;
	//	cout << "Numar de camere: ";
	//	cin >> nrCamere;

	//	float suprafata;
	//	cout << "Suprafata: ";
	//	cin >> suprafata;

	//	string* tipCamera = new string[nrCamere];
	//	cout << "Tipurile de camere separate prin spatiu: ";
	//	for (int j = 0; j < nrCamere; j++) {
	//		cin >> tipCamera[j];
	//	}

	//	vectorCase[i] = Casa(nrCamere, suprafata, tipCamera);
	//	delete[] tipCamera;
	//}

	//// Vector de obiecte de tip Curte
	//Curte* vectorCurti = new Curte[3];
	//for (int i = 0; i < 3; i++) {
	//	cout << "Introduceti informatii pentru curte " << i + 1 << ":" << endl;
	//	int nrAnimale;
	//	cout << "Numar de animale: ";
	//	cin >> nrAnimale;

	//	string* animale = new string[nrAnimale];
	//	cout << "Tipurile de animale separate prin spatiu: ";
	//	for (int j = 0; j < nrAnimale; j++) {
	//		cin >> animale[j];
	//	}

	//	bool fantana;
	//	cout << "Curtea are fantana? (1/0): ";
	//	cin >> fantana;

	//	float lungime;
	//	cout << "Lungimea curtii: ";
	//	cin >> lungime;

	//	vectorCurti[i] = Curte(fantana, lungime, nrAnimale, animale);
	//	delete[] animale;
	//}

	//// Vector de obiecte de tip Camara
	//Camara* vectorCamari = new Camara[3];
	//for (int i = 0; i < 3; i++) {
	//	cout << "Introduceti informatii pentru camara " << i + 1 << ":" << endl;
	//	int nrBorcane;
	//	cout << "Numar de borcane: ";
	//	cin >> nrBorcane;

	//	float latime;
	//	cout << "Latimea camerei: ";
	//	cin >> latime;

	//	string* tipBorcan = new string[nrBorcane];
	//	cout << "Tipurile de borcane separate prin spatiu: ";
	//	for (int j = 0; j < nrBorcane; j++) {
	//		cin >> tipBorcan[j];
	//	}

	//	vectorCamari[i] = Camara(nrBorcane, latime, tipBorcan);
	//	delete[] tipBorcan;
	//}

	//// Matrice de obiecte de tip Casa
	//Casa** matriceCase = new Casa * [2];
	//for (int i = 0; i < 2; i++) {
	//	matriceCase[i] = new Casa[2];
	//	for (int j = 0; j < 2; j++) {
	//		cout << "Introduceti informatii pentru casa " << i + 1 << ", rand " << j + 1 << ":" << endl;
	//		int nrCamere;
	//		cout << "Numar de camere: ";
	//		cin >> nrCamere;

	//		float suprafata;
	//		cout << "Suprafata: ";
	//		cin >> suprafata;

	//		string* tipCamera = new string[nrCamere];
	//		cout << "Tipurile de camere separate prin spatiu: ";
	//		for (int k = 0; k < nrCamere; k++) {
	//			cin >> tipCamera[k];
	//		}

	//		matriceCase[i][j] = Casa(nrCamere, suprafata, tipCamera);
	//		delete[] tipCamera;
	//	}
	//}

	//// Afișare obiecte din vectori
	//for (int i = 0; i < 3; i++) {
	//	cout << "Informatii pentru casa " << i + 1 << ":" << endl;
	//	cout << vectorCase[i];
	//}

	//for (int i = 0; i < 3; i++) {
	//	cout << "Informatii pentru curte " << i + 1 << ":" << endl;
	//	cout << vectorCurti[i];
	//}

	//for (int i = 0; i < 3; i++) {
	//	cout << "Informatii pentru camara " << i + 1 << ":" << endl;
	//	cout << vectorCamari[i];
	//}

	//// Afișare obiecte din matrice
	//for (int i = 0; i < 2; i++) {
	//	for (int j = 0; j < 2; j++) {
	//		cout << "Informatii pentru casa " << i + 1 << ", rand " << j + 1 << ":" << endl;
	//		cout << matriceCase[i][j];
	//	}
	//}

	//// Eliberare memorie
	//delete[] vectorCase;
	//delete[] vectorCurti;
	//delete[] vectorCamari;
	//for (int i = 0; i < 2; i++) {
	//	delete[] matriceCase[i];
	//}
	//delete[] matriceCase;

	ofstream afis("casa.txt", ios::out);
	afis<<casa3;
	afis.close();

	ifstream cit("casa.txt", ios::in);
	cit >> casa2;
	cout << casa2<<endl;
	cit.close();

	Curte crt;
	fstream curteAfisare("Curti.bin", ios::binary | ios::out);
	curteAfisare.write((char*)&crt, sizeof(Curte));
	curteAfisare.close();

	ofstream afisare("strada.txt", ios::out);
	afisare << strada3;
	afisare.close();

	ifstream citire("strada.txt", ios::in);
	citire >> strada2;
	cout << strada2 << endl;
	citire.close();

	Camara cmr;
	fstream camaraAfisare("Camara.bin", ios::binary | ios::out);
	camaraAfisare.write((char*)&cmr, sizeof(Camara));
	camaraAfisare.close();

	Beci b1;
	Beci b2("Negru", 1.9, 25);
	cout << b2;
	Beci b3 = b1;
	cout << b1;
	Beci b4;
	b4 = b2;
	
}

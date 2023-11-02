#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;


class Skin {
private:
    ///detalii despre skin
    string nume; ///nume skin
    string grad_uzura; ///cat de deteriorat este skin-ul
    int an_aparitie; ///in ce an a aparut
    float pret; ///pretul armei
public:
    ///Constructori
    Skin();
    Skin(string nume, string grad_uzura);
    Skin(int an_aparitie, float pret);
    Skin(string nume, string grad_uzura, int an_aparitie, float pret);
    Skin(const Skin& other);

    ///Setters & Getters
    void setNume(string nume);
    string getNume();
    void setGrad_uzura(string grad_uzura);
    string getGrad_uzura();
    void setAn_aparitie(int an_aparitie);
    int getAn_aparitie();
    void setPret(float pret);
    float getPret();

    ///Operatori
    Skin& operator=(const Skin& other);
    Skin operator++();
    Skin operator++(int);

    Skin operator+(Skin x);
    Skin operator+(float x);
    friend Skin operator+(float x, Skin skin);
    Skin operator-(float x);
    friend Skin operator-(float x, Skin skin);

    explicit operator int() const;
    bool operator<(const Skin& skin);
    bool operator==(const Skin& skin);

    friend istream& operator>>(istream& in, Skin& skin);
    friend ostream& operator<<(ostream& out, const Skin& skin);

    void tipSkin(Skin skin);

    ///Destructor
    ~Skin() {}

};

Skin::Skin() {
    this->nume = "Anonim";
    this->grad_uzura = "Anonim";
    this->an_aparitie = 0;
    this->pret = 0;
}

Skin::Skin(string nume, string grad_uzura) {
    this->nume = nume;
    this->grad_uzura = grad_uzura;
}

Skin::Skin(int an_aparitie, float pret) {
    this->an_aparitie = an_aparitie;
    this->pret = pret;
}

Skin::Skin(string nume, string grad_uzura, int an_aparitie, float pret) {
    this->nume = nume;
    this->grad_uzura = grad_uzura;
    this->an_aparitie = an_aparitie;
    this->pret = pret;
}

Skin::Skin(const Skin& skin) {
    this->nume = skin.nume;
    this->grad_uzura = skin.grad_uzura;
    this->an_aparitie = skin.an_aparitie;
    this->pret = skin.pret;
}

Skin& Skin::operator= (const Skin& skin) {
    if(this != &skin) {
        this->nume = skin.nume;
        this->grad_uzura = skin.grad_uzura;
        this->an_aparitie = skin.an_aparitie;
        this->pret = skin.pret;
    }
    return *this;
}

void Skin::setNume(string nume) {
    this->nume = nume;
}

string Skin::getNume() {
    return this->nume;
}

void Skin::setGrad_uzura(string grad_uzura) {
    this->grad_uzura = grad_uzura;
}

string Skin::getGrad_uzura() {
    return this->grad_uzura;
}

void Skin::setAn_aparitie(int an_aparitie) {
    this->an_aparitie = an_aparitie;
}

int Skin::getAn_aparitie() {
    return this->an_aparitie;
}


void Skin::setPret(float pret) {
    this->pret = pret;
}

float Skin::getPret() {
    return this->pret;
}

Skin Skin::operator++() {
    this->pret = this->pret + 1;
    return *this;
}

Skin Skin::operator++(int) {
    Skin aux = *this;
    this->pret = this->pret + 1;
    return aux;
}


Skin Skin::operator+(float x) {
    Skin aux = *this;
    aux.pret = aux.pret + x;
    return aux;
}

Skin operator+(float x, Skin skin) {
    skin.pret = skin.pret + x;
    return skin;
}

Skin Skin::operator-(float x) {
    Skin aux = *this;
    aux.pret = aux.pret - x;
    return aux;
}

Skin operator-(float x, Skin skin) {
    skin.pret = x - skin.pret;
    return skin;
}

bool Skin::operator==(const Skin& skin) {
    return this->nume == skin.nume && this->grad_uzura == skin.grad_uzura;
}

bool Skin::operator<(const Skin& skin) {
    return this->pret < skin.pret;
}

inline Skin::operator int() const {
    return int(this->pret);
}

void Skin::tipSkin(Skin skin) {
    if(skin.an_aparitie == 2022 && skin.grad_uzura == "nou")
        cout << "Skinul este nou\n";
    else cout << "Skinul nu este nou\n";
}

istream& operator>>(istream& in, Skin& skin) {
    cout << "Nume skin : ";
    in >> skin.nume;
    cout << "Gradul de uzura : ";
    in >> skin.grad_uzura;
    cout << "Anul aparitiei : ";
    in >> skin.an_aparitie;
    cout << "Pret : ";
    in >> skin.pret;
    cout << "\n";
    return in;
}

ostream& operator<<(ostream& out, const Skin& skin) {
    out << "\nNume skin : " << skin.nume;
    out << "\nGradul de uzura : " << skin.grad_uzura;
    out << "\nAnul aparitiei : " << skin.an_aparitie;
    out << "\nPret : " << skin.pret << "\n";
    return out;
}

///--------------------------------------------------------------------------

class Arma {
private:
    ///detalii despre arma
    string nume; ///nume arma
    int gloante; ///nr de gloante
    double pret; ///pretul armei IN JOC
    int nrSkins; ///Numarul de skin-uri ale armei
    vector <Skin> skins; ///ce skin-uri exista pe arma
public:
    ///Constructori
    Arma();
    Arma(string nume);
    Arma(string nume, int gloante);
    Arma(string nume, int gloante, double pret, int nrSkins, vector <Skin> skins);
    Arma(const Arma& other);

    void setPret(double pret);
    double getPret();

    ///Operatori
    Arma& operator=(const Arma& other);
    Arma operator++();
    Arma operator++(int);

    Arma operator+(Arma arma);
    Arma operator+(int x);
    friend Arma operator+(int x, Arma arma);
    Arma operator*(int x);
    friend Arma operator*(int x, Arma arma);

    explicit operator int() const;
    Skin operator[](int index);
    bool operator>(const Arma& arma);
    bool operator==(const Arma& arma);

    friend Arma operator+(Arma arma, Skin& skin);
    friend Arma operator+(Skin& skin, Arma arma);

    friend istream& operator>>(istream& in, Arma& arma);
    friend ostream& operator<<(ostream& out, const Arma& arma);

    ///Functionalitate
    void deleteSkin(int index);
    void addSkin(Skin skin);

    ///Destructor
    ~Arma() {}
};

Arma::Arma() {
    this->nume = "Anonim";
    this->gloante = 0;
    this->pret = 0;
    this->nrSkins = 0;
    this->skins = {};
}

Arma::Arma(string nume) {
    this->nume = nume;
}

Arma::Arma(string nume, int gloante) {
    this->nume = nume;
    this->gloante = gloante;
}

Arma::Arma(string nume, int gloante, double pret, int nrSkins, vector <Skin> skins) {
    this->nume = nume;
    this->gloante = gloante;
    this->pret = pret;
    this->nrSkins = nrSkins;
    this->skins = skins;
}

Arma::Arma(const Arma& arma) {
    this->nume = arma.nume;
    this->gloante = arma.gloante;
    this->pret = arma.pret;
    this->nrSkins = arma.nrSkins;
    this->skins = arma.skins;
}

Arma& Arma::operator=(const Arma& arma) {
    if(this != &arma) {
        this->nume = arma.nume;
        this->gloante = arma.gloante;
        this->pret = arma.pret;
        this->nrSkins = arma.nrSkins;
        this->skins = arma.skins;
    }
    return *this;
}

void Arma::setPret(double pret) {
    this->pret = pret;
}

double Arma::getPret() {
    return this->pret;
}


Arma Arma::operator+(int x) {
    Arma aux = *this;
    aux.gloante = aux.gloante + x;
    return aux;
}

Arma operator+(int x, Arma arma) {
    arma.gloante = arma.gloante + x;
    return arma;
}

Arma Arma::operator*(int x) {
    Arma aux = *this;
    aux.gloante = aux.gloante * x;
    return aux;
}

Arma operator*(int x, Arma arma) {
    arma.gloante = x * arma.gloante;
    return arma;
}

bool Arma::operator>(const Arma& arma) {
    return this->pret > arma.pret;
}

bool Arma::operator==(const Arma& arma) {
    return this->nume == arma.nume;
}

inline Arma::operator int() const {
    return int(this->pret);
}

Skin Arma::operator[](int index) {
    if(0 <= index && index < this->nrSkins)
        return this->skins[index];
    cout << "Index introdus gresit";
}

Arma Arma::operator+(Arma arma) {
    arma.nume = arma.nume + " , " + this->nume;
    arma.pret = arma.pret + this->pret;
    arma.gloante = arma.gloante + this->gloante;
    arma.nrSkins = arma.nrSkins + this->nrSkins;
    for(int i = arma.nrSkins; i < arma.nrSkins + this->nrSkins; i ++)
        arma.skins.push_back(this->skins[i - arma.nrSkins]);
    return arma;
}


Arma operator+(Arma arma, Skin& skin) {
    arma.skins.push_back(skin);
    return arma;
}

Arma operator+(Skin& skin, Arma arma) {
    arma.skins.push_back(skin);
    return arma;
}

void Arma::deleteSkin(int index) {
    this->nrSkins = this->nrSkins - 1;
    this->skins.erase(skins.begin() + index - 1);
}

void Arma::addSkin(Skin skin) {
    this->nrSkins = this->nrSkins + 1;
    this->skins.push_back(skin);
}

istream& operator>>(istream& in, Arma& arma) {
    cout << "Nume arma : ";
    in >> arma.nume;
    cout << "Nr gloante : ";
    in >> arma.gloante;
    cout << "Pret : ";
    in >> arma.pret;
    cout << "Numarul de skin-uri ale armei : ";
    in >> arma.nrSkins;
    cout << "Skin-urile armei : \n";
    arma.skins = vector <Skin> (arma.nrSkins);
    for(int i = 0; i < arma.nrSkins; i ++)
        in >> arma.skins[i];
    return in;
}

ostream& operator<<(ostream& out, const Arma& arma) {
    out << "\nNume arma : " << arma.nume;
    out << "\nNr gloante : " << arma.gloante;
    out << "\nPret : " << arma.pret;
    out << "\nNumarul de skin-uri ale armei : " << arma.nrSkins;
    out << "\nSkin-urile armei : ";
    for(const auto& a : arma.skins)
        out << a;
    return out;
}

///--------------------------------------------------------------------------


class Jucator {
private:
    ///detalii despre jucator
    char *nume; ///nume jucator
    string prenume; ///prenume jucator
    char initialaTata; ///initiala tatalui
    int varsta; ///varsta
    string tara; ///tara

    float* castigInUltimeleNLuni;
    int nLuni;

    int kills, deaths, assists; ///scorurile jucatorului
    int scor;

    int nr_arme;
    vector <Arma> arme; ///ce arme are

    static int contorId;
    const int idJucator;
public:
    ///Constructori
    Jucator();
    Jucator(int varsta);
    Jucator(int kills, int deaths, int assists);
    Jucator(char* nume, string prenume, char initialaTata, int varsta, string tara, int nLuni,
                 float* castigInUltimeleNLuni, int kills, int deaths, int assists, int scor, int nr_arme, vector<Arma> arme);
    Jucator(const Jucator& other);

    ///Setters & Getters
    void setNume(char *nume);
    const char* getNume();
    void setPrenume(string prenume);
    string getPrenume();
    void setInitialaTata(char initialaTata);
    char getInitialaTata();
    void setVarsta(int varsta);
    int getVarsta();
    void setTara(string tara);
    string getTara();
    void setCastigInUltimeleNLuni(float* castigInUltimeleNLuni, int nLuni);
    const float* getCastigInUltimeleNLuni() const;
    void setKills(int kills);
    int getKills();
    void setDeaths(int deaths);
    int getDeaths();
    void setAssists(int assists);
    int getAssists();
    void setScor(int scor);
    int getScor();
    Arma& getArma(int index);
    static int getContorId();
    int getIdJucator();


    ///Operatori
    Jucator& operator=(const Jucator& other);
    Jucator operator++();
    Jucator operator++(int);

    Jucator operator+(int x);
    friend Jucator operator+(int x, Jucator jucator);
    Jucator operator*(int x);
    friend Jucator operator*(int x, Jucator jucator);
    friend Jucator operator+(Jucator jucator, Arma& arma);
    friend Jucator operator+(Arma& arma, Jucator jucator);
    explicit operator int() const;
    Arma& operator[](int index);
    bool operator<(const Jucator& jucator);
    bool operator==(const Jucator& jucator);

    friend istream& operator>>(istream& in, Jucator& jucator);
    friend ostream& operator<<(ostream& out, const Jucator& jucator);

    ///Functionalitate
    void deleteArma(int index);
    void addArma(Arma arma);

    ///Destructor
    ~Jucator();
};

Jucator::Jucator():idJucator(contorId++) {
    this->nume = new char[strlen("Anonim") + 1];
    strcpy(this->nume, "Anonim");

    this->prenume = "Anonim";
    this->initialaTata = 'W';
    this->varsta = 0;
    this->tara = "Anonim";

    this->nLuni = 0;
    this->kills = 0;
    this->deaths = 0;
    this->assists = 0;

    this->castigInUltimeleNLuni = NULL;
    this->nr_arme = 0;
    this->arme = {};
}

Jucator::Jucator(int varsta):idJucator(contorId++) {
    this->varsta = varsta;
}

Jucator::Jucator(int kills, int deaths, int assists):idJucator(contorId++) {
    this->kills = kills;
    this->deaths = deaths;
    this->assists = assists;
}

Jucator::Jucator(char* nume, string prenume, char initialaTata, int varsta, string tara, int nLuni,
                 float* castigInUltimeleNLuni, int kills, int deaths, int assists, int scor, int nr_arme, vector<Arma> arme):idJucator(contorId++) {
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
    this->prenume = prenume;
    this->initialaTata = initialaTata;
    this->varsta = varsta;
    this->tara = tara;

    this->nLuni = nLuni;
    this->kills = kills;
    this->deaths = deaths;
    this->assists = assists;
    this->scor = scor;
    this->castigInUltimeleNLuni = new float[this->nLuni];
    for(int i = 0; i < nLuni; i ++)
        this->castigInUltimeleNLuni[i] = castigInUltimeleNLuni[i];
    this->nr_arme = nr_arme;
    for(int i = 0; i < nr_arme; i ++)
        this->arme[i] = arme[i];
}

Jucator::Jucator(const Jucator& other):idJucator(other.idJucator){
    this->nume = new char[strlen(other.nume) + 1];
    strcpy(this->nume, other.nume);
    this->prenume = other.prenume;
    this->initialaTata = other.initialaTata;
    this->varsta = other.varsta;
    this->tara = other.tara;
    this->nLuni = other.nLuni;
    this->castigInUltimeleNLuni = new float[other.nLuni];
    for(int i = 0; i < nLuni; i ++)
        this->castigInUltimeleNLuni[i] = other.castigInUltimeleNLuni[i];
    this->scor = other.scor;
    this->kills = other.kills;
    this->deaths = other.deaths;
    this->assists = other.assists;
    this->nr_arme = other.nr_arme;
    this->arme = other.arme;
    ///for(int i = 0; i < nr_arme; i ++)
       /// this->arme.push_back(other.arme[i]);
}

Jucator& Jucator::operator=(const Jucator& other) {
    if(this != &other) {
        if(this->nume != NULL)
            delete[] nume;
        this->nume = new char[strlen(other.nume) + 1];
        strcpy(this->nume, other.nume);
        this->prenume = other.prenume;
        this->initialaTata = other.initialaTata;
        this->varsta = other.varsta;
        this->tara = other.tara;
        this->nLuni = other.nLuni;
        this->castigInUltimeleNLuni = new float[other.nLuni];
        for(int i = 0; i < nLuni; i ++)
            this->castigInUltimeleNLuni[i] = other.castigInUltimeleNLuni[i];
        this->kills = other.kills;
        this->deaths = other.deaths;
        this->assists = other.assists;
        this->scor = other.scor;
        this->nr_arme = other.nr_arme;
        this->arme = other.arme;
    }
    return *this;
}

void Jucator::setNume(char *nume) {
    if(this->nume != NULL)
        delete[] this->nume;
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
}

const char* Jucator::getNume() {
    return this->nume;
}

int Jucator::getContorId() {
    return Jucator::contorId;
}

int Jucator::getIdJucator() {
    return this->idJucator;
}

void Jucator::setPrenume(string prenume) {
    this->prenume = prenume;
}

string Jucator::getPrenume() {
    return this->prenume;
}

void Jucator::setInitialaTata(char initialaTata) {
    this->initialaTata = initialaTata;
}

char Jucator::getInitialaTata() {
    return this->initialaTata;
}

void Jucator::setVarsta(int varsta) {
    this->varsta = varsta;
}

int Jucator::getVarsta() {
    return this->varsta;
}

void Jucator::setTara(string tara) {
    this->tara = tara;
}

string Jucator::getTara() {
    return this->tara;
}

void Jucator::setCastigInUltimeleNLuni(float* castigInUltimeleNLuni, int nLuni) {
    if(this->castigInUltimeleNLuni != NULL)
        delete[] this->castigInUltimeleNLuni;
    this->nLuni = nLuni;
    this->castigInUltimeleNLuni = new float[this->nLuni];
    for(int i = 0; i < this->nLuni; i ++)
        this->castigInUltimeleNLuni[i] = castigInUltimeleNLuni[i];
}

const float* Jucator::getCastigInUltimeleNLuni() const {
    return this->castigInUltimeleNLuni;
}

void Jucator::setKills(int kills) {
    this->kills = kills;
}

int Jucator::getKills() {
    return this->kills;
}

void Jucator::setDeaths(int deaths) {
    this->deaths = deaths;
}

int Jucator::getDeaths() {
    return this->deaths;
}

void Jucator::setAssists(int assists) {
    this->assists = assists;
}

int Jucator::getAssists() {
    return this->assists;
}

void Jucator::setScor(int scor) {
    this->scor = scor;
}

int Jucator::getScor() {
    return this->scor;
}

Arma& Jucator::getArma(int index) {
    return this->arme[index - 1];
}

Jucator Jucator::operator++() {
    this->kills = this->kills + 1;
    return *this;
}

Jucator Jucator::operator++(int) {
    Jucator aux = *this;
    this->kills = this->kills + 1;
    return aux;
}

Jucator Jucator::operator+(int x) {
    Jucator aux = *this;
    aux.kills = aux.kills + x;
    return aux;
}

Jucator operator+(int x, Jucator jucator) {
    jucator.kills = jucator.kills + x;
    return jucator;
}

Jucator Jucator::operator*(int x) {
    Jucator aux = *this;
    aux.assists = aux.assists * x;
    return aux;
}

Jucator operator*(int x, Jucator jucator) {
    jucator.assists = x * jucator.assists;
    return jucator;
}

bool Jucator::operator==(const Jucator& jucator) {
    return this->kills == jucator.kills && this->deaths == jucator.deaths && this->assists == jucator.assists;
}

bool Jucator::operator<(const Jucator& jucator) {
    return this->kills < jucator.kills;
}

inline Jucator::operator int() const {
    return int(this->kills);
}

Arma& Jucator::operator[](int index) {
    if(0 <= index && index < this->nr_arme)
        return this->arme[index];
    cout << "Index introdus gresit";
}

void Jucator::deleteArma(int index) {
    this->nr_arme = this->nr_arme - 1;
    this->arme.erase(arme.begin() + index - 1);
}

void Jucator::addArma(Arma arma) {
    this->nr_arme = this->nr_arme + 1;
    this->arme.push_back(arma);
}

istream& operator>>(istream& in, Jucator& jucator) {
    cout << "Nume jucator : ";
    char aux[100];
    in >> aux;
    if(jucator.nume != NULL)
        delete[] jucator.nume;
    jucator.nume = new char[strlen(aux) + 1];
    strcpy(jucator.nume, aux);

    cout << "Prenume : ";
    in >> jucator.prenume;
    cout << "Initiala Tata : ";
    in >> jucator.initialaTata;
    cout << "Varsta : ";
    in >> jucator.varsta;
    cout << "Tara : ";
    in >> jucator.tara;
    cout << "Pe cate luni contorizam ? ";
    in >> jucator.nLuni;
    cout << "Valori : ";
    if(jucator.castigInUltimeleNLuni != NULL)
        delete[] jucator.castigInUltimeleNLuni;
    jucator.castigInUltimeleNLuni = new float[jucator.nLuni];
    for(int i = 0; i < jucator.nLuni; i ++)
        in >> jucator.castigInUltimeleNLuni[i];
    cout << "Kills : ";
    in >> jucator.kills;
    cout << "Deaths : ";
    in >> jucator.deaths;
    cout << "Assists : ";
    in >> jucator.assists;
    cout << "Scor : ";
    in >> jucator.scor;
    cout << "Nr de arme : ";
    in >> jucator.nr_arme;
    cout << "Armele : \n";
    jucator.arme = vector <Arma> (jucator.nr_arme);
    for(int i = 0; i < jucator.nr_arme; i ++) {
        in >> jucator.arme[i];
    }
    return in;
}

ostream& operator<<(ostream& out, const Jucator& jucator) {
    out << "\nId jucator : " << jucator.idJucator;
    out << "\nNume jucator : " << jucator.nume;
    out << "\nPrenume : " << jucator.prenume;
    out << "\nInitiala tata : " << jucator.initialaTata;
    out << "\nVarsta : " << jucator.varsta;
    out << "\nTara : " << jucator.tara;
    out << "\nIn ultimele " << jucator.nLuni << " luni a castigat : ";
    for(int i = 0; i < jucator.nLuni; i ++)
        out << jucator.castigInUltimeleNLuni[i] << ", ";
    out << "\nKills : " << jucator.kills;
    out << "\nDeaths : " << jucator.deaths;
    out << "\nAssists : " << jucator.assists;
    out << "\nScor : " << jucator.scor;
    out << "\nNumarul de arme : " << jucator.nr_arme;
    if(jucator.nr_arme)
        out << "\nArmele : ";
    else out << '\n';
    for(const auto& a : jucator.arme)
        out << a;
    return out;
}

Jucator::~Jucator() {
    if(this->nume != NULL)
        delete[] this->nume;
    if(this->castigInUltimeleNLuni != NULL)
        delete[] this->castigInUltimeleNLuni;
}


///--------------------------------------------------------------------------

class Echipa {
private:
    ///detalii despre echipa
    string nume; ///nume echipa
    string tara; ///tara echipa
    int pozitie; ///pozitie clasament
    int meci_castigat; ///numar meciuri castigate
    int meci_pierdut; ///numar meciuri pierdute
    int nr_jucatori; ///nr de jucatori
    vector <Jucator> jucatori; ///jucatorii dintr-o echipa
public:
    ///Constructori
    Echipa();
    Echipa(string nume, string tara);
    Echipa(int pozitie, int meci_castigat, int meci_pierdut);
    Echipa(string nume, string tara, int pozitie, int meci_castigat, int meci_pierdut, int nr_jucatori, vector <Jucator> jucatori);
    Echipa(const Echipa& other);
    ///Operatori
    Echipa& operator=(const Echipa& other);
    Echipa operator++();
    Echipa operator++(int);

    Echipa operator+(int x);
    friend Echipa operator+(int x, Echipa echipa);
    Echipa operator*(int x);
    friend Echipa operator*(int x, Echipa echipa);

    explicit operator float() const;
    Jucator operator[](int index);
    bool operator<(const Echipa& echipa);
    bool operator==(const Echipa& echipa);

    friend istream& operator>>(istream& in, Echipa& echipa);
    friend ostream& operator<<(ostream& out, const Echipa& echipa);

    Jucator& getJucator(int index);
    int getPozitie();

    ///Functionalitate
    void deleteJucator(int index);
    void addJucator(Jucator& jucator);

    ///Destructor
    ~Echipa() {};

};

Echipa::Echipa() {
    this->nume = "Anonim";
    this->tara = "Anonim";
    this->pozitie = 0;
    this->meci_castigat = 0;
    this->meci_pierdut = 0;
    this->nr_jucatori = 0;
    this->jucatori = {};
}

Echipa::Echipa(string nume, string tara) {
    this->nume = nume;
    this->tara = tara;
}

Echipa::Echipa(int pozitie, int meci_castigat, int meci_pierdut) {
    this->pozitie = pozitie;
    this->meci_castigat = meci_castigat;
    this->meci_pierdut = meci_pierdut;
}

Echipa::Echipa(string nume, string tara, int pozitie, int meci_castigat, int meci_pierdut, int nr_jucatori, vector <Jucator> jucatori) {
    this->nume = nume;
    this->tara = tara;
    this->pozitie = pozitie;
    this->meci_castigat = meci_castigat;
    this->meci_pierdut = meci_pierdut;
    this->nr_jucatori = nr_jucatori;
    for(int i = 0; i < nr_jucatori; i ++)
        this->jucatori[i] = jucatori[i];
}

Echipa::Echipa(const Echipa& other) {
    this->nume = other.nume;
    this->tara = other.tara;
    this->pozitie = other.pozitie;
    this->meci_castigat = other.meci_castigat;
    this->meci_pierdut = other.meci_pierdut;
    this->nr_jucatori = other.nr_jucatori;
    for(int i = 0; i < other.nr_jucatori; i ++)
        this->jucatori[i] = other.jucatori[i];
}

Echipa& Echipa::operator=(const Echipa& other) {
    if(this != &other) {
        this->nume = other.nume;
        this->tara = other.tara;
        this->pozitie = other.pozitie;
        this->meci_castigat = other.meci_castigat;
        this->meci_pierdut = other.meci_pierdut;
        this->nr_jucatori = other.nr_jucatori;
        for(int i = 0; i < other.nr_jucatori; i ++)
            this->jucatori[i] = other.jucatori[i];
    }
    return *this;
}

int Echipa::getPozitie() {
    return this->pozitie;
}

Jucator& Echipa::getJucator(int index) {
    return this->jucatori[index - 1];
}

Echipa Echipa::operator++() {
    this->meci_castigat = this->meci_castigat + 1;
    return *this;
}


Echipa Echipa::operator++(int) {
    Echipa aux = *this;
    this->meci_castigat = this->meci_castigat + 1;
    return aux;
}

Echipa Echipa::operator+(int x) {
    Echipa aux = *this;
    aux.meci_castigat = aux.meci_castigat + x;
    return aux;
}

Echipa operator+(int x, Echipa echipa) {
    echipa.meci_castigat = echipa.meci_castigat + x;
    return echipa;
}

Echipa Echipa::operator*(int x) {
    Echipa aux = *this;
    aux.meci_castigat = aux.meci_castigat * x;
    return aux;
}

Echipa operator*(int x, Echipa echipa) {
    echipa.meci_castigat = x * echipa.meci_castigat;
    return echipa;
}

bool Echipa::operator==(const Echipa& echipa) {
    return this->nume == echipa.nume && this->tara == echipa.tara;
}

bool Echipa::operator<(const Echipa& echipa) {
    return this->meci_castigat < echipa.meci_castigat;
}

inline Echipa::operator float() const {
    return float(this->pozitie);
}

Jucator Echipa::operator[](int index) {
    if(0 <= index && index < this->nr_jucatori)
        return this->jucatori[index];
    cout << "Index introdus gresit";
}


void Echipa::deleteJucator(int index) {
    this->nr_jucatori = this->nr_jucatori - 1;
    this->jucatori.erase(jucatori.begin() + index - 1);
}

void Echipa::addJucator(Jucator& jucator) {
    this->nr_jucatori = this->nr_jucatori + 1;
    this->jucatori.push_back(jucator);
}

istream& operator>>(istream& in, Echipa& echipa) {
    cout << "\nNume echipa : ";
    in >> echipa.nume;
    cout << "Tara : ";
    in >> echipa.tara;
    cout << "Pozitie in clasament : ";
    in >> echipa.pozitie;
    cout << "Meciuri castigate : ";
    in >> echipa.meci_castigat;
    cout << "Meciuri pierdute : ";
    in >> echipa.meci_pierdut;
    cout << "Numarul de jucatori : ";
    in >> echipa.nr_jucatori;
    cout << "Jucatorii : \n";
    echipa.jucatori = vector <Jucator> (echipa.nr_jucatori);
    for(int i = 0; i < echipa.nr_jucatori; i ++)
        in >> echipa.jucatori[i];
    return in;
}

ostream& operator<<(ostream& out, const Echipa& echipa) {
    out << "\nNume echipa : " << echipa.nume;
    out << "\nTara : " << echipa.tara;
    out << "\nPozitie in clasament : " << echipa.pozitie;
    out << "\nMeciuri castigate : " << echipa.meci_castigat;
    out << "\nMeciuri pierdute : " << echipa.meci_pierdut;
    out << "\nNumarul de jucatori : " << echipa.nr_jucatori;
    if(echipa.nr_jucatori)
        out << "\nJucatorii : ";
    else out << '\n';
    for(const auto& j : echipa.jucatori)
        out << j;
    return out;
}

///--------------------------------------------------------------------------

class Harta {
private:
    ///detalii despre harta
    string nume; ///nume harta
    int perimetru; ///perimetrul hartii
    bool tip; ///0 - bomba, 1 - ostatici
    int nr_pozitii; ///numarul de pozitii de pe harta
    vector <string> pozitii; ///Pozitiile de pe harta
    Echipa e1, e2;
public:
    ///Constructori
    Harta();
    Harta(string nume);
    Harta(string nume, int perimetru, bool tip, int nr_pozitii, vector <string> pozitii, Echipa e1, Echipa e2);
    Harta(const Harta& other);

    void setTip(bool tip);
    bool getTip();
    Echipa& gete1();
    Echipa& gete2();

    ///Operatori
    Harta& operator=(const Harta& other);
    Harta operator++();
    Harta operator++(int);

    Harta operator+(int x);
    friend Harta operator+(int x, Harta harta);
    Harta operator*(int x);
    friend Harta operator*(int x, Harta harta);

    explicit operator int() const;
    bool operator<=(const Harta& harta);
    bool operator==(const Harta& harta);

    friend istream& operator>>(istream& in, Harta& harta);
    friend ostream& operator<<(ostream& out, const Harta& harta);

    ///Functionalitate
    void afisareEchipaSuperiorClasata();
    ///Destructor
    ~Harta() {};
};

Harta::Harta() {
    this->nume = "Anonim";
    this->perimetru = 0;
    this->tip = false;
    this->nr_pozitii = 0;
    this->pozitii = {};
    this->e1 = {};
    this->e2 = {};
}

Harta::Harta(string nume) {
    this->nume = nume;
}

Harta::Harta(string nume, int perimetru, bool tip, int nr_pozitii, vector <string> pozitii, Echipa e1, Echipa e2) {
    this->nume = nume;
    this->perimetru = perimetru;
    this->tip = tip;
    this->nr_pozitii = nr_pozitii;
    this->pozitii = pozitii;
    this->e1 = e1;
    this->e2 = e2;
}

Harta::Harta(const Harta& harta) {
    this->nume = harta.nume;
    this->perimetru = harta.perimetru;
    this->tip = harta.tip;
    this->nr_pozitii = harta.nr_pozitii;
    this->pozitii = harta.pozitii;
}

Harta& Harta::operator=(const Harta& harta) {
    if(this != &harta) {
        this->nume = harta.nume;
        this->perimetru = harta.perimetru;
        this->tip = harta.tip;
        this->nr_pozitii = harta.nr_pozitii;
        this->pozitii = harta.pozitii;
    }
    return *this;
}

void Harta::setTip(bool tip) {
    this->tip = tip;
}

bool Harta::getTip() {
    return this->tip;
}

Echipa& Harta::gete1() {
    return this->e1;
}

Echipa& Harta::gete2() {
    return this->e2;
}

Harta Harta::operator++() {
    this->perimetru = this->perimetru + 1;
    return *this;
}

Harta Harta::operator++(int) {
    Harta aux = *this;
    this->perimetru = this->perimetru + 1;
    return aux;
}


Harta Harta::operator+(int x) {
    Harta aux = *this;
    aux.perimetru = aux.perimetru + x;
    return aux;
}

Harta operator+(int x, Harta harta) {
    harta.perimetru = harta.perimetru + x;
    return harta;
}

Harta Harta::operator*(int x) {
    Harta aux = *this;
    aux.perimetru = aux.perimetru * x;
    return aux;
}

Harta operator*(int x, Harta harta) {
    harta.perimetru = harta.perimetru * x;
    return harta;
}

bool Harta::operator<=(const Harta& harta) {
    return this->perimetru <= harta.perimetru;
}

bool Harta::operator==(const Harta& harta) {
    return this->perimetru == harta.perimetru;
}

inline Harta::operator int() const {
    return int(this->tip);
}

void Harta::afisareEchipaSuperiorClasata() {
    if(this->gete1().getPozitie() < this->gete2().getPozitie())
        cout << "Prima echipa ocupa un loc mai bun in clasament\n";
    else if(this->gete1().getPozitie() > this->gete2().getPozitie())
        cout << "A doua echipa ocupa un loc mai bun in clasament\n";
    else cout << "Ambele echipa ocupa acelasi loc in clasament\n";
}

istream& operator>>(istream& in, Harta& harta) {
    cout << "Nume harta : ";
    in >> harta.nume;
    cout << "Perimetru : ";
    in >> harta.perimetru;
    cout << "Tip : (0 - bomba, 1 - ostatici) : ";
    in >> harta.tip;
    cout << "Nr pozitii : ";
    in >> harta.nr_pozitii;
    harta.pozitii = vector <string> (harta.nr_pozitii);
    cout << "Pozitiile : ";
    for(int i = 0; i < harta.nr_pozitii; i ++)
        in >> harta.pozitii[i];
    cout << "Echipa 1 : ";
    in >> harta.e1;
    cout << "Echipa 2 : ";
    in >> harta.e2;
    return in;
}

ostream& operator<<(ostream& out, const Harta& harta) {
    out << "--------------------------------------------------\n";
    out << "Nume harta : " << harta.nume;
    out << "\nPerimetru : " << harta.perimetru;
    out << "\nTip : " << harta.tip;
    out << "\nNr pozitii : " << harta.nr_pozitii;
    out << "\nPozitiile : ";
    for(const auto& p : harta.pozitii)
        out << p << " ";
    out << "\nEchipa 1 : " << harta.e1;
    out << "\nEchipa 2 : " << harta.e2;
    return out;
}

int Jucator::contorId = 1000;

int main() {
    Harta h;
    cin >> h;
    bool ok = true;
    int comanda;
    while(ok) {
        cout << "1. Adaugare jucator\n2. Stergere jucator\n3. Adaugare arma pentru un jucator\n4. Stergere arma pentru un jucator\n5. Adaugare skin pentru o arma\n";
        cout << "6. Stergere skin pentru o arma\n7. Pentru afisare\n8. Pentru iesire\n";
        cin >> comanda;
        switch(comanda) {
            case 1: {
                int echipa;
                cout << "In ce echipa vrei sa adaugi jucatorul ? (1 sau 2) : ";
                cin >> echipa;
                Jucator j;
                cin >> j;
                if(echipa == 1)
                    h.gete1().addJucator(j);
                else h.gete2().addJucator(j);
                break;
            }
            case 2: {
                int echipa;
                cout << "Din ce echipa vrei sa stergi jucatorul ? (1 sau 2) : ";
                cin >> echipa;
                cout << "Ce jucator vrei sa stergi : ";
                int index;
                cin >> index;
                if(echipa == 1)
                    h.gete1().deleteJucator(index);
                else h.gete2().deleteJucator(index);
                break;
            }
            case 3: {
                int echipa, index;
                cout << "Din ce echipa este jucatorul : ";
                cin >> echipa;
                cout << "Ce jucator : ";
                cin >> index;
                Arma a;
                cin >> a;
                if(echipa == 1) {
                    h.gete1().getJucator(index).addArma(a);
                }
                else if(echipa == 2) {
                    h.gete2().getJucator(index).addArma(a);
                }
                break;
            }
            case 4: {
                int echipa, index, nr_arma;
                cout << "Din ce echipa este jucatorul : ";
                cin >> echipa;
                cout << "Ce jucator : ";
                cin >> index;
                cout << "Numarul armei : ";
                cin >> nr_arma;
                if(echipa == 1) {
                    h.gete1().getJucator(index).deleteArma(nr_arma);
                }
                else if(echipa == 2) {
                    h.gete2().getJucator(index).deleteArma(nr_arma);
                }
                break;
            }
            case 5 : {
                int echipa, index, nr_arma;
                cout << "Din ce echipa este jucatorul : ";
                cin >> echipa;
                cout << "Ce jucator : ";
                cin >> index;
                cout << "Numarul armei : ";
                cin >> nr_arma;
                Skin s;
                cin >> s;
                if(echipa == 1) {
                    h.gete1().getJucator(index).getArma(nr_arma).addSkin(s);
                }
                else if(echipa == 2) {
                    h.gete2().getJucator(index).getArma(nr_arma).addSkin(s);
                }
                break;
            }
            case 6 : {
                int echipa, index, nr_arma, nr_skin;
                cout << "Din ce echipa este jucatorul : ";
                cin >> echipa;
                cout << "Ce jucator : ";
                cin >> index;
                cout << "Numarul armei : ";
                cin >> nr_arma;
                cout << "Numarul skin-ului : ";
                cin >> nr_skin;
                if(echipa == 1) {
                    h.gete1().getJucator(index).getArma(nr_arma).deleteSkin(nr_skin);
                }
                else if(echipa == 2) {
                    h.gete2().getJucator(index).getArma(nr_arma).deleteSkin(nr_skin);
                }
                break;
            }
            case 7 : {
                cout << "-----------------------------------------------------------";
                cout << h;
                break;
            }
            case 8 : {
                ok = false;
                break;
            }
            default : {
                cout << "Ati introdus o varianta gresita\n";
                ok = false;
                break;
            }
        }
   }
   return 0;
}

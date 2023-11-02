#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
using namespace  std;


class IOInterface {
public:
    virtual istream& read(istream& in) = 0;
    virtual ostream& write(ostream& out) const = 0;

    virtual ~IOInterface() = 0;
};

IOInterface::~IOInterface() {}

class Persoana : public IOInterface {
protected:
    string nume;
    string prenume;
    string CNP;
    int varsta;
public:
    Persoana();
    Persoana(string nume, string prenume, string CNP, int varsta);
    Persoana(const Persoana& persoana);
    Persoana& operator=(const Persoana& persoana);

    void setNume(string nume);
    string getNume() const;
    void setPrenume(string prenume);
    string getPrenume() const;
    void setCNP(string CNP);
    string getCNP() const;
    void setVarsta(int varsta);
    int getVarsta() const;

    friend istream& operator>>(istream& in, Persoana& persoana);
    friend ostream& operator<<(ostream& out, const Persoana& Persoana);

    virtual istream& read(istream& in);
    virtual ostream& write(ostream& out) const;

    ~Persoana();
};

Persoana::Persoana() {
    this->nume = "Anonim";
    this->prenume = "Anonim";
    this->CNP = "Anonim";
    this->varsta = 0;
}

Persoana::Persoana(string nume, string prenume, string CNP, int varsta) {
    this->nume = nume;
    this->prenume = prenume;
    this->CNP = CNP;
    this->varsta = 0;
}

Persoana::Persoana(const Persoana& persoana) {
    this->nume = persoana.nume;
    this->prenume = persoana.prenume;
    this->CNP = persoana.CNP;
    this->varsta = persoana.varsta;
}

Persoana& Persoana::operator=(const Persoana& persoana) {
    if(this != &persoana) {
        this->nume = persoana.nume;
        this->prenume = persoana.prenume;
        this->CNP = persoana.CNP;
        this->varsta = persoana.varsta;
    }
    return *this;
}

void Persoana::setNume(string nume) {
    this->nume = nume;
}

string Persoana::getNume() const {
    return this->nume;
}

void Persoana::setPrenume(string prenume) {
    this->prenume = prenume;
}

string Persoana::getPrenume() const {
    return this->prenume;
}

void Persoana::setCNP(string CNP) {
    this->CNP = CNP;
}

string Persoana::getCNP() const {
    return this->CNP;
}

void Persoana::setVarsta(int varsta) {
    this->varsta = varsta;
}

int Persoana::getVarsta() const {
    return this->varsta;
}

istream& Persoana::read(istream& in) {
    cout << "Nume : ";
    in >> this->nume;
    cout << "Prenume : ";
    in >> this->prenume;
    cout << "CNP : ";
    in >> this->CNP;
    cout << "Varsta : ";
    in >> this->varsta;
    return in;
}

ostream& Persoana::write(ostream& out) const{
    out << "Nume : " << this->nume << '\n';
    out << "Prenume : " << this->prenume << '\n';
    out << "CNP : " << this->CNP << '\n';
    out << "Varsta : " << this->varsta << '\n';
    return out;
}

istream& operator>>(istream& in, Persoana& persoana) {
    return persoana.read(in);
}

ostream& operator<<(ostream& out, const Persoana& persoana) {
    return persoana.write(out);
}

Persoana::~Persoana() {}

class Parior : virtual public Persoana {
protected:
    double buget; ///Cat isi permite sa parieze
public:
    Parior();
    Parior(string nume, string prenume, string cnp, int varsta, int buget);
    Parior(const Parior& parior);
    Parior& operator=(const Parior& parior);

    istream& read(istream& in);
    ostream& write(ostream& out) const;

    ///functionalitate pariaza(x) - scade/creste din buget
    void pariaza(double x);

    ~Parior() {};
};

Parior::Parior() : Persoana() {
    this->buget = 0;
}

Parior::Parior(string nume, string prenume, string CNP, int varsta, int buget) : Persoana(nume, prenume, CNP, varsta) {
    this->buget = buget;
}

Parior::Parior(const Parior& parior) : Persoana(parior) {
    this->buget = parior.buget;
}

Parior& Parior::operator=(const Parior& parior) {
    if(this != &parior) {
        Persoana::operator=(parior);
        this->buget = parior.buget;
    }
    return *this;
}

void Parior::pariaza(double x) {
    this->buget += x;
}

istream& Parior::read(istream& in) {
    Persoana::read(in);
    cout << "Buget pentru pariat : ";
    in >> this->buget;
    return in;
}

ostream& Parior::write(ostream& out) const{
    Persoana::write(out);
    out << "Bugetul pentru pariat este : " << this->buget << '\n';
    return out;
}

class Angajat : virtual public Persoana {
protected:
    int salariu;
public:
    Angajat();
    Angajat(string nume, string prenume, string cnp, int varsta, int salariu);
    Angajat(const Angajat& angajat);
    Angajat& operator=(const Angajat& angajat);

    istream& read(istream& in);
    ostream& write(ostream& out) const;

    ///functionalitate : primeste un bonus / ii scade din salariu
    void random(double);

    ~Angajat() {};
};

Angajat::Angajat() : Persoana() {
    this->salariu = 0;
}

Angajat::Angajat(string nume, string prenume, string CNP, int varsta, int salariu) : Persoana(nume, prenume, CNP, varsta) {
    this->salariu = salariu;
}

Angajat::Angajat(const Angajat& angajat) : Persoana(angajat) {
    this->salariu = angajat.salariu;
}

Angajat& Angajat::operator=(const Angajat& angajat) {
    if(this != &angajat) {
        Persoana::operator=(angajat);
        this->salariu = angajat.salariu;
    }
    return *this;
}

void Angajat::random(double x) {
    this->salariu += x;
}

istream& Angajat::read(istream& in) {
    Persoana::read(in);
    cout << "Salariu : ";
    in >> this->salariu;
    return in;
}

ostream& Angajat::write(ostream& out) const{
    Persoana::write(out);
    out << "Salariul este : " << this->salariu << '\n';
    return out;
}

class PariorAngajat : public Parior, public Angajat {
private:
    set <int> castiguriMaxime; ///primele 3 castiguri maxime pe care le-a facut
    map<string, bool> rezultat; ///In ziua "x" a "castigat"/"pierdut" - initial 3 date
public:
    PariorAngajat();
    PariorAngajat(string nume, string prenume, string CNP, int varsta, int buget, int salariu, set<int> castiguriMaxime, map<string, bool> rezultat);
    PariorAngajat(const PariorAngajat& pariorAngajat);
    PariorAngajat& operator=(const PariorAngajat& pariorAngajat);

    istream& read(istream& in);
    ostream& write(ostream& out) const;

    ///functionalitate - adauga o data si un castig/pierdere
    void adaugare(string zi, bool tip, int value);

    ~PariorAngajat() {}
};

void PariorAngajat::adaugare(string zi, bool tip, int value) {
    this->rezultat[zi] = tip;
    if(tip) {
        for(const auto& i : this->castiguriMaxime) {
            if(value > i) {
                this->castiguriMaxime.erase(this->castiguriMaxime.begin());
                this->castiguriMaxime.insert(value);
                break;
            }
        }
    }
}

PariorAngajat::PariorAngajat() : Persoana(), Parior(), Angajat()  {
    this->castiguriMaxime = {};
    this->rezultat = {};
}

PariorAngajat::PariorAngajat(string nume, string prenume, string CNP, int varsta, int buget, int salariu, set<int> castiguriMaxime, map<string, bool> rezultat) : Persoana(nume, prenume, CNP, varsta), Parior(nume, prenume, CNP, varsta, buget), Angajat(nume, prenume, CNP, varsta, salariu) {
    this->castiguriMaxime = castiguriMaxime;
    this->rezultat = rezultat;
}

PariorAngajat::PariorAngajat(const PariorAngajat& pariorAngajat) : Persoana(pariorAngajat), Parior(pariorAngajat), Angajat(pariorAngajat) {
    this->castiguriMaxime = pariorAngajat.castiguriMaxime;
    this->rezultat = pariorAngajat.rezultat;
}

PariorAngajat& PariorAngajat::operator=(const PariorAngajat& pariorAngajat) {
    if(this != &pariorAngajat) {
        Angajat::operator=(pariorAngajat);
        this->buget = pariorAngajat.buget;
        this->castiguriMaxime = pariorAngajat.castiguriMaxime;
        this->rezultat = pariorAngajat.rezultat;
    }
    return *this;
}

istream& PariorAngajat::read(istream& in) {
    Parior::read(in);
    cout << "Salariu : ";
    in >> this->salariu;
    cout << "Primele 3 castiguri maxime \n";
    int x;
    for(int i = 1; i <= 3; i ++) {
        cout << "Castigul de pe locul " << i << " este : ";
        in >> x;
        castiguriMaxime.insert(x);
    }
    string day;
    bool tip;
    cout << "Rezultatele din ultimele 3 parieri - 1 pentru win si 0 pentru lose\n";
    for(int i = 1; i <= 3; i ++) {
        cout << "Introduceti data : ";
        in >> day;
        cout << "Win sau lose : ";
        in >> tip;
        rezultat[day] = tip;
    }
    return in;
}

ostream& PariorAngajat::write(ostream& out) const{
    Parior::write(out);
    out << "Salariu : " << this->salariu << '\n';
    out << "Cele mai mari castiguri : ";
    for(const auto& i : this->castiguriMaxime)
        out << i << " ";
    out << '\n';
    out << "Rezultatele din anumite zile : \n";
    for(const auto& i : this->rezultat)
        out << "In ziua " << i.first << " a " << (i.second ? "castigat\n":"pierdut\n");
    return out;
}

class ExceptiaMea: public exception{
public:
    virtual const char* what() const throw(){

        return "Comanda invalida!";
    }
} exceptiaMea;


template<typename T = int>
class Agentie {
private:
    string numeAgentie;
    int vechime;
    T medieCastigLunar; ///care este castigul mediul lunar
    int n;
    list <int> castigUltimeleNLuni;
public:
    Agentie();
    Agentie(string numeAgentie, int vechime, T medieCastigLunar, int n, list <int> castigUltimeleNLuni);
    Agentie(const Agentie<T> &agentie);
    Agentie& operator=(const Agentie<T> &agentie);
    template<typename U>
    friend istream& operator>>(istream& in, Agentie<U>& agentie);
    template<typename U>
    friend ostream& operator<<(ostream& out, const Agentie<U>& agentie);

    template<typename U>
    void tipBonus(const U& castig);

    ~Agentie() {};
};

template<typename T>
Agentie<T>::Agentie() {
    this->numeAgentie = "Anonim";
    this->vechime = 0;
    this->medieCastigLunar = 0;
    this->n = 0;
    this->castigUltimeleNLuni = {};
}

template<typename T>
Agentie<T>::Agentie(string numeAgentie, int vechime, T medieCastigLunar, int n, list <int> castigUltimeleNLuni) {
    this->numeAgentie = numeAgentie;
    this->vechime = vechime;
    this->medieCastigLunar = medieCastigLunar;
    this->n = n;
    this->castigUltimeleNLuni = castigUltimeleNLuni;
}

template<typename T>
Agentie<T>::Agentie(const Agentie<T> &agentie) {
    this->numeAgentie = agentie.numeAgentie;
    this->vechime = agentie.vechime;
    this->medieCastigLunar = agentie.medieCastigLunar;
    this->n = agentie.n;
    this->castigUltimeleNLuni = agentie.castigUltimeleNLuni;
}

template<typename T>
Agentie<T>& Agentie<T>::operator=(const Agentie<T>& agentie) {
    if(this != &agentie) {
        this->numeAgentie = agentie.numeAgentie;
        this->vechime = agentie.vechime;
        this->medieCastigLunar = agentie.medieCastigLunar;
        this->n = agentie.n;
        this->castigUltimeleNLuni = agentie.castigUltimeleNLuni;
    }
    return *this;
}

template<typename U>
istream& operator>>(istream& in, Agentie<U>& agentie) {
    cout << "Nume agentie : ";
    in >> agentie.numeAgentie;
    cout << "Vechime : ";
    in >> agentie.vechime;
    cout << "Medie castig lunar : ";
    in >> agentie.medieCastigLunar;
    cout << "Cate luni ? : ";
    in >> agentie.n;
    cout << "Castigurile : \n";
    int x;
    for(int i = 1; i <= agentie.n; i ++) {
        in >> x;
        agentie.castigUltimeleNLuni.push_back(x);
    }
    return in;
}

template<typename U>
ostream& operator<<(ostream& out, const Agentie<U>& agentie) {
    out << "Nume agentie : " << agentie.numeAgentie << '\n';
    out << "Vechime : " << agentie.vechime << '\n';
    out << "Medie castig lunar : " << agentie.medieCastigLunar << '\n';
    out << "Castigul din ultimele " << agentie.n << " luni : ";
    for(const auto& i : agentie.castigUltimeleNLuni)
        out << i << " ";
    out << '\n';
    return out;
}

template<typename T>
template<typename U>
void Agentie<T>::tipBonus(const U& castig) {
    if(typeid(castig) == typeid(const int))
        cout << "Suma rotunda!";
    else cout << "Suma nu este rotunda!";
}

Agentie <> a;
vector <Persoana*> persoane;

class meniuInteractiv {
private:
    static meniuInteractiv *obiect;
    meniuInteractiv() {}
    meniuInteractiv(const meniuInteractiv& meniuInteractiv) {
        obiect = meniuInteractiv.obiect;
    }
    meniuInteractiv& operator=(const meniuInteractiv& meniuInteractiv) {
        if(this != &meniuInteractiv) {
            obiect = meniuInteractiv.obiect;
        }
        return *this;
    }
public:
    static meniuInteractiv *getInstance() {
        if (!obiect)
            obiect = new meniuInteractiv();
        return obiect;
    }
    void show();

};

void meniuInteractiv::show() {
    cin >> a;
    int option = 0;
    do {
        cout << "0. Pentru a iesi din program\n";
        cout << "1. Adauga persoana la agentie\n";
        cout << "2. Da afara persoana din agentie\n";
        cout << "3. Afiseaza toate persoanele din agentie\n";
        cout << "4. Afiseaza persoanele din agentie care sunt pariori\n";
        cout << "5. Afiseaza persoanele din agentie care sunt angajati\n";
        cout << "6. Afiseaza persoanele din agentie care sunt pariori angajati\n";
        cout << "7. Afiseaza Agentie\n";

        cin >> option;
        try {
            if(option < 0 || option > 7)
                throw("Comanda invalida!");
            switch(option) {
                case 0 : {
                    option = 0;
                    break;
                }
                case 1: {
                    cout << "Selecteaza Persoana [parior/angajat/pariorAngajat] : ";
                    string tip;
                    cin >> tip;
                    try {
                        if(tip != "parior" && tip != "angajat" && tip != "pariorAngajat") {
                            throw(exceptiaMea);
                        }
                        if(tip == "parior") {
                            Parior parior;
                            cin >> parior;
                            persoane.push_back(new Parior(parior));
                        }
                        else if(tip == "angajat") {
                            Angajat angajat;
                            cin >> angajat;
                            persoane.push_back(new Angajat(angajat));
                        }
                        else if(tip == "pariorAngajat") {
                            PariorAngajat pariorAngajat;
                            cin >> pariorAngajat;
                            persoane.push_back(new PariorAngajat(pariorAngajat));
                        }
                    }
                    catch(ExceptiaMea& e) {
                        cerr << e.what() << endl;
                    }
                    break;
                }
                case 2: {
                    cout << "Ce persoana doriti sa dati afara ? ";
                    int nr;
                    cin >> nr;
                    cout << persoane.size() << '\n';
                    try {
                        if(nr > persoane.size())
                            throw (string("Nu exista persoana cu indexul respectiv!\n"));
                        persoane.erase(persoane.begin() + nr - 1);
                    }
                    catch(string s) {
                        cout << s;
                    }
                    break;
                }
                case 3: {
                    for(const auto& i : persoane)
                        cout << *i;
                    break;
                }

                case 4: {
                    int cnt = 0;
                    for(const auto& i : persoane) {
                        try {
                            if(!dynamic_cast<Parior*>(const_cast<Persoana*>(i)) || dynamic_cast<PariorAngajat*>(const_cast<Persoana*>(i)))
                                throw(cnt);
                            cout << *i;
                        }
                        catch(int c) {
                            cout << "Persoana cu indexul " << c << " nu este parior\n";
                        }
                        cnt ++;
                    }
                    break;
                }
                case 5: {
                    int cnt = 0;
                    for(const auto& i : persoane) {
                        try {
                            if(!dynamic_cast<Angajat*>(const_cast<Persoana*>(i)) || dynamic_cast<PariorAngajat*>(const_cast<Persoana*>(i)))
                                throw(cnt);
                            cout << *i;
                        }
                        catch(int c) {
                            cout << "Persoana cu indexul " << c << " nu este angajat\n";
                        }
                        cnt ++;
                    }
                    break;
                }

                case 6: {
                    int cnt = 0;
                    for(const auto& i : persoane) {
                        try {
                            if(!dynamic_cast<PariorAngajat*>(const_cast<Persoana*>(i)))
                                throw(cnt);
                            cout << *i;
                        }
                        catch(int c) {
                            cout << "Persoana cu indexul " << c << " nu este parior angajat\n";
                        }
                        cnt ++;
                    }
                    break;
                }

                case 7: {
                    cout << a;
                    break;
                }
            }
        }
        catch(const char* s) {
            cout << s << '\n';
        }
    }while(option != 0);
}

meniuInteractiv *meniuInteractiv::obiect = 0;

int main() {

    meniuInteractiv *myMenu = myMenu->getInstance();
    myMenu->show();
}

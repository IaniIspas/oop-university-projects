#include <iostream>
#include <vector>
#include <string>
using namespace  std;


class IOInterface {
public:
    virtual istream& read(istream& in) = 0;
    virtual ostream& write(ostream& out) const = 0;
};

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

    virtual ~Persoana();
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
    double bonus; ///Pe langa salariu, primeste un bonus pentru ca face reclama
public:
    PariorAngajat();
    PariorAngajat(string nume, string prenume, string CNP, int varsta, int buget, int salariu, double bonus);
    PariorAngajat(const PariorAngajat& pariorAngajat);
    PariorAngajat& operator=(const PariorAngajat& pariorAngajat);

    istream& read(istream& in);
    ostream& write(ostream& out) const;

    ///Functionalitate : pentru fiecare 1000 de lei ramasi din banii dati de agentie primeste cate x lei
    void adaugaBonus(double x);

    ~PariorAngajat() {}
};

PariorAngajat::PariorAngajat() : Persoana(), Parior(), Angajat()  {
    this->bonus = 0;
}

PariorAngajat::PariorAngajat(string nume, string prenume, string CNP, int varsta, int buget, int salariu, double bonus) : Persoana(nume, prenume, CNP, varsta), Parior(nume, prenume, CNP, varsta, buget), Angajat(nume, prenume, CNP, varsta, salariu) {
    this->bonus = bonus;
}

PariorAngajat::PariorAngajat(const PariorAngajat& pariorAngajat) : Persoana(pariorAngajat), Parior(pariorAngajat), Angajat(pariorAngajat) {
    this->bonus = pariorAngajat.bonus;
}

PariorAngajat& PariorAngajat::operator=(const PariorAngajat& pariorAngajat) {
    if(this != &pariorAngajat) {
        Angajat::operator=(pariorAngajat);
        this->buget = pariorAngajat.buget;
        this->bonus = pariorAngajat.bonus;
    }
    return *this;
}

void PariorAngajat::adaugaBonus(double x) {
    for(int i = 1000; i <= this->buget; i += 1000)
        this->bonus += x;
}

istream& PariorAngajat::read(istream& in) {
    Parior::read(in);
    cout << "Salariu : ";
    in >> this->salariu;
    cout << "Bonus pentru a face reclama : ";
    in >> this->bonus;
    return in;
}

ostream& PariorAngajat::write(ostream& out) const{
    Parior::write(out);
    out << "Salariu : " << this->salariu << '\n';
    out << "Bonus pentru a face reclama : " << this->bonus << '\n';
    return out;
}

class Agentie {
private:
    string numeAgentie;
    int vechime;
    double medieCastigLunar; ///care este castigul mediul lunar
    double impozitCastig;
    double taxaRetragere;
public:
    Agentie();
    Agentie(string numeAgentie, int vechime, double medieCastigLunar, double impozitCastig, double taxaRetragere);
    Agentie(const Agentie& agentie);
    Agentie& operator=(const Agentie& agentie);

    friend istream& operator>>(istream& in, Agentie& agentie);
    friend ostream& operator<<(ostream& out, const Agentie& agentie);

    ~Agentie() {};
};


Agentie::Agentie() {
    this->numeAgentie = "Anonim";
    this->vechime = 0;
    this->medieCastigLunar = 0;
    this->impozitCastig = 0;
    this->taxaRetragere = 0;
}

Agentie::Agentie(string numeAgentie, int vechime, double medieCastigLunar, double impozitCastig, double taxaRetragere ) {
    this->numeAgentie = numeAgentie;
    this->vechime = vechime;
    this->medieCastigLunar = medieCastigLunar;
    this->impozitCastig = impozitCastig;
    this->taxaRetragere = taxaRetragere;
}

Agentie::Agentie(const Agentie& agentie) {
    this->numeAgentie = agentie.numeAgentie;
    this->vechime = agentie.vechime;
    this->medieCastigLunar = agentie.medieCastigLunar;
    this->impozitCastig = agentie.impozitCastig;
    this->taxaRetragere = agentie.taxaRetragere;
}

Agentie& Agentie::operator=(const Agentie& agentie) {
    if(this != &agentie) {
        this->numeAgentie = agentie.numeAgentie;
        this->vechime = agentie.vechime;
        this->medieCastigLunar = agentie.medieCastigLunar;
        this->impozitCastig = agentie.impozitCastig;
        this->taxaRetragere = agentie.taxaRetragere;
    }
    return *this;
}

istream& operator>>(istream& in, Agentie& agentie) {
    cout << "Nume agentie : ";
    in >> agentie.numeAgentie;
    cout << "Vechime : ";
    in >> agentie.vechime;
    cout << "Medie castig lunar : ";
    in >> agentie.medieCastigLunar;
    cout << "Impozit castig : ";
    in >> agentie.impozitCastig;
    cout << "Taxa retragere : ";
    in >> agentie.taxaRetragere;
    return in;
}

ostream& operator<<(ostream& out, const Agentie& agentie) {
    out << "Nume agentie : " << agentie.numeAgentie << '\n';
    out << "Vechime : " << agentie.vechime << '\n';
    out << "Medie castig lunar : " << agentie.medieCastigLunar << '\n';
    out << "Impozit castig : " << agentie.impozitCastig << '\n';
    out << "Taxa retragere : " << agentie.taxaRetragere << '\n';
    return out;
}

int main() {
    Agentie a;
    cin >> a;
    vector <Persoana*> persoane;
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
        switch(option) {
            case 0 : {
                option = 0;
                break;
            }
            case 1: {
                cout << "Selecteaza Persoana [parior/angajat/pariorAngajat] : ";
                string tip;
                cin >> tip;
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
                else cout << "Comanda invalida!\n";
                break;
            }
            case 2: {
                cout << "Ce persoana doriti sa dati afara ? ";
                int nr;
                cin >> nr;
                persoane.erase(persoane.begin() + nr - 1);
                break;
            }
            case 3: {
                for(const auto& i : persoane)
                    cout << *i;
                break;
            }

            case 4: {
                for(const auto& i : persoane)
                    if(!dynamic_cast<PariorAngajat*>(const_cast<Persoana*>(i)))
                        if(dynamic_cast<Parior*>(const_cast<Persoana*>(i)))
                            cout << *i;
                break;
            }
            case 5: {
                for(const auto& i : persoane)
                    if(!dynamic_cast<PariorAngajat*>(const_cast<Persoana*>(i)))
                        if(dynamic_cast<Angajat*>(const_cast<Persoana*>(i)))
                            cout << *i;
                break;
            }

            case 6: {
                for(const auto& i : persoane)
                    if(dynamic_cast<PariorAngajat*>(const_cast<Persoana*>(i)))
                        cout << *i;
                break;
            }

            case 7: {
                cout << a;
                break;
            }
            default:
                cout << "Optiune incorecta!\n";
        }
    }while(option != 0);

    return 0;
}

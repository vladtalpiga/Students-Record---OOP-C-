#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student{

    string nume;
    int anul_nasterii;
    int numar_credite;
    double media_generala;

public:

// Constructor, destructor

    Student(){
        this-> nume = "";
        this-> anul_nasterii = 0;
        this-> numar_credite = 0;
        this-> media_generala = 0;
    }

    Student(string nume, int anul_nasterii, int numar_credite, double media_generala){
        this-> nume = nume;
        this-> anul_nasterii = anul_nasterii;
        this-> numar_credite = numar_credite;
        this-> media_generala = media_generala;
    }

    Student(const Student& pers){
        this-> nume = pers.nume;
        this-> anul_nasterii = pers.anul_nasterii;
        this-> numar_credite = pers.numar_credite;
        this-> media_generala = pers.media_generala;
    }

    ~Student(){
        delete &nume;
        delete &anul_nasterii;
        delete &numar_credite;
        delete &media_generala;

    };

// Setters and getters

    void setNume(string nume){
        this-> nume = nume;
    }

    string getNume(){
        return nume;
    }

    void setAnulNasterii(int anul_nasterii){
        this-> anul_nasterii = anul_nasterii;
    }

    int getAnulNasterii(){
        return anul_nasterii;
    }

    void setNumarCredite(int numar_credite){
        this-> numar_credite = numar_credite;
    }

    int getNumarCredite(){
        return numar_credite;
    }

    void setMediaGenerala(int anul_nasterii){
        this-> anul_nasterii = anul_nasterii;
    }

    double getMediaGenerala(){
        return media_generala;
    }

// Supraincarcare << si >>

    friend istream& operator>>(istream& in, Student& s){

        cout<<"Nume student: ";
        in>>s.nume;

        cout<<endl<<"Anul nasterii: ";
        in>>s.anul_nasterii;

        cout<<endl<<"Numar credite: ";
        in>>s.numar_credite;

        cout<<endl<<"Media generala: ";
        in>>s.media_generala;
        cout<<endl;

        return in;
    }

    friend ostream& operator<<(ostream& out, Student &s){

        cout<<"Studentul "<<s.nume<<", nascut in anul "<<s.anul_nasterii<<", are "<<s.numar_credite<<" credite si media generala "<<s.media_generala<<"."<<endl;
        return out;
    }

    Student& operator=(const Student& a){

        nume = a.nume;
        anul_nasterii = a.anul_nasterii;
        numar_credite = a.numar_credite;
        media_generala = a.media_generala;

        return *this;
    }

};


class Grupa{

    Student* studenti_grupa;
    int numar_studenti;
    double medie_grupa;

public:

// Constructor, Destructor
    Grupa(){

        this-> studenti_grupa = NULL;
        this-> numar_studenti = 0;
        this-> medie_grupa = 0;
    }

    Grupa(Student* studenti_grupa, int numar_studenti, double medie_grupa){

        for(int i = 0; i < numar_studenti; i++)
            this-> studenti_grupa[i] = studenti_grupa[i];

        this-> numar_studenti = numar_studenti;
        this-> medie_grupa = medie_grupa;

    }

    Grupa(const Grupa& g){

        this-> studenti_grupa = g.studenti_grupa;
        this-> numar_studenti = g.numar_studenti;
        this-> medie_grupa = g.medie_grupa;

    }

    ~Grupa(){

        delete &studenti_grupa;
        delete &numar_studenti;
        delete &medie_grupa;
    };

// Getters and Setters
    void setStudentiGrupa(Student* studenti_grupa){
        this-> studenti_grupa = studenti_grupa;
    }

    Student* getStudentiGrupa(){
        return studenti_grupa;
    }

    void setNumarStudenti(int numar_studenti){
        this-> studenti_grupa = studenti_grupa;
    }

    int getNumarStudenti(){
        return numar_studenti;
    }

    void setMedieGrupa(double medie_grupa){
        this-> medie_grupa = medie_grupa;
    }

    double getMedieGrupa(){
        return medie_grupa;
    }

// Adaugare student
    void adaugaStudent(Student s){

        Student* aux = new Student[this-> numar_studenti];
        for (int i = 0; i < this-> numar_studenti; i++){

            aux[i].setNume(studenti_grupa[i].getNume());
            aux[i].setAnulNasterii(studenti_grupa[i].getAnulNasterii());
            aux[i].setNumarCredite(studenti_grupa[i].getNumarCredite());
            aux[i].setMediaGenerala(studenti_grupa[i].getMediaGenerala());
        }

        studenti_grupa = new Student[this-> numar_studenti + 1];

        for (int i = 0; i < this-> numar_studenti; i++){

            studenti_grupa[i] = aux[i];
//            studenti_grupa[i].setAnulNasterii(aux[i].getAnulNasterii());
//            studenti_grupa[i].setNume(aux[i].getNume());
//            studenti_grupa[i].setNumarCredite(aux[i].getNumarCredite());
//            studenti_grupa[i].setMediaGenerala(aux[i].getMediaGenerala());
        }
            studenti_grupa[this-> numar_studenti] = s;
//            studenti_grupa[this-> numar_studenti].setAnulNasterii(aux[this-> numar_studenti].getAnulNasterii());
//            studenti_grupa[this-> numar_studenti].setNume(aux[this-> numar_studenti].getNume());
//            studenti_grupa[this-> numar_studenti].setNumarCredite(aux[this-> numar_studenti].getNumarCredite());
//            studenti_grupa[this-> numar_studenti].setMediaGenerala(aux[this-> numar_studenti].getMediaGenerala());

        this-> numar_studenti++;
    }

// Stergere student

    void stergeStudent(string n){

        Student* aux = new Student[this-> numar_studenti - 1];

        for(int i = 0; i < this-> numar_studenti; i++)

            if(studenti_grupa[i].getNume() == n){

                for(int j = i; j < this-> numar_studenti - 1; j++){

                    studenti_grupa[j] = studenti_grupa[j + 1];

                }

                for(int j = 0; j < this-> numar_studenti - 1; j++){

                    aux[j] = studenti_grupa[j];
                }

                studenti_grupa = new Student[this-> numar_studenti - 1];

                for(int j = 0; j < this-> numar_studenti - 1; j++){

                    studenti_grupa[j] = aux[j];
                }

                this-> numar_studenti --;
            }
    }

// Verificare daca exista student dupa nume
        int existaStudent(string nume){

            for(int i = 0; i < this-> numar_studenti; i++){

                if(studenti_grupa[i].getNume()== nume)

                    return 1;
            }
            return 0;
        }

        Student dateStudent(string nume){

            for(int i = 0; i < this-> numar_studenti; i++){

                if(studenti_grupa[i].getNume()== nume)

                    return studenti_grupa[i];
            }

        }
};

    int meniu(){

        cout<<endl<<"Apasati tasta corespunzatoare comenzii pe care doriti sa o executati:"<<endl<<endl;
        cout<<"1. Adaugati un student in grupa."<<endl;
        cout<<"2. Eliminati un student din grupa."<<endl;
        cout<<"3. Verificati daca un student este in grupa. Daca numele acestuia exista in grupa, se vor afisa informatiile acestuia."<<endl;
//        cout<<"4. Actualizati media generala a unui student din grupa."<<endl;
        cout<<"0. EXIT"<<endl<<endl;

        int tasta;
        cin>>tasta;

        while(tasta > 3){

            cout<<"Optiunea introdusa este inexistenta. Introduceti alta comanda."<<endl;
            cin>>tasta;
        }

        return tasta;
    }

int main()
{
//    Student Vlad("Vlad", 2002, 30, 9.6);
//    G1.adaugaStudent(Vlad);
//
//    Student Andrei("Andrei", 2003, 24, 9.12);
//    G1.adaugaStudent(Andrei);
//
//    Student Marius("Marius", 2001, 17, 8.58);
//    G1.adaugaStudent(Marius);


//    Student* studenti = new Student[1];
//    studenti[0] = s;
//    Grupa(studenti, 1, 9.6);

Student A;
Grupa G1;

bool k = true;

while(k){

    int optiune = meniu();

    switch(optiune){

        case 0:
            {
                k = false;

                cout<<"La revedere!";

                break;
            }

        case 1:
            {
                cin>>A;

                G1.adaugaStudent(A);

                break;
            }

        case 2:
            {
                string name;

                cout<<"Introduceti numele studentului pe care doriti sa il eliminati:"<<endl;

                cin>>name;

                G1.stergeStudent(name);

                break;
            }

        case 3:
            {
                string nume_student;

                cout<<"Introduceti numele studentului: "<<endl;

                cin>>nume_student;

                if(G1.existaStudent(nume_student) == 0){

                    cout<<endl<<"Acest student nu se afla in grupa."<<endl<<endl;

                } else {

                    Student gasit = G1.dateStudent(nume_student);

                    cout<<endl<<gasit<<endl;
                }

                break;
            }

    //    case 4:
    //        {
    //            string nume_st;
    //        }

        }
}

    return 0;
}

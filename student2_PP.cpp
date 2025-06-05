#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Student.h"
#include "Materie.h"
#include "Nota.h"
#include "Absenta.h"
#include "Data.h"

using namespace std;

void vizualizareCatalog( vector<Student>& catalog) 
{   
    cout << endl;
    cout << "-----------------------------------------" << endl;
    for ( auto& elev : catalog) {
        elev.afisare();
        cout << "-----------------------------------------" << endl;
    }
}

vector<Student> citireFisier() {
    ifstream fin("file.txt");

    if (!fin.is_open()) {
        cerr << "Eroare la deschiderea file.txt\n";
        return {};
    }

    vector<Student> catalog;

    int nr_elevi, nr_materii;
    fin >> nr_elevi >> nr_materii;
    fin.ignore();

    for (int i = 0; i < nr_elevi; ++i) {
        string nume_elev;
        getline(fin, nume_elev);

        Student elev(nume_elev);

        for (int j = 0; j < nr_materii; ++j) {
            string materie;
            getline(fin, materie);

            Materie m(materie);

            string linie_note;
            getline(fin, linie_note);
            istringstream iss_note(linie_note);
            int nota, zi, luna, an;
            while (iss_note >> nota >> zi >> luna >> an) {
                m.adaugaNota(Nota(nota, Data(zi, luna, an)));
            }

            string linie_absente;
            getline(fin, linie_absente);
            istringstream iss_absente(linie_absente);
            int motivat;
            while (iss_absente >> zi >> luna >> an >> motivat) {
                m.adaugaAbsenta(Absenta(zi, luna, an, motivat == 1));
            }

            elev.adaugaMaterie(m);
        }

        catalog.push_back(elev);
    }

    return catalog;
}

void scriereFisier( vector<Student>& catalog, const string& numeFisier = "file.txt") {
    ofstream fout(numeFisier);

    if (!fout.is_open()) {
        cerr << "Eroare la deschiderea fisierului pentru scriere!\n";
        return;
    }

    int nr_elevi = catalog.size();
    int nr_materii = nr_elevi > 0 ? catalog[0].getMaterii().size() : 0;

    fout << nr_elevi << " " << nr_materii << "\n";

    for ( auto& elev : catalog) {
        fout << elev.getNume() << "\n";

        for (auto& materie : elev.getMaterii()) {
            fout << materie.getDenumire() << "\n";

            // Scrie notele
             const auto& note = materie.getNote();
            for (const auto& n : note) {
                fout << n.getValoare() << " "
                    << n.getData().getZi() << " "
                    << n.getData().getLuna() << " "
                    << n.getData().getAn() << " ";
            }
            fout << "\n";

            // Scrie absentele
            const auto& absente = materie.getAbsente();
            for (const auto& a : absente) {
                fout << a.getData().getZi() << " "
                    << a.getData().getLuna() << " "
                    << a.getData().getAn() << " "
                    << (a.getMotivata() ? 1 : 0) << " ";
            }
            fout << "\n";
        }
    }

    fout.close();
}

bool motiveazaAbsenta(vector<Student>& catalog, const string& nume_elev, const string& materie, const Data& data_absenta) {
    for (auto& elev : catalog) {
        if (elev.getNume() == nume_elev) {
            for (auto& m : elev.getMaterii()) {
                if (m.getDenumire() == materie) {
                    for (auto& abs : m.getAbsente()) {
                        const Data& d = abs.getData();
                        if (d == data_absenta) {
                            abs.motivareAbsenta();
                            return true;  // succes
                        }
                    }
                }
            }
        }
    }
    return false;  
}

bool stergereElev(vector<Student>& catalog, const string& numeElev) {
    for (auto it = catalog.begin(); it != catalog.end(); ++it) {
        if (it->getNume() == numeElev) {
            catalog.erase(it);
            return true; 
        }
    }
    return false; 
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Nu ai specificat nicio comanda.\n";
        return 1;
    }
    else
    {
        string comanda = argv[1];
        vector<Student> catalog = citireFisier();


        if (comanda == "vizualizare_catalog" && argc == 2) {
            vizualizareCatalog(catalog);
        }
        else 
            if (comanda == "motivare_absenta") {
                if (argc < 5) {
                    cerr << "Format: ./app_2.exe motivare_absenta <nume_elev> <materie> <zi>-<luna>-<an>\n";
                    return 1;
                }

                string nume_elev;
                for (int i = 2; i < argc - 2; ++i) {
                    if (i > 2) nume_elev += " ";
                    nume_elev += argv[i];
                }

                string materie = argv[argc - 2];
                string data_str = argv[argc - 1];

                int zi, luna, an;
                char delim;
                istringstream data_stream(data_str);
                if (!(data_stream >> zi >> delim >> luna >> delim >> an)) {
                    cerr << "Data invalida! Foloseste formatul zi-luna-an.\n";
                    return 1;
                }

                Data data(zi, luna, an);
                bool succes = motiveazaAbsenta(catalog, nume_elev, materie, data);

                if (succes) {
                    cout << "Absenta a fost motivata.\n";
                    scriereFisier(catalog);
                }
                else {
                    cout << "Absenta nu a fost gasita.\n";
                }
                scriereFisier(catalog,"file.txt");
            }
            else
                if (comanda == "adaugare_elev") {
                    if (argc < 3) {
                        cerr << "Format: ./app_2.exe adaugare_elev <nume_elev>\n";
                        return 1;
                    }

                    string nume_elev;
                    for (int i = 2; i < argc; ++i) {
                        if (i > 2) nume_elev += " ";
                        nume_elev += argv[i];
                    }

                    Student elevNou = adaugaStudent(nume_elev, catalog[0]);
                    catalog.push_back(elevNou);

                    scriereFisier(catalog, "file.txt");
                }
                else 
                    if (comanda == "stergere_elev")
                    {
                        string numeElev;
                        for (int i = 2; i < argc; ++i) {
                            if (i > 2) numeElev += " ";
                            numeElev += argv[i];
                        }
                        bool sters = stergereElev(catalog, numeElev);
                        if (sters) {
                            cout << "Elevul " << numeElev << " a fost sters din catalog.\n";
                        }
                        else {
                            cout << "Elevul " << numeElev << " nu a fost gasit in catalog.\n";
                        }
                        scriereFisier(catalog, "file.txt");
                    }
            else {
                cout << argv[1] << endl;
                cout << "Comanda necunoscuta sau argumente insuficiente.\n";
            }

    }
    return 0;
}
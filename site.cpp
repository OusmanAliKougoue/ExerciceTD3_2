#include <iostream>
#include <cstring>
#include "Document.h"
#include "site.h"

using namespace std;

site::site(int N) {
    cout << "\nAppel du constructeur pour l'objet site de l'adresse :" << " " << this << endl;
    nb_max = N;
    doc = new Document*[nb_max];
    if (doc == nullptr) {
        cerr << "Erreur d'allocation de mémoire :!!" << endl;
        exit(-1);
    }
    for (int i = 0; i < nb_max; i++) {
        doc[i] = nullptr;
    }
    nb_doc = 0;
}

site::~site() {
    cout << "\nAppel du destructeur pour l'objet site de l'adresse :" << " " << this << endl;
    if (doc) {
        for (int i = 0; i < nb_doc; i++)
            delete doc[i]; 
        delete[] doc; 
    }
}

void site::ajouterDoc(const Document& d) {
    if (nb_doc >= nb_max) {
        cerr << "Espace insuffisant !!" << endl;
        exit(-1);
    }
    doc[nb_doc] = new Document(d);
    nb_doc++;
}

void site::supprimerdoc(const char* title) {
    int i = 0, j;
    while (i < nb_doc && (strcmp(doc[i]->getTitre(), title) != 0)) {
        i++;
    }
    if (i < nb_doc) {
        delete doc[i];
        for (j = i; j < nb_doc - 1; j++) {
            doc[j] = doc[j + 1];
        }
        doc[--nb_doc] = nullptr;
    }
}
void situation(site s) {
    cout << "Cette situation est un passage d'un objet par valeur à une fonction :" << s.nb_doc<< endl;
}
bool site::contient(const char* motcle) const {
    for (int i = 0; i < nb_doc; i++) {
        if (doc[i]->motexiste(motcle))
            return true;
    }
    return false;
}

void site::affichersite() const {
    for (int i = 0; i < nb_doc; i++) {
        cout << "Doc n° " << i + 1 << ":" << endl;
        doc[i]->afficherDoc();
    }
}
int site::getTaille() const {
    return nb_doc;
}
//surdefinitions des operateurs 
site::site(const site& s2) {
    nb_max = s2.nb_max;
    nb_doc = s2.nb_doc;
    doc = new Document*[nb_max]; 
    for (int i = 0; i < nb_doc; i++) {
        doc[i] = new Document(*s2.doc[i]); 
    }
}

site& site::operator=(const site& s2) {
    if (this == &s2) {
        return *this;
    }
    if (doc) {
        for (int i = 0; i < nb_doc; i++) {
            delete doc[i];
        }
        delete[] doc; 
    }
    nb_max = s2.nb_max;
    nb_doc = s2.nb_doc;
    doc = new Document*[nb_max]; 
    for (int i = 0; i < nb_doc; i++) {
        doc[i] = new Document(*s2.doc[i]); 
    }
    return *this;
}

site& site::operator+=(const Document& d) {
    this->ajouterDoc(d);
    return *this;
}

site& site::operator-=(const char* titre) {
    this->supprimerdoc(titre);
    return *this;
}

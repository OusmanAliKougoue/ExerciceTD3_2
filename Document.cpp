#include "Document.h"
#include <cstring>
#include <iostream>
using namespace std;
Document::Document(char* title, int n) {
    cout<<"\nAppelle du constructeur pour l'objet Document de l'adresse :"<<" "<<this<<endl;
    taille_max=n, nb_mots=0; 
    titre = new char[strlen(title) + 1];
    if (titre == nullptr) {
        cerr << "Erreur d'allocation de la mémoire pour le titre !!" << endl;
        exit(-1);
    }
    strcpy(titre, title);

    listesmots = new char*[taille_max];
    if (listesmots == nullptr) {
        cerr << "Erreur d'allocation de la mémoire pour les mots !!" << endl;
        exit(-1);
    }
    for (int i = 0; i < taille_max; i++) {
        listesmots[i] = nullptr;
    }
}
Document::~Document() {
     cout<<"\nAppelle du destructeur pour l'objet Document de l'adresse :"<<" "<<this<<endl;
    if (titre) {
        delete[] titre;
    }
    if (listesmots) {
        for (int i = 0; i < nb_mots; i++) {
            delete[] listesmots[i];
        }
        delete[] listesmots;
    }
}
 char* Document::getTitre()const{
    return titre;
 }
void Document::ajouterMot(char* mot) {
    if (nb_mots >= taille_max) {
        cerr << "Espace insuffisant" << endl;
        exit(-1);
    }
    listesmots[nb_mots] = new char[strlen(mot) + 1];
    if (listesmots[nb_mots] == nullptr) {
        cerr << "Erreur d'allocation de la mémoire pour un mot !!" << endl;
        exit(-1);
    }
    strcpy(listesmots[nb_mots], mot);
    nb_mots++;
}
Document::Document(const Document& d1) {
     cout<<"\nAppelle du constructeur de recopie pour l'objet Document de l'adresse :"<<" "<<this<<endl;
      taille_max=d1.taille_max;
       nb_mots=d1.nb_mots;
    titre = new char[strlen(d1.titre) + 1];
    if (titre == nullptr) {
        cerr << "Erreur d'allocation de la mémoire pour le titre !!" << endl;
        exit(-1);
    }
    strcpy(titre, d1.titre);

    listesmots = new char*[taille_max];
    if (listesmots == nullptr) {
        cerr << "Erreur d'allocation de la mémoire pour les mots !!" << endl;
        exit(-1);
    }
    for (int i = 0; i < nb_mots; i++) {
        listesmots[i] = new char[strlen(d1.listesmots[i]) + 1];
        if (listesmots[i] == nullptr) {
            cerr << "Erreur d'allocation de la mémoire pour un mot !!" << endl;
            exit(-1);
        }
        strcpy(listesmots[i], d1.listesmots[i]);
    }
    for (int i = nb_mots; i < taille_max; i++) {
        listesmots[i] = nullptr;
    }
}
Document& Document::operator=(const Document& d1) {
    if (this == &d1) {
        return *this;
    }
    if (titre) {
        delete[] titre;
    }
    if (listesmots) {
        for (int i = 0; i < nb_mots; i++) {
            delete[] listesmots[i];
        }
        delete[] listesmots;
    }
    titre = new char[strlen(d1.titre) + 1];
    if (titre == nullptr) {
        cerr << "Erreur d'allocation de la mémoire pour le titre !!" << endl;
        exit(-1);
    }
    strcpy(titre, d1.titre);

    taille_max = d1.taille_max;
    nb_mots = d1.nb_mots;

    listesmots = new char*[taille_max];
    if (listesmots == nullptr) {
        cerr << "Erreur d'allocation de la mémoire pour les mots !!" << endl;
        exit(-1);
    }
    for (int i = 0; i < nb_mots; i++) {
        listesmots[i] = new char[strlen(d1.listesmots[i]) + 1];
        if (listesmots[i] == nullptr) {
            cerr << "Erreur d'allocation de la mémoire pour un mot !!" << endl;
            exit(-1);
        }
        strcpy(listesmots[i], d1.listesmots[i]);
    }
    for (int i = nb_mots; i < taille_max; i++) {
        listesmots[i] = nullptr;
    }

    return *this;
}
void Document::afficherDoc() const {
    cout << "Titre: " << titre << endl;
    cout<<"Mots-cles :";
    for (int i = 0; i < nb_mots; i++) {
        cout << listesmots[i] << " ";
    }
    cout << endl;
}
bool Document::motexiste(const char* mot){
    for (int i = 0; i < nb_mots; i++)
    {
       if(strcmp(listesmots[i],mot)==0)
       return true;
    }
    return false;
    
}

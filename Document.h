#ifndef DOCUMENT_H
#define DOCUMENT_H
#include<iostream>
#include <cstring>
using namespace std;
class Document{
    private:
    char* titre;
    char **listesmots;
    int taille_max;
    int nb_mots;
    public:
    Document(char*,int);
    ~Document();
    Document(const Document&);
    bool motexiste(const char*);
    void ajouterMot(char*);
    char* getTitre()const;
    void afficherDoc()const;
    Document& operator=(const Document& );
    
};
#endif 
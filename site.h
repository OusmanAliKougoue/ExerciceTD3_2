#ifndef SITE_H
#define SITE_H
#include"Document.h"
#include<iostream>
#include <cstring>
using namespace std;

class site
{
private:
    Document** doc;
    int nb_max;
    int nb_doc;
public:
    site(int );
    ~site();
    void ajouterDoc(const Document& d);
    void supprimerdoc(const char* titre);
    
    site(const site&);
    site& operator=(const site&);
    bool contient(const char * )const;
    void affichersite()const;
    int getTaille()const;
    friend void situation(site);
    site& operator+=(const Document&);
    site& operator-=(const char* titre);
   
};
#endif
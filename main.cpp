#include"site.h"
#include"Document.h"
int main()
{
    site s(10);

    char  title[]="sciencefo";
    char mot1[]="moral";
    char mot2[]="dignite";
    char mot3[]="experience";
    Document d1(title,5);
    d1.ajouterMot(mot1);
    d1.ajouterMot(mot2);
    d1.ajouterMot(mot3);

     char  title1[]="sciencefo1";
    char mot11[]="moral1";
    char mot22[]="dignite1";
    char mot33[]="experience1";
    Document d2(title1,5);
    d2.ajouterMot(mot11);
    d2.ajouterMot(mot22);
    d2.ajouterMot(mot33);
    
     char  title2[]="sciencefo2";
    char mot12[]="moral2";
    char mot23[]="dignite2";
    char mot34[]="experience2";
    Document d3(title2,4);
    d3.ajouterMot(mot12);
    d3.ajouterMot(mot23);
    d3.ajouterMot(mot34);
     cout<<"le titre du document d2 est :"<<d3.getTitre()<<endl;

     s+=d1;
     s+=d2;
     s+=d3;
      s.affichersite();

  if(s.contient(mot12)){
    cout<<"le site contient le document de mot-cle :"<<mot12<<endl;
  }
  else{
     cout<<"le site ne contient pas le document de mot-cle :"<<mot12<<endl;
  }
   site s2=s;
    situation(s);
  cout<<"affichage site s2 :"<<endl;s2.affichersite();
  s-=d3.getTitre();
  cout<<"la suppresion de du document avec le titre :"<<title2<<"\treussi avec succes ."<<endl;
  s.affichersite();
  

    return 0;
}









 //s.supprimerdoc(d3.getTitre());
  /* s.ajouterDoc(d1);
     s.ajouterDoc(d2);
     s.ajouterDoc(d3);
    */
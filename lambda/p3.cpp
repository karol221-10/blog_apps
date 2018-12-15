#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct dziennik {
    int id;
    string imie;
    string nazwisko;
    int ocena;
};
int main()
{
    vector<dziennik> lista_osob = {{1,"Jan","Kowalski",5},{4,"Marcin","Pomagier",4},{2,"Patryk","Programista",3},{7,"Teodor","Mufflon",2},{3,"Adam","Nowak",4},{5,"Karol","Zębkiewicz",2}};
    auto wypiszListe = [lista_osob](){
        for(dziennik osoba: lista_osob) {
            cout<<"Nr: "<<osoba.id<<endl;
            cout<<"imie: "<<osoba.imie<<endl;
            cout<<"nazwisko: "<<osoba.nazwisko<<endl;
            cout<<"ocena: "<<osoba.ocena<<endl;
            cout<<endl;
        }
    };
    cout<<"Przed sortowaniem"<<endl;
    wypiszListe();
    sort(lista_osob.begin(),lista_osob.end(),[](dziennik a,dziennik b){return a.id>b.id;});    
    cout<<"Posortowano wg indeksow"<<endl;
    wypiszListe();
    sort(lista_osob.begin(),lista_osob.end(),[](dziennik a,dziennik b){return a.nazwisko>b.nazwisko;});    
    cout<<"Posortowano wg nazwisk"<<endl;
    wypiszListe();
    return 0;
}

#include<iostream>
#include<stdlib.h>
using namespace std;
#include"palazzo.h"

int main(){
    Pavimento ciao;
    Palazzo villaCosta (4); //creo il palazzo di 4 stanze
    
    villaCosta.configuraStanze(1,0); //configuro le varie stanze definendo le dimensioni e il numero di persone all'interno (per ora tutte le stanze sono vuote). Se non indico il valore delle 3 dimensioni la stanza vine lasciata così com'è; in questo caso la stanza uno rimane di dimensioni di default
    villaCosta.configuraStanze(2,0,5,4,3);
    villaCosta.configuraStanze(3,0,10,10,5);
    villaCosta.configuraStanze(4,0,2,2,4);
    
    villaCosta.status(); //stampo lo stato delle 4 stanze del palazzo
    
    cout<<"numero di stanze nel palazzo "<<villaCosta.get_sizeP()<<endl;
    cout<<"superficie totale del pavimento "<<villaCosta.get_superficieTot()<<endl;
    cout<<"superficie totale delle pareti "<<villaCosta.get_paretiTot()<<endl;
    cout<<"volume totale "<<villaCosta.get_volumeTot()<<endl;
    cout<<"persone nel palazzo "<<villaCosta.get_NpersoneTot()<<endl;
    cout<<"posti disponibili nel palazzo "<<villaCosta.posti_disponibiliTot()<<endl;
    
    cout<<endl<<"apertura del palazzo"<<endl<<endl;
    for(int i=0; villaCosta.posti_disponibiliTot()>0; i++){ //inserisco randomicamente (numeri che vanno dallo 0 al 20) persone nel palazzo finchè la sua capicità non si satura
        villaCosta.INpalazzo(rand()%20); 
    }
    villaCosta.status();
    
    cout<<"persone nel palazzo "<<villaCosta.get_NpersoneTot()<<endl;
    cout<<"posti disponibili "<<villaCosta.posti_disponibiliTot()<<endl;
    
    cout<<endl<<"evacuazione del palazzo"<<endl;
    villaCosta.allarme();//svuoto il palazzo
    cout<<"persone nel palazzo "<<villaCosta.get_NpersoneTot()<<endl<<endl;
    villaCosta.status();
    cout<<endl;

    
    
    Stanza cucina(5,4,3); //creo una stanza cucina di lunghezza 5m, larghezza 4 e altezza 3
    cucina.IN(1); //inseriasco una persona ll'interno di cucina
    cout<<endl<<"Cucina: "<<endl;
    cout<<cucina.get_lunghezza()<<" * "<<cucina.get_larghezza()<<" * "<<cucina.get_altezza()<<endl;
    cout<<"superficie "<<cucina.get_area()<<endl<<"persone "<<cucina.get_Npersone()<<endl;
    
    Stanza salotto(6,5,3.2); //creo la stanza salotto
    cout<<endl<<"Salotto: "<<endl;
    salotto.IN(3); //inserisco 3 persone all'interno
    cout<<salotto.get_lunghezza()<<" * "<<salotto.get_larghezza()<<" * "<<salotto.get_altezza()<<endl;
    cout<<"superficie "<<salotto.get_area()<<endl<<"persone "<<salotto.get_Npersone()<<endl;
    
    Stanza openspace = cucina + salotto; //creo la stanza openspace come somma di cucina e salotto
    cout<<endl<<"openspace: "<<endl;
    cout<<openspace.get_lunghezza()<<" * "<<openspace.get_larghezza()<<" * "<<openspace.get_altezza()<<endl;
    cout<<"superficie "<<openspace.get_area()<<endl<<"persone "<<openspace.get_Npersone()<<endl;
    return 0;
}
#include "palazzo.h"
#include <iostream>

Palazzo::Palazzo(int size){
    if (size>0){
        P= new Stanza[size];
        this->size=size;
    }
    else {
        P= new Stanza[1];
        this->size=1;
    }
}
Palazzo::~Palazzo(){
    delete[] P; 
}
int Palazzo::get_sizeP(){
    return size;
}
double Palazzo::get_superficieTot(){
    double s=0;
    for(int i=0;i<size;i++){
        s+=P[i].get_area();
    }
    return s;
}
double Palazzo::get_paretiTot(){
    double p=0;
    for(int i=0;i<size;i++){
        p+=P[i].get_pareti();
    }
    return p;
}
double Palazzo::get_volumeTot(){
    double v=0;
    for(int i=0;i<size;i++){
        v+=P[i].get_volume();
    }
    return v;
}
int Palazzo::get_NpersoneTot(){
    int n=0;
    for(int i=0;i<size;i++){
        n+=P[i].get_Npersone();
    }
    return n;
}
void Palazzo::nuoveStanze(int n){
    if(n>0){
        Stanza* newP;
        newP= new Stanza[size];
        for(int i=0;i<size;i++){
            newP[i]= P[i];
        }
        delete [] P; 
        P= new Stanza[size+n];
        for(int i=0;i<size;i++){
            P[i]= newP[i];
        }
        delete [] newP;
        size+=n;
    }
    return;
}
void Palazzo::configuraStanze(int stanza, int persone, double lunghezza, double larghezza, double altezza){
    if (stanza>0 && stanza<=size && persone>=0 && lunghezza>0 && larghezza>0 && altezza>0){
        Stanza s(lunghezza, larghezza, altezza);
        s.IN(persone);
        P[stanza-1]= s;
    }
    else if(stanza>0 && stanza<=size && persone>=0 && (lunghezza<=0 || larghezza<=0) && altezza>0){
        Stanza s(P[stanza-1].get_lunghezza(),P[stanza-1].get_larghezza(), altezza);
        s.IN(persone);
        P[stanza-1]= s;
    }
    else if(stanza>0 && stanza<=size && persone>=0 && lunghezza>0 && larghezza>0 && altezza<=0){
        Stanza s(lunghezza, larghezza, P[stanza-1].get_altezza());
        s.IN(persone);
        P[stanza-1]= s;
    }
    else if(stanza>0 && stanza<=size && persone>=0 && (lunghezza<=0 || larghezza<=0) && altezza<=0){
        P[stanza-1].IN(persone);
    }
    return;
}
void Palazzo::sposta(int stanza1, int stanza2, int persone){
    if (stanza1>0 && stanza1<=size && stanza2>0 && stanza2<=size && stanza1!=stanza2 && persone>0){
        int from_stanza1=persone;
        if (P[stanza1-1].get_Npersone()<persone) from_stanza1=P[stanza1-1].get_Npersone();
        int a=P[stanza2-1].get_Npersone();
        P[stanza2-1].IN(from_stanza1);
        a=P[stanza2-1].get_Npersone()-a;
        P[stanza1-1].OUT(a);
    }
    return;
}
int Palazzo::posti_disponibiliTot(){
    int count=0;
    for(int i=0;i<size;i++){
        count+=P[i].posti_disponibili();
    }
    return count;
}
void Palazzo::INpalazzo(int persone){
    if(persone>0){
        int restanti=persone;
        for(int i=0;restanti>0 && posti_disponibiliTot()>0 && i<=size-1;i++){
            int a=P[i].get_Npersone();
            P[i].IN(restanti);
            restanti-=P[i].get_Npersone()-a;
        }
    }
    return;
}
void Palazzo::allarme(){
    for(int i=0; i<size;i++){
        P[i].svuota();
    }
    return;
}
void Palazzo::status(){
    for(int i=0; i<size; i++){
        std::cout<<"stanza "<<i+1<<std::endl;
        std::cout<<"lunghezza "<<P[i].get_lunghezza()<<"  "<<"larghezza "<<P[i].get_larghezza()<<"  "<<"altezza "<<P[i].get_altezza()<<std::endl;
        std::cout<<"persone nella stanza "<<P[i].get_Npersone()<<std::endl;
        std::cout<<"posti disponibili nella stanza "<<P[i].posti_disponibili()<<std::endl<<std::endl;
    }
    return;
}
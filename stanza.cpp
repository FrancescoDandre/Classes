#include"stanza.h"

Stanza::Stanza(double lunghezza, double larghezza, double altezza):Pavimento(lunghezza, larghezza){
    Npersone=0;
    if(altezza>0){
        this->altezza=altezza;
    }
    else this->altezza=2.70;
    
}
Stanza::Stanza(){
    altezza=2.70;
    Npersone=0;
}
double Stanza::get_altezza(){
    return altezza;
}
double Stanza::get_pareti(){
    return get_perimetro()*get_altezza();
}
double Stanza::get_volume(){
    return get_area()*get_altezza();
}
int Stanza::get_Npersone(){
    return Npersone;
}
int Stanza::posti_disponibili(){
    return (get_area()/8 < get_volume()/10)?(get_area()/8)-Npersone:(get_volume()/10)-Npersone;
}
void Stanza::IN(int n){
    if (n>0){
        int posti=posti_disponibili();
        if(posti>n) Npersone+=n;
        else Npersone+=posti;
    }
    return;
}
void Stanza::OUT(int n){
    if (n>0){
        Npersone=(get_Npersone()>n)? Npersone-n:0;
    }
    return;
}
void Stanza::svuota(){
    Npersone=0;
    return;
}
Stanza Stanza::operator+(Stanza& a){
    double ln;
    double lr;
    double h;
    h=(get_altezza()<a.get_altezza())?a.get_altezza():altezza;
    lr=larghezza+a.get_larghezza();
    ln=(get_area()+a.get_area())/lr;
    Stanza s(ln, lr, h);
    s.IN(get_Npersone()+a.get_Npersone());
    return s;
}
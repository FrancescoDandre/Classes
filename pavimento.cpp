#include"pavimento.h"

Pavimento::Pavimento(double lunghezza,double larghezza){
    if (lunghezza>0 && larghezza>0){
        this->lunghezza=lunghezza;
        this->larghezza=larghezza;
    }
    else {
        this->lunghezza=4.0;
        this->larghezza=3.0;
    }
}
Pavimento::Pavimento(){
    lunghezza=4.0;
    larghezza=3.0;
}
double Pavimento::get_lunghezza(){
    return lunghezza;
}
double Pavimento::get_larghezza(){
    return larghezza;
}
double Pavimento::get_area(){
    return lunghezza*larghezza;
}
double Pavimento::get_perimetro(){
    return 2*(lunghezza+larghezza);
}
#include "stanza.h"

class Palazzo {
    private:
    int size;
    Stanza* P; // la classe palazzo ha come unico attributo un array di stanze. Se size<=0 il palazzo viene creato di una solo stanza
    public:
    Palazzo (int size); //size è il numero di stanze di cui si vuole creare il palazzo (le stanze sono inizialmente create tutte di dimensioni standard)
    ~Palazzo();
    int get_sizeP(); //ritorna il numero di stanze del palazzo
    double get_superficieTot();
    double get_paretiTot();
    double get_volumeTot();
    int get_NpersoneTot(); //ritorna il numero totoale di persone contenute nel palazzo, sommando le persone di tutte le stanze
    void nuoveStanze(int n); //crea n nuove stanze (di dimensione standard)
    void configuraStanze(int stanza, int persone, double lunghezza=-1, double larghezza=-1, double altezza=-1); //una volta creato il palazzo è possibile andare a configuare le sue varie stanze, definendo quindi per qualsiasi sua stanza il numero di persone che contiene e le 3 dimensioni. Se le dimensioni non vengono indicate oppure sono <= 0, la stanza (il pavimento e/o l'altezza) viene lasciata così com'è e vengono solo inserite le persone. Se il numero della stanza non è tra le stanze del palazzo e/o il numero delle persone è <0 il metodo non fa nulla.
    void sposta(int stanza1, int stanza2, int persone); //metodo che sposta persone dalla stanza1 alla stanza 2 (sposta solo le persone per le quali c'è posto nella nuova stanza)
    int posti_disponibiliTot(); //ritorna il numero di posti disponibili (rimasti) all'interno di tutto il palazzo
    void INpalazzo(int persone); //inserisce persone all'interno del palazzo. partendo dalla prima stanza fino all'ultima riempie progressivamente il palazzo fino a quando tutte le persone non sono state inserite o finchè il palazzo non è pieno
    void allarme(); //metodo che svuota tutte le stanze del palazzo
    void status(); //stampa a temrminale lo stato attuale del palazzo stanza per stanza
};
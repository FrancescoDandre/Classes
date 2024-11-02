#include"pavimento.h"
class Stanza: public Pavimento{
    protected:
    double altezza;
    int Npersone;
    public:
    Stanza(double lunghezza, double larghezza, double altezza); //se le dimensioni sono <=0, la stanza viene creata di dimensioni standard
    Stanza();
    double get_altezza();
    double get_pareti(); //restituisce la superifice complessiva delle pareti della stanza
    double get_volume();
    int get_Npersone();
    int posti_disponibili(); //ritorna il numero di posti rimansti nella stanza
    void IN(int n); //permette di inserire n persone nella stanza; se n>posti disponibili il metodo satura la stanza inserendo solo le persone che possono starci
    void OUT(int n); //metodo che rimuove n persone dalla stanza; se n>persone nella stanza la stana viene svuotata del tutto
    void svuota(); //svuota completamente la stanza
    Stanza operator+(Stanza& a); //operatore somma fra stanze. Il metodo restituisce una stanza con altezza pari alla più alta fra le 2, con area la somma delle aree (con larghezza pari alla somma delle larghezze) e con un numero di persone pari alla somma delle persone contenute nelle 2 stanze di partenza
};
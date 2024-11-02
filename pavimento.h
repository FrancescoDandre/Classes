class Pavimento{
    protected:
    double lunghezza;
    double larghezza;
    public:
    Pavimento(double lunghezza, double larghezza); //costruttore. Se larhezza e/o lunghezza sono <=0 il pavimento vine creato di dimensioni standard
    Pavimento(); //costruttore di default
    double get_lunghezza();
    double get_larghezza();
    double get_area();
    double get_perimetro();
};
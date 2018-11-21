#ifndef NO_H
#define NO_H


class no
{
private:
    item* dados;
    no* pai;
    no* filhoEsquerdo;
    no* filhoDireito;

public:
    no();
    item* getDados();
    no* getPai();
    no* getfilhoEsquerdo();
    no* getfilhoDireito();
    void setPai(no* aux){pai=aux;}
    void setfilhoEsquerdo(no* aux){filhoEsquerdo = aux;}
    void setfilhoDireito(no* aux){filhoDireito = aux;}
    static no* montano(item *);
    static item* desmontano(no*);

    //geters e seters;
};

#endif // NO_H

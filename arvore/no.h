#ifndef NO_H
#define NO_H
#include "item.h"


class no
{
private:
    Item* dados;
    no* pai;
    no* filhoEsquerdo;
    no* filhoDireito;

public:
    no();
    Item* getDados();
    no* getPai();
    no* getfilhoEsquerdo();
    no* getfilhoDireito();
    void setPai(no* aux){pai=aux;}
    void setfilhoEsquerdo(no* aux){filhoEsquerdo = aux;}
    void setfilhoDireito(no* aux){filhoDireito = aux;}
    static no* montano(Item*);
    static Item* desmontano(no*);

    //geters e seters;
};

#endif // NO_H

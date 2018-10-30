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
    no* montano(item*);
    item* desmontano(no*);
    //geters e seters;
};

#endif // NO_H

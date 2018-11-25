#ifndef ABP_H
#define ABP_H
#include "no.h"
#include <iostream>


class ABP
{
private:
    no* raiz, *nulo;
public:
    ABP();
    bool inserir(Item*);
    Item* retirar(Item*);
    Item* consultar(Item*);
    void mostrarOrdem(no* pNo, std::string &aux)const;
    void mostrarOrdem(std::string &aux)const;
    void mostrarPreOrdem(no* pNo, std::string &aux)const;
    void mostrarPreOrdem(std::string &aux)const;
    void mostrarPosOrdem(no* pNo, std::string &aux)const;
    void mostrarPosOrdem(std::string &aux)const;
    bool vazia()const;

private:
    no* minimo(no*);
    no* maximo(no*);
    no* antecessor(no*);
    no* sucessor(no*);

};

#endif // ABP_H

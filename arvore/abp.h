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
    bool inserir(item*);
    item* retirar(item*);
    item* consultar(item*);
    ~ABP();
private:
    no* minimo(no*)const;
    no* maximo(no*)const;
    no* antecessor(no*)const;
    no* sucessor(no*)const;
public:
    bool vazia()const;
    std::string mostrarOrdem()const;
    std::string mostrarPosOrdem()const;
    std::string mostrarPreOrdem()const;
};

#endif // ABP_H

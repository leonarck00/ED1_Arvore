#ifndef ABP_H
#define ABP_H
#include "no.h"


class ABP
{
private:
    no* raiz;
public:
    ABP();
    logico inserir(item*);
    item* retirar(item*);
    item* consultar(item*);
    std::string mostrarOrdem();
    std::string mostrarPosOrdem();
    std::string mostrarPreOrdem();
    logico vazia();
    no* minimo(no*);
    no* maximo(no*);
    no* antecessor(no*);
    no* sucessor(no*);
};

#endif // ABP_H

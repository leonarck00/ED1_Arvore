#include "no.h"

no::no()
{

}

Item* no::getDados(){
    return dados;
}

no* no::getPai(){
    return pai;
}

no* no::getfilhoEsquerdo(){
    return filhoEsquerdo;
}

no* no::getfilhoDireito(){
    return filhoDireito;
}

no* no::desmontano(no* aux){
    Item* ptr = aux->dados;
    delete aux;
    aux = 0;
    return ptr;
}

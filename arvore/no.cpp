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

no* no::montano(Item *aux){
    no *ptr=new no;
    ptr->dados=aux;
    ptr->pai=nullptr;
    ptr->filhoEsquerdo=nullptr;
    ptr->filhoDireito=nullptr;
    return ptr;
}

Item* no::desmontano(no* aux){
    Item* ptr = aux->dados;
    delete aux;
    aux = 0;
    return ptr;
}

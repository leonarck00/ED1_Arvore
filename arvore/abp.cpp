#include "abp.h"

ABP::ABP()
{
    nulo = no::montano(0);
    raiz = nulo;
}

bool ABP::inserir(item* aux){
    item*
}


item* ABP::consultar(item* aux){
    if(aux == 0) return 0;
    no* ptr = raiz;

    while(ptr != nulo){
        if(aux -> getcodBarras() < ptr -> getDados()->getcodBarras()){
            ptr = ptr->getfilhoEsquerdo();
        }else
            if(aux->getcodBarras() > ptr->getDados()->getcodBarras()){
                ptr = ptr->getfilhoDireito();
            }else{
                break;
            }
    }
}
if(ptr == nullo) return 0;
item* copia = new item;
*copia = *ptr->getDados();
return copia;

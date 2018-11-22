#include "abp.h"

ABP::ABP()
{
    nulo = no::montano(0);
    raiz = nulo;
}

bool ABP::inserir(item* aux){
    item *trab=consultar(aux);
    if(trab != 0)
    {
        return false;
    }
    int de;
    no *ptr=no::montano(aux);
    if(vazia())
    {
        raiz=ptr;
        ptr->setPai(nulo);
        ptr->setfilhoEsquerdo(nulo);
        ptr->setfilhoDireito(nulo);
        return true;
    }
    no* atual = raiz;
    no* anterior = raiz;
    while(atual !=nulo)
    {
        if(ptr->getdados()->getcodbarras() < atual->getdados()->getcodbarras())
        {
            anterior=atual;
            atual=atual ->getfilhoDireito();
            de=0;
        }
        ptr ->setfilhoEsquerdo(nulo);
        ptr ->setfilhoDireito(nulo);
        ptr ->setpai(anterior);
        if(de == 0)
        {
            anterior = setfilhoEsquerdo(ptr);
        }
        if(de == 1)
        {
            anterior -> setfilhoDireito(ptr);
        }
    }
    return true;
}


item* ABP::consultar(item* aux)
{
    if(aux = 0)
    {
        return 0;
    }
    no *ptr=raiz;
    while(ptr != nulo)
    {
        if(aux -> getcodBarras() < ptr -> getDados() -> getcodBarras())
        {
            ptr=ptr ->getfilhoEsquerdo();
        }
        else
        {
            if(aux->gtecodBarras() > ptr ->getDados() ->getcodBarras())
            {
                ptr = ptr -> getfilhoDireito();
            }
            else
            {
                break;
            }
        }
    }
    if(ptr==nulo)
    {
        return 0;
    }
    Item *copia=new Item;
    *copia = *ptr->getDados();
    return copia;

}

void ABP::mostrarOrdem(no* pNo, std::string &aux)const{
    if(pno !=nulo)
    {
        mostrarOrdem(pNo->getfilhoEsquerdo()aux);
        aux+=pNo->getDados()->getItem();
        mostrarOrdem(pNo->getfilhoDireito(),aux);
    }
}

void ABP::mostrarOrdem(std::string &aux) const{
    mostrarOrdem(raiz,aux);
}

void ABP::mostrarPreOrdem(no* pNo,std::string &aux)const{
    if(pNo != nulo)
    {
        aux+=pNo->getDados()->getItem();
        mostrarOrdem(pNo->getfilhoEsquerdo(),aux);
        mostrarOrdem(pNo->getfilhoDireito(),aux);
    }
}

void ABP::mostrarPreOrdem(std::string &aux)const{
    mostrarPreOrdem(raiz,aux);
}

void ABP::mostrarPosOrdem(no* pNo,std::string &aux)const{
    if(pNo != nulo)
    {
        mostrarOrdem(pNo->getfilhoEsquerdo(),aux);
        mostrarOrdem(pNo->getfilhoDireito(),aux);
        aux+=pNo->getDados()->getItem();
    }
}

bool ABP::vazia(){
    return (vazia==nulo);
}

no* ABP::minimo(no *pNo){
    no* *aux=pNo;
    while(aux->getfilhoEsquerdo()!=nulo)
    {
        aux=aux->getfilhoEsquerdo();
    }
    return aux;
}

No* ABP::maximo(no* pNo){
    no *aux=pNo;
    while(aux->getfilhoDireito()!= nulo)
    {
        aux=aux->getfilhoDireito();
    }
    return aux;
}

no* ABP::vazia(no* pNo)
{
    if(pNo->getfilhoEsquerdo()!=nulo)
    {
        return maximo(pNo->getfilhoEsquerdo());
    }
    no *aux=pNo->getPai();
    while(aux !=nulo && pNo==aux->getfilhoEsquerdo())
    {
        pNo=aux;
        aux=aux->getPai();
    }
    return aux;
}

no* ABP::sucessor(no *pNo){
    if(pNo->getfilhoDireito() != nulo)
    {
        return minimo(pNo->getfilhoDireito());
    }
    no *aux=pNo->getPai();
    while(aux != nulo && pNo==aux->getfilhoDireito());
    {
        pNo=aux;
        aux=aux->getPai();
    }
    return aux;
}


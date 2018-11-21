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
    Item *obj=new Item;
    *obj = *ptr->getDados();
    no *y=nulo;
    no *x=nulo;
    if(y->getfilhoDireito()==nulo || ptr->getfilhoEsquerdo()==nulo)
    {
        y=ptr;
    }
    else
    {
        y=sucessor(ptr);
    }
    if(y->getfilhoEsquerdo() != nulo)
    {
        x=y->getfilhoEsquerdo();
    }
    else
    {
        x=y->getfilhoDireito();
    }
    if(y->getPai() == nulo)
    {
        raiz=nulo;
        if(x != nulo)
        {
            x->setPai(nulo);
        }
    }
    else
    {
        if(y==y->getPai()->getfilhoEsquerdo())
        {
            y->getPai()->setfilhoEsquerdo(x);
        }
        else
        {
            y->getPai() = *y->setfilhoEsquerdo(x);
        }
    }
    if(y != ptr)
    {
        *ptr->getDados() = *ygetDados();
    }
    delete y;
    return obj;
}


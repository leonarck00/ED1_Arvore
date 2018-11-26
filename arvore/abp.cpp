#include "abp.h"

ABP::ABP()
{
    raiz=nulo=no::montano(nullptr);
}

bool ABP::inserir(Item* aux){
    if(aux==nullptr)
    {
        return false;
    }
    Item *trab=consultar(aux);
    if(trab != nullptr)
    {
        return false;
    }
    int DE = 0;
    no *ptr=no::montano(aux);

    if(vazia())
    {
        raiz=ptr;
        ptr->setPai(nulo);
        ptr->setfilhoEsquerdo(nulo);
        ptr->setfilhoDireito(nulo);
        return true;
    }

    no* atual=raiz;
    no* anterior=raiz;
    while(atual != nulo)
    {
        if(ptr->getDados()->getcodBarras() < atual->getDados()->getcodBarras())
        {
            anterior = atual;
            atual=atual->getfilhoEsquerdo();
            DE=0;
        }
        if(ptr->getDados()->getcodBarras() > atual->getDados()->getcodBarras())
        {
            anterior=atual;
            atual=atual->getfilhoDireito();
            DE=1;
        }
    }
    ptr->setfilhoEsquerdo(nulo);
    ptr->setfilhoDireito(nulo);
    ptr->setPai(anterior);
    if(DE == 0)
    {
        anterior->setfilhoEsquerdo(ptr);
    }
    if(DE ==1)
    {
        anterior->setfilhoDireito(ptr);
    }
    return true;
}


Item* ABP::retirar(Item* aux)
{
    if(aux = nullptr)
    {
        return nullptr;
    }
    no *ptr=raiz;
    while(ptr != nulo)
    {
        if(aux->getcodBarras() < ptr->getDados()->getcodBarras())
        {
            ptr=ptr->getfilhoEsquerdo();
        }
        else
        {
            if(aux->getcodBarras() > ptr->getDados()->getcodBarras())
            {
                ptr = ptr->getfilhoDireito();
            }
            else
            {
                break;
            }
        }
    }
    if(ptr==nulo)
    {
        return nullptr;
    }
    Item *obj=new Item;
    *obj = *ptr->getDados();
    no *y=nulo;
    no *x=nulo;
    if(ptr->getfilhoDireito()==nulo || ptr->getfilhoEsquerdo()==nulo)
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
    if(x != nulo)
    {
        x->setPai(y->getPai());
    }
    if(y->getPai() == nulo)
    {
        raiz=nulo;
        if(x!=nulo)
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
            y->getPai()->setfilhoDireito(x);
        }
    }
    if(y!=ptr)
    {
        *ptr->getDados()=*y->getDados();
    }
    delete y;
    return obj;
}

Item* ABP::consultar(Item *aux){
    if(aux=nullptr)
    {
        return nullptr;
    }
    no* ptr=raiz;
    while(ptr!=nulo)
    {
        if(aux->getcodBarras() < ptr->getDados()->getcodBarras())
        {
            ptr=ptr->getfilhoEsquerdo();
        }
        else
        {
            if(aux->getcodBarras() > ptr->getDados()->getcodBarras())
            {
                ptr=ptr->getfilhoDireito();
            }
            else
            {
                break;
            }
        }
    }
    if(ptr == nulo)
    {
        return nullptr;
    }
    Item* copia;
    copia = ptr->getDados();
    return copia;
}

void ABP::mostrarOrdem(no* pNo, std::string &aux)const{
    if(pNo !=nulo)
    {
        mostrarOrdem(pNo->getfilhoEsquerdo(),aux);
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
void ABP::mostrarPosOrdem(std::string &aux) const{
    mostrarOrdem(raiz,aux);
}

bool ABP::vazia()const{
    return (raiz==nulo);
}

no* ABP::minimo(no *pNo){
    no *aux=pNo;
    while(aux->getfilhoEsquerdo()!=nulo)
    {
        aux=aux->getfilhoEsquerdo();
    }
    return aux;
}

no* ABP::maximo(no* pNo){
    no *aux=pNo;
    while(aux->getfilhoDireito()!= nulo)
    {
        aux=aux->getfilhoDireito();
    }
    return aux;
}

no* ABP::antecessor(no *pNo){
    if(pNo->getfilhoEsquerdo()!= nulo)
    {
        return maximo(pNo->getfilhoEsquerdo());
    }
    no *aux=pNo->getPai();
    while(aux!=nulo && pNo==aux->getfilhoEsquerdo())
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


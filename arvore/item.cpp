#include "item.h"

Item::Item()
{
    qt=0;
    valor=0;
    nomeProd=codBarras="";
}
int Item::getQt(){
    return qt;
}

void Item::setQt(int aux){
    qt=aux;
}

float Item::getValor(){
    return valor;
}

void Item::setValor(float aux){
    valor = aux;
}

std::string Item::getnomeProd(){
    return nomeProd;
}


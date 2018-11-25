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

void Item::setnomeProd(std::string aux){
    nomeProd = aux;
}

std::string Item::getItem(){
    std::string aux;
    aux="Nome do Produto " + nomeProd + "\nCodigo de barras " + codBarras + "\nPreço do produto " + std::to_string(valor)+"\nQuantidade "+std::to_string(getQt())+"\n";
    return aux;
}

std::string Item::getcodBarras(){
    return codBarras;
}

void Item::setcodBarras(std::string aux){
    codBarras = aux;
}


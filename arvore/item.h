#ifndef ITEM_H
#define ITEM_H
#include<iostream>
#include<string>


class Item
{
private:
    std::string nomeProd, codBarras;
    int qt;
    float valor;
public:
    Item();
    int getQt();
    void setQt(int);
    double getValor();
    void setValor(double);
    std::string getnomeProd();
    void setnomeProd(std::string);
    std::string getcodBarras();
    void setcodBarras(std::string);
    std::string getItem();

};

#endif // ITEM_H

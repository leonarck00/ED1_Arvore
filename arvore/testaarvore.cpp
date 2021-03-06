#include "testaarvore.h"

testaArvore::testaArvore()
{

}

void testaArvore::testa(){
    obj=new ABP;
    Item *aux = nullptr;
    Item *buscaaux=new Item;
    int op;
    std::string codDeBarra="", mostra="";
    do
    {
        std::cout<<"\n---------------------Digite a Opcao------------------------\n";
        std::cout<<"\n1 - Para Inserir\n";
        std::cout<<"\n2 - Para Retirar\n";
        std::cout<<"\n3 - Para Consultar\n";
        std::cout<<"\n4 - Para Mostrar em ordem\n";
        std::cout<<"\n5 - Para Mostrar pre-ordem\n";
        std::cout<<"\n6 - Para Mostrar pos-ordem\n";
        std::cout<<"\n7 - Para encerrar\n";
        std::cout<<"\nOPCAO:";
        std::cin>>op;
        system("cls");

        switch (op)
        {
        case 1://inserir
            aux = criarItem();
            if(obj->inserir(aux))
            {
                std::cout<<"\nSucesso\n";
            }
            else
            {
                std::cout<<"\nErro\n";
            }
            break;

        case 2:
            std::cout<<"\nDigite o Codigo de Barras que deseja para remocao: ";
            std::cin.ignore();
            std::cin>>codDeBarra;
            buscaaux->setcodBarras(codDeBarra);
            if(obj->consultar(buscaaux) != nullptr)
            {
                std::cout<<obj->retirar(buscaaux)->getItem();
                std::cout<<"\nREMOVIDO\n";
            }
            else
            {
                std::cout<<"\nNAO REMOVIDO\n";
            }
            break;

        case 3:
            std::cout<<"\nDigite o Codigo de Barras que deseja consultar: ";
            std::cin.ignore();
            std::cin>>codDeBarra;
            buscaaux->setcodBarras(codDeBarra);
            if(obj->consultar(buscaaux) != nullptr)
            {
                std::cout<<"\nEncontrado\n";
                std::cout<<std::setprecision(2);
                std::cout<<obj->consultar(buscaaux)->getItem();
            }
            else
            {
                std::cout<<"\nNao encontrado\n";
            }
            break;

        case 4:
            obj->mostrarOrdem(mostra);
            std::cout<<mostra<<std::endl;
            mostra="";
            break;

        case 5:
            obj->mostrarPreOrdem(mostra);
            std::cout<<mostra<<std::endl;
            mostra="";
            break;

        case 6:
            obj->mostrarPosOrdem(mostra);
            std::cout<<mostra<<std::endl;
            mostra="";
            break;

        case 7:
            std::cout<<"\nENCERRANDO BYE\n";
            exit(0);

        default:
            break;
        }

    }
    while(op!=0);
}

Item* testaArvore::criarItem(){
    Item *ret=new Item;
    std::string nomeProduto;
    std::string codBarras;
    float val;
    int qt;

    std::cout<<"\nDigite o Nome do Produto: ";
    std::cin.ignore();
    std::getline(std::cin,nomeProduto);
    ret->setnomeProd(nomeProduto);

    std::cout<<"\nDigite o Codigo de Barras do Produto: ";
    std::getline(std::cin,codBarras);
    ret->setcodBarras(codBarras);

    std::cout<<"\nDigite a Quantidade: ";
    std::cin.ignore();
    std::cin>>qt;
    ret->setQt(qt);

    std::cout<<"\nDigite o preco do produto: ";
    std::cin.ignore();
    std::cin>>val;
    ret->setValor(val);
    return ret;

}

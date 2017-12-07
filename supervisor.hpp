#ifndef supervisor_hpp
#define supervisor_hpp

#include "funcionario.hpp"
#include "vendas.hpp"

class Supervisor : public Funcionario{    
public:
    virtual void exibirSalario(Vendas* vendas){
        vector <Vendas> vendas;
        double salario=(getPonto().emDecimal()+getExtra().emDecimal()*2.5)*50;
        for(int i=0; i<vendedor.size(); i++){
            vendas = vendedor[i].getVendas();
            for (int j=0; j<vendas.size(); j++)
                salario+=vendas[i].getPreco()*0.01;
        }
    }
    virtual void listarVendas(Vendas* vendas;){
        vector <Vendas> vendas;
        for(int i=0; i<vendedor.size(); i++){
            vendas = vendedor[i].getVendas();
            for( int j=0; j < vendas.size(); j++){
                cout << "Venda " << i+j << ":" << endl;
                vendas[j].print();
                cout << "-------------------";
            }
        }
    }
};

#endif
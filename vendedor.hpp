#ifndef vendedor_hpp
#define vendedor_hpp

#include "funcionario.hpp"
#include "vendas.hpp"

class Vendedor : public Funcionario{
    vector<Vendas> vendas;
public:
    virtual void exibirSalario(){
        double salario=(getPonto().emDecimal()+getExtra().emDecimal()*2)*50;
        for(int i=0; i<vendas.size(); i++){
            salario+=vendas[i].getPreco()*0.1;
        }
    }
    void cadVenda(string nome, double preco){
        Venda nova(nome,preco);
        vendas.push_back(nova);
        cout << "Cadastrado com sucesso";
    }
    vector<Vendas> getVendas(){
        return vendas;
    }
    virtual void listarVendas(){
        for( int i=0; i < vendas.size(); i++){
            cout << "Venda " << i << ":" << endl;
            vendas[i].print();
            cout << "-------------------";
        }
    }
};

#endif
#ifndef vendas_hpp
#define vendas_hpp

#include <string>

class Vendas{
    string nome;
    double preco;
public:
    Vendas(string nome="Coisa", double preco=0.0){
        this-> nome =nome;
        this-> preco =preco;
    }
    string getNome(){
        return nome;
    }

    double getPreco(){
        return preco;
    }
    void print(){
        cout << "Produto: " << nome << " - Preço: " << preco << endl; 
    }

};

#endif
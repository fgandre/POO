#ifndef vendedor_hpp
#define vendedor_hpp

#include "funcionario.hpp"
//#include "tempo.hpp"

class Vendedor : public Funcionario{
    vector<Vendas> vendas;
public:
    Vendedor (string nome, string usuario, string senha): Funcionario(nome,usuario,senha){ };
    int op;
    virtual double exibirSalario(){
        double salario=(getPonto().emDecimal()+getExtra().emDecimal()*2)*50;
        for(int i=0; i<vendas.size(); i++){
            salario+=vendas[i].getPreco()*0.1;
        }
        return salario;
    }
    void cadVenda(string nome, double preco){
        Vendas nova(nome,preco);
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
    void menu(){
        
        do{
            cout << getNome() << ", deseja: " << endl;
            cout << "1-Cadastrar Venda: " << endl;
            cout << "2-Cadastrar Ponto: " << endl;
            cout << "3-Listar Vendas: " << endl;
            cout << "4-Exibir Salario: " << endl;
            cout << "100-Voltar ao Menu Principal: " << endl;
            cout << "Informe sua opcao: ";cin >> op;
            switch(op){
                case 1:{
                    string produto;
                    double venda;
                    cout << "Nome do produto: "; cin >> produto;
                    cout << "Preço da venda: "; cin >> venda;
                    cadVenda(produto,venda);
                    break;
                }
                case 2:{
                    int hora, minuto;
                    cout << "Digite a hora e o minuto: " << endl; cin >> hora >> minuto;
                    if (cadastrarPonto(hora,minuto)) cout << "Cadastrado com sucesso!" << endl;
                    else cout << "Falha ao cadastrar!";
                    break;
                }
                case 3:{
                    listarVendas();
                    break;
                }
                case 4:{
                    double salario=exibirSalario();
                    cout << "Salario: " << salario << endl;
                    break;
                }
                case 100:{
                    cout << "Saindo...";
                    break;
                }
            }
        }while(op!=100);
    }

    virtual Tempo getPonto(){
        return Funcionario::getPonto();
    }
    virtual void setPonto(Tempo tempo){
        Funcionario::setPonto(tempo);
    }

    virtual Tempo getExtra(){
        return Funcionario::getExtra();
    }
    virtual void setExtra(Tempo tempo){
        Funcionario::setExtra(tempo);
    }
};

#endif
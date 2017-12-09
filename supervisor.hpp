#ifndef supervisor_hpp
#define supervisor_hpp

#include "funcionario.hpp"
#include "Vendedor.hpp"
//#include "tempo.hpp"
class Supervisor : public Funcionario{    
public:
    Supervisor (string nome, string usuario, string senha): Funcionario(nome,usuario,senha){ };
    int op;
    
    virtual double exibirSalario(vector<Vendedor> vendedor){
        vector <Vendas> vendas;
        double salario=(getPonto().emDecimal()+getExtra().emDecimal()*2.5)*50;
        for(int i=0; i<vendedor.size(); i++){
            vendas = vendedor[i].getVendas();
            for (int j=0; j<vendas.size(); j++)
                salario+=vendas[i].getPreco()*0.01;
        }
        return salario;
    }
    virtual void listarVendas(vector<Vendedor> vendedor){
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

    /*void menu(vector<Vendedor> vendedor){
        cout << "sup" << endl;
        while(op!=100){
            cout << getNome() << ", deseja: " << endl;
            cout << "1-Exibir Salario: " << endl;
            cout << "2-Cadastrar Ponto: " << endl;
            cout << "3-Listar Vendas: " << endl;
            cout << "100-Voltar ao Menu Principal: " << endl;
            cout << "Informe sua opcao: ";cin >> op;
            switch(op){
                case 1:{
                    double salario=exibirSalario(vendedor);
                    cout << "Salario: " << salario << endl;
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

                    listarVendas(vendedor);
                    break;
                }
                case 100:{
                    cout << "Saindo...";
                    break;
                }
            }
        }
    }*/
};

#endif
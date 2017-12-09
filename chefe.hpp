#ifndef chefe_hpp
#define chefe_hpp

#include "pessoa.hpp"
#include "supervisor.hpp"
#include "vendedor.hpp"
#include "funcionario.hpp"
class Chefe : public Pessoa{
    vector<Supervisor> sup;
    vector<Vendedor> vend;
public: 
    Chefe(string nome="afonso",string usuario="admim",string senha="souchefesim") : Pessoa(nome,usuario,senha){};
    ~Chefe(){};
    void setSupervisor(vector<Supervisor> sup){
        this->sup=sup;
    }
    vector<Supervisor> getSupervisor(){
        return sup;
    }
    void setVendedor (vector<Vendedor> vend){
        this->vend=vend;
    }
    vector<Vendedor> getVendedor(){
        return vend;
    }
    void cadastrarFuncionario(){
        int menu;
        cout <<"1-Supervisor: "<< endl;
        if (sup.size()!=0) cout << "2-Vendedor: "<< endl;
        cin >> menu;
        switch(menu){
            case 1: 
                cadastrarSup();
                break;
            case 2:
                cadastrarVend();
        }
    }
    void cadastrarSup(){
        string n,us,se;
        cout << "Informe seu nome: "; cin >>n;
        cout << "Informe seu usuario: "; cin >> us;
        cout << "Informe sua senha: "; cin >> se;
        Supervisor super(n,us,se);
        sup.push_back(super);
    }
    void cadastrarVend(){
        string n,us,se;
        cout << "Informe seu nome: "; cin >>n;
        cout << "Informe seu usuario: "; cin >> us;
        cout << "Informe sua senha: "; cin >> se;
        Vendedor vender(n,us,se);
        vend.push_back(vender);
    }
    /*void verificarPonto(){
        cout << "--Supervisores--" << endl;
        for(int i=0; i< sup.size(); i++){
            cout << "Nome: " << sup[i].Pessoa::getNome() << endl;
            cout << "Tempo Obrigatorio: " << sup[i].Funcionario::getPonto().print() << endl;
            cout << "Tempo Extra: " << sup[i].Funcionario::getExtra().print() << endl;
            cout << "------------------------------" << endl;
        }
        cout << "--Vendedores--" << endl;
        for(int i=0; i< vend.size(); i++){
            cout << "Nome: " << vend[i].Pessoa::getNome() << endl;
            cout << "Tempo Obrigatorio: " << vend[i].Funcionario::getPonto().print() << endl;
            cout << "Tempo Extra: " << vend[i].Funcionario::getExtra().print() << endl;
            cout << "------------------------------" << endl;
        }
    }*/
    
    void calcSalario(){
        cout << "--Supervisores--" << endl;
        for(int i=0; i< sup.size(); i++)
            cout << "Nome: " << sup[i].Pessoa::getNome() << "\nSalário: " << sup[i].Funcionario::exibirSalario() << endl;
        cout << "------------------------------" << endl;
        cout << "--Vendedores--" << endl;
        for(int i=0; i< vend.size(); i++)
            cout << "Nome: " << vend[i].Pessoa::getNome() << "\nSalário: " << vend[i].Funcionario::exibirSalario() << endl;
        cout << "------------------------------" << endl;
    }
    
    void listarFunc(){
        cout << "--Supervisores--" << endl;
        for(int i=0; i< sup.size(); i++)
            cout << "Nome: " << sup[i].Pessoa::getNome() << endl;
        cout << "------------------------------" << endl;
        cout << "--Vendedores--" << endl;
        for(int i=0; i< vend.size(); i++)
            cout << "Nome: " << vend[i].Pessoa::getNome()<< endl;
        cout << "------------------------------" << endl;
    }

    int verificacao(string user,string senha){ // melhor retornar qual o tipo do funcionario

        for(int i=0; i< sup.size(); i++){
            if(user == sup[i].Pessoa::getUsuario() && senha == sup[i].Pessoa::getSenha()){
                cout << "Bem-Vindo, " << sup[i].Pessoa::getNome() << endl;
                return 1;
            }
        }
        for(int i=0; i< vend.size(); i++){
            if(user == vend[i].Pessoa::getUsuario() && senha == vend[i].Pessoa::getSenha()){
                cout << "Bem-Vindo, " << vend[i].Pessoa::getNome() << endl;
                return 2;
            }
        }
        return 0;
    };
    
    virtual void menu() {
        int op;
        do {
            cout << "Chefe, deseja: " << endl;
            cout << "------------------------------" << endl;
            cout << "1-Cadastrar Funcionario. " << endl;
            cout << "2-Verificar Ponto. " << endl;
            cout << "3-Calculo de Salario. " << endl;
            cout << "4-Listar Funcionarios. " << endl;
            cout << "0-Voltar ao Menu Principal. " << endl;
            cout << "------------------------------" << endl;
            cout << "Informe a opercao desejada: "; cin >> op;
            switch (op) {
                case 1: {
                    cadastrarFuncionario();
                    cout << "Funcionario cadastrado!" << endl;
                    break;
                }
                case 2: {
                    //verificarPonto();
                    cout << "Foi verificar";
                    break;
                }
                case 3: {
                    calcSalario();
                    cout << "Foi calcular";
                    break;
                }
                case 4: {
                    listarFunc(); //chama funcao que vai imprimir todos os supervisores e vendedores no sistema
                }
                case 0: {
                    cout << "Saindo..." << endl;
                    break;
                }
            }
        } while (op != 0);

    }
};

#endif
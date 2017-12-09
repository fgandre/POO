#include <iostream>
#include "chefe.hpp"

using namespace std;

int main () {
    Chefe c;
    Funcionario f;
    string nome,usuario,senha;
    int op,cont=0;
    do{
        cout << "----------------------------" << endl;
        cout << "Informe a operacao desejada: "<<endl;
        cout << "1 - LOGIN " << endl;
        cout << "2 - SAIR" << endl;
        cout << "----------------------------" << endl;
        cin >> op;

        switch (op){
            case 1:
                if(cont==0){ // primeiro login eh sempre do chefe
                    cout << "Digite seu nome: "; cin >> nome;
                    cout << "Digite seu usuario: "; cin >> usuario;
                    cout << "Digite sua senha: "; cin >> senha;
                    if(c.validacao(usuario,senha)) {// verifica se a senha e o usuario existem
                        cout << "Bem-Vindo!" << endl;
                        cout << "----------------------" << endl;
                        c.menu();
                        cont++;
                    }
                }
                else{
                    cout << "Digite seu usuario: "; cin >> usuario;
                    cout << "Digite sua senha: "; cin >> senha;
                    if(c.validacao(usuario,senha)){
                        cout << "Bom dia, Chefe !" << endl;
                        c.menu(); // menu para chefe
                    }
                    else {
                        if (c.verificacao(usuario, senha) == 0) {
                            cout << "Funcionario nao existe!" << endl;
                        }
                        else if(c.verificacao(usuario, senha) == 1){
                            f.menu(); // chama menu de supervisor
                        }
                        else{
                            f.menu();// chama menu de vendedor
                        }
                    }
                }

                break;
            case 2:
                cout << "Saindo" << endl;
                break;
        }

    }while (op!=2);

    return 0;
}
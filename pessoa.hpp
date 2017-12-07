#ifndef pessoa_hpp
#define pessoa_hpp

#include <iostream>
#include <string>

using namespace std;

class Pessoa {
    string nome, usuario, senha;
public: 
    // CONSTRUTOR E DESTRUTOR DE PESSOA
    Pessoa(string nome="", string usuario="default", string senha="default"){
        this->nome=nome;
        this->usuario=usuario;
        this->senha=senha;
    }
    ~Pessoa(){};

    // GETTERS AND SETTERS 
        //NOME
    string getNome(){
        return Nome;
    }
    void setNome(string nome){
        this->nome=nome;
    }
        //USUARIO
    string getUsuario(){
        return usuario;
    }
    void setUsuario(string usuario){
        this->usuario=usuario;
    }
        //SENHA 
    string getSenha(){
        return senha;
    }
    void setSenha(string senha){
        this->senha=senha;
    }

    //VALIDACAO
    Boolean validacao(){
        strign us, se;
        cout << "Usuario: "; cin >> us;
        cout << "Senha: "; cin >> se; 
        return (us==usuario) && (se==senha);
    }
    //MENU PARA AS CLASSES DERIVADAS
    virtual void menu();
};

#endif
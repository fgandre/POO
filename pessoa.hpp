#ifndef pessoa_hpp
#define pessoa_hpp

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pessoa {
    string nome, usuario, senha;
    //vector <Pessoa> bancoDados;
   // int cont=0;
public: 
    // CONSTRUTOR E DESTRUTOR DE PESSOA
    Pessoa(string nome="", string usuario="", string senha=""){
       // if(cont==0){
            //cont++;
            this->nome=nome;
            this->usuario=usuario;
            this->senha=senha;
       // }
        //else{
        //    Pessoa func(nome,usuario,senha);
        //    bancoDados.push_back(func);
        //}


    }
    ~Pessoa(){};

    // GETTERS AND SETTERS 
        //NOME
    string getNome(){
        return nome;
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
    bool validacao(string user, string password){

        if(user == this->usuario && password==this->senha)
            return true;
        else return false;
    }
    //MENU PARA AS CLASSES DERIVADAS
    virtual void menu(){};
};

#endif
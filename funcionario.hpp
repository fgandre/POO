#ifndef funcionario_hpp
#define funcionario_hpp

#include "pessoa.hpp"
#include "tempo.hpp"
#include "vendas.hpp"
//50 REAIS O CUSTO DA HORA DE TRABALHO

class Funcionario : public Pessoa {
    Tempo ponto; Tempo extra;

public:
    Funcionario(string nome="", string usuario="default", string senha="default", Tempo p) : Pessoa(nome, usuario, senha){
        ponto=p;
    }

    Boolean cadastrarPonto(int hora=8, int min=0, int sec=0){
        Tempo max(50,0,0);
        Tempo total;
        total.somar(ponto,extra);
        if ((hora < 8) || (hora == 10 && ((min > 0) || (sec > 0)))) return false; // no minimo 8 horas, no maximo 10 horas
        else{
            Tempo novo(hora,min,sec);
            total.somar(novo);
            if (total > max) return false;  // ANTES DE SOMAR, SIMULA O TOTAL DE HORAS PARA VERIFICAR SE EXCEDE O LIMITE SEMANAL
            else{
                novo.inst(8,0,0);
                ponto.somar(novo);
                novo.inst(hora-8,min,sec);
                extra.somar(novo);
                return true;
            }
        }
    }
    Tempo getPonto(){
        return ponto;
    }
    Tempo getExtra(){
        return extra;
    }
    virtual void exibirSalario();
    virtual void listarVendas();
};

#endif
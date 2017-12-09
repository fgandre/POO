#ifndef tempo_hpp
#define tempo_hpp

#include <iostream>
using namespace std;

class Tempo{
    int hora;
    int min;
    int sec;
public:
    Tempo(int hora=0, int min=0, int sec=0){
        this->hora=hora;
        this->min=min;
        this->sec=sec;
    }
    void setHora(int hora=0){
        this->hora=hora;
    }
    int getHora(){
        return hora;
    }

    void setMin(int min=0){
        this->min=min;
    }
    int getMin(){
        return min;
    }

    void setSec(int sec){
        this->sec=sec;
    }
    int getSec(){
        return sec;
    }

    double emDecimal(){
        return hora+(min+(sec/60))/60; //CONVERTE HORA PARA NUMERO DECIMAL
    }

    void init(){
        hora=0;
        min=0;
        sec=0;
    }
    void inst(int hora,int min,int sec){
        this->hora=hora;
        this->min=min;
        this->sec=sec;
    }
    void print(){
        cout << hora << ":" << min << ":" << sec << endl;
    }
   
    void subtrair(Tempo maior, Tempo menor){
        if (menor.getHora() < maior.getHora())
            this->hora = maior.getHora() - menor.getHora();
        else this->hora = menor.getHora() - maior.getHora();

        if (menor.getMin() < maior.getMin())
            this->min = maior.getMin() - menor.getMin();
        else this->min = menor.getMin() - maior.getMin();

        if (menor.getSec() < maior.getSec())
            this->sec = maior.getSec() - menor.getSec();
        else this->sec = menor.getSec() - maior.getSec();
    }

    void somar(Tempo maior, Tempo menor){
        this->hora=menor.getHora()+maior.getHora();
        this->min=menor.getMin()+maior.getMin();
        this->sec=menor.getSec()+maior.getSec();
    }
    Tempo somar(Tempo menor){
        Tempo resp;
        resp.init();
        resp.setHora(menor.getHora()+getHora());
        resp.setMin(menor.getMin()+getMin());
        resp.setSec(menor.getSec()+getSec());
        return resp;
    }
    bool operator>(Tempo& b){
        return (emDecimal() > b.emDecimal());
    }
};
#endif
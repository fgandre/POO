#ifndef chefe_hpp
#define chefe_hpp

#include "pessoa.hpp"

class Chefe : public Pessoa{
    vector<Supervisor> sup;
    vector<Vendedor> ved;
public: 
    void setSupervisor(Supervisor* sup){
        this->sup=sup;
    }
    Supervisor* getSupervisor(){
        return sup;
    }

    set
    get
};

#endif
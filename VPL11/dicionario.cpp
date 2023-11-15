#include<iostream>
#include "dicionario.h"
#include<string>
#include<list>
    using std::list;
    using std::string;

Dicionario::Dicionario(){}

Dicionario::~Dicionario(){elementos_.clear();}

int Dicionario::tamanho(){
    return elementos_.size();
}

bool Dicionario::pertence(string chave){
    for(auto itr = elementos_.begin(); itr != elementos_.end(); itr++){
        if(itr->chave== chave){
            return true;
        }
        else{
            continue;
        }
    }
    return false;
}

string Dicionario::menor(){
    auto aux = elementos_.begin();
    int menor = aux->chave.size();
        for(auto itr = elementos_.begin(); itr != elementos_.end(); itr++){
            if(aux->chave > itr->chave){
                aux = itr;
            }
            else{continue;}
        }
        return aux->chave;
}

void Dicionario::Inserir(string chave, string valor){
    Elemento x = {chave, valor};
    elementos_.push_front(x);
}

void Dicionario:: Remover(string chave){
    for(auto itr = elementos_.begin(); itr != elementos_.end(); itr++){
        if(itr->chave == chave){
            elementos_.erase(itr);
            break;
        }
    }
}

string Dicionario::valor(string chave){
    for(auto itr = elementos_.begin(); itr != elementos_.end(); itr++){
        if(itr->chave == chave){
            return itr->valor;
        }
        else{
            continue;
        }
    }
}

void Dicionario::Alterar(string chave, string valor){
    for(auto itr = elementos_.begin(); itr != elementos_.end(); itr++){
        if(itr->chave == chave){
            itr->valor = valor;
            break;
        }
    }
}




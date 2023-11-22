#include<iostream>
#include "vetor.h"
#include<string>
    using std::string;

Vetor::Vetor(int inicio, int fim){
    if(fim < inicio){
        throw IntervaloVazio{inicio, fim};
    }
    else{
        int quantidade = fim - inicio + 1;
        elementos_ = new string [quantidade];
            for(int a = 0; a < quantidade; a++){
                elementos_[a] = "/0";
            }
        inicio_ = inicio;
    }
}

Vetor::~Vetor(){
    delete [] elementos_;
}
// size() = fim - inicio + 1 -> fim = size() + inicio - 1
void Vetor::atribuir(int i, std::string valor){
    int fim = elementos_->size() + inicio_ - 1;
        if(i < inicio_ || i > fim){
            throw IndiceInvalido{inicio_, fim, i};
        }
        else{
            elementos_[i - inicio_] = valor;
        }
}

std::string Vetor::valor(int i) const{
    int fim = elementos_->size() + inicio_ - 1;
        if(i < inicio_ || i > fim){
            throw IndiceInvalido{inicio_, fim, i};
        }
        else{
            if(elementos_[i - inicio_] == "/0"){
                throw IndiceNaoInicializado{i};
            }
            else{
            return elementos_[i - inicio_];
            }
        }
    
}
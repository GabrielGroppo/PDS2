#include<iostream>
#include "vetor.h"
#include<string>
    using std::string;

Vetor::Vetor(int inicio, int fim){
    int quantidade = fim - inicio + 1;
    elementos_ = new string [quantidade];
    inicio_ = inicio;
}

Vetor::~Vetor(){
    delete [] elementos_;
}

void Vetor::atribuir(int i, std::string valor){
    elementos_[i - inicio_] = valor;
}

std::string Vetor::valor(int i) const{
    return elementos_[i - inicio_];
}
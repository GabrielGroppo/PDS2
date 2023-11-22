#include<iostream>
#include "fila.h"
#include<string>
    using std::string;

Fila::Fila(){
    primeiro_ = new No;
        primeiro_ = nullptr;
    ultimo_ = new No;
        ultimo_ = nullptr;
}

Fila::~Fila(){
    No *anterior = new No;
        anterior = nullptr;
    No *posterior = new No;
        posterior = primeiro_;
            while(posterior != nullptr){
                anterior = posterior;
                posterior = posterior->proximo;
                delete anterior;
            }
        delete anterior;
        delete posterior;
}

string Fila::primeiro(){
    return primeiro_->chave;
}

string Fila::ultimo(){
    return ultimo_->chave;
}

bool Fila::vazia(){
    if(primeiro_== nullptr){
        return 1;
    }
    else{
        return 0;
    }
}

void Fila::Inserir(string k){
    No *aux = new No;
        aux->chave = k;
        aux->proximo = nullptr;
            if(this->vazia() == 1){
                primeiro_ = aux;
                ultimo_ = aux;
            }
            else{
                ultimo_->proximo = aux;
                ultimo_ = aux;
            }
}

void Fila::Remover(){
    No *aux = new No;
        aux = primeiro_;
            if(this->vazia()==0){
                primeiro_ = primeiro_->proximo;
                delete aux;
            }
}

int Fila::tamanho(){
    int contador = 0;
    No *aux = new No;
        aux = primeiro_;
        while(aux != nullptr){
            aux = aux->proximo;
            contador++;
        }
    delete aux;
    return contador;
}





























// Fila::~Fila() {
//     No *atual = primeiro_;
//     No *proximo = nullptr;

//     while (atual != nullptr) {
//         proximo = atual->proximo;
//         delete atual;
//         atual = proximo;
//     }

//     primeiro_ = nullptr;
//     ultimo_ = nullptr;
// }


















// Fila::Fila(){
//     primeiro_ = new No;
//         primeiro_->proximo = nullptr;
//     ultimo_ = new No;
//         ultimo_->proximo = nullptr;
// }

// string Fila::primeiro(){
//     return primeiro_->chave;
// }

// string Fila::ultimo(){
//     return ultimo_->chave;
// }

// bool Fila::vazia(){
//     if(primeiro_->proximo == nullptr)return 1;
//     else return 0;
// }

// void Fila::Inserir(string k){
//     No* x = new No;
//         x->chave = k;
//         x->proximo =nullptr;
//     if(primeiro_ == nullptr){
//         primeiro_ = x;
//         ultimo_ = x;
//     }
//     else{
//         ultimo_->proximo = x;
//         ultimo_ = x;
//     }
        
// }

// void Fila::Remover(){
//     No* segundo = new No;
//     segundo = primeiro_->proximo;
//     delete primeiro_;
//     primeiro_ = segundo;
//     delete segundo;
// }

// int Fila::tamanho(){
//     int contador = 0;
//         No* aux = new No;
//         aux = primeiro_;
//             while(aux->proximo != nullptr){
//                 contador++;
//             }
//         delete aux;
//         return contador;
// }

// Fila::~Fila(){
//     No* antes = primeiro_;
//     No* depois = primeiro_;
//         while(depois->proximo != nullptr){
//             antes = depois;
//             depois = primeiro_->proximo;
//             delete antes;
//         }
//     delete primeiro_;
//     delete ultimo_;
// }


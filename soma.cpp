#include<iostream>
#include<vector>
int Media (std::vector<int> x, int y){
    int soma = 0;
        for(int a=0; a<x.size(); a++){
            soma += x[a];
        }
        soma = soma/y;
        return soma;
}
int main(){
    std::vector<int> Soma;
    int aux=0;
        for(int a=0; a<5; a++){
            std::cin>> aux;
           Soma.push_back(aux);
        }
    int res= Media(Soma, 5);
        std::cout << res << std::endl;
    return 0;
}
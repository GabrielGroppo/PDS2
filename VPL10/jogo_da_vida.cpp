#include<iostream>
#include "jogo_da_vida.h"
#include<vector>
    using std::vector;

JogoDaVida::JogoDaVida(int l, int c){
   vivas_ = vector<vector<bool>>(l,vector<bool>(c,0));
};

bool JogoDaVida::viva(int i, int j){
    return vivas_[i][j];
};

void JogoDaVida::Matar(int i, int j){
    vivas_[i][j] = 0;
};

void JogoDaVida::Reviver(int i, int j){
    vivas_[i][j] = 1;
};

void JogoDaVida::ExecutarProximaIteracao(){
    vector<vector<bool>>matrix(linhas(),vector<bool>(colunas()));
    matrix = vivas_;
    for(int a = 0; a < linhas(); a++){
        for(int b = 0; b < colunas(); b++){
            if(viva(a,b)==1){
                if(NumeroDeVizinhasVivas(a,b) <= 1){
                    matrix[a][b] = 0;
                }
                else if(NumeroDeVizinhasVivas(a,b) > 3){
                  matrix[a][b] = 0;
                }
                else{
                    continue;
                }
            }
            else{
                if(NumeroDeVizinhasVivas(a,b)==3){
                    matrix[a][b]= 1;
                }
            }
        }
    }
    vivas_ = matrix;
};

int JogoDaVida::NumeroDeVizinhasVivas(int x, int y){
  int num_viz = 0;
    int linhas = vivas_.size();
    int colunas = vivas_[0].size();
        for(int a = -1; a < 2; a++){
            for(int b = -1; b < 2; b++){
                int auxl = (x + a + linhas) % linhas;
                int auxc = (y + b + colunas) % colunas;
                    if(a == 0 && b == 0){
                        continue;
                    }
                    else if(vivas_[auxl][auxc] == 1){
                        num_viz++;
                    }
                    else{
                        continue;
                    }
            }
        }
    return num_viz;
}



// [x-1, y-1] | [x-1, y] | [x-1, y+1]
// [x, j-1]   | [x, j]   | [x, y+1]  
// [x+1, j-1] | [x+1, j] | [x+1, y+1] 

// [3,4] -> [2, 3]
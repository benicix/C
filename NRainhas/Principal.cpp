#include<iostream>
#include<vector>
using namespace std;
void executar(vector<vector<int>> &tab, int N, int coluna);
bool verificaPosicoes(vector<vector<int>> &tabuleiro, int N,int linha, int coluna);


int Rainhas=0;
int solucao=0;
int main(){
    
    int N=8;
    vector<vector<int>> tab;
    for(int i=0;i<N;i++){
        vector<int> aux(N);
        tab.push_back(aux);
    }
    
    executar(tab, N,0);
    cout<<"total de soluções é "<< solucao<<endl;
    

}
void executar(vector<vector<int>> &tab, int N, int coluna){
    if(coluna ==N){
        solucao++;
        
        Rainhas=0;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if(verificaPosicoes(tab, N,i,coluna)){
            tab[i][coluna]=1;
            executar(tab, N, coluna+1);
            tab[i][coluna]=0;
        }
    }
    
    
    
}

bool verificaPosicoes(vector<vector<int>> &tabuleiro, int N,int linha, int coluna){
    int i,j;
    for ( i = 0; i < N; i++)
    {
        if(tabuleiro[i][coluna]==1){
            return false;
        }
    }
    for ( i = 0; i < N; i++)
    {
        if(tabuleiro[linha][i]==1){
            return false;
        }
    }
    for ( i = linha, j=coluna; i >=0 && j>=0 ; i--,j--)
    {
        if(tabuleiro[i][j]==1){
            return false;
        }
    }
    for ( i = linha, j=coluna; i <N && j<N ; i++,j++)
    {
        if(tabuleiro[i][j]==1){
            return false;
        }
    }
    for ( i = linha, j=coluna; i <N && j>=0 ; i++,j--)
    {
        if(tabuleiro[i][j]==1){
            return false;
        }
    }
    for ( i = linha, j=coluna; i >=0 && j<N ; i--,j++)
    {
        if(tabuleiro[i][j]==1){
            return false;
        }
    }
    return true;
    
    
    
}
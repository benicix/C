#include<iostream>
#include<regex>
#include<list>
#include<iterator>
#include<unistd.h>
struct localizacao{
    int linha,coluna;
};

//declarando funções
void posicionandoRainhas(int linha, int coluna);
void mostraRainhas();
void zerarTabuleiro();
localizacao capturarLocalizacao(int linha, int coluna);

int Tabuleiro[8][8];
int Rainhas[8];

using namespace std;

int main(){
    
    
    
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            zerarTabuleiro();
            capturarLocalizacao(i,j);
        }
        
    }
       
    mostraRainhas();
}
localizacao capturarLocalizacao(int linha, int coluna){
    
    
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(linha==i &&coluna==j){
                
                posicionandoRainhas(i,j);
            }
        }
        
    }
    
}

void zerarTabuleiro(){
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Tabuleiro[i][j]=99;
        }
        Rainhas[i]=i;
    }
}
void mostraRainhas(){
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            
            if(Tabuleiro[i][j]==1){
                cout<<"1 ";
            }else if(Tabuleiro[i][j]==0){
                cout<<"0 ";
            }else if(Tabuleiro[i][j]==2){
                cout<<"2 ";
            }else if(Tabuleiro[i][j]==3){
                cout<<"3 ";
            }else if(Tabuleiro[i][j]==4){
                cout<<"4 ";
            }else if(Tabuleiro[i][j]==5){
                cout<<"5 ";
            }else if(Tabuleiro[i][j]==6){
                cout<<"6 ";
            }else if(Tabuleiro[i][j]==7){
                cout<<"7 ";
            }else{ 
                cout<<"* ";
            }
            

        }
        cout<<endl;
    }
    sleep(1);
    system("clear");
}

void posicionandoRainhas(int linha, int coluna){
    int cont=1;
    if(Tabuleiro[linha][coluna]==99){
        Tabuleiro[linha][coluna]=Rainhas[0];
        //cout<<i<<endl;
        for (int k = 0; k < 8; k++)
        {
            
            Tabuleiro[linha][k]=Rainhas[0];
            Tabuleiro[k][coluna]=Rainhas[0];
            if((coluna+k) <8  && (k+ linha) <8){
                Tabuleiro[k+linha][k+coluna]=Rainhas[0];
            }
            if(coluna-k > -1 && k+linha<8){
                Tabuleiro[k+linha][coluna-k]=Rainhas[0];
            }if (linha-k >-1 && coluna+k<8){
                 Tabuleiro[linha-k][coluna+k]=Rainhas[0];
            }if ((linha-k) > -1 && coluna-k > -1){
                 Tabuleiro[linha-k][coluna-k]=Rainhas[0];
            }
                mostraRainhas();
        }
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            
                if(Tabuleiro[i][j]==99){
                    Tabuleiro[i][j]=Rainhas[cont];
                    //cout<<i<<endl;
                    for (int k = 0; k < 8; k++)
                    {
                        
                        Tabuleiro[i][k]=Rainhas[cont];
                        Tabuleiro[k][j]=Rainhas[cont];
                        if((j+k) <8  && (k+ i) <8){
                            Tabuleiro[k+i][k+j]=Rainhas[cont];
                        }
                        if(j-k > -1 && k+i<8){
                            Tabuleiro[k+i][j-k]=Rainhas[cont];
                            cout<<k+i<<j-k<<endl;
                        }if (i-k >-1 && j+k<8){
                             Tabuleiro[i-k][j+k]=Rainhas[cont];
                        }if ((i-k) > -1 && j-k > -1){
                             Tabuleiro[i-k][j-k]=Rainhas[cont];
                        }
                        cout<<i+1<<endl;
                        mostraRainhas();

                    }
                    cont++;
                    i=0,j=0;
                }
            
        }
        
        
    }
    /*/for (linha; linha < 8; linha++)
    {
        for (coluna; coluna < 8; coluna++)
        {
            if(coluna<8){
                zerarTabuleiro();
                coluna++;
                posicionandoRainhas(linha, coluna);
            }else if(linha<8){
                coluna=0;
                linha++;
                zerarTabuleiro();
                posicionandoRainhas(linha,coluna);
            }
        }
    }*/
    
    
}
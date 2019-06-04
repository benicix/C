#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include<unistd.h>


using namespace std;
struct localizacao{
    int linha, coluna;
    
};
//declaração de funções
void forma();
int Movimentacao(localizacao *atual);
int MovimentacaoAprimorada(localizacao *novo);

//mapa
int Campo[10][20] = {
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,1,1,
        1,0,0,1,0,1,1,1,1,1,1,1,1,1,0,1,0,0,0,1,
        1,0,1,1,8,0,0,0,0,0,0,0,0,1,0,1,1,1,0,1,
        1,0,0,0,1,0,99,0,1,1,1,1,0,1,0,0,0,0,0,1,
        1,0,1,0,1,0,0,0,1,0,0,0,0,1,0,1,1,1,1,1,
        1,0,1,8,1,1,1,1,1,0,1,1,1,1,0,1,1,8,1,1,
        1,0,0,0,0,0,0,0,0,0,1,8,0,1,0,0,0,0,8,1,
        1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,
        1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};

int main(){
    localizacao *atual = new localizacao();
    atual->linha=9;
    atual->coluna=1;
    forma();
    Movimentacao(atual);
    cout<<"recomeçando"<<endl;
    localizacao *novo = new localizacao();
    novo->linha=9;
    novo->coluna=1;
    MovimentacaoAprimorada(novo);
    cout<<"checagem aprimorada terminada";
    
}
void forma(){
    
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if(Campo[i][j]==1 || Campo[i][j]==8){
                cout<<"|";
            }else if(Campo[i][j]==0){
                cout<<" ";
            }else if(Campo[i][j]==2){
                cout<<"*";
            }else if(Campo[i][j]==3){
                cout<<"-";
            }else if(Campo[i][j]==6){
                cout<<"#";
            }else if(Campo[i][j]==9){
                cout<<"*";
            }
            else{
                cout<<" ";
            }

        }
        cout<<endl;
    }
    sleep(1);
    system("clear");
}
int auxiliar=0;
int Movimentacao(localizacao *atual){
    
    for(int i =0;i<10;i++){
        
        for(int j =0;j<20;j++){
            
            if ((atual->linha == i) && (atual->coluna ==j))
            {
                if(Campo[atual->linha+1][j]==0 || Campo[atual->linha-1][j]==0 || Campo[i][atual->coluna+1]==0||Campo[i][atual->coluna-1]==0){
                    auxiliar=0;
                    
                }else if(Campo[atual->linha+1][j]==8 || Campo[atual->linha-1][j]==8 || Campo[i][atual->coluna+1]==8||Campo[i][atual->coluna-1]==8){
                    auxiliar=3;
                    
                }
                //efetuando checagens 
                if(Campo[i][atual->coluna-1]==auxiliar) {
                    
                    Campo[i][j]=auxiliar+3;
                    atual->coluna--;
                    forma();
                    Movimentacao(atual);
                } else if(Campo[atual->linha-1][j]==auxiliar) {
                    
                    Campo[i][j]=auxiliar+3;
                    atual->linha--;
                    forma();
                    Movimentacao(atual);
                } else if(Campo[i][atual->coluna+1]==auxiliar) {
                    
                    Campo[i][j]=auxiliar+3;
                    atual->coluna++;
                    forma();
                    Movimentacao(atual);
                } else if (Campo[atual->linha+1][j]==auxiliar){
                    
                    Campo[i][j]=auxiliar+3;
                    atual->linha++;
                    forma();
                    Movimentacao(atual);
                }if(Campo[atual->linha+1][j]==99 || Campo[atual->linha-1][j]==99 || Campo[i][atual->coluna+1]==99||Campo[i][atual->coluna-1]==99){
                    return 0;

                }
                
            }
        }    
    }

}
int MovimentacaoAprimorada(localizacao *novo){
    for(int i=0;i<10;i++){
        for(int j=0;j<20;j++){
            if(novo->linha==i && novo->coluna==j){
                if(Campo[i][novo->coluna-1]==3) {
                    
                    Campo[i][j]=9;
                    novo->coluna--;
                    forma();
                    MovimentacaoAprimorada(novo);
                } else if(Campo[novo->linha-1][j]==3) {
                    
                    Campo[i][j]=9;
                    novo->linha--;
                    forma();
                    MovimentacaoAprimorada(novo);
                } else if(Campo[i][novo->coluna+1]==3) {
                    
                    Campo[i][j]=9;
                    novo->coluna++;
                    forma();
                    MovimentacaoAprimorada(novo);
                } else if (Campo[novo->linha+1][j]==3){
                    
                    Campo[i][j]=9;
                    novo->linha++;
                    forma();
                    MovimentacaoAprimorada(novo);
                }if(Campo[novo->linha+1][j]==99 || Campo[novo->linha-1][j]==99 || Campo[i][novo->coluna+1]==99||Campo[i][novo->coluna-1]==99){
                    return 0;

                }
                
            }
        }
    }
}

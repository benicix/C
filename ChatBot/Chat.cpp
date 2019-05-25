#include<iostream>
#include<iterator>
#include<list>
#include<string>
#include<stdlib.h>
#include<locale.h>
#include"Resultados.hpp"
#include"buscarDados.hpp"

//declaração de funções
 
void comunicacao();
list<Boca> Produtos();
void verificarRespotas(string falas);
list<Boca> VasculharProdutos(string fala); 
string qualidade(string qualidade, list<Boca> resultado);

//declaração de namespace
using namespace std;

//declaração variavel
size_t achou[6];

//listas
list<string> aceitos={"sim", "exatamente", "exato", "pode", "quer", "aceito", "gostaria", "favor"};
list<string> rejeitar={"nao","não", "recuso", "dispenso", "nada"};
list<string> indeciso={"talvez","gostei"};
list<string> perguntas={"o que", "quais", "melhor", "qual", "tem"};
list<Boca> captura=buscar();


int main(){
    setlocale(LC_ALL,"");
    cout<<"salve! quer o que hoje meu chegado?"<<endl;
    
    try
    {
        comunicacao();
    }
    catch(const std::bad_alloc& e)
    {
        return -1;
    }
    
} 



list<Boca> Produtos(){
    list<Boca>::iterator it;
    for( it = captura.begin();it!=captura.end();it++){
        cout<< it->GetNome()<<"\t"<<it->GetQualidade()<<"\t"<<it->GetPreco()<<endl;
    }
    return captura;
    
}

void comunicacao( ){
    string str;
    static int teste , aux=0;
    while(true){
        
        
        list<Boca> valor;
        getline(cin, str);
        verificarRespotas(str);
        valor = VasculharProdutos(str);
        if (achou[3]!=string::npos) {
            cout<< "parceiro, a gente tem isso aqui "<<endl;
            Produtos();
            cout<<"vai querer ?"<<endl;
            
            getline(cin,str);
            verificarRespotas(str);
            if(achou[0]!=string::npos){
                cout<<"qual?"<<endl;
                Produtos();
                continue;
            }
            else if((achou[0]!=string::npos && achou[2]!=string::npos) || achou[2]!=string::npos){
                cout<<"então tchau"<<endl;
                continue;
                
            }
        }else if(achou[1]!=string::npos){
            cout<<"veio fazer o que aqui então?"<<endl;
            continue;
            
        }else if((achou[0]!=string::npos && achou[4]!=string::npos) || achou[4]!=string::npos){
            string preco;
            list<Boca>::iterator it2, it=valor.begin();
            
            if(valor.size()<2){
                cout<<"aceita?"<<it->GetPreco()<<"\t"<<it->GetQualidade()<< endl;
                getline(cin, str);
                preco=qualidade(str, valor);
                teste= stoi(preco);
                aux+=teste;
                cout<<"blz ele vai ficar "<<aux<<"\n vai querer mais alguma coisa?"<< endl;
                
                str.clear();
                getline(cin, str);
                verificarRespotas(str);
            }
            else{
                cout<<"qual você quer?"<<endl;
                for(it2=valor.begin();it2!=valor.end(); it2++)
                {
                    cout<<it2->GetPreco()<<"\t"<<it2->GetQualidade()<<endl;
                }
                getline(cin, str);
                preco=qualidade(str, valor);
                teste= stoi(preco);
                aux+=teste;
                cout<<"blz ele vai ficar "<<aux<<"\n vai querer mais alguma coisa?"<< endl;

                str.clear();
                getline(cin, str);
                verificarRespotas(str);
            }

            if((achou[0]!=string::npos && achou[1]!=string::npos)|| achou[1]!=string::npos){
                cout<<"então sai cortando"<<endl;
                break;
                

            }else {
                cout<<"o que ?"<<endl;
                Produtos();
                continue;
            }
            

        }else{
            cout<<"não entendeu, repete"<<endl;
            continue;
        }
    
    
        
    }
}

void verificarRespotas(string falas){
    list<string>::iterator it;
     for(it=aceitos.begin();it != aceitos.end();it++)
    {
        achou[0]=falas.find(*it);
        if(achou[0]!=string::npos){
            //cout<<*it<<endl;
           
           break;   
        }
        //cout<<*it<<endl;
    }
    
    for(it=rejeitar.begin();it != rejeitar.end();it++)
    {
        achou[1]=falas.find(*it);
        if(achou[1]!=string::npos){
            //cout<<*it2<<endl;
           
           break;   
        }
        //cout<<*it<<endl;
    }
    for(it= indeciso.begin(); it!=indeciso.end(); it++)
    {
        achou[2]=falas.find(*it);
        if(achou[2]!=string::npos){
           //cout<<*it<<endl;
            
            break;
        }
        //cout<<*it<<endl;
    }
    for(it=perguntas.begin(); it !=perguntas.end(); it++)
    {
        achou[3]=falas.find(*it);
        if(achou[3]!=string::npos){
            //cout<<*it4<<endl;
            
            break;
        }
        //cout<<*it<<endl;
    }
}
string qualidade(string qualidade, list<Boca> resultado){
    list<Boca>::iterator it;
    verificarRespotas(qualidade);
    for(it=resultado.begin();it!=resultado.end();it++){        
        achou[5]=qualidade.find(it->GetPreco());
        if(achou[5]!=string::npos ||achou[0]!=string::npos){
            return it->GetPreco();
        }
    }
    for(it=resultado.begin();it!=resultado.end();it++){
        achou[5]=qualidade.find(it->GetQualidade());
        if(achou[5]!=string::npos ||achou[0]!=string::npos){
            return it->GetPreco();
        }
    }
    
}

list<Boca> VasculharProdutos(string fala){
    list<Boca>::iterator it;
    list<Boca>Prod;
    for(it=captura.begin();it!=captura.end();it++){
        achou[4]=fala.find(it->GetNome());
        
        if(achou[4]!=string::npos){
            Prod= ConsultaProduto(it->GetNome());
            return Prod;
        }
    }
    
}
#include<string>
using namespace std;
class Boca{
private:
    string nome, preco,qualidade;
    
public:
    
    string GetNome(){
        return nome;
    }
    void SetNome(string nome){
        this->nome=nome;
    }
    string GetPreco(){
        return preco;
    }
    void SetPreco(string Preco){
        this->preco=Preco;
    }
    string GetQualidade(){
        return qualidade;
    }
    void SetQualidade(string qualidade){
        this->qualidade=qualidade;
    }
};
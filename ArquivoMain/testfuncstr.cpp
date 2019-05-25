#include<iostream>
#include<string>
using namespace std;
int main(int argc, char const *argv[])
{
    string teste="eu eu eu";
    cout<<teste<<endl;
    cout<<teste.size()<<endl;//mostra o tamnho da string e tambeḿ exite a lenght
    cout<<teste.back()<<endl;//mostra o último caracter da string
    teste.append("zubumafu e a batata");//concatena a string com o que tiver dentro dos parênteses
    cout<<teste<<endl;
    
    cout<<teste.at(1)<<endl;//retorna a string correspondete as valor do parâmetro
    teste.insert(8, " você ");//adiciona a string entre parênteses na posição indicada no primeiro parâmetro
    teste.erase(3, 5);//utilizada para apagar uma parte da string que são os valores dos parâmetros
    teste.erase(18, teste.size());
    cout<<teste<<endl;
    return 0;
}

#include<iostream>
using namespace std;

int main(){
    if (system("g++ teste.cpp -o teste 2> erros.txt"))
    {
        cout<<"compilado com sucesso";
    }else{
        system("g++ teste.cpp -o teste 2> erros.txt");
    }
    
}

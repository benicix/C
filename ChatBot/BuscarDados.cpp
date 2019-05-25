#include<cppconn/connection.h>
#include<cppconn/resultset.h>
#include<cppconn/statement.h>
#include<mysql_connection.h>
#include<mysql_driver.h>
#include<cppconn/exception.h>
#include<list>
#include<iostream>
#include<string> 
#include"Resultados.hpp"

 
using namespace std;
using namespace sql;


//definido parâmetros da conexão
#define host "localhost"
#define user "root"
#define passwd ""
#define database "biqueira"

//Alimentos comidas;
list<Boca> buscar(){
    
    Driver* driver;
    Statement* statement;
    ResultSet* resultset;
    Connection* connect;
    //criando conexao
    list<Boca> negocio;
    try
    {
        driver= get_driver_instance();
        connect=driver->connect(host, user, passwd);
        //conextando ao banco
        connect->setSchema(database);
        //configuração do statement e resultset
        statement=connect->createStatement();
        resultset = statement->executeQuery("select * from negocio");
        while(resultset->next()){
            Boca bagui;
            bagui.SetNome(resultset->getString("nome")); 
            bagui.SetPreco(resultset->getString("preco"));
            bagui.SetQualidade(resultset->getString("qualidade"));
            
            negocio.push_back(bagui);
        }
        return negocio;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    connect->close();
    delete statement;
    delete connect;
    delete resultset;
    delete &driver;
}
list<Boca> ConsultaProduto(string tmpBusca){
    Driver *drive;
    Statement* statement;
    ResultSet* resultset;
    Connection* connect;
    list<Boca> treco;
    try{
        drive=get_driver_instance();
        connect=drive->connect(host,user, passwd);
        connect->setSchema(database);
        statement=connect->createStatement();
        resultset=statement->executeQuery("select * from negocio WHERE nome = '"+tmpBusca+"'");
        while(resultset->next()){//se houver registro
            Boca boca;
            boca.SetNome(resultset->getString("nome"));
            boca.SetPreco(resultset->getString("preco"));
            boca.SetQualidade(resultset->getString("Qualidade"));
            treco.push_back(boca);
        }
        return treco;
    }catch(const std::exception& e){
        std::cerr<<e.what()<<'\n';
    }
    connect->close();
    delete statement;
    delete connect;
    delete resultset;
    delete &drive;
}




#include<iostream>
#include<cppconn/exception.h>
#include<mysql_connection.h>
#include<cppconn/driver.h>
#include<cppconn/resultset.h>
#include<cppconn/statement.h>
#include<mysql_driver.h>

using namespace std;
using namespace sql;

#define  host "localhost"
#define user "root"
#define passwd ""
#define database "chatBot"

int main(){
    Driver *driver;
    Statement *statement;
    ResultSet *resultset;
    Connection *connect;
    // criando conexão
    driver = get_driver_instance();
    connect=driver->connect(host,user, "");
    //conetanddo a base de dados
    connect->setSchema(database);
    //criando execução e resposta do bd
    statement=connect->createStatement();
    resultset=statement->executeQuery("select * from Alimentos");
    //mostra resultados
    while(resultset->next()){
        cout<<resultset->getString(1)<<" ";
        //cout<<"teste"<<endl;
    }

    try
    { 
        //resultset=statement->executeQuery("select * from Alimentos");
        cout<<resultset->getString(2)<<endl;;
    }
    catch(const std::exception& e)
    {
        cout << e.what() << '\n';
    }
    
    return 0;
}
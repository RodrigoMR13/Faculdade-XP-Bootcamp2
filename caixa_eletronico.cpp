/******************************************************************************

                              Online C++ Debugger.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int opcao = 0, opcao_in;
    float valor_in, valor, saldo_atual, saldo = 0;
    string cpf, cpf_in;
    ifstream inFile; // variavel p leitura de arquivo
    ofstream outFile; // variavel p escrita em arquivo
    
    while(opcao != 4){
        cout << "Digite o CPF do cliente: \n";
        cin >> cpf;
    
        cout << "digite a opcao a ser realizada: \n";
        cout << "1. visualizar extrato: \n";
        cout << "2. efetuar deposito: \n";
        cout << "3. efetuar saque: \n";
        cout << "4. sair: \n";
        cin >> opcao;
    
        if(opcao == 1) {
            cout << "Opcao selecionada: extrato.";
            inFile.open("base.txt", ios::in);
            
            cout << "extrato do cliente " << cpf << "\n";
            
            while(inFile >> cpf_in >> opcao_n >> valor_in) {
                if(cpf_in == cpf) {
                    if(opcao_in == 2) {
                        cout << "deposito: " << valor_in << "\n";
                        saldo = saldo + valor_in;
                    } else {
                        cout << "saque: " << valor_in << "\n";
                        saldo = saldo - valor_in;
                    }
                }
            }
            cout << "saldo final: " << saldo;
            inFile.close();
        } else if(opcao == 2) {
            cout << "Opcao selecionada: deposito.\n";
            
            outFile.open("base.txt", ios::app); // abre arquivo p escrita incremental
            
            cout << "informe o valor do deposito: \n"
            cin >> valor;
            
            outFile << cpf << " " << opcao << " " << valor << "\n";
            
            outFile.close();
            
        } else if(opcao == 3) {
            cout << "Opcao selecionada: saque.";
            
            cout >> "informe o valor da retirada: \n";
            cin >> valor;
            
            inFile.open("base.txt", ios::in);
            
            while(inFile >> cpf_in >> opcao_in >> valor_in) {
                if(cpf_in == cpf) {
                    if(opcao_in == 2) {
                        cout << "deposito: " << valor_in << "\n";
                        saldo = saldo + valor_in;
                    } else {
                        cout << "saque: " << valor_in << "\n";
                        saldo = saldo - valor_in;
                    }
                }
            }
            
            if(valor > saldo) {
                cout << "saldo insuficiente para a operacao.";
                
            } else {
                outFile.open("base.txt", ios_base::app);
                outFile << cpf << " " << opcao << " " << valor << "\n";
                outFile.close()
                
                saldo_atual = saldo - valor;
                
                cout << "\nsaque realizado com sucesso.";
                cout << "\nsaldo atualizado: " << saldo_atual;
            }
            
        } else if(opcao == 4) {
            cout << "Opcao invalida.";
        } else {
            cout << "Saindo do sistema.";
        }
        
        cout << "\n-----------------------------------------------\n"
    }
    
}



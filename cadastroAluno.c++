#include <bits/stdc++.h>
#include <locale.h>
#include <string>
using namespace std;

struct Aluno {
    string nome;
    int matricula;
    string curso;
    float mediaFinal;
};

void cadastrarAluno(Aluno lista[], int i) {
    cout << "Cadastrar aluno " << i + 1 << endl;
    cout << "Digite o nome: ";
    getline(cin, lista[i].nome);
    
    cout <<"Digite o numero de matricula: ";
    cin >> lista[i].matricula;
    cin.ignore();
        
    cout << "Digite o curso: ";
    getline(cin, lista[i].curso);
        
    cout <<"Digite a media final: ";
    cin >> lista[i].mediaFinal;
    cin.ignore();
    cout << endl;
    
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    const int TAM = 100;
    Aluno a1;
    Aluno lista [TAM];
    int opcao, quant, i;
    
    do{
        cout << endl;
        cout << "----------- MENU -----------" << endl;
        cout << "1 - Cadastrar Aluno" << endl;
        cout << "2 - Listar alunos cadastrados" << endl;
        cout << "3 - Buscar por matricula" << endl;
        cout << "4 - Sair" << endl;
        cout << "Digite a opção desejada: ";
        cin >> opcao;
        cin.ignore();
        cout << endl;
        
        switch(opcao){
            case 1: 
                cout << "Quantos alunos deseja cadastrar: ";
                cin >> quant;
                cin.ignore();
                
                for (i = 0; i < quant; i++){
                    cadastrarAluno(lista, i);
                }
                
                cout << "Alunos cadastrados com sucesso!" << endl;
                
                break;
        }
    }while (opcao != 4);
    return 0;
}

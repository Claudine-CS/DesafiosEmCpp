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

int gerarMatricula() {
    int ano = 2025;
    int aleatorio = rand() % 90000 + 10000;
    return ano * 100000 + aleatorio;
}

void cadastrarAluno(Aluno lista[], int i) {
    cout << "\nCadastrar aluno " << i + 1 << endl;
    cout << "Digite o nome: ";
    getline(cin, lista[i].nome);
    
    //Deixando aqui apenas para exemplo, mas será gerado automaticamente.
    /*cout <<"Digite o numero de matricula: ";
    cin >> lista[i].matricula;
    cin.ignore();*/
        
    cout << "Digite o curso: ";
    getline(cin, lista[i].curso);
        
    cout <<"Digite a media final: ";
    cin >> lista[i].mediaFinal;
    cin.ignore();
    cout << endl;
    
    int numDaMatricula = gerarMatricula();
    
    cout << "Número de matrícula: " << numDaMatricula << endl;
    lista[i].matricula = numDaMatricula;
}

void listarAlunos(Aluno lista[], int i){
    cout << "- " << lista[i].nome << endl;
}

void buscarPorMatricula (Aluno lista[], int totalAlunos) {
    int busca;

    bool encontrado = false;
    if (totalAlunos != 0) {
        cout << "Digite o número de matrícula: ";
        cin >> busca;
        cin.ignore();
        for (int i = 0; i < totalAlunos; i++) {
            if (busca == lista[i].matricula) {
                cout << "\nAluno encontrado:\n";
                cout << "Nome: " << lista[i].nome << endl;
                cout << "Curso: " << lista[i].curso << endl;
                cout << "Média Final: " << lista[i].mediaFinal << endl;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            cout << "\nAluno não encontrado!" << endl;
        }
    } else {
        cout << "Nenhum aluno cadastrado!" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(0));
    const int TAM = 100;
    Aluno lista [TAM];
    int opcao, quant, i, j, totalAlunos = 0, numDaMatricula; 
    
    do{
        cout << endl;
        cout << "----------- MENU -----------\n1 - Cadastrar Aluno\n2 - Listar alunos cadastrados\n3 - Buscar por matricula\n4 - Sair" << endl;
        cout << "\nDigite a opção desejada: ";
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
                    totalAlunos++;
                }
                cout << "\nAlunos cadastrados com sucesso!" << endl;
                break;
            case 2:
                if (totalAlunos != 0){
                    cout << "Alunos cadastrados: " << endl;
                    for (i = 0; i < totalAlunos; i++)
                        listarAlunos(lista, i);
                }else{
                    cout << "Nenhum aluno cadastrado!" << endl; 
                }          
                break;
            case 3:
                buscarPorMatricula(lista, totalAlunos);
                break; 
            case 4:
                cout << "Saindo do programa..." << endl;
                break;
            default:
                cout << "Opção Inválida! Tente novamente." << endl;
                break;
        }
    }while (opcao != 4);
    cout << "\nPrograma finalizado com sucesso!";
    return 0;
}
    
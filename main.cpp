#include <iostream>
#include <cctype>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <cmath>

using namespace std;
#define QTD_ESTUDANTES 5
#define QTD_NOTAS 3

struct Estudante
{
    string nome;
    double notas[QTD_NOTAS];
    double media;
    string situacao;
};

double obterMedia(double notas[QTD_NOTAS])
{
    double soma = 0;

    for (int i = 0; i < QTD_NOTAS; i++)
    {
        soma += notas[i];
    }

    return soma / QTD_NOTAS;
}

int main()
{   
    int quant;
    cout<<"Quantos alunos você quer cadastrar? ";
    while (!(cin>>quant) || quant < 0 || quant > QTD_ESTUDANTES){
        cout<<"O valor digitado não é válido. Por favor, digite novamente: "<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    Estudante estudantes[QTD_ESTUDANTES];

    Estudante* estMaiorMedia;

    for (int i = 0; i < quant; i++)
    {
        Estudante* est = &estudantes[i];
        printf("\nDigite o nome do aluno %d: ", i + 1);
        getline(cin>> ws, est->nome);
        while (isdigit(est->nome[i])){
            cout<<"O nome informado não é válido. Por favor, tente novamente: ";
            cin.clear();
            getline(cin>> ws, est->nome);
        }

        for (int j = 0; j < QTD_NOTAS; j++)
        {
            printf("Digite a nota %d do aluno %s: ", j + 1, est->nome.c_str());
            while (!(cin>>est->notas[j]) || est->notas[j] < 0 || est->notas[j] > 10){
                cout<<"Comando inválido, por favor digite a nota novamente: ";
                cin.clear();
                
            }
        }
        cout<<endl;
        est->media = obterMedia(est->notas);

        est->situacao = (est->media >= 7) ? "Aprovado" : "Reprovado";

        if (i == 0) {
            estMaiorMedia = est;
        } else {
            if (est->media > estMaiorMedia->media) {
                estMaiorMedia = est;
            }
        }
    }
    printf("''' \n");
    cout<< left << setw(15) << "Nome"
        << setw(8) << "Nota1"
        << setw(8) << "Nota2"
        << setw(8) << "Nota3"
        << setw(10) << "Media"
        << setw(12) << "Situacao" << endl;
    
    for (int i = 0; i < quant; i++) {
        double n1, n2, n3;
        
        n1 = estudantes[i].notas[0];
        n2 = estudantes[i].notas[1];
        n3 = estudantes[i].notas[2];
        
        cout<< fixed << setprecision(2)
            << left << setw(15) << estudantes[i].nome.c_str()
            << setw(8) << n1
            << setw(8) << n2
            << setw(8) << n3 
            << setw(10) << estudantes[i].media
            << setw(12) << estudantes[i].situacao.c_str() << endl;
    }
    
    printf("'''\nAluno com maior média: %s (%.2f)"
    , estMaiorMedia->nome.c_str(), estMaiorMedia->media);
    

    return 0;
}
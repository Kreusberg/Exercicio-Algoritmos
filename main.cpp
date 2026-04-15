#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>

#define QTD_ESTUDANTES 3
#define QTD_NOTAS 5

struct Estudante
{
    std::string nome;
    double notas[QTD_NOTAS];
    double media;
    std::string situacao;
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
    Estudante estudantes[QTD_ESTUDANTES];

    Estudante estMaiorMedia;

    for (int i = 0; i < QTD_ESTUDANTES; i++)
    {
        Estudante est = estudantes[i];
        printf("Digite o nome do aluno %d: ", i + 1);
        std::getline(std::cin >> std::ws, est.nome);

        for (int j = 0; j < QTD_NOTAS; j++)
        {
            printf("Digite a nota %d do aluno %s: ", j + 1, est.nome.c_str());
            std::cin >> est.notas[j];
        }

        est.media = obterMedia(est.notas);

        est.situacao = (est.media >= 7) ? "Aprovado" : "Reprovado";
    }

    return 0;
}

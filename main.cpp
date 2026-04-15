#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>

#define QTD_ESTUDANTES 5
#define QTD_NOTAS 3

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

    Estudante* estMaiorMedia;

    for (int i = 0; i < QTD_ESTUDANTES; i++)
    {
        Estudante* est = &estudantes[i];
        printf("Digite o nome do aluno %d: ", i + 1);
        std::getline(std::cin >> std::ws, est->nome);

        for (int j = 0; j < QTD_NOTAS; j++)
        {
            printf("Digite a nota %d do aluno %s: ", j + 1, est->nome.c_str());
            std::cin >> est->notas[j];
        }

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

    printf("'''\n ALUNO N1 N2 N3 MÉDIA SITUAÇÃO\n");
    
    for (int i = 0; i < QTD_ESTUDANTES; i++) {
        double n1, n2, n3;
        
        n1 = estudantes[i].notas[0];
        n2 = estudantes[i].notas[1];
        n3 = estudantes[i].notas[2];
        
        printf("%s %.2f %.2f %.2f %.2f %s\n", estudantes[i].nome.c_str(), n1, n2, n3, estudantes[i].media, estudantes[i].situacao.c_str());
    }
    
    printf("'''\n Aluno com maior média: %s (%.2f)"
    , estMaiorMedia->nome.c_str(), estMaiorMedia->media);
    

    return 0;
}

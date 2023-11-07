/*
    Acadêmico: Ícaro Souza Azevedo Lopes
    R.A. 23167454-5
    Curso: Bacharelado em Engenharia de Software
    Disciplina: Linguagem e Técnicas de Programação - 53/2023
    Valor da atividade: 3,00
    Prazo: 08/12/2023 23:59
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct Atendimento {
    char nome[100];
    char cpf[15];
    int tipoAtendimento;
};

void clear_screen() {
    for (int i = 0; i < 20; i++) {
        printf("\n");
    }
}

void listarAtendimentos(struct Atendimento atendimentos[], int totalAtendimentos) {
    if (totalAtendimentos == 0) {
        printf("Nenhum atendimento registrado ainda.\n");
    } else {
        clear_screen();
        printf("Listagem de Atendimentos:\n");
        for (int i = 0; i < totalAtendimentos; i++) {
            printf("Nome: %s\nCPF: %s\nTipo de Atendimento: %d\n===============================\n",
                   atendimentos[i].nome, atendimentos[i].cpf, atendimentos[i].tipoAtendimento);
        }
    }
}

void listarAtendimentosSetor(struct Atendimento atendimentos[], int totalAtendimentos, int tipoAtendimento) {
    clear_screen();
    printf("Listagem de Atendimentos por Setor:\n");
    int encontrouAtendimentos = 0;

    for (int i = 0; i < totalAtendimentos; i++) {
        if (atendimentos[i].tipoAtendimento == tipoAtendimento) {
            encontrouAtendimentos = 1;
            printf("Nome: %s\nCPF: %s\nTipo de Atendimento: %d\n===============================\n",
                   atendimentos[i].nome, atendimentos[i].cpf, atendimentos[i].tipoAtendimento);
        }
    }

    if (!encontrouAtendimentos) {
        printf("Nenhum atendimento do tipo %d registrado.\n", tipoAtendimento);
    }
}

void sistemaAtendimento() {
    setlocale(LC_ALL, "Portuguese");
    struct Atendimento atendimentos[50];
    int totalAtendimentos = 0;
    int decisao = 0;

    while (1) {
        printf("Bem-vindo ao sistema de atendimento\n1 - Solicitar Atendimento\n2 - Listar Atendimentos Registrados\n3 - Listar Atendimento por Setor\n4 - Sair\n\n");
        scanf("%d", &decisao);

        switch (decisao) {
            case 1:
                if (totalAtendimentos < 50) { 
                    clear_screen();
                    printf("Opção - Registrar Atendimento\nDigite o seu nome\n");
                    scanf(" %99[^\n]", atendimentos[totalAtendimentos].nome);

                    printf("Digite o seu CPF\n");
                    scanf(" %14s", atendimentos[totalAtendimentos].cpf);

                    printf("1 - Abertura de Conta\n2 - Caixa\n3 - Gerente Pessoa Física\n4 - Gerente Pessoa Jurídica\n");
                    scanf("%d", &atendimentos[totalAtendimentos].tipoAtendimento);
                    
                    clear_screen();
                    printf("Nome: %s\nCPF: %s\nTipo de Atendimento: %d\n===================================\n",
                           atendimentos[totalAtendimentos].nome, atendimentos[totalAtendimentos].cpf, atendimentos[totalAtendimentos].tipoAtendimento);

                    ++totalAtendimentos;
                } else {
                    clear_screen();
                    printf("Limite de atendimentos atingido.\n");
                }
                break;

            case 2:
                listarAtendimentos(atendimentos, totalAtendimentos);
                break;

            case 3:
                clear_screen();
                printf("1 - Abertura de Conta\n2 - Caixa\n3 - Gerente Pessoa Física\n4 - Gerente Pessoa Jurídica\n");
                scanf("%d", &decisao);

                if (decisao >= 1 && decisao <= 4) {
                    listarAtendimentosSetor(atendimentos, totalAtendimentos, decisao);
                } else {
                    clear_screen();
                    printf("Número inválido, tente novamente!\n\n");
                }
                break;

            case 4:
                clear_screen();
                return;

            default:
                clear_screen();
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    }
}

int main() {
    sistemaAtendimento();
    return 0;
}

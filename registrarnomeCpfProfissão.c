#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char Nome[50];
    char CPF[15];
    char Profissao[50];
} Funcionario;

typedef struct Arvore {
    Funcionario *funcionario;
    struct Arvore *esq;
    struct Arvore *dir;
} NoArvore;

void inserirNome(NoArvore **raiz, Funcionario funcionario) {
    if (*raiz == NULL) {
        *raiz = (NoArvore *) malloc(sizeof(NoArvore));
        (*raiz)->funcionario = (Funcionario *) malloc(sizeof(Funcionario));
        strcpy((*raiz)->funcionario->Nome, funcionario.Nome);
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
    } else {
        if (strcmp(funcionario.Nome, (*raiz)->funcionario->Nome) < 0) {
            inserirNome(&(*raiz)->esq, funcionario);
        } else {
            inserirNome(&(*raiz)->dir, funcionario);
        }
    }
}

void inserirProfissao(NoArvore **raiz, Funcionario funcionario) {
    if (*raiz == NULL) {
        *raiz = (NoArvore *) malloc(sizeof(NoArvore));
        (*raiz)->funcionario = (Funcionario *) malloc(sizeof(Funcionario));
        strcpy((*raiz)->funcionario->Profissao, funcionario.Profissao);
        (*raiz)->esq = NULL;
        (*raiz)->dir = NULL;
    } else {
        if (strcmp(funcionario.Profissao, (*raiz)->funcionario->Profissao) < 0) {
            inserirProfissao(&(*raiz)->esq, funcionario);
        } else {
            inserirProfissao(&(*raiz)->dir, funcionario);
        }
    }
}

NoArvore *buscarNome(NoArvore *raiz, char nome[]) {
    if (raiz == NULL) {
        return NULL;
    }

    if (strcmp(nome, raiz->funcionario->Nome) == 0) {
        return raiz;
    }

    if (strcmp(nome, raiz->funcionario->Nome) < 0) {
        return buscarNome(raiz->esq, nome);
    } else {
        return buscarNome(raiz->dir, nome);
    }
}

NoArvore *buscarProfissao(NoArvore *raiz, char profissao[]) {
    if (raiz == NULL) {
        return NULL;
    }

    if (strcmp(profissao, raiz->funcionario->Profissao) == 0) {
        return raiz;
    }

    if (strcmp(profissao, raiz->funcionario->Profissao) < 0) {
        return buscarProfissao(raiz->esq, profissao);
    } else {
        return buscarProfissao(raiz->dir, profissao);
    }
}

void exibirFuncionario(Funcionario funcionario) {
    printf("Nome: %s\n", funcionario.Nome);
    printf("CPF: %s\n", funcionario.CPF);
    printf("Profissao: %s\n", funcionario.Profissao);
}

void preencherFuncionario(Funcionario *funcionario) {
    printf("Digite o nome do funcionario: ");
    scanf(" %[^\n]", funcionario->Nome);
    printf("Digite o CPF do funcionario: ");
    scanf(" %[^\n]", funcionario->CPF);
    printf("Digite a profissao do funcionario: ");
    scanf(" %[^\n]", funcionario->Profissao);
}

int main() {
    NoArvore *raizNome = NULL;
    NoArvore *raizProfissao = NULL;
    int opcao;
    Funcionario funcionario;

    do {
        printf("\nMenu de Opcoes:\n");
        printf("1. Inserir Funcionario.\n");
        printf("2. Buscar Funcionario por Nome.\n");
        printf("3. Buscar Funcionario por Profissao.\n");
        printf("4. Sair.\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                preencherFuncionario(&funcionario);
                inserirNome(&raizNome, funcionario);
                inserirProfissao(&raizProfissao, funcionario);
                break;
            case 2:
                printf("Digite o nome do funcionario que deseja buscar: ");
                scanf(" %[^\n]", funcionario.Nome);
                NoArvore *resultadoNome = buscarNome(raizNome, funcionario.Nome);
                if (resultadoNome != NULL) {
                    exibirFuncionario(*(resultadoNome->funcionario));
                } else {
                    printf("Funcionario nao encontrado.\n");
                }
                break;
            case 3:
                printf("Digite a profissao do funcionario que deseja buscar: ");
                scanf(" %[^\n]", funcionario.Profissao);
                NoArvore *resultadoProfissao = buscarProfissao(raizProfissao, funcionario.Profissao);
                if (resultadoProfissao != NULL) {
                    exibirFuncionario(*(resultadoProfissao->funcionario));
                } else {
                    printf("Funcionario nao encontrado.\n");
                }
                break;
            case 4:
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 4);

    return 0;
}

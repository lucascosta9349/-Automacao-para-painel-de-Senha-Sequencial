#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int senha;
    int aux;
    int opcao;
    FILA *f1 = (FILA *)malloc(sizeof(FILA));
    inicializaFila(f1); // Seta as posi��es

    do
    {
        opcao = lerOpcaoMenu();
        system("cls");

        switch (opcao)
        {
        case 0:
            printf("\n\nSaindo...\n\n");
            break;

        case 1:
            printf("\nGerando senha...\n");
            senha = gerarSenha();
            mostrarSenha(senha);
            enfileirar(senha, f1);
            system("PAUSE");
            system("cls");
            break;

        case 2:
            do
            {
                system("cls");
                printf("*******Chamada de Senha*******\n");
                printf("\n\tSenha: %d\n", desenfileirar(f1));
                printf("\n\n\t1 - chamar outra senha\n");
                printf("\t0 - Voltar ao Menu\n");
                printf("\t>>");
                scanf("%d", &aux);
                system("cls");
            } while (aux != 0);
            break;

        case 3:
            system("cls");
            imprimeFila(f1);
            system("PAUSE");
            system("cls");
            break;
        }

    } while (opcao != 0);

    return (EXIT_SUCCESS);
}

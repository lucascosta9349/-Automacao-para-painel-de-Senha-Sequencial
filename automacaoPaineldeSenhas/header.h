#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct NO{
    int dado;
    struct NO *prox;
}NO;

typedef struct FILA{
    NO *ini;
    NO *fim;
}FILA;

void inicializaFila(FILA *f){
  f->ini = NULL;
  f->fim = NULL;
}

void enfileirar(int dado, FILA *f){
    NO *ptr = (NO*) malloc(sizeof(NO));
    if(ptr == NULL){
        printf("Erro de alocação.\n");
        return;
    }
    else{
        ptr->dado = dado;
        ptr->prox = NULL;
        if(f->ini == NULL){
            f->ini = ptr;
        }
        else{
            f->fim->prox = ptr;
        }
        f->fim = ptr;
    }
}

int desenfileirar(FILA *f){
    NO *ptr = f->ini;
    int dado;
    if(ptr != NULL){
        f->ini = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        if(f->ini == NULL){
            f->fim = NULL;
        }
        return dado;
    }
    else{
        printf("Fila vazia.\n");
        return;
    }
}

void imprimeFila(FILA *f){
  NO *ptr = f->ini;
  int i=1;
  if (ptr != NULL){
    while (ptr != NULL){
      printf("senha %d: %d\n",i ,ptr->dado);
      ptr = ptr->prox;
      i++;
    }
  }
  else{
    printf("Fila vazia.\n");
    return;
  }
}
 int gerarSenha(){
    srand(time(NULL));
    int senha = 0;
    while(senha<100){
        senha = rand()%999;
    }
  return senha;
 }
 int lerOpcaoMenu(){

    int opcao;
    printf("\n ============== Sistemas de Senhas ==============");
    printf("\n |\t\t**Geracao de senhas**  \t\t|");
    printf("\n ================================================");
    printf("\n | (1)Gerar senha \t\t\t\t|");
    printf("\n | (2)Chamar senha \t\t\t\t|");
    printf("\n | (3)Listar fila \t\t\t\t|");
    printf("\n | (0)Sair do programa \t\t\t\t|");
    printf("\n ================================================\n");
    printf("\n>> ");
    scanf("%d", &opcao);
    return opcao;
}

void mostrarSenha(int senha){
    printf("________________________________\n");
    printf("|      **Senha gerada**\t\t|\n");
    printf("|\t\t\t\t|\n");
    printf("| SENHA:     ** %d **   \t\t|\n", senha);
    printf("|_______________________________|\n");
}



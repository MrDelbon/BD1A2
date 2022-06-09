#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoArv;

void inserir(NoArv **raiz, int num){
    NoArv *aux = *raiz;
    while(aux){
        if(num < aux->valor)
            raiz = &aux->esquerda;
        else
            raiz = &aux->direita;
        aux = *raiz;
    }
    aux = malloc(sizeof(NoArv));
    aux->valor = num;
    aux->esquerda = NULL;
    aux->direita = NULL;
    *raiz = aux;
}

NoArv* buscar(NoArv *raiz, int num){
    while(raiz){
        if(num < raiz->valor)
            raiz = raiz->esquerda;
        else if(num > raiz->valor)
            raiz = raiz->direita;
        else
            return raiz;
    }
    return NULL;
}

NoArv* remover(NoArv *raiz, int chave) {
    if(raiz == NULL){
        printf("\n\tValor nao encontrado!\n");
        return NULL;
    } else { 
        if(raiz->valor == chave) {
            if(raiz->esquerda == NULL && raiz->direita == NULL) {
                free(raiz);
                printf("\n\tElemento folha removido: %d !\n", chave);
                return NULL;
            }
            else{
                if(raiz->esquerda != NULL && raiz->direita != NULL){
                    NoArv *aux = raiz->esquerda;
                    while(aux->direita != NULL)
                        aux = aux->direita;
                    raiz->valor = aux->valor;
                    aux->valor = chave;
                    printf("\n\tElemento trocado: %d !\n", chave);
                    raiz->esquerda = remover(raiz->esquerda, chave);
                    return raiz;
                }
                else{
                    NoArv *aux;
                    if(raiz->esquerda != NULL)
                        aux = raiz->esquerda;
                    else
                        aux = raiz->direita;
                    free(raiz);
                    printf("\n\tElemento com 1 filho removido: %d !\n", chave);
                    return aux;
                }
            }
        } else {
            if(chave < raiz->valor)
                raiz->esquerda = remover(raiz->esquerda, chave);
            else
                raiz->direita = remover(raiz->direita, chave);
            return raiz;
        }
    }
}

void imprimir_preorder(NoArv *raiz){
    if(raiz){
        printf("%d ", raiz->valor);
        imprimir_preorder(raiz->esquerda);
        imprimir_preorder(raiz->direita);
    }
}

void imprimir_inorder(NoArv *raiz){
    if(raiz){
        imprimir_inorder(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir_inorder(raiz->direita);
    }
}

void imprimir_postorder(NoArv *raiz){
    if(raiz){
        imprimir_postorder(raiz->esquerda);
        imprimir_postorder(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

void menu(void){
	system("cls");
    printf("\t|--------------------|\n");
	printf("\t|                    |\n");
	printf("\t|   MENU PRINCIPAL   |\n");
	printf("\t|                    |\n");
	printf("\t|--------------------|\n\n");  
	printf("\t   0 - Sair\n");
    printf("\t   1 - Inserir\n");
    printf("\t   2 - Imprimir\n");
    printf("\t   3 - Buscar\n");
    printf("\t   4 - Remover\n");
}

int main(){

    NoArv *busca, *raiz = NULL;
    int opcao, valor;

    do{
        menu();
		scanf("%d", &opcao);

        switch(opcao){
        
        case 1:
        	system("cls");
            printf("\n\tDigite um valor: ");
            scanf("%d", &valor);
            inserir(&raiz, valor);
            printf("\n\tElemento %d inserido, qualquer tecla para voltar ao menu\n\t", valor);
			fflush(stdin); getch();
            break;    
        case 2:
        	system("cls");
            printf("\n\tImpressao preorder:\n\t");
            imprimir_preorder(raiz);
            printf("\n");
            printf("\n\tImpressao inorder:\n\t");
            imprimir_inorder(raiz);
            printf("\n");
            printf("\n\tImpressao postorder:\n\t");
            imprimir_postorder(raiz);
            printf("\n");
            printf("\n\tImpressao realizada, pressione qualquer tecla para voltar ao menu\n\t");
			fflush(stdin); getch();
            break;
        case 3:
        	system("cls");
            printf("\n\tDigite o valor a ser procurado: ");
            scanf("%d", &valor);
            busca = buscar(raiz, valor);
            if(busca)
                printf("\n\tValor encontrado: %d\n", busca->valor);
            else
                printf("\n\tValor nao encontrado!\n");
            printf("\n\tPressione qualquer tecla para voltar ao menu\n\t");
			fflush(stdin); getch();
            break;
        case 4:
        	system("cls");
            printf("\n\tDigite o valor a ser removido: ");
            scanf("%d", &valor);
            raiz = remover(raiz, valor);
            printf("\n\tPressione qualquer tecla para voltar ao menu\n\t");
			fflush(stdin); getch();
            break;
        default:
            if(opcao != 0)
            	printf("\n\tOpcao invalida!!!\n");
        }
    }while(opcao != 0);

    return 0;
}

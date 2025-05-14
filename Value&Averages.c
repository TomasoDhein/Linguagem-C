// Esse código em C solicita ao usuário que digite números positivos e calcula a média aritmética desses números.
// A entrada de dados continua até que um número negativo seja digitado, o que encerra o loop.

#include <stdio.h>

void main() {
    int num, soma = 0, qtd = 0;

    printf("Digite valores positivos (Caso digite um valor negativo o bloco encerrará)!!!\n\n");
    printf("==========================================================\n\n");

    do {
        printf("Valor: ");
        scanf("%d", &num);

        if (num < 0) break;

        soma += num;
        qtd++;
    } while (1);

    if (qtd > 0) {
        float media = (float)soma / qtd;
        printf("A média dos valores é: %.2f\n", media);
    } else {
        printf("Nenhum valor positivo foi digitado.\n");
    }

    printf("\n====================================================");
}

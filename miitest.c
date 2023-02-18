#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

int main() {
    printf("Olá! Seja bem-vindo(a) a minha interação!\n");
    //sleep(1);
    printf("Por favor, informe seu nome para que possamos começar.\n");
    //sleep(1);

    char name[100];
    int nameLength = strlen(name);
    printf("Digite seu nome: ");
    scanf("%s", name);

    for (int i = 0; i < nameLength; i++) {
        if (ispunct(name[i]) || isdigit(name[i]) || !isspace(name[i])){
            printf("Por favor, digite um nome válido.\n");
            return 1;
        }
    }
    printf("Olá, %s!", name);
}

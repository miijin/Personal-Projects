#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

char answer[100];

int main() {
    system("cls");
    //Apresentação da interação.
    char message[100];
    char message1[] = "Olá! Seja bem-vindo(a) a minha interação!\n";
    char message2[] = "Por favor, informe seu nome para que possamos começar.\n";
    strcpy(message, message1);
    strcat(message, message2);
    CaracterByCaracter(message);

    char name[100];
    while (1) {
        char askName[] = "Digite seu nome: ";
        CaracterByCaracter(askName);
        scanf("%s", name);

        int validName = 1;
        for (int i = 0; i < strlen(name); i++) {
            if (ispunct(name[i]) || isdigit(name[i])) {
                printf("Por favor, digite um nome válido.\n");
                validName = 0;
                break;
            }
        }
        if (validName == 1) {
            break;
        }
    }
    // Iniciando a interação.
    printf("Olá, %s! ", name);
    printf("Está preparado para começar a nossa imersão?(S / N)\n");
    scanf("%s", answer);

    if (strcasecmp(answer, "sim") == 0 || strcasecmp(answer, "s") == 0) {
        printf("Então vamos embarcar nessa jornada, espero que se divirta!");
    }
    else {
        printf("ERROR!");
    }
}

void CaracterByCaracter(char message[]) {
    for (int i = 0; i < strlen(message); i++) {
        printf("%c", message[i]);
        fflush(stdout);
        usleep(50000);
    }
}

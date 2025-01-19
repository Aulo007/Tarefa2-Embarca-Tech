#include <stdio.h>
#include "pico/stdlib.h"

// Definição dos pinos
#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 13
#define BUZZER 21

void init_gpio()
{
    // Inicializa LEDs
    gpio_init(LED_GREEN);
    gpio_init(LED_BLUE);
    gpio_init(LED_RED);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_set_dir(LED_RED, GPIO_OUT);

    // Inicializa Buzzer
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
}

void turn_off_all_leds()
{
    gpio_put(LED_GREEN, 0);
    gpio_put(LED_BLUE, 0);
    gpio_put(LED_RED, 0);
}

void display_menu()
{
    printf("\n\r=== BitDogLab Control System ===\n\r");
    printf("1 - Ligar LED Verde\n\r");
    printf("2 - Ligar LED Azul\n\r");
    printf("3 - Ligar LED Vermelho\n\r");
    printf("4 - Ligar Luz Branca (todos LEDs)\n\r");
    printf("5 - Desligar todos LEDs\n\r");
    printf("6 - Acionar Buzzer\n\r");
    printf("7 - Reboot\n\r");
    printf("Digite um comando: \n\r");
}

int main()
{
    stdio_init_all();
    sleep_ms(2000); // Aguarda inicialização do USB

    init_gpio();
    turn_off_all_leds(); // Garante que todos os LEDs começam desligados

    printf("\n\rIniciando sistema...\n\r");
    sleep_ms(1000);

    while (1)
    {
        display_menu();

        char cmd = getchar(); // Aguarda entrada do usuário
        printf("Comando recebido: %c\n\r", cmd);

        switch (cmd)
        {
        case '1':
            turn_off_all_leds();
            gpio_put(LED_GREEN, 1);
            printf("LED Verde ligado!\n\r");
            break;

        case '2':
            turn_off_all_leds();
            gpio_put(LED_BLUE, 1);
            printf("LED Azul ligado!\n\r");
            break;

        case '3':
            turn_off_all_leds();
            gpio_put(LED_RED, 1);
            printf("LED Vermelho ligado!\n\r");
            break;

        case '4':
            gpio_put(LED_GREEN, 1);
            gpio_put(LED_BLUE, 1);
            gpio_put(LED_RED, 1);
            printf("Luz Branca ativada!\n\r");
            break;

        case '5':
            turn_off_all_leds();
            printf("Todos LEDs desligados!\n\r");
            break;

        case '6':
            printf("Acionando Buzzer por 2 segundos...\n\r");
            gpio_put(BUZZER, 1);
            sleep_ms(2000);
            gpio_put(BUZZER, 0);
            printf("Buzzer desligado!\n\r");
            break;

        case '7':
            printf("Reiniciando sistema...\n\r");
            watchdog_enable(1, 1);
            while (1)
                ;
            break;

        default:
            printf("Comando invalido!\n\r");
            break;
        }

        sleep_ms(500); // Pequeno delay entre comandos
    }
    return 0;
}
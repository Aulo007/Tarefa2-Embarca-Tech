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
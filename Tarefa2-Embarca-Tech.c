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
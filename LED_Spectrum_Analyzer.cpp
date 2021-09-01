#include <stdio.h>
#include "pico/stdlib.h"

int main()
{
    stdio_init_all();

    const unsigned int LED_PIN = 25;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while(true) {
        gpio_put(LED_PIN, true);
        printf("I am ON\n");
        sleep_ms(1000);
        gpio_put(LED_PIN, false);
        printf("I am OFF\n");
        sleep_ms(1000);
    }

    return 0;
}

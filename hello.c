#include "pico/stdlib.h"
#include "hardware/pio.h"
// Our assembled program:
#include "hello.pio.h"

int main() {
    stdio_init_all();

    // PIO pio = pio1;
    // uint offset = pio_add_program(pio, &hello_program);
    // uint sm = pio_claim_unused_sm(pio, true);
    // pio_sm_config c = hello_program_init(pio, sm, offset, 0);


    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true) {
        getchar();
        gpio_put(LED_PIN, 1);
        getchar();
        gpio_put(LED_PIN, 0);
    }
}
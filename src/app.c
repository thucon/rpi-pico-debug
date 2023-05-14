#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

const uint LED_PIN = 25;

int main()
{
    bi_decl(bi_program_description("This is a test binary."));
    bi_decl(bi_1pin_with_name(LED_PIN, "On-board LED"));

    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    uint32_t cnt = 0;
    
    while (1)
    {
        gpio_put(LED_PIN, 0);
        printf("[%u] LED OFF\n", cnt);
        sleep_ms(250);
        gpio_put(LED_PIN, 1);
        printf("[%u] LED ON\n", cnt);
        sleep_ms(1000);
        ++cnt;
    }
}
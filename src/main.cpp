#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>

#include <libopencm3/stm32/spi.h>
#include <libopencm3/stm32/usart.h>

// Настройка таймера
void timer_setup() {
    rcc_periph_clock_enable(RCC_GPIOD);
    rcc_periph_clock_enable(RCC_GPIOE);
    rcc_periph_clock_enable(RCC_GPIOC);
    rcc_periph_clock_enable(RCC_GPIOB);
    rcc_periph_clock_enable(RCC_SPI1);
}

// Настройка радиомодуля NRF24L01
void setup_NRF24L01() {


    // CE
    gpio_mode_setup(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO5); 
    // IRQ
    gpio_mode_setup(GPIOC, GPIO_MODE_INPUT, GPIO_PUPD_NONE, GPIO4); 
    // Настройка SPI для радиомодуля (MISO - PA6, MOSI - PA7, SCK - PA5, CSN - PA4)
 
    gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_16_MHZ,
        GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO4 | GPIO5 | GPIO7);

    gpio_set_mode(GPIOA, GPIO_MODE_INPUT, GPIO_CNF_INPUT_FLOAT,
        GPIO6);
    // МК в Master
    spi_init_master(SPI1, SPI_CR1_BAUDRATE_FPCLK_DIV_64, SPI_CR1_CPOL_CLK_TO_1_WHEN_IDLE,
        SPI_CR1_CPHA_CLK_TRANSITION_2, SPI_CR1_DFF_8BIT, SPI_CR1_MSBFIRST);                  

    spi_enable(SPI1);
}

// Настройка радиомодуля E45-ttl-1w
void setup_ER45 () {

    gpio_set_mode(GPIOD, GPIO_MODE_OUTPUT_16_MHZ,
        GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO_UART5_TX);
    gpio_set_mode(GPIOC, GPIO_MODE_INPUT,
        GPIO_CNF_INPUT_FLOAT, GPIO_UART5_RX);

    usart_set_baudrate(UART5, 115200);
    usart_set_databits(UART5, 8);
    usart_set_stopbits(UART5, USART_STOPBITS_1);
    usart_set_mode(UART5, USART_MODE_TX_RX);
    usart_set_parity(UART5, USART_PARITY_NONE);
    usart_set_flow_control(UART5, USART_FLOWCONTROL_NONE);

    // M0, M1
    gpio_mode_setup(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO1 | GPIO3);
    // AUX
    gpio_mode_setup(GPIOD, GPIO_MODE_INPUT, GPIO_PUPD_NONE, GPIO0);
}

//Настройка клавиатуры
void setup_keyboard() {
    gpio_mode_setup(GPIOD, GPIO_MODE_INPUT, GPIO_PUPD_NONE, GPIO14 | GPIO13 | GPIO12 | GPIO10 | GPIO9 | GPIO8);
    gpio_mode_setup(GPIOB, GPIO_MODE_INPUT, GPIO_PUPD_NONE, GPIO13 | GPIO11);
}

//Настройка светодиода
void setup_led() {
    gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO2);
}

int main () {
    
return 0;
}


# Курсовая работа по дисциплине "Микроконтроллеры мехатронных устройств"
# На тему "Внешняя система ретрансляции для робота - ассистента"
### Автор : Сафронов И.А.

### Используемое программное обеспечение

1. arm-none-eabi-g++ --- кросс-компилятор.
1. make --- система сборки проекта.
1. cmake --- система управления проектом.
1. git --- система контроля версий.

- Настройка проекта: 
    cmake -B build
- Сборка проекта:
    cmake --build build     
- Прошивка МК:
    cmake --install build 

### Переферийные устройства:
    - Радиомодуль NRF24L01 - Интерфейс SPI
        MISO - интерфейс SPI (PA6)
        MOSI - интерфейс SPI (PA7)
        SCK  - интерфейс SPI (PA5)
        CSN(SS)  - интерфейс SPI (PA4)
        CE   - Режим для радиомодуля (приемник/передатчик) (PC5 работает на выход)
        IRQ  - Прерывание (PC4 работает на вход)
    - Радиомодуль E45-TTL-1W - Интерфес UART
        RXD - интерфейс UART (PC12)
        TXD - интерфейс UART (PD2)
        M0  - для переключения режимов (PD3 работает на выход)
        M1  - для переключения режимов (PD1 работает на выход)
        AUX - для отслеживания состояния (PD0 работает на вход)
    - Подключение к другим модулям - SPI
        MISO - интерфейс SPI (PC2)
        MOSI - интерфейс SPI (PC3)
        SCK  - интерфейс SPI (PB10)
        SS   - интерфейс SPI (PB12)
    - Программатор - SWD 
        SWD_IO (PA13)
        SWD_CLK (PE9)
    - Клавиатура - I/O (PD14, PD13, PD12, PD10, PD9, PD8, PB13, PB11 работает на вход) 
    - Светодиод - I/O (PE2 работает на выход)

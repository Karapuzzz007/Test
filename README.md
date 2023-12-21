# Курсовая работа по дисциплине "Микроконтроллеры мехатронных устройств"
# На тему "Внешняя система ретрансляции для робота - ассистента"
### Автор : Сафронов И.А.

### Используемое программное обеспечение

1. arm-none-eabi-g++ --- кросс-компилятор.
1. make --- система сборки проекта.
1. cmake --- система управления проектом.
1. git --- система контроля версий.

-Настройка проекта: 
    cmake -B build
-Сборка проекта:
    cmake --build build     
-Прошивка МК:
    cmake --install build 

    Переферийные устройства:
    1. Радиомодуль NRF24L01 - Интерфес SPI
        MISO - интерфес SPI (PA6)
        MOSI - интерфес SPI (PA7)
        SCK  - интерфес SPI (PA5)
        CSN  - интерфес SPI (PA4)
        CE   - Режим для радиомодуля (приемник/передатчик) (PC5)
        IRQ  - Прерывание (PC4)
    2. Радиомодуль E45-TTL-1W - Интерфес UART
        RXD - интерфес UART (PC12)
        TXD - интерфес UART (PD2)
        M0  - для переключения режимов (PD3)
        M1  - для переключения режимов (PD1)
        AUX - для отслеживания состояния (PD0)
    3. Подключение к другим модулям - SPI
    4. Программатор - SWD 
        SWD_IO (PA13)
        SWD_CLK (PE9)
    5. Клавиатура - I/O (PD14, PD13, PD12, PD10, PD9, PD8, PB13, PB11)
    6. Светодиод - I/O (PE2)

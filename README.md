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

Питание устройства 12В

### Переферийные устройства:
    - Радиомодуль NRF24L01 - Интерфейс SPI
        MISO - интерфейс SPI (PA6)
        MOSI - интерфейс SPI (PA7)
        SCK  - интерфейс SPI (PA5)
        CSN(SS)  - интерфейс SPI (PA4)
        CE   - Режим для радиомодуля (приемник/передатчик) (PC5 работает на выход)
        Входной, активный - высокий уровень. Наличие высокого уровня на этом входе активирует режим приёма. 
        В режиме передачи импульс не менее 10мкс начинает передачу.
        IRQ  - Прерывание (PC4 работает на вход)
        Если трансивер находится в режиме передатчика, появление на этом выводе низкого уровня свидетельствует об одном из двух событий – 
        1) пакет данных успешно отправлен, 
        2) разрешенное количество попыток отправки израсходовано, но пакет данных так и не был отправлен.

    - Радиомодуль E45-TTL-1W - Интерфес UART
        RXD - интерфейс UART (PC12)
        TXD - интерфейс UART (PD2)
        M0  - для переключения режимов (PD3 работает на выход)
        M1  - для переключения режимов (PD1 работает на выход)
        (4 Режима) M0/M1
        Режим 0-НИЗКИЙ/НИЗКИЙ	Нормальный режим работы
        Режим 1-НИЗКИЙ/ВЫСОКИЙ	Режим пробуждения, лучше всего использовать в качестве передатчика с приемником в режиме 2
        Режим 2-ВЫСОКИЙ/НИЗКИЙ	Режим энергосбережения. Модуль выйдет из спящего режима только после того, как передатчик в режиме 1 отправит радиопакет
        Режим 3-ВЫСОКИЙ/ВЫСОКИЙ	Спящий режим / Режим настроек

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
        Ожидает на двух из 8 линий высого уровня сигнала 

    - Светодиод - I/O (PE2 работает на выход)



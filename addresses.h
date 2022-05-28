#define FIRMWARE_START_ADDRESS 0x08005C00 //начало адресного пространства доступного для записи (начинается с адреса, где заканчивается бутлодер)
#define UPPER_ADDRESS 0x08018800 //0x08006000, //0x08018800, //конец его (64kb минус последняя страница)
#define PAGE_SIZE 0x0400 //размер страницы в памяти
#define BOOTLOADER_FLAG_ADDRESS 0x08018C00

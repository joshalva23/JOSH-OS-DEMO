#ifndef CONFIG_H
#define CONFIG_H

#define KERNEL_CODE_SELECTOR 0x08
#define KERNEL_DATA_SELECTOR 0x10
#define JOSHOS_TOTAL_INTERRUPTS 512

//Heap memory 100MB
#define JOSHOS_HEAP_SIZE_BYTES 104857600 
#define JOSHOS_HEAP_BLOCK_SIZE 4096
#define JOSHOS_HEAP_ADDRESS 0x01000000
#define JOSHOS_HEAP_TABLE_ADDRESS 0x00007E00

#define JOSHOS_SECTOR_SIZE 512;

#endif
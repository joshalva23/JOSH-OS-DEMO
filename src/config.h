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

#define JOSHOS_SECTOR_SIZE 512

#define JOSHOS_MAX_FILESYSTEMS 12
#define JOSHOS_MAX_FILE_DESCRIPTORS 512

#define JOSHOS_MAX_PATH 108

#define JOSHOS_TOTAL_GDT_SEGMENTS 6

#define JOSHOS_PROGRAM_VIRTUAL_ADDRESS 0x400000
#define JOSHOS_USER_PROGRAM_STACK_SIZE 1024 * 16 
#define JOSHOS_PROGRAM_VIRTUAL_STACK_ADDRESS_START 0x3FF000
#define JOSHOS_PROGRAM_VIRTUAL_STACK_END  JOSHOS_PROGRAM_VIRTUAL_STACK_ADDRESS_START - JOSHOS_USER_PROGRAM_STACK_SIZE


#define USER_DATA_SEGMENT 0x23
#define USER_CODE_SEGMENT 0x1b

#define JOSHOS_MAX_PROGRAM_ALLOCATIONS 1024
#define JOSHOS_MAX_PROCESSES 12

#define JOSHOS_MAX_ISR80H_COMMANDS 1024

#define JOSHOS_KEYBOARD_BUFFER_SIZE 1024

#endif
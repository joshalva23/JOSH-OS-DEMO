#include "kernel.h"
#include <stdint.h>
#include <stddef.h>
#include "idt/idt.h"
#include "memory/heap/kheap.h"
#include "memory/paging/paging.h"
#include "disk/disk.h"
#include "fs/pparser.h"
#include "string/string.h"
#include "disk/streamer.h"
#include "fs/file.h"

uint16_t* video_mem= 0;

uint16_t terminal_row=0;
uint16_t terminal_col=0;


uint16_t terminal_make_char(char c, char color){
    return (color <<8) | c;
}

void terminal_putchar(int x, int y, char c, char colour){
    video_mem[ (y *VGA_WIDTH ) + x ] = terminal_make_char(c, colour);
}

void terminal_writechar(char c, char colour)
{
    if( c == '\n' )
    {
        terminal_row +=1;
        terminal_col =0;
        return;
    }
    
    terminal_putchar(terminal_col , terminal_row, c , colour);
    terminal_col += 1;

    if( terminal_col >= VGA_WIDTH )
    {
        terminal_col = 0;
        terminal_row +=1 ;
    }

}

void terminal_initialize(){ //clear screen

    video_mem = (uint16_t*)(0xB8000);
    terminal_row = 0;
    terminal_col = 0;

    for(int y =0; y < VGA_HEIGHT; y++){

        for(int x = 0; x < VGA_WIDTH; x++){

            terminal_putchar( x , y , ' ' , 0 );
        }
    }
}



void print(const char* str)
{
    size_t len = strlen(str);
    for (int i=0; i<len; i++)
    {
        terminal_writechar(str[i],15);
    }
}

static struct paging_4gb_chunk* kernel_chunk = 0;

void kernel_main()
{
    
    terminal_initialize();
    print("hello world\ntest");
    
    kheap_init(); //Heap Initialize

    fs_init(); //Initialise file system

    //Search and intitialise the disks
    disk_search_and_init();

    idt_init(); // Initialize interrupt desciptor table

    //set up paging
    kernel_chunk = paging_new_4gb(PAGING_IS_WRITEABLE | PAGING_IS_PRESENT | PAGING_ACCESS_FROM_ALL);

    //switch to kernelpaging_chunk
    paging_switch( paging_4gb_chunk_get_directory(kernel_chunk));


    //enable paging
    enable_paging();

    
    //Enable the system interrupts
    enable_interrupts(); 

    char buf[20];
    strcpy(buf, "hello!");
    while(1){}
}

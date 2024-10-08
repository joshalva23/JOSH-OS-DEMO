#ifndef DISK_H
#define DISK_H


#include "fs/file.h"

typedef unsigned int JOSHOS_DISK_TYPE;

//Represents a real physical harddisk
#define JOSHOS_DISK_TYPE_REAL 0;

struct disk
{
    JOSHOS_DISK_TYPE type;
    int sector_size;

    //the id of the disk
    int id; 

    struct filesystem* filesystem;

    //the private data of out filesystem
    void* fs_private;
};

void disk_search_and_init();
struct disk* disk_get(int index);
int disk_read_block(struct disk* idisk, unsigned int lba, int total, void*buf);


#endif
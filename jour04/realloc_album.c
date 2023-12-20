#include <stdio.h>
#include <stdlib.h>
#include "album.h"
void print_album(t_album *album);

t_album *realloc_album(t_album *album,int size, int new_size){
    t_album *new_album = (t_album *)malloc(sizeof(t_album) * new_size);
    int i;
    for(i = 0; i < size; i++){
        new_album[i] = album[i];
    }
    free(album);
    return new_album;
}

#include <unistd.h>
#include "album.h"
int my_strlen(char *str);
char *my_itoa(int num);



void print_album(t_album *album){
    write(1, album->title, my_strlen(album->title));
    write(1, " by ", 5);
    write(1, album->artist, my_strlen(album->artist));
    write(1, " released in ", 14);
    write(1, my_itoa(album->year), 4);
    write(1, ".", 1);
}

void print_album_list_element(t_album_list *album){
    write(1, album->title, my_strlen(album->title));
    write(1, " by ", 5);
    write(1, album->artist, my_strlen(album->artist));
    write(1, " released in ", 14);
    write(1, my_itoa(album->year), 4);
    write(1, ".", 1);
}

void print_album_list(t_album_list *album_list){
    while(album_list != NULL){
        print_album_list_element(album_list);
        write(1, "\n", 1);
        album_list = album_list->next;
    }  
}
#include <stdio.h>
#include <stdlib.h>
#include "album.h"
t_album_list *create_album(char *title, char *artist, int year);
void print_album_list(t_album_list *album);

void push_back_album(t_album_list *album_list, t_album_list *album){
    while(album_list->next != NULL)
        album_list = album_list->next;
    album_list->next = album;
}

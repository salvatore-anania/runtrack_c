#include "album.h"
#include <stdlib.h>
void print_album_list_element(t_album_list *album);
t_album_list *create_album(char *title, char *artist, int year);
void print_album_list(t_album_list *album_list);

void push_front_album(t_album_list **album_list, t_album_list *album){
    album->next = *album_list;
    *album_list = album;
}
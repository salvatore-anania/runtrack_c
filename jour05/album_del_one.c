#include "album.h"
#include <stdlib.h>
t_album_list *create_album(char *title, char *artist, int year);
void print_album_list(t_album_list *album_list);
void push_back_album(t_album_list *album_list, t_album_list *album);

void album_del_one(t_album_list **album_list, t_album_list *album){
    t_album_list *tmp = *album_list;
    if(tmp == album){
        *album_list = tmp->next;
        free(tmp);
        return;
    }
    while(tmp->next != album)
        tmp = tmp->next;
    tmp->next = album->next;
    free(album);
}
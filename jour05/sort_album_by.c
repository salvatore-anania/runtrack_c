#include "album.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void push_back_album(t_album_list *album_list, t_album_list *album);
t_album_list *create_album(char *title, char *artist, int year);
void print_album_list(t_album_list *album_list);

void sort_album_by(t_album_list **head, int (*cmp_func)(const t_album_list *, const t_album_list *)) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    t_album_list *sorted = NULL;
    t_album_list *current = *head;

    while (current != NULL) {
        t_album_list *next = current->next;

        if (sorted == NULL || cmp_func(current, sorted) <= 0) {
            current->next = sorted;
            sorted = current;
        } else {
            t_album_list *search = sorted;
            while (search->next != NULL && cmp_func(current, search->next) > 0) {
                search = search->next;
            }
            current->next = search->next;
            search->next = current;
        }
        current = next;
    }

    *head = sorted;
}

void free_album_list(t_album_list *head) {
    while (head != NULL) {
        t_album_list *temp = head;
        head = head->next;
        free(temp->title);
        free(temp->artist);
        free(temp);
    }
}
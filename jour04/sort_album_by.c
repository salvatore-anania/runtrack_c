#include "album.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void push_back_album(t_album_list *album_list, t_album_list *album);
void album_del_one(t_album_list **album_list, t_album_list *album);
t_album_list *create_album(char *title, char *artist, int year);
void print_album_list(t_album_list *album_list);

int compare_by_title(const t_album_list *a, const t_album_list *b) {
    return strcmp(a->title, b->title);
}

int compare_by_year(const t_album_list *a, const t_album_list *b) {
    return a->year - b->year;
}

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

int main() {
    
    t_album_list *head = create_album("The Dark Side of the Moon", "Pink Floyd", 1973);
    push_back_album(head, create_album("The Wall", "Pink Floyd", 1979));
    push_back_album(head, create_album("Wish You Were Here", "Pink Floyd", 1975));
    push_back_album(head, create_album("Animals", "Pink Floyd", 1977));
    push_back_album(head, create_album("The Piper at the Gates of Dawn", "Pink Floyd", 1967));

    sort_album_by(&head, compare_by_title);

    printf("Albums triés par titre :\n");
    print_album_list(head);

    sort_album_by(&head, compare_by_year);

    printf("\nAlbums triés par année :\n");
    print_album_list(head);

    free_album_list(head);

    return 0;
}
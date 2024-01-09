#include "album.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
void push_back_album(t_album_list *album_list, t_album_list *album);
t_album_list *create_album(char *title, char *artist, int year);
void print_album_list(t_album_list *album_list);
void sort_album_by(t_album_list **head, int (*cmp_func)(const t_album_list *, const t_album_list *));
void free_album_list(t_album_list *head);
int my_atoi(char *str);
int my_strcmp(char const *s1, char const *s2);

int compare_by_title(const t_album_list *a, const t_album_list *b)
{
    return my_strcmp(a->title, b->title);
}

int compare_by_artist(const t_album_list *a, const t_album_list *b)
{
    return my_strcmp(a->artist, b->artist);
}

int compare_by_year(const t_album_list *a, const t_album_list *b)
{
    return a->year - b->year;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        write(1, "Usage: <filename> <artist|title|year>\n", 38);
        write(1, "Incorrect number of arguments.\n", 31);
        return 1;
    }

    const char *filename = argv[1];
    const char *sort_order = argv[2];

    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        write(1, "File not found\n", 15);
        return 1;
    }

    t_album_list *head = NULL;
    char buffer[1024];
    ssize_t bytes_read;

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
    {
        char *start = buffer;
        char *end = buffer + bytes_read;
        char *token_start = buffer;

        while (token_start < end)
        {
            if (*start == '\n')
            {
                *start = '\0';

                char *artist = token_start;
                char *title = token_start;
                while (*title != ',' && title < start)
                {
                    title++;
                }
                if (title >= start)
                {
                    write(STDERR_FILENO, "Incorrect format.\n", 18);
                    free_album_list(head);
                    close(fd);
                    return 1;
                }
                *title = '\0';
                title++;

                char *year_str = title;
                while (*year_str != ',' && year_str < start)
                {
                    year_str++;
                }
                if (year_str >= start)
                {
                    write(STDERR_FILENO, "Incorrect format.\n", 18);
                    free_album_list(head);
                    close(fd);
                    return 1;
                }
                *year_str = '\0';
                year_str++;

                int year = my_atoi(year_str);

                t_album_list *new_album = create_album(title, artist, year);

                if (head == NULL)
                {
                    head = new_album;
                }
                else if (new_album != NULL)
                {
                    push_back_album(head, new_album);
                }

                token_start = start + 1;
            }
            start++;
        }

        if (bytes_read == -1)
        {
            write(STDERR_FILENO, "Error reading file.\n", 20);
            free_album_list(head);
            close(fd);
            return 1;
        }
    }
    close(fd);
    // Sorting and printing the list
    if (my_strcmp(sort_order, "artist") == 0)
    {
        sort_album_by(&head, compare_by_artist);
    }
    else if (my_strcmp(sort_order, "title") == 0)
    {
        sort_album_by(&head, compare_by_title);
    }
    else if (my_strcmp(sort_order, "year") == 0)
    {
        sort_album_by(&head, compare_by_year);
    }
    else
    {
        write(1, "Sort method does not exist.\n", 27);
        free_album_list(head);
        return 1;
    }

    print_album_list(head);

    free_album_list(head);

    return 0;
}
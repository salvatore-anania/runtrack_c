typedef struct album{
    char *title;
    char *artist;
    int year;
} t_album;

typedef struct album_list{
    char *title;
    char *artist;
    int year;
    struct album_list *next;
} t_album_list;
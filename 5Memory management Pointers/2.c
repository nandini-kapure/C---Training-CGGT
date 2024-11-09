#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Playlist {
    char title[200];
    char artist[200];
    int freq;
};

 
void add_song(struct Playlist* playlist, int* size, int maxSize);
void play_song(struct Playlist* playlist, int size, const char* songTitle);
void remove_song(struct Playlist* playlist, int* size, const char* songTitle);
void modify_song(struct Playlist* playlist, int size, const char* songTitle);
void search_song(struct Playlist* playlist, int size, const char* songTitle);
void list_songs(struct Playlist* playlist, int size);
void sortplaylist(struct Playlist* playlist, int size);
int main() {
    int max_size;
    char choice;
    int current_size = 0;
    printf("Enter the maximum number of songs in the playlist: ");
    scanf("%d", &max_size);
    struct Playlist* playlist = (struct Playlist*)malloc(max_size * sizeof(struct Playlist));
    while (1) {
        printf("\nOptions:\n");
        printf("a - Add song\n");
        printf("p - Play song\n");
        printf("r - Remove song\n");
        printf("m - Modify song\n");
        printf("s - Search song\n");
        printf("l - List songs\n");
        printf("e - Exit\n");
        printf("Choose an option: ");
        scanf(" %c", &choice);
        char title[200];
        switch (choice) {
            case 'a':
                add_song(playlist, &current_size, max_size);
                break;
            case 'p':
                printf("Enter the title of the song to play: ");
                scanf(" %[^\n]s", title);
                play_song(playlist, current_size, title);
                break;
            case 'r':
                printf("Enter the title of the song to remove: ");
                scanf(" %[^\n]s", title);
                remove_song(playlist, &current_size, title);
                break;
            case 'm':
                printf("Enter the title of the song to modify: ");
                scanf(" %[^\n]s", title);
                modify_song(playlist, current_size, title);
                break;
            case 's':
                printf("Enter the title of the song to search: ");
                scanf(" %[^\n]s", title);
                search_song(playlist, current_size, title);
                break;
            case 'l':
                list_songs(playlist, current_size);
                break;
            case 'e':
                free(playlist);
                return 0;
            default:
                printf("Invalid option. Try again.\n");
        }
    }
}
void add_song(struct Playlist* playlist, int* size, int max_size) {
    if (*size >= max_size) {
        printf("Memory is full.\n");
        return;
    }
    printf("Enter the title of the song: ");
    scanf(" %[^\n]s", playlist[*size].title);
    printf("Enter the artist of the song: ");
    scanf(" %[^\n]s", playlist[*size].artist);
    playlist[*size].freq = 0;
    (*size)++;
    printf("Song added successfully.\n");
    sortplaylist(playlist, *size);
}
void play_song(struct Playlist* playlist, int size, const char* song_title) {
    for (int i = 0; i < size; i++) {
        if (strcmp(playlist[i].title, song_title) == 0) {
            playlist[i].freq++;
            printf("Playing %s by %s\n", playlist[i].title, playlist[i].artist);
            sortplaylist(playlist, size);
            return;
        }
    }
    printf("Song not found.\n");
}
void remove_song(struct Playlist* playlist, int* size, const char* song_title) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(playlist[i].title, song_title) == 0) {
            for (int j = i; j < *size - 1; j++) {
                playlist[j] = playlist[j + 1];
            }
            (*size)--;
            printf("Song removed successfully.\n");
            return;
        }
    }
    printf("Song not found.\n");
}
void modify_song(struct Playlist* playlist, int size, const char* song_title) {
    for (int i = 0; i < size; i++) {
        if (strcmp(playlist[i].title, song_title) == 0) {
            printf("Enter the new title: ");
            scanf(" %[^\n]s", playlist[i].title);
            printf("Enter the new artist: ");
            scanf(" %[^\n]s", playlist[i].artist);
            printf("Song modified successfully.\n");
            return;
        }
    }
    printf("Song not found.\n");
}
void search_song(struct Playlist* playlist, int size, const char* song_title) {
    for (int i = 0; i < size; i++) {
        if (strcmp(playlist[i].title, song_title) == 0) {
            printf("Song found: %s by %s (Played %d times)\n", playlist[i].title, playlist[i].artist, playlist[i].freq);
            return;
        }
    }
    printf("Song not found.\n");
}
void list_songs(struct Playlist* playlist, int size) {
    printf("Playlist:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s by %s (Played %d times)\n", i + 1, playlist[i].title, playlist[i].artist, playlist[i].freq);
    }
}
void sortplaylist(struct Playlist* playlist, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (playlist[j].freq < playlist[j + 1].freq) {
                struct Playlist temp = playlist[j];
                playlist[j] = playlist[j + 1];
                playlist[j + 1] = temp;
            }
        }
    }
}
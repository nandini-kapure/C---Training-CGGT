#include <stdio.h>
#include <stdlib.h>
 
#define MAX_VIDEOS 100
 
int resolutions[MAX_VIDEOS];
int durations[MAX_VIDEOS];
int count;
 
void get_video_details() {
    printf("Enter the number of videos: ");
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        printf("\nVideo %d:\n", i + 1);
        printf("Enter resolution (e.g., 1080 for 1080p): ");
        scanf("%d", &resolutions[i]);
        printf("Enter duration in seconds: ");
        scanf("%d", &durations[i]);
    }
}
 
int compare_videos(const void *a, const void *b) {
    int idx1 = *(const int *)a;
    int idx2 = *(const int *)b;
 
    if (resolutions[idx1] != resolutions[idx2]) {
        return resolutions[idx2] - resolutions[idx1];
    }
    return durations[idx1] - durations[idx2]; 
}
 
void display_sorted_videos(int sorted_indices[]) {
    printf("\nSorted Video Files (by resolution and then duration):\n");
    for (int i = 0; i < count; i++) {
        int idx = sorted_indices[i];
        printf("Resolution: %dp, Duration: %d seconds\n", resolutions[idx], durations[idx]);
    }
}
 
int main() {
    int indices[MAX_VIDEOS];
    get_video_details();
 
    for (int i = 0; i < count; i++) {
        indices[i] = i;
    }
 
    qsort(indices, count, sizeof(int), compare_videos);
    display_sorted_videos(indices);
 
    return 0;
}
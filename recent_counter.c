#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

typedef struct {
    int* pingHistory;
    int head;
    int tail;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter* obj = malloc(sizeof(RecentCounter));
    obj->pingHistory = calloc(MAX_SIZE, sizeof(int));
    obj->head = 0;
    obj->tail = 0;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    obj->pingHistory[obj->head++] = t;
    
    while (obj->pingHistory[obj->tail] < t - 3000) {
        obj->tail++;
    }
    
    return obj->head - obj->tail;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj->pingHistory);
    free(obj);
}

int main() {
    RecentCounter* counter = recentCounterCreate();
    int n, t;
    
    printf("Enter number of pings: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter ping time: ");
        scanf("%d", &t);
        printf("%d\n", recentCounterPing(counter, t));
    }
    
    recentCounterFree(counter);
    return 0;
}

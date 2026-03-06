#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int  time;
    int  cross;
    char name;
} People;

int comparar(const void *a, const void *b) {
    const People *pa = (const People *)a;
    const People *pb = (const People *)b;
    if (pa->time < pb->time) return -1;
    if (pa->time > pb->time) return  1;
    return 0;
}

int min(int a, int b, int c) {
    int m = a < b ? a : b;
    return m < c ? m : c;
}

int roadBridge(People *left, int length) {
    int time = 0;

    qsort(left, length, sizeof(left[0]), comparar);

    // shift de 4 elementos
    People fatest        = left[0];
    People secondFatest  = left[1];
    People secondLowest  = left[2];
    People lowest        = left[3];

    int fatestStrategie  = fatest.time * 2 + secondFatest.time + lowest.time + secondLowest.time;
    int lowestStrategie  = secondLowest.time * 2 + lowest.time + fatest.time + secondFatest.time;
    int medianStrategie  = fatest.time + secondFatest.time * 3 + lowest.time;

    time += min(fatestStrategie, lowestStrategie, medianStrategie);

    return time;
}

int main(void) {
    People peoples[] = {
        { .time = 5,  .cross = 0, .name = 'A' },
        { .time = 10, .cross = 0, .name = 'B' },
        { .time = 1,  .cross = 0, .name = 'C' },
        { .time = 2,  .cross = 0, .name = 'D' },
    };

    int length = sizeof(peoples) / sizeof(peoples[0]);
    int result = roadBridge(peoples, length);

    printf("%d\n", result);

    return 0;
}

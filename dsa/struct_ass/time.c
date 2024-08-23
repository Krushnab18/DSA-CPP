#include <stdio.h>

typedef struct time {
    int hr;
    int min;
    int sec;
} time;

void increment_time(time *t) {
    t->sec++;

    if (t->sec == 60) {
        t->sec = 0;
        t->min++;
    }

    if (t->min == 60) {
        t->min = 0;
        t->hr++;
    }
    
    return;
}
    
// Function to compare two times
int is_time_equal(time t1, time t2) {
    return t1.hr == t2.hr && t1.min == t2.min && t1.sec == t2.sec;
}

int main() {
    time start_time, end_time;

    printf("Enter start time (hr min sec): ");
    scanf("%d %d %d", &start_time.hr, &start_time.min, &start_time.sec);

    printf("Enter end time (hr min sec): ");
    scanf("%d %d %d", &end_time.hr, &end_time.min, &end_time.sec);

    while (!is_time_equal(start_time, end_time)) {
        printf("GOOD DAY\n");
        increment_time(&start_time);
    }

    return 0;
}


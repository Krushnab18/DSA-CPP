#include <stdio.h>

typedef struct hotel{
    char name[30];
    char address[100];
    char grade;
    int num_rooms;
    int room_charges;
}hotel;

void print_hotel_with_grade(hotel hotels[], char grade) {
    for(int i = 0; i < 10; i++) {
        if(hotels[i].grade == grade) {
            printf("%s\n", hotels[i].name);
        }
    }
    return;
}

void hotels_with_less_charges(hotel hotels[], int charges) {
    for(int i = 0; i < 10; i++) {
        if(hotels[i].room_charges < charges) {
            printf("%s\n", hotels[i].name);
        }
    }
    return;
}

int main() {

    /* sample of 10 hotels */
    int charges;
    hotel hotels[10] = {
        {"Grand Plaza", "123 Main St, Cityville", 'A', 100, 1500},
        {"Ocean View", "456 Beach Rd, Seaside", 'B', 80, 1200},
        {"Mountain Retreat", "789 Hilltop Dr, Highland", 'A', 60, 180},
        {"Urban Inn", "101 Downtown Ave, Metropolis", 'C', 120, 100},
        {"Country Lodge", "202 Country Ln, Farmington", 'B', 40, 90},
        {"Royal Suites", "303 Luxury Blvd, Elegance", 'A', 50, 200},
        {"Sunset Hotel", "404 Sunset Blvd, Bayside", 'B', 70, 1100},
        {"Historic Hotel", "505 Heritage St, Oldtown", 'C', 90, 130},
        {"Vista Hotel", "606 Viewpoint Dr, Skyline", 'B', 85, 140},
        {"Comfort Inn", "707 Cozy Ct, Suburbia", 'C', 110, 95}
    };

    char grade;
    printf("Enter grade to get hotel names: \n");
    grade = getchar();
    print_hotel_with_grade(hotels, grade);
    printf("Enter room charges: \n");
    scanf("%d", &charges);
    printf("Following hotels have room charges less than %d\n", charges);
    hotels_with_less_charges(hotels, charges);
    return 0;
}

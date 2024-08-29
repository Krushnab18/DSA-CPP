#include <stdio.h>

int main() {
    char str1[30] = "a";
    char str2[15] = "a";
    int i = 0;
    int len = 3;
    int found = 0;
    while(str1[i] != '\0') {
        int j = 0, k = i;
        while(str2[j] == str1[k] && str2[j] != '\0' && str1[k] != '\0') {
            if(str2[j+1] != '\0' && str1[k + 1] == '\0') {
                printf("-1");
                return 0;
            }
            j++;
            k++;
        }
        if(j == (len)) {
            found = 1;
            printf("%d\n", i);
            return 0;
        }

        i++;
    }
    if(found == 0) {
        printf("-1");
    }
    return 0;
}

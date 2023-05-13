#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int birth_year;
    char gender[20];
    int height;
} User;

int compare_by_name(const void *a, const void *b) {
    return strcmp(((User *)a)->name, ((User *)b)->name);
}

int compare_by_birth_year(const void *a, const void *b) {
    return ((User *)a)->birth_year - ((User *)b)->birth_year;
}

int compare_by_gender(const void *a, const void *b) {
    return strcmp(((User *)a)->gender, ((User *)b)->gender);
}

int compare_by_height(const void *a, const void *b) {
    return ((User *)a)->height - ((User *)b)->height;
}

int main() {
    FILE *fp;
    char line[100];
    User users[100];
    int num_users = 0;
    int sort_field = 1;
	int i;
    fp = fopen("people.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%s %d %s %d", users[num_users].name, &users[num_users].birth_year, &users[num_users].gender, &users[num_users].height);
		num_users++;
    }

    fclose(fp);
    while (sort_field != 0){
	
    printf("Enter sort field (1 for name, 2 for birth year, 3 for gender, 4 for height, 0 to stop): ");
    scanf("%d", &sort_field);

    switch (sort_field) {
        case 1:
            qsort(users, num_users, sizeof(User), compare_by_name);
            break;
        case 2:
            qsort(users, num_users, sizeof(User), compare_by_birth_year);
            break;
        case 3:
            qsort(users, num_users, sizeof(User), compare_by_gender);
            break;
        case 4:
            qsort(users, num_users, sizeof(User), compare_by_height);
            break;
        case 0:
            break;            
        default:
            printf("Invalid sort field\n");
            return 1;
    }
	}
    for (i = 0; i < num_users; i++) {
        printf("\nName: %s\nBirth year: %d\nGender: %s\nHeight: %d\n", users[i].name, users[i].birth_year, users[i].gender, users[i].height);
    }

    return 0;
}

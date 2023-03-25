#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char name[50];
    int year;
    char gender[10];
    float height;
} Person;


int compare(const void *a, const void *b)
	{
    Person *p1 = (Person *) a;
    Person *p2 = (Person *) b;

    int result = 0;

    char order_fields[4];
    printf("Insert your sorting needings: ");
    scanf("%c, %c, %c, %c", order_fields[0], order_fields[1], order_fields[2], order_fields[3]);
	int i = 0;
    for (i = 0; i < 4; i++)
		{
        if (strcmp(order_fields[i], "y") == 0)
			{
            result = p1->year - p2->year;
        	}
			else if (strcmp(order_fields[i], "n") == 0)
				{
            	result = strcmp(p1->name, p2->name);
        		}
				else if (strcmp(order_fields[i], "g") == 0)
					{
            			result = strcmp(p1->gender, p2->gender);
        			}
					else if (strcmp(order_fields[i], "h") == 0)
						{
            			if (p1->height > p2->height)
							{
                			result = 1;
            				}
							else if (p1->height < p2->height)
								{
                				result = -1;
            					}
        				}

        if (result != 0)
			{
            return result;
        	}
    	}
    }

int main()
{
    FILE *f = fopen("people.txt", "r");

    Person people[100];

    int i = 0;
    while (fscanf(f, "%[^,], %d, %[^,], %f\n", people[i].name, &people[i].year, people[i].gender, &people[i].height) != EOF)
		{
        i++;
    	}
    fclose(f);

    qsort(people, 100, sizeof(Person), compare);

    printf("Your result, check it:\n");
    for (i = 0; i < 100; i++)
	{
        printf("%s, %d, %s, %.2f\n", people[i].name, people[i].year, people[i].gender, people[i].height);
    }

    return 0;
}

#include <stdio.h>

struct student
{
    int regno;
    char name[20];
};

int main()
{
    FILE *fp;
    struct student s;

    fp = fopen("student.dat", "w");

    if (fp == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    printf("Enter Register Number: ");
    scanf("%d", &s.regno);

    printf("Enter Name: ");
    scanf("%s", s.name);

    fprintf(fp, "%d %s\n", s.regno, s.name);
    fclose(fp);

    fp = fopen("student.dat", "r");

    if (fp == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    fscanf(fp, "%d %s", &s.regno, s.name);

    printf("\nRecord Details\n");
    printf("Register Number : %d\n", s.regno);
    printf("Name : %s\n", s.name);

    fclose(fp);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

//struct def
 struct productinfo{
    char name[50];
    int year_product;
    double price;
    double weight;
    char description[50];
    };

//function declaration
void changeinfo(struct productinfo *p);

int main()
{
    struct productinfo currentproduct;
    printf("----------Edit productinfo----------\n");
    changeinfo(&currentproduct); //& is required to convert 'productinfo' to 'productinfo*'. in other words, it can't assigned 'productinfo' into a pointer (which stores an address, not a value)
    printf("New update-- Name:%s, Year of production:%d, price:%.1lf, weight:%.1lf \n, description:%s \n", currentproduct.name, currentproduct.year_product, currentproduct.price, currentproduct.weight, currentproduct.description);

    return 0;
}

//function def
void changeinfo(struct productinfo *p)
{
    while(1)
    {
        printf("Enter your choice of edit \n1)name \n2)year of production \n3)price \n4)weight \n5)description\nEnter: ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter the name without spaces in between: ");
                scanf("%50s", &((*p).name)); //scanf: left to right  input according to 50s; then, put into &currentproduct.country
                break;
            case 2:
                printf("Enter the year of production without spaces in between: ");
                scanf("%d", &((*p).year_product)); //() to enclose '*p'. Or it will have "error: 'p' is a pointer; did you mean to use '->'?|" as an error
                break;
            case 3:
                printf("Enter the price without spaces in between: ");
                scanf("%lf", &((*p).price));
                break;
            case 4:
                printf("Enter the weight without spaces in between: ");
                scanf("%lf", &((*p).weight));
                break;
            case 5:
                printf("Enter the description without spaces in between: ");
                scanf("%50s", &((*p).description));
                break;
        }

        printf("if exit and save, enter 'q' (Warning: enter lower-case letter): \n");
        char quit;
        scanf("%c", &quit); //If I don't pass it as an address, 1) it can't alter the variable & 2) Norton will render this program "suspicious" and block it
        if ('q'==quit)
        {
            break;
        }
    }
}


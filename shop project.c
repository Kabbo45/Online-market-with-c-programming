#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include "registration.h"
#include "signin.h"
#include "shop.h"
#include "clothing.h"
#include "electronics.h"
#include "healthcare.h"
#include "furnitures.h"
#include "consumer_foods.h"
#include "stationaries.h"
#include "digital_services.h"

//////////////////////////////////////////////////////////////////////////////////////////

void admin()
{
    char name[100],pass[100];
    printf("\n\n\t\t\t\t===================\n");
    printf("\t\t\t\t||  Admin Panel  ||\n");
    printf("\t\t\t\t===================\n");
    printf("\n\t\t\t\tUser Name : ");
    scanf("%s",&name);
    printf("\n\t\t\t\tUser Password : ");
    scanf("%d",&pass);
}

//////////////////////////////////////////////////////////////////////////////////////////

void invoice()
{
    struct date
    {
        int day;
        int month;
        int year;
    };
    struct details
    {
        char name[20];
        int price;
        int code;
        int qty;
        struct date mfg;
    };
    struct details item[50];
    int n, i;
    printf("Enter number of items:");
    scanf("%d", &n);
    fflush(stdin);
    for (i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("Item name: \n");
        scanf("%s", item[i].name);
        fflush(stdin);
        printf("Item code: \n");
        scanf("%d", &item[i].code);
        fflush(stdin);
        printf("Quantity: \n");
        scanf("%d", &item[i].qty);
        fflush(stdin);
        printf("price: \n");
        scanf("%d", &item[i].price);
        fflush(stdin);
        printf("Manufacturing date(dd-mm-yyyy): \n");
        scanf("%d-%d-%d", &item[i].mfg.day,
              &item[i].mfg.month, &item[i].mfg.year);
    }
    printf("*************************  INVENTORY *****************************\n");
    printf("------------------------------------------------------------------\n");
    printf("S.N.|    NAME          |   CODE   |  QUANTITY |  PRICE | MFG.DATE \n");
    printf("------------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
        printf("%d     %-15s        %-d          %-5d     %-5d  %d/%d/%d \n", i + 1, item[i].name, item[i].code, item[i].qty,item[i].price, item[i].mfg.day, item[i].mfg.month,item[i].mfg.year);
    printf("------------------------------------------------------------------\n");
}

///////////////////////////////////////////////////////////////////////////////

int main()
{
    int num,i;
    printf("\t\t\t\t  _______________________\n");
    printf("\t\t\t\t  =======================\n");
    printf("\t\t\t\t /|||||||||||||||||||||||\\\n");
    printf("\t\t\t\t  |_____________________|\n");
    printf("\t\t\t\t  |                     |\n");
    printf("\t\t\t\t  |                     |\n");
    printf("\t\t\t\t  |  ONLINE MULTI-SHOP  |\n");
    printf("\t\t\t\t  |                     |\n");
    printf("\t\t\t\t  |_____________________|\n");
    printf("\t\t\t\t /_______________________\\\n");
    printf("\t\t\t\t|_________________________|");
    printf("\n\n\t\t\t\t1. Registration\n");
    printf("\t\t\t\t2. Sign In\n");
    printf("\t\t\t\t3. Shop\n");
    printf("\t\t\t\t4. Admin Panel Log-in  \n");
    printf("\n\n\t\t\t\tEnter your choice : ");
    scanf("%d",&num);
    switch(num)
    {
    case 1:
        registration();
        break;

    case 2:
        signin();
        break;

    case 3:
        shop();
        break;

    case 4:
        admin();
        break;

    default:
        printf("Error!");
    }
    getch();
}

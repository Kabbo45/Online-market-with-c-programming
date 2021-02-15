#include<stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"
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
    system("cls");
    char name[100],pass[100];
    printf("\n\n\t\t\t\t===================\n");
    printf("\t\t\t\t||  Admin Panel  ||\n");
    printf("\t\t\t\t===================\n");
    printf("\n\t\t\t\tUser Name : ");
    scanf("%s",&name);
    printf("\n\t\t\t\tUser Password : ");
    scanf("%d",&pass);
}
///////////////////////////////////////////////////////////////////////////////////////////
void loadingBar()
{
    system("cls");
    char a = 177, b = 219;
    printf("\n\n\n\n");
    printf("\n\n\n\n\t\t\t\t\t");
    printf(ANSI_COLOR_RED"Loading...\n\n"ANSI_COLOR_RESET);
    printf("\t\t\t\t\t");
    for (int i = 0; i < 26; i++)
        printf("%c", a);
    printf("\r");
    printf("\t\t\t\t\t");
    for (int i = 0; i < 26; i++) {
        printf(ANSI_COLOR_RED);
        printf("%c", b);
        printf(ANSI_COLOR_RESET);
        Sleep(20);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////

void invoice(char a[], int b, int z)
{
    system("cls");
    int n = 1, i;
    printf("\n\n\t\t\t\t\t*********************  INVENTORY *********************\n");
    printf("\t\t\t\t\t------------------------------------------------------\n");
    printf("\t\t\t\t\t  S.N.  |    NAME          |    QUANTITY   |   PRICE \n");
    printf("\t\t\t\t\t------------------------------------------------------\n");
    for (i = 0; i < n; i++)
    printf("\t\t\t\t\t   %d    -   %s          -       %d      -    %d\n", i+1, a, z, b);

        FILE *invoice;
        invoice = fopen("invoice.txt", "w");
        fprintf(invoice, "\n\n\t\t\t\t*********************** INVOICE **********************\n");
        fprintf(invoice, "\t\t\t\t---------------------------------------------------------\n");
        fprintf(invoice, "\t\t\t\t|  S.N.  |    NAME          |    QUANTITY   |   PRICE   |\n");
        fprintf(invoice, "\t\t\t\t---------------------------------------------------------\n");
        fprintf(invoice, "\t\t\t\t|  %d    -   %s          -       %d      -     %d  |\n", i+1, a, z, b);
        fclose(invoice);

    printf("\n\n\t\t\t\t\t Press Any Key To Pay The Amount...");
    getch();
    payment(b);
}
///////////////////////////////////////////////////////////////////////////////

void payment(int c)
{
    system("cls");
    int p, n;
    char a[] = "Bkash";
    char b[] = "Rocket";
    char l[] = "Nagad";
    char d[] = "Credit/Debit";
    char e[] = "Cash On Delivery";
    printf("\n\n\n\t\t\t\t\t ===========\n");
    printf("\t\t\t\t\t | Payment |");
    printf("\n\t\t\t\t\t ===========\n\n");
    printf("\n\t\t\t\t Choose a payment method:\n");
    printf("\n\t\t\t\t 1. %s\n", a);
    printf("\n\t\t\t\t 2. %s\n", b);
    printf("\n\t\t\t\t 3. %s\n", l);
    printf("\n\t\t\t\t 4. %s\n", d);
    printf("\n\t\t\t\t 5. %s\n", e);
    printf("\n\t\t\t\t 6. <= Back to the shop\n");
    printf("\n\n\t\t\t\t__________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d", &n);
    switch(n)
    {
    case 1:
        bkash();
        break;

    case 2:
        rocket();
        break;

    case 3:
        nagad();
        break;

    case 4:
        card();
        break;

    case 5:
        cod(c);
        break;

    case 6:
        shop();
        break;

    default:
        printf("Error!");

    }
}

bkash()
{
    system("cls");
    int m, o, p;
    printf("\n\n\n\t\t\t\t\t =========\n");
    printf("\t\t\t\t\t | Bkash |");
    printf("\n\t\t\t\t\t =========\n\n");
    printf("\n\t\t\t\tEnter your bkash number\n");
    printf("\t\t\t\t------------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%d", &m);
    printf("\n\t\t\t\tEnter the OTP\n");
    printf("\t\t\t\t------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &o);
    printf("\n\t\t\t\tEnter your password\n");
    printf("\t\t\t\t-----------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &p);

    file();

    printf("\n\n\t\t\t\t\tYou have paid your amount with Bkash.\n");

    thanks();
}

rocket()
{

}
nagad()
{

}
card()
{

}
cod()
{

}

file()
{
    system("cls");
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    fp = fopen("invoice.txt", "r");
    while ((read = getline(&line, &len, fp)) != -1) {
        printf("\n%s", line);
    }
    fclose(fp);
}
///////////////////////////////////////////////////////////////////////////////
void thanks()
{

    {
    printf(ANSI_COLOR_RED "\n\n\n\n\t\t\t\t\t\t  =============\n");
    printf(ANSI_COLOR_RED "\t\t\t\t\t\t  | Thank You |\n");
    printf(ANSI_COLOR_RED "\t\t\t\t\t\t  =============\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN"\n\n\t\t\t\t\t  Press any key to continue shopping.....\n" ANSI_COLOR_RESET);
    }
    getch();
    shop();
}
///////////////////////////////////////////////////////////////////////////////
int main()
{
    system("cls");
    int num,i;
    printf(ANSI_COLOR_RED"\n\n\t\t\t\t  _______________________\n");
    printf(ANSI_COLOR_YELLOW"\t\t\t\t  =======================\n");
    printf(ANSI_COLOR_MAGENTA"\t\t\t\t /|||||||||||||||||||||||\\\n");
    printf(ANSI_COLOR_GREEN"\t\t\t\t  |_____________________|\n");
    printf(ANSI_COLOR_RED"\t\t\t\t  |                     |\n");
    printf(ANSI_COLOR_YELLOW"\t\t\t\t  |                     |\n"ANSI_COLOR_RESET);
    printf("\t\t\t\t  |  ONLINE MULTI-SHOP  |\n");
    printf(ANSI_COLOR_GREEN"\t\t\t\t  |                     |\n");
    printf(ANSI_COLOR_MAGENTA"\t\t\t\t  |_____________________|\n");
    printf(ANSI_COLOR_RED"\t\t\t\t /_______________________\\\n");
    printf(ANSI_COLOR_YELLOW"\t\t\t\t|_________________________|"ANSI_COLOR_RESET);
    printf("\n\n\t\t\t\t1. Registration\n");
    printf("\t\t\t\t2. Sign In\n");
    printf("\t\t\t\t3. Shop\n");
    printf("\t\t\t\t4. Admin Panel Log-in  \n");
    printf("\n\n\t\t\t\tEnter your choice : ");
    scanf("%d",&num);
    switch(num)
    {
    case 1:
        loadingBar();
        registration();
        break;

    case 2:
        loadingBar();
        signin();
        break;

    case 3:
        loadingBar();
        shop();
        break;

    case 4:
        loadingBar();
        admin();
        break;

    default:
        printf("Error!");
    }
    getch();
}

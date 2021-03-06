#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE   "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"


void gotoxy(short x, short y)
{
    COORD pos = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}



////////////////////////////////////////////////// Structure ///////////////////////////////////////////////////////////
struct shop
{
    int code;
    int price;
    char name[1000];
};

struct item
{
    char productname[40], c;
    int productid;
    int price;
} st;
////////////////////////////////////////////////// Loading Bar /////////////////////////////////////////////////////////

loadingBar()
{
    system("cls");
    char a = 177, b = 219;
    printf("\n\n\n\n");
    printf("\n\n\n\n\t\t\t\t\t");
    printf("Loading...\n\n");
    printf("\t\t\t\t\t");
    for (int i = 0; i < 26; i++)
        printf("%c", a);
    printf("\r");
    printf("\t\t\t\t\t");
    for (int i = 0; i < 26; i++)
    {
        printf(ANSI_COLOR_RED);
        printf(ANSI_COLOR_YELLOW"%c", b);
        Sleep(20);
    }
}

////////////////////////////////////////////////// Registration /////////////////////////////////////////////////////////

registration()
{
    system("cls");
    char name[200], email[100], usrname[100], address[200];
    char pass[100], pass2[100];
    int mobile;
    FILE *fptr;
    fptr = fopen("regestration.txt","w");
    printf(ANSI_COLOR_YELLOW"\n\n\t\t\t\t\t====================\n");
    printf("\t\t\t\t\t||  Registration  ||\n");
    printf("\t\t\t\t\t====================\n\n"ANSI_COLOR_RESET);
    fflush(stdin);
    printf("\t\t\t\tEnter your full name\n");
    printf("\t\t\t\t--------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%[^\n]s", name);
    printf("\n\t\t\t\tEnter your mobile number\n");
    printf("\t\t\t\t------------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%d", &mobile);
    fflush(stdin);
    printf("\n\t\t\t\tEnter your address\n");
    printf("\t\t\t\t------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%[^\n]s", address);
    printf("\n\t\t\t\tEnter your e-mail\n");
    printf("\t\t\t\t-----------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &email);
    printf("\n\t\t\t\tChoose your username\n");
    printf("\t\t\t\t--------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &usrname);
    fflush(stdin);
    printf("\n\t\t\t\tChoose your password\n");
    printf("\t\t\t\t--------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%[^\n]s", &pass);
    fflush(stdin);
    printf("\n\t\t\t\tConfirm your password\n");
    printf("\t\t\t\t---------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%[^\n]s", &pass2);
    int result = strcmp(pass, pass2);
    if(result == 0)
    {
        fprintf(fptr,"Registration Details \n-------------------- \nFull Name: %s \nMobile Number: +880%d \nDistrict Name: %s \nE-mail: %s \nUsername: %s \nPassword: %s \n", name, mobile, address, email, usrname, pass);
        fclose(fptr);
        FILE *username;
        username = fopen("username.txt", "w");
        fprintf(username, "%s", usrname);
        fclose(username);
        FILE *passx;
        passx = fopen("password.txt", "w");
        fprintf(passx, "%s", pass);
        fclose(passx);
        signin();
    }

    else
    {
        do
        {
            printf(ANSI_COLOR_RED"\a\n\t\t\t\tOOPS! You're password didn't match\n"ANSI_COLOR_RESET);
            printf("\n\t\t\t\tChoose your password again\n");
            printf("\t\t\t\t--------------------------\n");
            printf("\t\t\t\t=> ");
            scanf("%s", &pass);
            printf("\n\t\t\t\tConfirm your password\n");
            printf("\t\t\t\t---------------------\n");
            printf("\t\t\t\t=> ");
            scanf("%s", &pass2);
        }
        while (result == 0);
        fprintf(fptr,"Registration Details \n-------------------- \nFull Name: %s %s %s \nMobile Number: +880%d \nDistrict Name: %s \nE-mail: %s \nUsername: %s \nPassword: %s \n", name, mobile, address, email, usrname, pass);
        fclose(fptr);
        FILE *username;
        username = fopen("username.txt", "w");
        fprintf(username, "%s", usrname);
        fclose(username);
        FILE *passx;
        passx = fopen("password.txt", "w");
        fprintf(passx, "%s", pass);
        fclose(passx);
        signin();
    }
}

///////////////////////////////////////////////// Sign In /////////////////////////////////////////////////////////////

signin()
{
    system("cls");
    char user[100], password[100], usr[100], passc[100];
    int n, i;
    printf(ANSI_COLOR_YELLOW"\n\n\t\t\t\t\t===============\n");
    printf("\t\t\t\t\t||  Sign In  ||\n");
    printf("\t\t\t\t\t===============\n" ANSI_COLOR_RESET);
    printf("\n\t\t\t\tEnter your username\n");
    printf("\t\t\t\t-------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &user);
    printf("\n\t\t\t\tEnter your password\n");
    printf("\t\t\t\t-------------------\n");
    printf("\t\t\t\t=> ");
    FILE *username;
    username = fopen("username.txt", "r");
    fscanf(username, "%s", &usr);
    FILE *passx;
    passx = fopen("password.txt", "r");
    fscanf(passx, "%s", &passc);
    int length;
    length = strlen(passc);
    for(i=0; i<length; i++)
    {
        password[i] = getch();
        printf("*");
    }
    password[i]='\0';
    printf(ANSI_COLOR_RED"\n\n\t\t\t\tPress any key to continue..."ANSI_COLOR_RESET);
    getch();
    int users = strcmp(usr, user);
    int passes = strcmp(passc, password);
    if((users == 0)&&(passes == 0))
    {
        login_successful();
        shop();
    }

    else
    {
        login_error();
        signin();
    }
}

////////////////////////////////////////////////////// Thanks //////////////////////////////////////////////

thanks()
{

    {
        printf(ANSI_COLOR_RED "\n\n\n\n\t\t\t\t\t\t  ===============\n");
        printf(ANSI_COLOR_RED  "\t\t\t\t\t\t  |~ Thank You ~|\n");
        printf(ANSI_COLOR_RED "\t\t\t\t\t\t  ===============\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_GREEN"\n\n\t\t\t\t\tPress any key to continue shopping..." ANSI_COLOR_RESET);
    }
    getch();
    shop();
}

//////////////////////////////////////////////////// Graphics ////////////////////////////////////////////////

graphics()
{
    system("cls");
    int x;
    printf(ANSI_COLOR_BLUE"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t");
    char name1[] = "\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  WELCOME ";

    for(x=0; name1[x]!=NULL; x++)
    {
        printf(ANSI_COLOR_RESET"%c",name1[x]);
        Sleep(40);
    }
    char name2[] = "TO OUR  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
    for(x=0; name2[x]!=NULL; x++)
    {
        printf("%c",name2[x]);
        Sleep(40);
    }
    printf("\n\n\t\t\t\t");
    char name3[] = "\xdb\xdb\xdb\xdb\xdb\xdb\xdb  MULTI SHOPPING SYSTEM  \xdb\xdb\xdb\xdb\xdb\xdb";
    for(x=0; name3[x]!=NULL; x++)
    {
        printf(ANSI_COLOR_YELLOW"%c",name3[x]);
        Sleep(40);
    }
    printf(ANSI_COLOR_RED"\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n\n"ANSI_COLOR_RESET);

    Sleep(1000);
}

///////////////////////////////////////////////////// Credit ///////////////////////////////////////////////////

credit()
{
    system("cls");
    printf(ANSI_COLOR_YELLOW"\n\n\n\n\n\n\n\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\n\t\t\tTeam Member - 01  |  Tunazzinur Rahman Kabbo  |  ID: 19202103268\n");
    printf(ANSI_COLOR_MAGENTA"\n\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
    printf("\t\t\tTeam Member - 02  |  MD. Naimul Rahman        |  ID: 19202103274\n");
    printf(ANSI_COLOR_GREEN"\n\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n");
    printf("\t\t\tTeam Member - 03  |  MD. Mehedi Hasan         |  ID: 19202103264\n");
    printf(ANSI_COLOR_RED"\n\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
    printf("\n\n\t\t\tPress any key to go back to main menu...");
    getch();
    menu();


}

////////////////////////////////////////////////// Wrong Choice /////////////////////////////////////////////////////

wrong()
{
    system("cls");
    printf(ANSI_COLOR_YELLOW"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t=============\n"ANSI_COLOR_RESET);
    printf("\a\t\t\t\t\tWrong Choice!\n");
    printf(ANSI_COLOR_GREEN"\t\t\t\t\t=============\n"ANSI_COLOR_RESET);
    getch();
    menu();
}

///////////////////////////////////////////// Login Graphics /////////////////////////////////////////////////

login_successful()
{
    system("cls");
    printf(ANSI_COLOR_GREEN"\n\n\n\n\n\n\t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
    printf("\n\t\t\t\t\t\xdb\xdb                       \xdb\xdb");
    printf("\n\t\t\t\t\t\xdb\xdb    Login Successful   \xdb\xdb");
    printf("\n\t\t\t\t\t\xdb\xdb                       \xdb\xdb");
    printf("\n\t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
    printf("\n\n\t\t\t\t\tPress any key to continue ..."ANSI_COLOR_RESET);
    getch();
}


login_error()
{
    system("cls");
    printf(ANSI_COLOR_RED"\a\n\n\n\n\n\n\t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
    printf("\n\t\t\t\t\t\xdb\xdb                       \xdb\xdb");
    printf("\n\t\t\t\t\t\xdb\xdb   WRONG CREDENTIALS   \xdb\xdb");
    printf("\n\t\t\t\t\t\xdb\xdb                       \xdb\xdb");
    printf("\n\t\t\t\t\t\xdb\xdb       Try Again!!     \xdb\xdb");
    printf("\n\t\t\t\t\t\xdb\xdb                       \xdb\xdb");
    printf("\n\t\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb"ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN"\n\n\t\t\t\t\tPress any key to continue ..."ANSI_COLOR_RESET);
    getch();
}

/////////////////////////////////////////////////// Menu /////////////////////////////////////////////////////////////

menu()
{
    system("cls");
    int num,i;
    printf(ANSI_COLOR_RED"\n\n\t\t\t\t  ___________________________\n");
    printf(ANSI_COLOR_YELLOW"\t\t\t\t  ===========================\n");
    printf(ANSI_COLOR_MAGENTA"\t\t\t\t /|||||||||||||||||||||||||||\\\n");
    printf(ANSI_COLOR_GREEN"\t\t\t\t  |_________________________|\n");
    printf(ANSI_COLOR_RED"\t\t\t\t  |                         |\n");
    printf(ANSI_COLOR_BLUE"\t\t\t\t  |                         |\n");
    printf(ANSI_COLOR_YELLOW"\t\t\t\t  |    ONLINE MULTI-SHOP    |\n");
    printf(ANSI_COLOR_GREEN"\t\t\t\t  |                         |\n");
    printf(ANSI_COLOR_MAGENTA"\t\t\t\t  |_________________________|\n");
    printf(ANSI_COLOR_RED"\t\t\t\t /___________________________\\\n");
    printf(ANSI_COLOR_BLUE"\t\t\t\t|_____________________________|"ANSI_COLOR_RESET);
    printf("\n\n\t\t\t\t1. Registration\n");
    printf("\t\t\t\t2. Sign In\n");
    printf("\t\t\t\t3. Shop\n");
    printf("\t\t\t\t4. Admin Panel  \n");
    printf("\t\t\t\t5. Credits  \n");
    printf("\t\t\t\t6. Exit  \n");
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

    case 5:
        credit();
        break;

    case 6:
        system("cls");
        printf(ANSI_COLOR_YELLOW"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t========================================\n"ANSI_COLOR_RESET);
        printf("\t\t\t\t\tThank You For Using Our Shopping System.\n");
        printf(ANSI_COLOR_GREEN"\t\t\t\t\t========================================\n"ANSI_COLOR_RESET);
        exit(1);
        break;

    default:
        wrong();
        break;
    }
}

/////////////////////////////////////////////////// Admin ////////////////////////////////////////////////////////////

void admin_login()
{
    system("cls");
    int i = 0;
    char uname[10], c = ' ';
    char pword[10], code[10];
    char user[10] = "admin";
    char pass[10] = "admin";
    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ADMIN LOGIN \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
    printf("\n\t\t\tUser Name : ");
    scanf("%s", &uname);
    printf("\n\t\t\tPassword : ");
    while(i < 10)
    {
        pword[i] = getch();
        c = pword[i];
        if(c == 13) break;
        else printf("*");
        i++;
    }
    pword[i] = '\0';
    i = 0;

    if(strcmp(uname,"admin") == 0 && strcmp(pword,"admin") == 0)
    {
        login_successful();
        admin_panel();
    }
    else
    {
        login_error();
        admin_login();
    }
    main();
}



admin_panel()
{
    system("cls");
    int z;
    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb Admin Panel \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\t\t[1] Add Items");
    printf("\n\t\t\t\t\t[2] Delete Items");
    printf("\n\t\t\t\t\t[3] View Items");
    printf("\n\t\t\t\t\t[4] Edit Items");
    printf("\n\t\t\t\t\t[5] <= Back");
    printf("\n\t\t\t\t\t[6] Exit!");
    printf("\n\t\t\t\t____________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d", &z);

    if (z==1)
        add_item();
    else if (z==2)
        deleteproduct();
    else if (z == 4)
        edit_item();
    else if (z == 3)
        read_item();

}

////////////////////////////////////////////// add items //////////////////////////////////////////////////////////////

add_graphics()
{
    system("cls");
    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb ADD PRODUCT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
}

void add_item()
{
    int index, valid;
    char c;
    int ID;
    int a=0;
    FILE *fp;
    do
    {
        add_graphics();
        fp = fopen("product.dat","a+");

        if((fp = fopen("product.dat","a+"))!=NULL)
        {
I:
            printf(ANSI_COLOR_YELLOW"\n\t\t\t\tEnter Item Code: "ANSI_COLOR_RESET);
            scanf("%d",&ID);
            while(fscanf(fp,"%s %d %d", &st.productname, &st.price, &st.productid)!=EOF)
            {
                if(ID == st.productid)
                {
                    do
                    {
                        add_graphics();
                        printf(ANSI_COLOR_RED"\n\n\n\t\t\t\t   [*] THE PRODUCT CODE ALREADY EXIST.\n");
                        printf(ANSI_COLOR_GREEN"\n\t\t\t\t   Press any key to continue...\n"ANSI_COLOR_RESET);
                        getch();
                        add_graphics();
                        goto I;
                    }
                    while(ID =! st.productid);
                }
            }
            st.productid = ID;
        }

        else
        {
            printf(ANSI_COLOR_YELLOW"\n\t\t\t\tEnter Product Code: "ANSI_COLOR_RESET);
            scanf("%d", &st.productid);
        }

        do
        {
            fflush(stdin);
            printf(ANSI_COLOR_YELLOW"\n\t\t\t\tEnter Item Name: "ANSI_COLOR_RESET);
            gets(st.productname);
            st.productname[0]=toupper(st.productname[0]);
            for (index=0; index < strlen(st.productname); ++index)
            {
                if(isalpha(st.productname[index]))
                    valid = 1;
                else
                {
                    valid = 0;
                    break;
                }
            }
            if (!valid)
            {
                printf(ANSI_COLOR_RED"\nName contain invalid character. Please 'Enter' again"ANSI_COLOR_RESET);
                getch();
            }
        }
        while(!valid);


        printf(ANSI_COLOR_YELLOW"\n\t\t\t\tEnter Price: "ANSI_COLOR_RESET);
        scanf("%d",&st.price);

        fp=fopen("product.dat","a");
        fprintf(fp,"\n%s %d %d", st.productname, st.price, st.productid);
        fclose(fp);
        printf(ANSI_COLOR_GREEN"\n\n\t\t\t\tPress 'Enter' to add more item or any other key to go to admin panel"ANSI_COLOR_RESET);
    }
    while((c = getch()) =='\r');
    admin_panel();
}


//////////////////////////////////////////////////////////ITEM VIEW///////////////////////////////////////////////////
item_view()
{
    system("cls");
    FILE *f;
    int i, q;
    if((f=fopen("product.dat","r"))==NULL)
    {
        gotoxy(10,3);
        printf("NO RECORDS");
        printf("\n\t\tPress any key to go back to Menu.");
        getch();
        menu();
    }
    else
    {
        gotoxy(0,5);
        printf("\t\t\t      ");
        for(i = 0; i < 50; i++)
        {
            printf(ANSI_COLOR_RED"_"ANSI_COLOR_RESET);
        }
        gotoxy(5,6);
        printf("\t\t\t\tName");
        gotoxy(25,6);
        printf("\t\t\t\tPrice");
        gotoxy(40,6);
        printf("\t\t\t\tCode\n");

        printf("\t\t\t      ");
        for(i = 0; i < 50; i++)
        {
            printf(ANSI_COLOR_RED"_"ANSI_COLOR_RESET);
        }

        q = 8;
        while(fscanf(f,"%s %d %d\n", &st.productname, &st.price, &st.productid)!=EOF)
        {
            gotoxy(5,q);
            printf("\t\t\t\t%s", st.productname);
            gotoxy(25,q);
            printf("\t\t\t\t%d", st.price);
            gotoxy(40,q);
            printf("\t\t\t\t%d", st.productid);
            q++;
        }

        printf("\n\t\t\t      ");
        for(i = 0; i < 50; i++)
            printf(ANSI_COLOR_RED"_"ANSI_COLOR_RESET);
    }
    fclose(f);
}
///////////////////////////////////////////////READ ITEM ADMIN MENU///////////////////////////////////////////////////
void read_item()
{
    item_view();
    printf(ANSI_COLOR_GREEN"\n\n\t\t\t\t\tPress any key to go to Main Menu!"ANSI_COLOR_RESET);
    getch();
    admin_panel();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
delete_graphics()
{
    system("cls");
    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb DELETE PRODUCT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
}
void deleteproduct(void)
{
    char target[40];
    int found=0;
    FILE *sfile, *tfile;
    sfile=fopen("product.dat","r");
    tfile=fopen("TempFile.dat","w+");
    delete_graphics();
    printf("\n\t\t\t\tEnter Name To Delete: ");
    fflush(stdin);
    scanf("%s",target);
    target[0]=toupper(target[0]);
    while (fscanf(sfile,"%s %d %d\n", &st.productname, &st.price, &st.productid)!=EOF)
    {
        if(strcmp(target, st.productname)==0)
        {
            found=1;
        }
        else
        {
            fprintf(tfile,"%s %d %d\n", st.productname, st.price, st.productid);
        }
    }
    if(!found)
    {
        delete_graphics();
        printf(ANSI_COLOR_RED"\n\n\a\t\t\t\t\t\tRecord not found!!"ANSI_COLOR_RESET);
        getch();
        admin_panel();
    }
    else
    {
        printf("\n\n\t\t\t\t\t\tRecord deleted");
    }
    fclose(sfile);
    fclose(tfile);
    remove("product.dat");
    rename("TempFile.dat","product.dat");

    printf("\n\n\n\t\t\t\tPress any key to go to admin panel!");
    while((st.c = getch()) =='\r');
    admin_panel();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
edit_graphics()
{
    system("cls");
    printf(ANSI_COLOR_RED"\n\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb EDIT PRODUCT \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
}

edit_item()
{
    int index, valid;
    char target[40];
    FILE *fp, *rp;
    int a=0;
    int id;
    char edit;
    long int size = sizeof(st);
    if((fp=fopen("product.dat","r+"))==NULL)
    {
        edit_graphics();
        printf("NO RECORD FOUND.");
        getch();
        admin_panel();
    }
    else
    {
        system("cls");
        edit_graphics();
        rp = fopen("TempFile.dat","a");
        printf("\n\t\t\t\tEnter Item's Code to edit: ");
        scanf("%d",&id);
        fflush(stdin);
        while(fscanf(fp,"%s %i %i\n", &st.productname, &st.price, &st.productid)!=EOF)
        {
            if(id == st.productid)
            {
                a = 1;
                printf(ANSI_COLOR_GREEN"\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb RECORD FOUND \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
                printf("\n\t\t\t\tItem's Name: %s", st.productname);
                printf("\n\t\t\t\tPrice: %d", st.price);
                printf("\n\t\t\t\tItem's Code: %d"ANSI_COLOR_RESET, st.productid);

                printf(ANSI_COLOR_RED"\n\n\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb NEW RECORD \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
                do
                {
                    fflush(stdin);
                    printf("\n\t\t\t\tNew Item's Name\t\t: ");
                    gets(st.productname);
                    st.productname[0] = toupper(st.productname[0]);
                    for (index = 0; index < strlen(st.productname); ++index)
                    {
                        if(isalpha(st.productname[index]))
                            valid = 1;
                        else
                        {
                            valid = 0;
                            break;
                        }
                    }
                    if (!valid)
                    {
                        printf("\n Name contain invalid character. Please 'Enter' again");
                        getch();
                    }
                }
                while(!valid);

                printf("\n\t\t\t\tEnter New Price: ");
                scanf("%d", &st.price);
                printf("\n\t\t\t\tEnter New Item's Code: "ANSI_COLOR_RESET);
                scanf("%d", &st.productid);

                printf("\n\n\t\t\t\tPress 'Y' to edit the existing record or any key to cancel");
                edit=getche();
                if(edit == 'y' || edit == 'Y')
                {
                    fprintf(rp,"%s %d %d\n", st.productname, st.price, st.productid);
                    fflush(stdin);
                    printf("\n\n\t\t\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
                }
            }
            else
            {
                fprintf(rp,"%s %d %d\n", st.productname, st.price, st.productid);
                fflush(stdin);
            }

        }
        if(!a)
        {
            printf("\n\n\t\t\t\tTHIS ITEM DOESN'T EXIST!!!!");
        }
        fclose(rp);
        fclose(fp);
        remove("product.dat");
        rename("TempFile.dat","product.dat");
        getch();
    }
    admin_panel();
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

admin()
{
    system("cls");
    printf(ANSI_COLOR_RED"\n\n\n\n\n\n\n\n\n\n\t\t\t      \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\n\t\t\t\t You have to log in first to access the admin panel.");
    printf(ANSI_COLOR_BLUE"\n\n\t\t\t\t\t     Press any key to login.");
    printf(ANSI_COLOR_RED"\n\n\t\t\t      \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n"ANSI_COLOR_RESET);
    getch();
    admin_login();
}

/////////////////////////////////////////////////// Invoice //////////////////////////////////////////////////////////

void invoice(char a[], int b, int z, int v)
{
    system("cls");
    int n = 1, i;
    printf(ANSI_COLOR_RED "\n\n\n\t\t\t\t*********************  INVENTORY *********************\n" ANSI_COLOR_RESET);
    printf("\t\t\t\t------------------------------------------------------\n");
    printf("\t\t\t\t  S.N.  |    NAME          |    QUANTITY   |   PRICE \n");
    printf("\t\t\t\t------------------------------------------------------\n");
    for (i = 0; i < n; i++)
        printf("\t\t\t\t   %d    -   %s          -       %d      -    %d\n", v, a, z, b*z);

    FILE *invoice;
    invoice = fopen("invoice.txt", "w");
    fprintf(invoice, "\n\n\t\t\t\t*********************** INVOICE ************************\n");
    fprintf(invoice, "\t\t\t\t---------------------------------------------------------\n");
    fprintf(invoice, "\t\t\t\t|  S.N.  |    NAME          |    QUANTITY   |   PRICE   |\n");
    fprintf(invoice, "\t\t\t\t---------------------------------------------------------\n");
    fprintf(invoice, "\t\t\t\t|  %d    -   %s          -       %d      -     %d  |\n", v, a, z, b);
    fclose(invoice);

    printf("\n\n\t\t\t\t\t Press Any Key To Pay The Amount...");
    getch();
    payment();

}

file()
{
    system("cls");
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    fp = fopen("invoice.txt", "r");
    while ((read = getline(&line, &len, fp)) != -1)
    {
        printf("\n%s", line);
    }
    fclose(fp);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////

payment()
{
    system("cls");
    int p, n;
    char a[] = "Bkash";
    char b[] = "Rocket";
    char l[] = "Nagad";
    char d[] = "Credit/Debit";
    char e[] = "Cash On Delivery";
    printf(ANSI_COLOR_YELLOW"\n\n\n\t\t\t\t\t ===========\n");
    printf("\t\t\t\t\t | Payment |");
    printf("\n\t\t\t\t\t ===========\n\n"ANSI_COLOR_RESET);
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
        cod();
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
    printf(ANSI_COLOR_YELLOW"\n\n\n\t\t\t\t\t =========\n");
    printf("\t\t\t\t\t | Bkash |");
    printf("\n\t\t\t\t\t =========\n\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\tEnter your bkash number\n");
    printf("\t\t\t\t------------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%d", &m);
    printf("\n\t\t\t\tEnter the OTP\n");
    printf("\t\t\t\t--------------\n");
    printf("\t\t\t\t=> ");
    scanf("%d", &o);
    printf("\n\t\t\t\tEnter your pin\n");
    printf("\t\t\t\t---------------\n");
    printf("\t\t\t\t=> ");
    scanf("%d", &p);

    {
        FILE *pay;
        pay = fopen("payment.txt", "w");
        fprintf(pay, "\n\n\n\t\t\t\t\t =========\n");
        fprintf(pay, "\t\t\t\t\t | Bkash |");
        fprintf(pay, "\n\t\t\t\t\t =========\n\n");
        fprintf(pay, "\n\t\t\t\tEnter your bkash number\n");
        fprintf(pay, "\t\t\t\t------------------------\n");
        fprintf(pay, "\t\t\t\t=> %d", m);
        fprintf(pay, "\n\t\t\t\tEnter the OTP\n");
        fprintf(pay, "\t\t\t\t--------------\n");
        fprintf(pay, "\t\t\t\t=> %d", o);
        fprintf(pay, "\n\t\t\t\tEnter your pin\n");
        fprintf(pay, "\t\t\t\t---------------\n");
        fprintf(pay, "\t\t\t\t=> %d", p);
        fclose(pay);
    }

    file();

    printf(ANSI_COLOR_MAGENTA "\n\n\t\t\t\t\tYou have paid your amount with Bkash.\n" ANSI_COLOR_RESET);
    Sleep(100);

    thanks();
}

rocket()
{
    system("cls");
    int m, o, p;
    printf(ANSI_COLOR_YELLOW"\n\n\n\t\t\t\t\t ==========\n");
    printf("\t\t\t\t\t | Rocket |");
    printf("\n\t\t\t\t\t ==========\n\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\tEnter your rocket number\n");
    printf("\t\t\t\t------------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%d", &m);
    printf("\n\t\t\t\tEnter the OTP\n");
    printf("\t\t\t\t--------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &o);
    printf("\n\t\t\t\tEnter your pin\n");
    printf("\t\t\t\t---------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &p);

    {
        FILE *pay;
        pay = fopen("payment.txt", "w");
        fprintf(pay, "\n\n\n\t\t\t\t\t ==========\n");
        fprintf(pay, "\t\t\t\t\t | Rocket |");
        fprintf(pay, "\n\t\t\t\t\t ==========\n\n");
        fprintf(pay, "\n\t\t\t\tEnter your rocket number\n");
        fprintf(pay, "\t\t\t\t------------------------\n");
        fprintf(pay, "\t\t\t\t=> %d", m);
        fprintf(pay, "\n\t\t\t\tEnter the OTP\n");
        fprintf(pay, "\t\t\t\t--------------\n");
        fprintf(pay, "\t\t\t\t=> %d", o);
        fprintf(pay, "\n\t\t\t\tEnter your pin\n");
        fprintf(pay, "\t\t\t\t---------------\n");
        fprintf(pay, "\t\t\t\t=> %d", p);
        fclose(pay);
    }


    file();

    printf(ANSI_COLOR_MAGENTA "\n\n\t\t\t\t\tYou have paid your amount with Rocket.\n" ANSI_COLOR_RESET);

    thanks();
}
nagad()
{
    system("cls");
    int m, o, p;
    printf(ANSI_COLOR_YELLOW"\n\n\n\t\t\t\t\t =========\n");
    printf("\t\t\t\t\t | Nagad |");
    printf("\n\t\t\t\t\t =========\n\n"ANSI_COLOR_RESET);
    printf("\n\t\t\t\tEnter your nagad number\n");
    printf("\t\t\t\t------------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%d", &m);
    printf("\n\t\t\t\tEnter the OTP\n");
    printf("\t\t\t\t--------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &o);
    printf("\n\t\t\t\tEnter your pin\n");
    printf("\t\t\t\t---------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &p);

    {
        FILE *pay;
        pay = fopen("payment.txt", "w");
        fprintf(pay, "\n\n\n\t\t\t\t\t =========\n");
        fprintf(pay, "\t\t\t\t\t | Nagad |");
        fprintf(pay, "\n\t\t\t\t\t =========\n\n");
        fprintf(pay, "\n\t\t\t\tEnter your nagad number\n");
        fprintf(pay, "\t\t\t\t------------------------\n");
        fprintf(pay, "\t\t\t\t=> %d", m);
        fprintf(pay, "\n\t\t\t\tEnter the OTP\n");
        fprintf(pay, "\t\t\t\t--------------\n");
        fprintf(pay, "\t\t\t\t=> %d", o);
        fprintf(pay, "\n\t\t\t\tEnter your pin\n");
        fprintf(pay, "\t\t\t\t---------------\n");
        fprintf(pay, "\t\t\t\t=> %d", p);
        fclose(pay);
    }


    file();

    printf(ANSI_COLOR_MAGENTA "\n\n\t\t\t\t\tYou have paid your amount with Nagad.\n" ANSI_COLOR_RESET);

    thanks();
}
card()
{
    system("cls");
    int m, o, p;
    char n[200];
    printf(ANSI_COLOR_YELLOW"\n\n\n\t\t\t\t\t ================\n");
    printf("\t\t\t\t\t | Credit/Debit |");
    printf("\n\t\t\t\t\t ================\n\n"ANSI_COLOR_RESET);
    fflush(stdin);
    printf("\n\t\t\t\tEnter your full name:\n");
    printf("\t\t\t\t---------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%[^\n]s", n);
    printf("\n\t\t\t\tEnter your card number\n");
    printf("\t\t\t\t------------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%d", &m);
    printf("\n\t\t\t\tEnter your CVC\n");
    printf("\t\t\t\t---------------\n");
    printf("\t\t\t\t=> ");
    scanf("%d", &o);
    printf("\n\t\t\t\tEnter your pin\n");
    printf("\t\t\t\t---------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &p);

    {
        FILE *pay;
        pay = fopen("payment.txt", "w");
        fprintf(pay, "\n\n\n\t\t\t\t\t ================\n");
        fprintf(pay, "\t\t\t\t\t | Credit/Debit |");
        fprintf(pay, "\n\t\t\t\t\t ================\n\n");
        fprintf(pay, "\n\t\t\t\tEnter your full name:\n");
        fprintf(pay, "\t\t\t\t---------------------\n");
        fprintf(pay, "\t\t\t\t=> %s", n);
        fprintf(pay, "\n\t\t\t\tEnter your card number\n");
        fprintf(pay, "\t\t\t\t------------------------\n");
        fprintf(pay, "\t\t\t\t=> %d", m);
        fprintf(pay, "\n\t\t\t\tEnter your pin\n");
        fprintf(pay, "\t\t\t\t---------------\n");
        fprintf(pay, "\t\t\t\t=> %d", p);
        fclose(pay);
    }


    file();

    printf(ANSI_COLOR_MAGENTA "\n\n\t\t\t\t\tYou have paid your amount with Card.\n" ANSI_COLOR_RESET);

    thanks();
}
cod()
{
    system("cls");
    int m;
    char o[200];
    char n[200];
    printf(ANSI_COLOR_YELLOW"\n\n\n\t\t\t\t\t ====================\n");
    printf("\t\t\t\t\t | Cash On Delivery |");
    printf("\n\t\t\t\t\t ====================\n\n"ANSI_COLOR_RESET);
    fflush(stdin);
    printf("\n\t\t\t\tEnter your full name:\n");
    printf("\t\t\t\t---------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%[^\n]s", n);
    printf("\n\t\t\t\tEnter your phone number\n");
    printf("\t\t\t\t------------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%d", &m);
    fflush(stdin);
    printf("\n\t\t\t\tEnter your address:\n");
    printf("\t\t\t\t--------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%[^\n]s", o);

    {
        FILE *pay;
        pay = fopen("payment.txt", "w");
        fprintf(pay, "\n\n\n\t\t\t\t\t ====================\n");
        fprintf(pay, "\t\t\t\t\t | Cash On Delivery |");
        fprintf(pay, "\n\t\t\t\t\t ====================\n\n");
        fprintf(pay, "\n\t\t\t\tEnter your full name:\n");
        fprintf(pay, "\t\t\t\t---------------------\n");
        fprintf(pay, "\t\t\t\t=> %s", n);
        fprintf(pay, "\n\t\t\t\tEnter your phone number\n");
        fprintf(pay, "\t\t\t\t-------------------------\n");
        fprintf(pay, "\t\t\t\t=> %d", m);
        fprintf(pay, "\n\t\t\t\tEnter your address:\n");
        fprintf(pay, "\t\t\t\t--------------------\n");
        fprintf(pay, "\t\t\t\t=> %s", o);
        fclose(pay);
    }

    file();

    printf(ANSI_COLOR_MAGENTA "\n\n\t\t\t\tYou choose cash on delivery. Your product will be delivered soon.\n" ANSI_COLOR_RESET);

    thanks();
}

/////////////////////////////////////////////// Shop //////////////////////////////////////////////////////

shop()
{
    item_view();
    FILE *buy;
    long int size = sizeof(st);
    buy = fopen("product.dat","r+");
    int id, z;
    printf("\n\t\t\t\tEnter Item's Code to buy: ");
    scanf("%d",&id);
    printf("\n\t\t\t\tEnter how many: ");
    scanf("%d",&z);
    fflush(stdin);
    while(fscanf(buy,"%s %i %i\n", &st.productname, &st.price, &st.productid)!=EOF)
    {
        if(id == st.productid)
        {

            invoice(st.productname, st.price, z, st.productid);

        }
    }
}

/////////////////////////////////////////////// Main //////////////////////////////////////////////////////

int main()
{

    graphics();
    Sleep(300);
    menu();
    getch();
}


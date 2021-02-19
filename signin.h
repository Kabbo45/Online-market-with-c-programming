void signin()
{
    system("cls");
    char user[100], password[100], usr[100], passc[100];
    int n;
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
    scanf("%s", &password);

    FILE *username;
    username = fopen("username.txt", "r");
    fscanf(username, "%s", &usr);

    FILE *passx;
    passx = fopen("password.txt", "r");
    fscanf(passx, "%s", &passc);

    int users = strcmp(usr, user);
    int passes = strcmp(passc, password);

    if((users == 0)&&(passes == 0))
    {
        system("cls");
        printf(ANSI_COLOR_GREEN"\n\n\t\t\t\t\t[*] Successfully logged in."ANSI_COLOR_RESET);
        Sleep(1000);
        shop();
    }

    else if((users == 0)||(passes == 0))
    {
        system("cls");
        printf(ANSI_COLOR_RED"\a\n\n\t\t\t\t[*] One of your credential is wrong.\n");
        printf("\t\t\t\t[*] Try again."ANSI_COLOR_RESET);
        getch();
        signin();
    }

    else
    {
        system("cls");
        printf(ANSI_COLOR_RED"\a\n\n\t\t\t\t[*] Username and password didn't match.\n");
        printf("\t\t\t\t[*] Try again."ANSI_COLOR_RESET);
        getch();
        signin();
    }
}

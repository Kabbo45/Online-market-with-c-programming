int registration()
{
    char first[50], middle[50], last[50], email[100], usrname[100], pass[100], address[100], pass2[100];
    int mobile;
    FILE *fptr;
    fptr = fopen("regestration.txt","w");
    printf("\n\n\t\t\t\t\t====================\n");
    printf("\t\t\t\t\t||  Registration  ||\n");
    printf("\t\t\t\t\t====================\n\n");
    printf("\t\t\t\tEnter your full name [First Middle Last]\n");
    printf("\t\t\t\t----------------------------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s %s %s", &first, &middle, &last);
    printf("\n\t\t\t\tEnter your mobile number\n");
    printf("\t\t\t\t------------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%d", &mobile);
    printf("\n\t\t\t\tEnter your district\n");
    printf("\t\t\t\t------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &address);
    printf("\n\t\t\t\tEnter your e-mail\n");
    printf("\t\t\t\t-----------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &email);
    printf("\n\t\t\t\tChoose your username\n");
    printf("\t\t\t\t --------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &usrname);
    printf("\n\t\t\t\tChoose your password\n");
    printf("\t\t\t\t--------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &pass);
    printf("\n\t\t\t\tConfirm your password\n");
    printf("\t\t\t\t---------------------\n");
    printf("\t\t\t\t=> ");
    scanf("%s", &pass2);
    int result = strcmp(pass, pass2);
    if(result == 0)
    {
        fprintf(fptr,"Registration Details \n-------------------- \nFull Name: %s %s %s \nMobile Number: +880%d \nDistrict Name: %s \nE-mail: %s \nUsername: %s \nPassword: %s \n", first, middle, last, mobile, address, email, usrname, pass);
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
            printf("\n\t\t\t\tOOPS! You're password didn't match\n");
            printf("\n\t\t\t\tChoose your password again\n");
            printf("\t\t\t\t--------------------------\n");
            printf("\t\t\t\t=> ");
            scanf("%s", &pass);
            printf("\n\t\t\t\tConfirm your password\n");
            printf("\t\t\t\t---------------------\n");
            printf("\t\t\t\t=> ");
            scanf("%s", &pass2);
        }
        while (pass == pass2);

        fprintf(fptr,"Registration Details \n-------------------- \nFull Name: %s %s %s \nMobile Number: +880%d \nDistrict Name: %s \nE-mail: %s \nUsername: %s \nPassword: %s \n", first, middle, last, mobile, address, email, usrname, pass);
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


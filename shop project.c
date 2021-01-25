#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
//////////////////////////////////////////////////////////////////////////////////////////
struct login
{
    char usrname[30];
    char pass[30];
    int n;
};
//////////////////////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////////////////////
void signin()
{
    char user[100], password[100], usr[100], passc[100];
    int n;
    printf("\n\n\t\t\t\t\t===============\n");
    printf("\t\t\t\t\t||  Sign In  ||\n");
    printf("\t\t\t\t\t===============\n");
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
        printf("\n\n\t\t\t\t[*] Successfully logged in.");
        shop();
    }

    else if((users == 0)||(passes == 0))
    {
        printf("\n\n\t\t\t\t[*] One of your credential is wrong.\n");
        printf("\t\t\t\t[*] Try again.");
        signin();
    }

    else
    {
        printf("\n\n\t\t\t\t[*] Username and password didn't match.\n");
        printf("\t\t\t\t[*] Try again.");
        signin();
    }
}

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
void shop()
{
    struct login s;
    printf("\n\n\t\t\t\t========================================\n");
    printf("\n\n\t\t\t\t\t    ================\n");
    printf("\t\t\t\t\t    | Our Services |");
    printf("\n\t\t\t\t\t    ================\n");
    printf("\n\n\t\t\t\t1. Clothing");
    printf("\n\n\t\t\t\t2. Electronics");
    printf("\n\n\t\t\t\t3. Health & Care");
    printf("\n\n\t\t\t\t4. Furnitures");
    printf("\n\n\t\t\t\t5. Consumer Foods");
    printf("\n\n\t\t\t\t6. Stationaries");
    printf("\n\n\t\t\t\t7. Digital Services");
    printf("\n\n\t\t\t\t8. <= Back");
    printf("\n\n\t\t\t\t________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");

    scanf("%d",&s.n);
    switch(s.n)
    {
    case 1:
        clothing();
        break;

    case 2:
        electronics();
        break;

    case 3:
        healthcare();
        break;

    case 4:
        furnitures();
        break;

    case 5:
        consumer_foods();
        break;

    case 6:
        stationaries();
        break;

    case 7:
        digital_service();
        break;

    case 8:
        main();

    default:
        printf("Error!");
    }

}
//////////////////////////////////////////////////////////////////////////////////////////
void clothing()
{
    struct login c;
    printf("\n\n\t\t\t\t==========================================\n");
    printf("\n\n\t\t\t\t\t    ====================\n");
    printf("\t\t\t\t\t    | Clothing Section |");
    printf("\n\t\t\t\t\t    ====================\n");
    printf("\n\t\t\t\t1. Women\n");
    printf("\n\t\t\t\t2. Men\n");
    printf("\n\t\t\t\t3. Children\n");
    printf("\n\t\t\t\t4. Footwear\n");
    printf("\n\t\t\t\t5. Jewelries\n");
    printf("\n\t\t\t\t6. <= Back");
    printf("\n\n\t\t\t\t__________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");

    scanf("%d",&c.n);
    switch(c.n)
    {
    case 1:
        women();
        break;

    case 2:
        men();
        break;

    case 3:
        children();
        break;

    case 4:
        footwear();
        break;

    case 5:
        jwelries();
        break;

    case 6:
        shop();
        break;

    default:
        printf("Error!");
    }
}
void women()
{
    int n;
    printf("\n\n\t\t\t\t=============================\n");
    printf("\t\t\t\t| Welcome to the Women site |");
    printf("\n\t\t\t\t=============================\n");
    printf("\n\t\t\t\t1. Saree--1200 Taka\n");
    printf("\n\t\t\t\t2. Shirt--500 Taka\n");
    printf("\n\t\t\t\t3. Pant--600 Taka\n");
    printf("\n\t\t\t\t4. 3-Pic--1800 Taka\n");
    printf("\n\t\t\t\tEnter your choice: ");
    scanf("%d", &n);
    switch(n)
    {
    case 1:
        printf("Your order is : Saree || Price: 1200 Taka");
        break;
    case 2:
    default:
        printf("Error!");

    }
}

void men()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Men site ");
    printf("\n\t\t\t\t1. Shirt--900 Taka\n");
    printf("\n\t\t\t\t2. Pant--500 Taka\n");
    printf("\n\t\t\t\t3. T-Shirt--300 Taka\n");
    printf("\n\t\t\t\t4. watch--600 Taka\n");
}

void children()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Children site ");
    printf("\n\t\t\t\t1. Shirt--500 Taka\n");
    printf("\n\t\t\t\t2. Pant--500 Taka\n");
    printf("\n\t\t\t\t3. Toy--1200 Taka\n");
    printf("\n\t\t\t\t4. watch--300 Taka\n");

}

void footwear()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Footwear site ");
    printf("\n\t\t\t\t1. Shoes--1500 Taka\n");
    printf("\n\t\t\t\t2. Socks--200 Taka\n");
    printf("\n\t\t\t\t3. Belt--300 Taka\n");
    printf("\n\t\t\t\t4. Wallet--1200 Taka\n");
}

void jwelries()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Jewelires site ");
    printf("\n\t\t\t\t1. Neekless--2,50,000 Taka\n");
    printf("\n\t\t\t\t2. Braselet--15000 Taka\n");
    printf("\n\t\t\t\t3. Chain-- 5000 Taka\n");
    printf("\n\t\t\t\t4. Diamond-Ring 20,000 Taka\n");
}
//////////////////////////////////////////////////////////////////////////////////////////
void electronics()
{
    struct login e;
    printf("\n\n\t\t\t\t==========================================\n");
    printf("\n\n\t\t\t\t\t    ==============\n");
    printf("\t\t\t\t\t    | Electroics |");
    printf("\n\t\t\t\t\t    ==============\n");
    printf("\n\t\t\t\t1. Home Appliances\n");
    printf("\n\t\t\t\t2. Computer Accessories\n");
    printf("\n\t\t\t\t3. Digital Goods");
    printf("\n\t\t\t\t4. <= Back");
    printf("\n\n\t\t\t\t__________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d",&e.n);
    switch(e.n)
    {
    case 1:
        home_app();
        break;

    case 2:
        computer();
        break;

    case 3:
        digital_goods();
        break;

    case 4:
        shop();
        break;

    default:
        printf("Error!");
    }
}
void home_app()
{
    printf("\n\t\t\t\t1. Fan -- 3500 Taka\n");
    printf("\n\t\t\t\t2. Light -- 250 Taka\n");
    printf("\n\t\t\t\t3. Calling Bell --200 Taka\n");
    printf("\n\t\t\t\t4. Switch --250 Taka\n");
    printf("\n\t\t\t\t5. Electric Door --5000 Taka\n");
}
void computer()
{
    printf("\n\t\t\t\t1. Ram-- 3500 Taka\n");
    printf("\n\t\t\t\t2. Ram -- 250 Taka\n");
    printf("\n\t\t\t\t3. Ram -- 200 Taka\n");
    printf("\n\t\t\t\t4. SSD -- 250 Taka\n");
    printf("\n\t\t\t\t5. SSD -- 5000 Taka\n");
    printf("\n\t\t\t\t1. Processor-I -- 3500 Taka\n");
    printf("\n\t\t\t\t2. Processor-II -- 250 Taka\n");
    printf("\n\t\t\t\t3. Processor-Ill --200 Taka\n");
    printf("\n\t\t\t\t4. Processor-IV --250 Taka\n");
    printf("\n\t\t\t\t5. Processor-V --5000 Taka\n");
}
void digital_goods()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Digital Goods site ");
    printf("\n\t\t\t\t1. Electric Door--2000 Taka\n");
    printf("\n\t\t\t\t2. Washing Machine--45,000 Taka\n");
    printf("\n\t\t\t\t3. Refrigrator--35,000 Taka\n");
    printf("\n\t\t\t\t4. Blander Machine -- 35,00Taka\n");
    printf("\n\t\t\t\t5. Fridge -- 95,000 Taka\n");
}
//////////////////////////////////////////////////////////////////////////////////////////Health & care
void healthcare()
{
    struct login h;
    printf("\n\n\t\t\t\t==========================================\n");
    printf("\n\n\t\t\t\t\t    ===============\n");
    printf("\t\t\t\t\t    | Health Care |");
    printf("\n\t\t\t\t\t    ===============\n");
    printf("\n\t\t\t\t1. Medical Accessories\n");
    printf("\n\t\t\t\t2. Hygienic Products\n");
    printf("\n\t\t\t\t3. Personal Care\n");
    printf("\n\t\t\t\t4. Dental Care\n");
    printf("\n\t\t\t\t5. Medicines\n");
    printf("\n\t\t\t\t6. <= Back");
    printf("\n\n\t\t\t\t__________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");

    scanf("%d",&h.n);
    switch(h.n)
    {
    case 1:
        medical_acc();
        break;

    case 2:
        hygenic();
        break;

    case 3:
        personal();
        break;

    case 4:
        dental();
        break;

    case 5:
        medicines();
        break;

    case 6:
        shop();

    default:
        printf("Error!");
    }
}
void medical_acc()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Medicine site ");
    printf("\n\t\t\t\t1. Bed--250 Taka\n");
    printf("\n\t\t\t\t2. Chair--100 Taka\n");
    printf("\n\t\t\t\t3. Injection-- 300 Taka\n");
    printf("\n\t\t\t\t4. Fanel-- 35,00Taka\n");
    printf("\n\t\t\t\t5. Acid -- 95,000 Taka\n");
    printf("\n\t\t\t\t6. wheel-chair -- 95,000 Taka\n");
}
void hygenic()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Hygenic Goods site ");
    printf("\n\t\t\t\t1. Osmotics Cosmeceuticals--2500 Taka\n");
    printf("\n\t\t\t\t2. BPI Sports--100 Taka\n");
    printf("\n\t\t\t\t3. Bulk Apothecary-- 300 Taka\n");
    printf("\n\t\t\t\t4. The Dairy Fairy -- 5,00Taka\n");
    printf("\n\t\t\t\t5. Oyin Handmade -- 5,000 Taka\n");
}
void personal()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Personal Goods site ");
    printf("\n\t\t\t\t1. Fast Aid--250 Taka\n");
    printf("\n\t\t\t\t2. Bandage-- 100 Taka\n");
    printf("\n\t\t\t\t3. Kneif-- 300 Taka\n");
}
void dental()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Dental site ");
    printf("\n\t\t\t\t1. Teeth cleaner--250 Taka\n");
    printf("\n\t\t\t\t2. Mouth Wash--250 Taka\n");
    printf("\n\t\t\t\t3. Fake Teeth--500  Taka\n");
    printf("\n\t\t\t\t4. Brush--20 Taka\n");
    printf("\n\t\t\t\t5. Tooth-pest-- 250 Taka\n");
}
void medicines()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the madicine site ");
    printf("\n\t\t\t\t1. Ace--10 Taka\n");
    printf("\n\t\t\t\t2. Deflux--50 Taka\n");
    printf("\n\t\t\t\t3. Sinaron Plus--20 Taka\n");
    printf("\n\t\t\t\t4. Isoral Mums--100 Taka\n");
    printf("\n\t\t\t\t5. Viscosid --150  Taka\n");
    printf("\n\t\t\t\t6. Napa -- 10 Taka\n");
    printf("\n\t\t\t\t7. Sallyn --5  Taka\n");
    printf("\n\t\t\t\t8.  Tofen --23 Taka\n");
}
//////////////////////////////////////////////////////////////////////////////////////////
void furnitures()
{
    struct login f;
    printf("\n\n\t\t\t\t==========================================\n");
    printf("\n\n\t\t\t\t\t    ==============\n");
    printf("\t\t\t\t\t    | Furnitures |");
    printf("\n\t\t\t\t\t    ==============\n");
    printf("\n\t\t\t\t1. Living Room\n");
    printf("\n\t\t\t\t2. Drawing Room\n");
    printf("\n\t\t\t\t3. Kitchen\n");
    printf("\n\t\t\t\t4. Bathroom\n");
    printf("\n\t\t\t\t5. <= Back");
    printf("\n\n\t\t\t\t__________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d",&f.n);
    switch(f.n)
    {
    case 1:
        living();
        break;

    case 2:
        drawing();
        break;

    case 3:
        kitchen();
        break;

    case 4:
        bathroom();
        break;

    case 5:
        shop();
        break;

    default:
        printf("Error!");
    }
}
void living()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Living-room Accessorise site ");
    printf("\n\t\t\t\t1. Bed--10000 Taka\n");
    printf("\n\t\t\t\t2. Table--5000 Taka\n");
    printf("\n\t\t\t\t3. Sofa--1,50000 Taka\n");
    printf("\n\t\t\t\t4. Devan--2,00000 Taka\n");
    printf("\n\t\t\t\t5. Rollin-Chair--5000 Taka\n");
}
void drawing()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Drawing  site ");
    printf("\n\t\t\t\t1. Show-pics--2500 Taka\n");
    printf("\n\t\t\t\t2. Flower--100 Taka\n");
    printf("\n\t\t\t\t3. Tv-Mart-- 300 Taka\n");
    printf("\n\t\t\t\t4. T-table-- 35,00Taka\n");
    printf("\n\t\t\t\t5. Pic-Art -- 95,0 Taka\n");
    printf("\n\t\t\t\t6. wheel-chair -- 95,000 Taka\n");
}
void kitchen()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Kitchen site ");
    printf("\n\t\t\t\t1. Pan--1500 Taka\n");
    printf("\n\t\t\t\t2. Non-stikiPan--1500 Taka\n");
}
void bathroom()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Bathroom site ");
    printf("\n\t\t\t\t1. Herpik--250 Taka\n");
    printf("\n\t\t\t\t2. Floor-Brash--100 Taka\n");
    printf("\n\t\t\t\t3. Ditargent-- 150 Taka\n");
    printf("\n\t\t\t\t4. Soda-- 30 Taka\n");
}
//////////////////////////////////////////////////////////////////////////////////////////
void consumer_foods()
{
    struct login c;
    printf("\n\n\t\t\t\t==========================================\n");
    printf("\n\n\t\t\t\t\t    ==================\n");
    printf("\t\t\t\t\t    | Consumer Foods |");
    printf("\n\t\t\t\t\t    ==================\n");
    printf("\n\n\t\t\t\t1. Grocery Items\n");
    printf("\n\t\t\t\t2. Beverages\n");
    printf("\n\t\t\t\t3. Dairy\n");
    printf("\n\t\t\t\t4. Meat & Fish\n");
    printf("\n\t\t\t\t5. Snacks\n");
    printf("\n\t\t\t\t6. Cooking Needs\n");
    printf("\n\t\t\t\t7. <= Back");
    printf("\n\n\t\t\t\t__________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d",&c.n);
    switch(c.n)
    {
    case 1:
        grocery();
        break;

    case 2:
        beverages();
        break;

    case 3:
        dairy();
        break;

    case 4:
        meat();
        break;

    case 5:
        snacks();
        break;

    case 6:
        cooking();
        break;

    case 7:
        shop();

    default:
        printf("Error!");
    }
}
void grocery()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Grocerry Item site ");
    printf("\n\t\t\t\t1. Rice--2500 Taka\n");
    printf("\n\t\t\t\t2. Lantil--100 Taka\n");
    printf("\n\t\t\t\t3. Potato-- 50 Taka\n");
    printf("\n\t\t\t\t4. Cucumber-- 30 Taka\n");
    printf("\n\t\t\t\t5. Onion -- 95,0 Taka\n");
}
void beverages()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Beverage Item site ");
    printf("\n\t\t\t\t1. Pepsi--2500 Taka\n");
    printf("\n\t\t\t\t2. CocaCola--100 Taka\n");
    printf("\n\t\t\t\t3. 7Up-- 50 Taka\n");
    printf("\n\t\t\t\t4. Sprite-- 30 Taka\n");
    printf("\n\t\t\t\t5. Mountain-Due -- 95,0 Taka\n");
}
void dairy()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Dairy Item site ");
    printf("\n\t\t\t\t1. Milk--250 Taka\n");
    printf("\n\t\t\t\t2. Honey--100 Taka\n");
    printf("\n\t\t\t\t3. Dano-Milk-- 50 Taka\n");
    printf("\n\t\t\t\t4. Gorur Gura Milk-- 30 Taka\n");
    printf("\n\t\t\t\t5. Minarel Water-- 50 Taka\n");
}
void meat()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Meat & Fish Item site ");
    printf("\n\t\t\t\t1. Chicken--120 Taka--per kg\n");
    printf("\n\t\t\t\t2. Beef--500  Taka-- per kg\n");
    printf("\n\t\t\t\t3. Baffalow meat-- 500 Taka--per kg\n");
    printf("\n\t\t\t\t4. Duck Meat-- 300 Taka--per kg\n");
    printf("\n\t\t\t\t5. Chiken-- 250 Taka--per pic\n");
}
void snacks()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Snacks Item site ");
    printf("\n\t\t\t\t1. Chips--10 Taka\n");
    printf("\n\t\t\t\t2. Biscuits--50  Taka\n");
    printf("\n\t\t\t\t3. Chanachur-- 50 Taka\n");
    printf("\n\t\t\t\t4. Pithas-- 30 Taka\n");
    printf("\n\t\t\t\t5. Samucha-- 50 Taka\n");
}
void cooking()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Cooking Needs site ");
    printf("\n\t\t\t\t1. Kneif--150 Taka\n");
    printf("\n\t\t\t\t2. Spoon--50  Taka\n");
    printf("\n\t\t\t\t3. Plate-- 600 Taka\n");
    printf("\n\t\t\t\t4. Pan-- 300 Taka\n");
    printf("\n\t\t\t\t5. Glass-- 350 Taka\n");
}
//////////////////////////////////////////////////////////////////////////////////////////
void stationaries()
{
    struct login s;
    printf("\n\n\t\t\t\t==========================================\n");
    printf("\n\n\t\t\t\t\t    ================\n");
    printf("\t\t\t\t\t    | Stationaries |");
    printf("\n\t\t\t\t\t    ================\n");
    printf("\n\t\t\t\t1. Books\n");
    printf("\n\t\t\t\t2. Study Equipment\n");
    printf("\n\t\t\t\t3. Lab Accessories\n");
    printf("\n\t\t\t\t4. <= Back");
    printf("\n\n\t\t\t\t__________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d",&s.n);
    switch(s.n)
    {
    case 1:
        books();
        break;

    case 2:
        study();
        break;

    case 3:
        lab();
        break;

    case 4:
        shop();
        break;

    default:
        printf("Error!");
    }
}
void books()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Books site ");
    printf("\n\t\t\t\t1. Class 8th books all--1400 Taka\n");
    printf("\n\t\t\t\t2. Class 9th books all--1500 Taka\n");
    printf("\n\t\t\t\t3. Class 10th books all--1600 Taka\n");
    printf("\n\t\t\t\t4. Class 11th books all--2000 Taka\n");
    printf("\n\t\t\t\t5. Class 12th books all--2200 Taka\n");
    printf("\n\t\t\t\t5. Versity books all--2300 Taka\n");
}
void study()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Books site ");
    printf("\n\t\t\t\t1. Geomeitry--200 Taka\n");
    printf("\n\t\t\t\t2. Pen--15 Taka\n");
    printf("\n\t\t\t\t3. Paper--160 Taka\n");
    printf("\n\t\t\t\t4. Pencil--20 Taka\n");
    printf("\n\t\t\t\t5. penbox--220 Taka\n");
}
void lab()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Lab Accessorise site ");
    printf("\n\t\t\t\t1. Acid--500 Taka\n");
    printf("\n\t\t\t\t2. Lamp--150 Taka\n");
    printf("\n\t\t\t\t3. Tube Fanel--160 Taka\n");
    printf("\n\t\t\t\t4. Lab Paper--20 Taka\n");
    printf("\n\t\t\t\t5. Aprone--220 Taka\n");
    printf("\n\t\t\t\t6. Gloves --60 Taka\n");
    printf("\n\t\t\t\t7. Glass--220 Taka\n");
}
//////////////////////////////////////////////////////////////////////////////////////////
void digital_service()
{
    struct login d;
    printf("\n\n\t\t\t\t==========================================\n");
    printf("\n\n\t\t\t\t\t    ===================\n");
    printf("\t\t\t\t\t    | Digital Service |");
    printf("\n\t\t\t\t\t    ===================\n");
    printf("\n\t\t\t\t1. Gift Cards\n");
    printf("\n\t\t\t\t2. Account Subscription\n");
    printf("\n\t\t\t\t3. Game Top-Up\n");
    printf("\n\t\t\t\t4. Bkash to Paypal\n");
    printf("\n\t\t\t\t5. <= Back");
    printf("\n\n\t\t\t\t__________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d",&d.n);
    switch(d.n)
    {
    case 1:
        gift();
        break;

    case 2:
        account_sub();
        break;

    case 3:
        game();
        break;

    case 4:
        bkash_paypal();
        break;

    case 5:
        shop();
        break;

    default:
        printf("Error!");
    }
}
void gift()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Gift site ");
    printf("\n\t\t\t\t1.  music-Box --500 Taka\n");
    printf("\n\t\t\t\t2.  Light box --500 Taka\n");
    printf("\n\t\t\t\t3.  Doll --500 Taka\n");
}
void account_sub()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Account site ");
    printf("\n\t\t\t\t1. Netflix Subscription --150 Taka\n");
    printf("\n\t\t\t\t5. G-Suite --60 Taka\n");
    printf("\n\t\t\t\t3. Netflix Gift Voucher--200 Taka\n");
}
void game()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Games site ");
    printf("\n\t\t\t\t1. Free-Fire -Weekly--250 Taka\n");
    printf("\n\t\t\t\t2. Free-Fire-Monthly--660 Taka\n");
    printf("\n\t\t\t\t3. Free-Fire-100 Diamond--1360 Taka\n");
    printf("\n\t\t\t\t4. Free-Fire-210 Diamond--220 Taka\n");
    printf("\n\t\t\t\t5. Free-Fire-320 Diamond --260 Taka\n");
    printf("\n\t\t\t\t7. Free-Fire-510 Diamond--430 Taka\n");
    printf("\n\t\t\t\t7. PUBG-UC--430 Taka\n");
}
void bkash_paypal()
{
    printf("\n\t\t\t\t=========\n");
    printf("\n\n\t\t\t\t Welcome to the Games site ");
    printf("\n\t\t\t\t1. Dollar To Taka--2tk per dollar changes\n");
    printf("\n\t\t\t\t2. Taka To Dollar--2 tk per dollar changes\n");
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

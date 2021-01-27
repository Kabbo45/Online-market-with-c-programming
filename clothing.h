void clothing()
{
    int c;
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

    scanf("%d",&c);
    switch(c)
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
    printf("\n\n\n\t\t\t\t\t =================\n");
    printf("\t\t\t\t\t | Women Section |");
    printf("\n\t\t\t\t\t =================\n\n");
    printf("\n\t\t\t\t 1. Saree--1200 Taka\n");
    printf("\n\t\t\t\t 2. Shirt--500 Taka\n");
    printf("\n\t\t\t\t 3. Pant--600 Taka\n");
    printf("\n\t\t\t\t 4. 3-Pic--1800 Taka\n");
    printf("\n\t\t\t\t 5. <= Back\n");
    printf("\n\n\t\t\t\t__________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d", &n);
    switch(n)
    {
    case 1:
        printf("Your order is : Saree || Price: 1200 Taka");
        break;

    case 2:
        printf("Your order is : Shirt || Price: 500 Taka");
        break;

    case 3:
        printf("Your order is : Pant || Price: 600 Taka");
        break;

    case 4:
        printf("Your order is : 3-Pic || Price: 1800 Taka");
        break;

    case 5:
        clothing();
        break;

    default:
        printf("Error!");

    }
}

void men()
{
    int n;
    printf("\n\n\n\t\t\t\t\t ===============\n");
    printf("\t\t\t\t\t | Men Section |");
    printf("\n\t\t\t\t\t ===============\n\n");
    printf("\n\t\t\t\t 1. Shirt--900 Taka\n");
    printf("\n\t\t\t\t 2. Pant--500 Taka\n");
    printf("\n\t\t\t\t 3. T-Shirt--300 Taka\n");
    printf("\n\t\t\t\t 4. Watch--600 Taka\n");
    printf("\n\t\t\t\t 5. <= Back\n");
    printf("\n\n\t\t\t\t__________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d", &n);
    switch(n)
    {
    case 1:
        printf("Your order is : Shirt || Price: 900 Taka");
        break;

    case 2:
        printf("Your order is : Pant || Price: 500 Taka");
        break;

    case 3:
        printf("Your order is : T-Shirt || Price: 300 Taka");
        break;

    case 4:
        printf("Your order is : Watch || Price: 600 Taka");
        break;

    case 5:
        clothing();
        break;

    default:
        printf("Error!");

    }
}


void children()
{
    int n;
    printf("\n\n\n\t\t\t\t\t ====================\n");
    printf("\t\t\t\t\t | Children Section |");
    printf("\n\t\t\t\t\t ====================\n\n");
    printf("\n\t\t\t\t 1. Shirt--500 Taka\n");
    printf("\n\t\t\t\t 2. Pant--500 Taka\n");
    printf("\n\t\t\t\t 3. Toy--1200 Taka\n");
    printf("\n\t\t\t\t 4. Watch--300 Taka\n");
    printf("\n\t\t\t\t 5. <= Back\n");
    printf("\n\n\t\t\t\t__________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        printf("Your order is : Shirt || Price: 500 Taka");
        break;

    case 2:
        printf("Your order is : Pant || Price: 500 Taka");
        break;

    case 3:
        printf("Your order is : Toy || Price: 1200 Taka");
        break;

    case 4:
        printf("Your order is : Watch || Price: 300 Taka");
        break;

    case 5:
        clothing();
        break;


    default:
        printf("Error!");
    }

}

void footwear()
{
    int n;
    printf("\n\n\n\t\t\t\t\t ====================\n");
    printf("\t\t\t\t\t | Footwear Section |");
    printf("\n\t\t\t\t\t ====================\n\n");
    printf("\n\t\t\t\t 1. Shoes--1500 Taka\n");
    printf("\n\t\t\t\t 2. Socks--200 Taka\n");
    printf("\n\t\t\t\t 3. Belt--300 Taka\n");
    printf("\n\t\t\t\t 4. Wallet--1200 Taka\n");
    printf("\n\t\t\t\t 5. <= Back\n");
    printf("\n\n\t\t\t\t__________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        printf("Your order is : Shoes || Price: 1500 Taka");
        break;

    case 2:
        printf("Your order is : Socks || Price: 200 Taka");
        break;

    case 3:
        printf("Your order is : Belt || Price: 300 Taka");
        break;

    case 4:
        printf("Your order is : Wallet || Price: 1200 Taka");
        break;
    case 5:
        clothing();
        break;

    default:
        printf("Error!");
    }

}

void jwelries()
{
    int n;
    printf("\n\n\n\t\t\t\t\t ===================\n");
    printf("\t\t\t\t\t | Jewelry Section |");
    printf("\n\t\t\t\t\t ===================\n\n");
    printf("\n\t\t\t\t 1. Neekless--2,50,000 Taka\n");
    printf("\n\t\t\t\t 2. Braselet--15000 Taka\n");
    printf("\n\t\t\t\t 3. Chain-- 5000 Taka\n");
    printf("\n\t\t\t\t 4. Diamond-Ring 20,000 Taka\n");
    printf("\n\t\t\t\t 5. <= Back\n");
    printf("\n\n\t\t\t\t__________________________________________\n\n");
    printf("\t\t\t\tEnter your choice: ");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        printf("Your order is : Neekless || Price: 2,50,000 Taka");
        break;

    case 2:
        printf("Your order is : Braselet || Price: 15000 Taka");
        break;

    case 3:
        printf("Your order is : Chain || Price: 5000 Taka");
        break;

    case 4:
        printf("Your order is : Diamond-Ring || Price: 20,000 Taka");
        break;
    case 5:
        clothing();
        break;

    default:
        printf("Error!");
    }
}

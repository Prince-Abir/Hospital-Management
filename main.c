#include <stdio.h>
#include <windows.h> //use of gotoXY()
#include <conio.h>   //use of delay(), getCh();
#include <ctype.h>   //use of toUpper(), toLower(),etc;
#include <string.h>  //use of Stringcmp(),Stringcpy(),StringLen,etc;
#include <stdlib.h>
#include <unistd.h>

void welcome_screen();
void title_screen();
void login_screen();
void mainmenu();
void add_rec();


FILE *SignUpName;
FILE *SignUpEmail;
FILE *SignUpPassword;

struct patient
{
    int age;
    char gender;
    char first_name[15];
    char last_name[15];
    char contract_number[14];
    char address[50];
    char doctor[20];
    char problem[20];
};
struct patient p;
int b, valid = 0;

int main()
{
    welcome_screen();
    title_screen();
    signup_screen();
}

//function for welcome Screen
void welcome_screen()
{
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t##############################################################");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\tWELCOME TO");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tSQUARE HOSPITAL LTD");
    printf("\n\t\t\t\t\t\t\t\t\t##############################################################");
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tPress any key to continue.....");
    getch();      //to hold the screen
    system("cls");
    signup_screen(); // to clear the screen
}

//function for title screen
void title_screen()
{
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t----------------------------------------------------");
    printf("\n\t\t\t\t\t\t\t\t\t\t\tSQUARE HOSPITAL LTD");
    printf("\n\t\t\t\t\t\t\t\t\t----------------------------------------------------");
}

void signup_screen()
{

    char FullName[30];
    char Email[30];
    char Password[30];
    char ConfirmPassword[30];
    int e = 0;



    do
    {

        title_screen();

        SignUpName = fopen("Names.txt","w");
        SignUpEmail = fopen("Emails.txt","w");
        SignUpPassword = fopen("Passwords.txt","w");

        printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tUsername: ");
        gets(FullName);

        printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tEmail: ");
        gets(Email);

        printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPassword: ");
        gets(Password);

        printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tConfirm Password: ");
        gets(ConfirmPassword);

        if (strcmp(Password, ConfirmPassword) == 0)
        {

                    fputs(FullName,SignUpName);

                    fputs(Email,SignUpEmail);

                    fputs(Password,SignUpPassword);

                    fclose(SignUpName);
                    fclose(SignUpEmail);
                    fclose(SignUpPassword);


                printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\tYou Have Successfully Signed Up-------");
                sleep(3);
                system("cls");
                login_screen();
            }

        else
        {

            printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPassword Does not Match! Try Again ):");
            e++;
            system("cls");
            signup_screen();

        }
    } while (e <= 10);

    if (e > 10)
    {
        system("cls");
    }
}

//function for login screen
void login_screen()
{

    int e = 0;
    char email[30];
    char password[30];

    char OriginalPassword[30];
    char OriginalEmail[30];

    SignUpEmail = fopen("Emails.txt","r");
    SignUpPassword = fopen("Passwords.txt","r");

    fgets(OriginalEmail,sizeof(OriginalEmail),SignUpEmail);
    fgets(OriginalPassword,sizeof(OriginalPassword),SignUpPassword);



    do
    {

        title_screen();
        printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t.....Login to Your Account.....");
        printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tEmail : ");
        gets(email);
        printf("\n\n\t\t\t\t\t\t\t\t\t\tPassword : ");
        gets(password);

        if (strcmp(email,OriginalEmail) == 0 && strcmp(password, OriginalPassword) == 0)
        {

            printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tLogin Successful......");
            sleep(3);
            system("cls");
            mainmenu();
        }

        else
        {

            printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tLogin Failed!Try Again");
            sleep(2);
            e++;
            system("cls");
            login_screen();
        }
    } while (e <= 5);
    if (e > 5)
    {
        printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t   You have cross the limit!You cannot login Now!");
    }
}


//main Menu Starts from here
void mainmenu()
{
    title_screen();
    int choose;

    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t1. Add patients Record");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t2. List patients Record");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t3. Search patients Record");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t4. Edit patients Record");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t5. Delete patients Record");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t6. Exit");
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tChoose 1 to 6: ");
    scanf("%i", &choose);
    switch (choose)
    {
    case 1:
        add_rec();

    case 2:
        printf("\n\n\t\t\t\t\t\t\t\t\t\tList patients Record");


    case 3:
        printf("\n\n\t\t\t\t\t\t\t\t\t\tSearch patients Record");


    case 4:
        printf("\n\n\t\t\t\t\t\t\t\t\t\tEdit patients Record");


    case 5:
        printf("\n\n\t\t\t\t\t\t\t\t\t\tDelete patients Record");

    case 6:
        printf("\n\n\t\t\t\t\t\t\t\t\t\tExit");


    default:
        printf("\n\n\t\t\t\t\t\t\t\t\t\tInvalid Input!");
    }
    system("cls");
}

void add_rec()
{
    system("cls");
    FILE *file;
    file = fopen("Record.dat", "a");
    title_screen();
    printf("\n\n\n\n\n\t\t\t\t\t\t\t.....................Add Patient Record!.....................");

//----------------------------------------First Name--------------------------------------------//
A:
    title_screen();
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tEnter First Name: ");
    gets(p.first_name);
    system("cls");
    p.first_name[0] = toupper(p.first_name[0]);

    if (strlen(p.first_name) > 15 || strlen(p.first_name) <= 2)
    {

        title_screen();
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tMaximum range of First name is 20 and Minimum range is 3");
        goto A;
    }
    else
    {
        for (b = 0; b < strlen(p.first_name); b++)
        {
            if (isalpha(p.first_name[b]))
            {
                valid = 1;
            }
            else
            {

                valid = 0;
                break;
            }
        }

        if (!valid)
        {

            title_screen();
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t   Invalid Input!First name cannot contain Numbe or any Operator");
            goto A;
        }
    }
    system("cls");

    //-------------------------------------Last Name-------------------------------------------//
    title_screen();
B:
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tEnter Last Name: ");
    gets(p.last_name);
    system("cls");
    p.last_name[0] = toupper(p.last_name[0]);

    if (strlen(p.last_name) > 15 || strlen(p.last_name) <= 2)
    {

        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t max range of Last name is 20 and min range is 2");
        goto B;
    }
    else
    {
        for (b = 0; b < strlen(p.last_name); b++)
        {
            if (isalpha(p.last_name[b]))
            {
                valid = 1;
            }
            else
            {

                valid = 0;
                break;
            }
        }

        if (!valid)
        {

            printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tInvalid Input!Last name cannot contain Numbe or any Operator");
            goto B;
        }
    }
    system("cls");

    //------------------------------------Gender-------------------------------------//
    title_screen();
C:
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tEnter Your Gender(M/F): ");
    scanf(" %c", &p.gender);
    system("cls");

    if (toupper(p.gender) == 'M' || toupper(p.gender) == 'F')
    {

        goto D;
    }
    else
    {
        title_screen();
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t     Invalid Input!For male Choose 'M' and For Female Choose 'F'");
        goto C;
    }
    system("cls");

D:
    title_screen();
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tEnter your Age: ");
    scanf("%d", &p.age);
    system("cls");

    if (p.age <= 0 || p.age > 200)
    {
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tAge cannot be Less than 0 or Grater than 200!");
        goto D;
    }
    else
    {
        goto E;
    }
    system("cls");

//-------------------------------------Contact Number-------------------------------------------//
E:
    title_screen();
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tEnter contact number: ");
    scanf("%s", &p.contract_number);

    if (strlen(p.contract_number) > 14 || strlen(p.contract_number) < 11)
    {

        printf("n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tMax range of contact number is 14");
        goto E;
    }
    else
    {
        for (b = 0; b < strlen(p.contract_number); b++)
        {
            if (!isalpha(p.contract_number[b]))
            {
                valid = 1;
            }

            else
            {

                valid = 0;
                break;
            }
        }

        if (!valid)
        {

            printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tInvalid Input!contact number cannot contain character");
            goto E;
        }
    }
    system("cls");

    //-------------------------------------Address-------------------------------------------//
    do
    {

        title_screen();
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tEnter Your Address: ");
        scanf("%s", &p.address);
        system("cls");

        p.address[0] = toupper(p.address[0]);

        if (strlen(p.address) > 50 || strlen(p.address) <= 3)
        {

            valid = 0;
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tMax range of Address is 50 and min range is 3");
        }
        else
        {

            valid = 1;
            break;
        }
    }

    while (!valid);
    system("cls");

//-------------------------------------Doctor Name-------------------------------------------//
F:
    system("cls");
    title_screen();
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tEnter Doctor Name: ");
    gets(p.doctor);
    system("cls");

    p.doctor[0] = toupper(p.doctor[0]);

    if (strlen(p.doctor) > 15 || strlen(p.doctor) <= 2)
    {

        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tMaximum range of Doctor name is 15 and Minimum range is 3");
        getch();
        goto F;
    }
    else
    {
        for (b = 0; b < strlen(p.doctor); b++)
        {
            if (!isalpha(p.doctor[b]))
            {

                valid = 0;
            }
            else
            {

                valid = 1;
                break;
            }
        }

        if (!valid)
        {
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tInvalid Input!Doctor name must be in Character");
            getch();
            goto F;
        }
    }
    system("cls");

    //-------------------------------------Patient Problem-------------------------------------------//
    do
    {

        title_screen();
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tEnter patient's problem: ");
        scanf("%s", &p.problem);
        system("cls");

        p.problem[0] = toupper(p.problem[0]);

        if (strlen(p.problem) > 50 || strlen(p.problem) <= 3)
        {

            valid = 0;
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tMax range of character is 50 and min range is 3");
        }
        else
        {

            valid = 1;
            break;
        }
    }

    while (!valid);
    system("cls");
}

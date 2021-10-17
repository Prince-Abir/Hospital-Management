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



void TakingFirstName();
void TakingLastName();
void TakingGender();
void TakingAge();
void TakingNumber();
void TakingAddress();
void TakingDoctorName();
void TakingProblem();



FILE *SignUpName;
FILE *SignUpEmail;
FILE *SignUpPassword;

struct patient
{
    int age;
    char gender;
    char first_name[15];
    char last_name[15];
    char contract_number[20];
    char address[50];
    char doctor[20];
    char problem[20];
};
struct patient p;
int b, valid = 0;

int main()
{
    //welcome_screen();
    //title_screen();
    //signup_screen();

    add_rec();
}

void gotoXY(int x,int y){

    COORD pos = {x , y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
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
            sleep(2);
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

            printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tLoged In Successfully......");
            sleep(2);
            system("cls");
            mainmenu();
        }

        else
        {

            printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tEmail or Password Does not Match! Try Again ):");
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
        break;

    case 2:
        printf("\n\n\t\t\t\t\t\t\t\t\t\tList patients Record");
        break;


    case 3:
        printf("\n\n\t\t\t\t\t\t\t\t\t\tSearch patients Record");
        break;


    case 4:
        printf("\n\n\t\t\t\t\t\t\t\t\t\tEdit patients Record");
        break;


    case 5:
        printf("\n\n\t\t\t\t\t\t\t\t\t\tDelete patients Record");
        break;

    case 6:
        printf("\n\n\t\t\t\t\t\t\t\t\t\tExit");
        break;


    default:
        printf("\n\n\t\t\t\t\t\t\t\t\t\tInvalid Input!");
        getch();
        mainmenu();
    }

}

void add_rec()
{
    TakingFirstName();
    TakingLastName();
    TakingGender();
    TakingAge();
    TakingNumber();
    TakingAddress();
    TakingDoctorName();
    TakingProblem();
}


//----------------------------------------Add Record Section Here--------------------------------------------//

//----------------------------------------First Name--------------------------------------------//
void TakingFirstName()
{
    FILE *AddPatientRecord;
    AddPatientRecord = fopen("PatientRecord.dat","a");


    B:
    title_screen();
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t..............Add Patient Record!................");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tEnter First Name: ");
    gets(p.first_name);

    p.first_name[0] = toupper(p.first_name[0]);

    if (strlen(p.first_name) > 15 || strlen(p.first_name) <= 2)
    {

        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t max range of First name is 20 and min range is 2");
        sleep(2);
        system("cls");
        goto B;
    }
    else
    {
        for (b = 0; b < strlen(p.first_name); b++)
        {
            if (isalpha(p.first_name[b]))
            {
                system("cls");
                TakingLastName();
            }
            else
            {

                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tInvalid Input!First name cannot contain Numbe or any Operator");
                sleep(2);
                system("cls");
                goto B;
            }
        }

    }
}


//-------------------------------------Last Name-------------------------------------------//
void TakingLastName()
{
    B:
    title_screen();
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t..............Add Patient Record!................");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tEnter Last Name: ");
    gets(p.last_name);

    p.last_name[0] = toupper(p.last_name[0]);

    int length = strlen(p.last_name);

    if(length>15 || length<=2)
    {
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t max range of Last name is 20 and min range is 2");
        sleep(2);
        system("cls");
        goto B;

    }
    else
    {
        for (b=0; b<length; b++)
        {
            if (isalpha(p.last_name[b]))
            {
                system("cls");
                TakingGender();
            }
            else
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tInvalid Input!Last name cannot contain Numbe or any Operator");
                sleep(2);
                system("cls");
                goto B;
            }
        }


    }
}



//------------------------------------Gender-------------------------------------//
void TakingGender()
{
    C:
    title_screen();
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t..............Add Patient Record!................");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tEnter Your Gender(M/F): ");
    scanf("%c",&p.gender);

    if (toupper(p.gender) == 'M' || toupper(p.gender) == 'F')
    {
        system("cls");
        TakingAge();
    }
    else
    {
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t     Invalid Input!For male Choose 'M' and For Female Choose 'F'");
        sleep(2);
        system("cls");
        goto C;
    }
}



//------------------------------------Age-------------------------------------//
void TakingAge()
{

    D:
    title_screen();
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t..............Add Patient Record!................");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tEnter your Age: ");
    scanf("%d", &p.age);

    if (p.age <= 0 || p.age > 200)
    {
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tAge cannot be Less than 0 or Grater than 200!");
        sleep(2);
        system("cls");
        goto D;
    }
    else
    {
        system("cls");
        TakingNumber();
    }

}



//-------------------------------------Contact Number-------------------------------------------//
void TakingNumber()
{

    title_screen();
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t..............Add Patient Record!................");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tEnter Contact Number: ");
    scanf("%s", &p.contract_number);

    int numLength = strlen(p.contract_number);

        for(b = 0; b<numLength; b++)
        {
            if(!isalpha(p.contract_number[b]))
            {
                if(numLength == 11)
                    {
                        system("cls");
                        TakingAddress();
                    }
                    else{
                        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t The Length of Number must be 11! Try Again ");
                        sleep(2);
                        system("cls");
                        TakingNumber();
                    }

            }
            else
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tInvalid Input!Number cannot contain any Character or Operator");
                    sleep(2);
                    system("cls");
                    TakingNumber();
                    }

        }
}




//-------------------------------------Address-------------------------------------------//

    void TakingAddress()
    {

                title_screen();
                printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t..............Add Patient Record!................");
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tEnter Your Address: ");
                gets(p.address);

                int addLength = strlen(p.address);

                p.address[0] = toupper(p.address[0]);

                if (addLength < 3)
                {
                    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tMax range of Address is 50 and min range is 3");
                    sleep(2);
                    system("cls");
                    TakingAddress();
                }
                else
                {
                    system("cls");
                    TakingDoctorName();
                }
}





//-------------------------------------Doctor Name-------------------------------------------//

void TakingDoctorName()
{
    title_screen();
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t..............Add Patient Record!................");
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tEnter Doctor Name: ");
    gets(p.doctor);

    p.doctor[0] = toupper(p.doctor[0]);

    if (strlen(p.doctor) <= 2)
    {

        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tMaximum range of Doctor name is 15 and Minimum range is 3");
        sleep(2);
        system("cls");
        TakingDoctorName();

    }
    else{

        for (b = 0; b < strlen(p.doctor); b++)
        {
            if(isalpha(p.doctor[b]))
            {
                system("cls");
                TakingProblem();

                }
            else
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tInvalid Input!Doctor name must be in Character");
                sleep(2);
                system("cls");
                TakingDoctorName();
                }
        }
    }
}

//-------------------------------------Patient Problem-------------------------------------------//

    void TakingProblem()
    {
    title_screen();
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t..............Add Patient Record!................");
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tEnter Disease Name : ");
    gets(p.problem);

    p.problem[0] = toupper(p.problem[0]);

    if (strlen(p.doctor) <= 2)
    {

        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tMaximum range of Disease Name is 100 and Minimum range is 3");
        sleep(2);
        system("cls");
        TakingProblem();

    }
    else{

        for (b = 0; b < strlen(p.problem); b++)
        {
            if(isalpha(p.problem[b]))
            {
                system("cls");
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tCode is Working Good!");
                getch();
                exit(0);

                }
            else
            {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tInvalid Input!Disease name must be in Character");
                sleep(2);
                system("cls");
                TakingProblem();
                }
        }
    }
}


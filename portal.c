#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct std_reg
{
    char eno [12];
    char fname [20];
    char lname [20];
    char mother [20];
    char collage [50];
};

struct staff
{
    char username [20];
    char password [20];
};

struct mark
{
    char m_eno [20];
    char das [3];
    char rdbms [3];
    char python [3];
    char ds [3];
};

void reg ();
void staff ();
void check ();
void mark (char eno2 []);
void mark_check (char eno1 []);
void display (char eno1 []);
void staff_display (char username1 [], char password1 []);

int main(){
    int ch;
    
home:
    system("cls");
    printf("\n\n                                                                                STUDENT PORTAL");
    printf("\n\n                                    ****************************************************************************************************");
    printf("\n\n                                                                           1... New Registration");
    printf("\n\n                                                                           2... Staff Registration");
    printf("\n\n                                                                           3... Student Registration");
    printf("\n\n                                                                           4... exit");
    printf("\n\n                                                                             Enter your choice : ");
    scanf("%d",&ch);

    switch (ch)
    {
    case 1:
        reg();
        break;

    case 2:
        staff();
        break;

    case 3:
        check();
        break;

    case 4:
        exit(0);
        
    default:
        printf("\n\nPlease, enter the rigth choice !!!");
        break;
    }

    printf("\n\n                                                                          Press Enter to go");
    getch();

goto home;
}

void reg(){
    system("cls");
    FILE *fp, *fu;
    struct std_reg s1;

    fp = fopen("std_info.txt", "ab");

    printf("\n\n                                                                           NEW REGISTRATION FORM");
    printf("\n\n                                    ****************************************************************************************************");
    printf("\n\n                                                         Enter your new Enrollment no. : ");
    scanf("%s",s1.eno);
    
    printf("\n\n                                                                Enter your first name  : ");
    scanf("%s",s1.fname);

    printf("\n\n                                                                  Enter your last name : ");
    scanf("%s",s1.lname);

    printf("\n\n                                                               Enter your collage name : ");
    scanf("%s",s1.collage);

    printf("\n\n                                    ****************************************  USER CREATED  ********************************************");

    fwrite(&s1, sizeof(s1), 1, fp);

    fclose(fp);
}

void check(){
    system("cls");
    struct std_reg s1;
    FILE *fp, *fu;
    fp = fopen("std_info.txt","rb");
    
    char eno1 [20];

    printf("\n\n                                                                                   STUDENT LOGIN PAGE");
    printf("\n\n                                                                ****************************************************");
    printf("\n\n                                                                          Enter your enrollment no. : ");
    scanf("%s",&eno1);
    
    while (fread(&s1, sizeof(s1), 1, fp))
    {
        if (strcmp(eno1,s1.eno) == 0)
        {
            display(eno1);
        }
        
    }
    fclose(fp);
    
}

void display(char eno1 []){
    system("cls");

    FILE *fp;
    int ch;
    struct std_reg s1;
    struct mark m1;

    fp = fopen("std_info.txt", "rb");
    printf("\n%d",eno1);
    while (fread(&s1, sizeof(s1), 1 ,fp))
    {
        if (strcmp(eno1,s1.eno) == 0)
        {
        h_page:

            system("cls");
            printf("\n\n                                                                           STUDENT LOGIN PAGE");
            printf("\n\n                                    ****************************************************************************************************");
            printf("\n\n                                                                 Your enrollment no. : %s",s1.eno);
            printf("\n\n                                                        =================================================");

            printf("\n\n                                                                           1... Your Details");
            printf("\n\n                                                                           2... Your marksheet");
            printf("\n\n                                                                           3... exit");
            printf("\n\n                                                                           Enter your choice : ");
            scanf("%d",&ch);

            switch (ch)
            {
            case 1:

                printf("\n\n                                                                           DETAILS PAGE");
                printf("\n\n                                    ****************************************************************************************************");
                printf("\n\n                                                                   Enrollment no. : %s",s1.eno);
                printf("\n\n                                                                       First name : %s",s1.fname);
                printf("\n\n                                                                        Last name : %s",s1.lname);
                printf("\n\n                                                                     Collage name : %s",s1.collage);
                
                printf("\n\n                                                                       == Press Enter to go ==");
                getch();
                break;
            
            case 2:
                mark_check(eno1);
                break;

            case 3:
                return;

            default:
                printf("\n\nPlease, enter the rigth choice !!!");
                break;
            }
        goto h_page;
        }
        
    }

    fclose(fp);
    
}

void staff (){
    FILE *fp,*fu;
    struct staff s1;

    char username1 [20];
    char password1 [20];

    fp = fopen("staff.txt", "rb");
    printf("\n\n                                                                           STAFF LOGIN PAGE");
    printf("\n\n                                    ****************************************************************************************************");
    printf("\n\n                                                                       enter your username : ");
    scanf("%s",&username1);
    printf("\n\n                                                                       enter your password : ");
    scanf("%s",&password1);

    while (fread(&s1, sizeof(s1), 1,fp));
    {
        if (strcmp(username1,s1.username) == 0)
        {
            if (strcmp(password1,s1.password) == 0)
            {
                staff_display(username1, password1);
            }
            else{
                printf("\n\n         please, enter right password   ");
            }
            
        }
        else{
            printf("\n\n           please, enter rigth username");
        }
        
    }
    fclose(fp);
}

void staff_display (char username1 [], char password1 []){
    FILE *fp,*fu;
    struct staff s1;
    int ch;
    fp = fopen("staff.txt" , "rb");

    while (fread(&s1, sizeof(s1), 1,fp));
    {
        if (strcmp(username1,s1.username) == 0)
        {
            if (strcmp(password1,s1.password) == 0)
            {
                system("cls");
                staff:
                printf("\n\n                                                                      WELCOME, SIR");
                printf("\n\n                            ****************************************************************************************************");
                printf("\n\n                                                                  1... For enter student mark");
                printf("\n\n                                                                  2... Exit");
                printf("\n\n                                                                Enter your choice : ");
                scanf("%d",&ch);

                switch (ch)
                {
                case 1:
                    fp = fopen("mark.txt", "ab");
                    struct mark m1;
                    
                    printf("\n\n                 Enter enrollment no. : ");
                    scanf("%s",&m1.m_eno);
                    printf("\n\n");
                    printf("                     Enter DS mark : ");
                    scanf("%s",&m1.ds);
                    printf("                     Enter DSA mark : ");
                    scanf("%s",&m1.das);
                    printf("                     Enter PYTHON mark : ");
                    scanf("%s",&m1.python);
                    printf("                     Enter RDBMS mark : ");
                    scanf("%s",&m1.rdbms);

                    fwrite(&m1, sizeof(m1), 1, fp);
                    fclose(fp);

                    break;
                
                case 2:
                    return;
                default:
                    break;
            }
            goto staff;
            }
        }
    }
    fclose(fp);
}

void mark_check (char eno1 []){

    FILE *fp, *fu;
    struct mark m1;

    fp = fopen("mark.txt", "rb");
    ;

    while (fread(&m1, sizeof(m1), 1, fp))
    {
        if (strcmp(eno1, m1.m_eno) == 0)
        {
            mark(eno1);
        }
        
    }
    fclose(fp);
}

void mark (char eno1 []){

    struct mark m1;
    FILE *fp,*fu;
    fp = fopen("mark.txt", "rb");

                while (fread(&m1, sizeof(m1), 1, fp))
                {
                    if (strcmp(eno1,m1.m_eno) == 0)
                    {
                        printf("\n\n                                                                 Your enrollment no. : %s",m1.m_eno);
                        printf("\n\n");
                        printf("\n\n                                                               ********************************");
                        printf("\n\n                                                               **      Enter DS mark : %s    **",m1.ds);
                        printf("\n\n                                                               **     Enter DSA mark : %s    **",m1.das);
                        printf("\n\n                                                               **  Enter PYTHON mark : %s    **",m1.python);
                        printf("\n\n                                                               **   Enter RDBMS mark : %s    **",m1.rdbms);
                        printf("\n\n                                                               ********************************");
                    }
                    
                }
                printf("\n\n                                                                       == Press Enter to go ==");
                getch();
                fclose(fp);
}
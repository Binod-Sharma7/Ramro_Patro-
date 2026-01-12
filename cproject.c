#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
char username[10];
int year,month,day;
void notes();
void datesection();

void logo()
{
    system("cls");
    printf("\n\n");
    printf("\t\t\t #   #####\n");
    printf("\t\t\t #   #\n");
    printf("\t\t\t #########\n");
    printf("\t\t\t     #   #\n");
    printf("\t\t\t #####   #\n");
    printf("\t\t\tRAMRO PATRO\n\n");
}

void logosmall()
{
    system("cls");
    printf("# RAMRO PATRO_________________________________\n");
}

void loading()
{
     int i;
    printf("\n\t\tLoging in...\n");
    printf("\t\t");
    for ( i = 0; i < 20; i++)
    {
        printf("#");
        _sleep(20);
    }
}

void homepage()
{
    //this page consist all the availabel features of program
    logo();
    printf("\tWelcome %s!!!\n\n",username);
    printf("\t\t1.Calendar\n");
    printf("\t\t2.Rashifal\n");
    printf("\t\t3.News\n");
    printf("\t\t4.Notes\n");
    printf("\t\t5.Age calculator\n");
    printf("\t\t6.Date converter\n");
    printf("\t\t7.Logout\n\n");
}
// Function to check if a user exists in the user data file
int userExists(const char *username) {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        return 0; // File not found or cannot be opened
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ":");
        if (strcmp(token, username) == 0) {
            fclose(file);
            return 1; // User found
        }
    }

    fclose(file);
    return 0; // User not found
}

// Function to register a new user
void registerUser(const char *username, const char *password) {
    FILE *file = fopen("users.txt", "a");
    if (file == NULL) {
        printf("Error: Cannot open file for writing.\n");
        return;
    }

    fprintf(file, "%s:%s\n", username, password);
    fclose(file);
}

// Function to authenticate user login
int login1(const char *username, const char *password) {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        return 0; // File not found or cannot be opened
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ":");
        if (strcmp(token, username) == 0) {
            token = strtok(NULL, ":");
            token[strcspn(token, "\n")] = 0; // Remove newline character, if present
            if (strcmp(token, password) == 0) {
                fclose(file);
                return 1; // Login successful
            }
        }
    }

    fclose(file);
    return 0; // Login failed
}

void login()
{
    //this function is to login user to system
    int check;
    logo();
    datesection();
    char password[10];
    printf("\n\n\t\t\tLogin!\n");
    printf("\n\t\tUsername: ");
    scanf("%s",username);
    printf("\t\tPassword: ");
    scanf("%s",password);
   //if ( strcmp(username,defult)== 0 && strcmp(password,defult)==0)
   if (login1(username, password))
   {
        loading();//this is sucessful login
        homepage();
   }
    else
    {
        printf("\n\tInvalid username or password!!!\n\n");
        printf("Press 1 to sign up!!!  ");
        scanf("%d",&check);
        if( check == 1)
        {
                reenter:
                logosmall();
                printf("\n\n\t\tSign up!\n\n");
                printf("\tEnter username: ");
                scanf("%s", username);
                if (userExists(username)) 
                {
                    printf("\n\tError~~ User already exists.\n");
                    char hold;
                    hold=getch();
                    goto reenter;
                }
                else 
                {
                    printf("\tEnter password: ");
                    scanf("%s", password);
                    registerUser(username, password);
                    printf("\n\tRegistration successful!\n");
                    sleep(1);
                    loading();
                    homepage();
                
                }
        }
        else
        {
            login();
        }
    }
}

void datesection()
{
    time_t currentTime;
    struct tm *localTime;
    
    // Get the current time in seconds since the epoch
    currentTime = time(NULL);
    
    // Convert the time to a more readable format
    localTime = localtime(&currentTime);

    //getting vlaues gloabally to reuse
    year=localTime->tm_year + 1900;
    month=localTime->tm_mon + 1;
    day=localTime->tm_mday;
    
    // Print the current time in a readable format
    printf(" %04d-%02d-%02d\n %02d:%02d\n",year,month,day,
           localTime->tm_hour, localTime->tm_min);
           int t= localTime->tm_hour;
           if (t<=11)
            printf(" Good morning!");
           else if (t<=16)
            printf(" Good afternoon!");
           else
            printf(" Good evening!");
}

void calender()
{
    logosmall();
    printf("\n\t\t*****CALENDAR*****\n\n");
    printf("%d,Aug\n",year);
    printf("------------------------------------------------------\n");
    printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
    printf("------------------------------------------------------\n");
    int i=1,j,k=1;
    while(i<30)
    {
        for(j=0;j<7;j++)
        {
            if(k<3)
            {
                printf(" \t");
                k++;
            }
            else
            {
                if(i<30)
                {
                    if (i==day)
                    {
                     printf("\033[31m %d\033[0m\t",i);
                    }
                else
                printf(" %d\t",i);
                i++;
                }
        }
    }
    printf("\n");
    }
    printf("\nPress any key to exit... ");
    char hold;//we hold screen here,if we press any key then next statement will execute
    hold=getch();
    homepage();
}

int horoscope()
{
    logosmall();
    printf("\n\t\t\tHoroscope\n\n");
    int n;
    printf("1.Aries\n2.Taraus\n3.Gemini\n4.Cancer\n5.Leo\n6.Virgo\n7.Libra\n8.Scorpio\n9.Sagittarius\n10.Capricorn\n11.Aquarius\n12.Pisces\n0.Exit\n\n");
      printf("Enter your horoscope \n");
          scanf("%d",&n);
          if (n==0){
          homepage();
            return 0;
          }
            logosmall();
             printf("\n\t\t****HOROSCOPE****\n\n");
      switch(n)
      {
        case 1:
        printf("Aries:\nYou're a social creature, Aries, and today you can expect to attract a lot of attention.\nYou're feeling good and looking even better - and don't think that people don't notice! Make it a point\n to get out and mingle with others. You're a talented, capable person in your own right, but you really \nshine when you're with others. This is especially true today.\n\n");
        break;
        case 2:
        printf("Taraus:\n You have a romantic soul, Taurus. Today your thoughts are on love and romance. You may be \nthinking of that special someone in your life, grateful that you've found each other. Or you may wish you had \nsomeone important in your life and spend a good part of the day plotting how to find a mate. If you're serious \nabout settling down, draw on all of your resources to make it happen.\n\n");
        break;
        case 3:
        printf("Gemini:\nSomething big could be occurring close to home today, Gemini. It would be advisable to stay inside, if possible, or at least not stray too far. Traffic may be gridlocked and the sidewalks crowded with pedestrians anxious for a closer look. Use this self-imposed . Play music and have fun while you organize bookshelves and clear the clutter from your closets.\n\n");
        break;
        case 4:
         printf("Cancer:\n You have hidden talents that may be revealed to you today, Cancer. Perhaps collaboration with someone new has you doing things you never thought you could. Perhaps you discover a talent for writing, graphic design, or money management. You can't help but delight in this discovery, as it opens up a world of new possibilities. You don't need to take action now. Revel in your untapped potential.\n\n");
        break;
        case 5:
        printf("Leo:\nYou're a kind, caring individual, Leo. Today your concern for others may be so strong that you take steps to do something concrete to save, if not the world, at least a few of the individuals in it. You may hear of a worthy cause that's about to fold for lack of volunteers. You could turn out to be just the savior they need. One person truly can make a difference. You can prove it today.\n\n");
        break;
        case 6:
        printf("Virgo:\nToday you may develop a deeper understanding of what's really important to you, Virgo. You may be surprised by what you discover. The material means far less to you than the spiritual. It may have taken you a while to learn this, but now there's no going back. Your possessions feel like dead weight. The mere thought of your family and friends fills your heart with love and light.\n\n");
        break;
        case 7:
        printf("Libra:\nYour life is likely to enlarge today, Libra, either through a new group affiliation or people you meet. You may be invited to a party where a whole world of new and exciting events opens up to you. You may be reunited with a good friend from your past who can open all sorts of professional doors for you. Be receptive to anyone and everyone you meet.\n\n");
        break;
        case 8:
         printf("Scorpio:\nSometimes it's better to be lucky than smart, Scorpio. You'll learn this today as good fortune puts you in the right place at the right time. You may meet someone who makes a big difference to your career. Perhaps he or she turns you on to a good job prospect or introduces you to someone who ends up being a business partner. Your life may change if you're open to possibilities.\n\n");
         break;
         case 9:
         printf("Sagittarius:\nBe open to any invitations that come your way or any new people you meet. Change is in the air for you, Sagittarius, and you need only be receptive in order for it to come about. You may even meet someone at a social event who winds up being your partner for life. Explore all your interests and trust your intuition, for it will be a reliable guide.\n\n");
         break;
         case 10:
         printf("Capricorn:\nToday you may wake up and realize that there is serious room for improvement, Capricorn. If decorating isn't your strong suit, why not call in the professionals? In the meantime, there's a lot you can do by simply clearing away the clutter and reorganizing your bookcases in a more attractive way. Mingle some artwork and knickknacks among the books for a more interesting visual effect.\n\n");
         break;
         case 11:
          printf("Aquarius:\nYou tend to keep to yourself, Aquarius, but today you could be inspired to join a group activity. Perhaps some friends have invited you to come out for drinks. Or maybe a neighbor asked you to consider joining a neighborhood organization. Whatever the scenario, all signs indicate that any group activity you join will be worthwhile. You will do some good and likely make new friends, too.\n\n");
          break;
          case 12:
           printf("Pisces:\n Technology is highlighted for you today, Pisces. It could be that you install a new phone or computer system, which will make life just a bit easier. Or perhaps you decide to take a course to learn to master a technical area that has been difficult for you to grasp. Whatever you do or learn today is bound to make you happier and more productive.\n\n");
           }  
    printf("\nPress any key to exit... ");
    char hold;//we hold screen here,if we press any key then next statement will execute
    hold=getch();
    horoscope();
}

void news()
{
    logosmall();
    printf("\n\t\t****NEWS****\n\n");
    FILE *n;
    char s;
    n=fopen("news.txt","r");
    if (n==NULL)
    printf("error\n");
    while((s=fgetc(n))!=EOF)
    {
        printf("%c",s);
        _sleep(1);
    }
    fclose(n);    
    printf("\nPress any key to exit... ");
    char hold;//we hold screen here,if we press any key then next statement will execute
    hold=getch();
    homepage();
}

void readingnote()
{
    FILE * fptr;
char s;
fptr=fopen("note.txt","r");
while((s=fgetc(fptr))!=EOF)
{
    printf("%c",s);
}
fclose(fptr);
}

void addnote()
{
FILE * fptr;
char s;
logosmall();
printf("\n\t\t*****NOTES*****\n\n");
fptr=fopen("note.txt","a");
printf("Enter your note:\n");
fflush(stdin);
fputs("\n#",fptr);
while((s=getchar())!='\n')
{
    fputc(s,fptr);
}
fclose(fptr);
notes();
} 

void notes()
{
    logosmall();
    int value;
    printf("\n\t\t*****NOTES*****\n\n");
    readingnote();
    printf("\n\n\n\t1.Add note\n\t2.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&value);
    if ( value == 1)
    {
        addnote();
    }
    homepage();
}

void agecalculator()
{
    int y,m,d;
    logosmall();
    printf("\n\t*****AGE CALCULATOR*****\n\n");
    printf("  Enter your date of birth in AD...\n\n");
    printf("\tYear : ");
    scanf("%d",&y);
    printf("\tMonth: ");
    scanf("%d",&m);
    printf("\tDay  : ");
    scanf("%d",&d);
    
    int a,b,c;
    a=year-y;
    b=month-m;
    c=day-d;
    if(c<0)
    {
        c=c+30;
        b=b-1;
    }
    if(b<0)
    {
        b=b+12;
        a=a-1;
    }
    printf("\n  Your age is %d years %d months %d days\n",a,b,c);
    printf("\nPress any key to exit... ");
    char hold;//we hold screen here,if we press any key then next statement will execute
    hold=getch();
    homepage();

}

void dateconverter()
{
    logo();
    printf("\n\t*****DATE CONVERTER*****");
    printf("\n\n\tComing soon!!!");
    char hold;//we hold screen here,if we press any key then next statement will execute
    hold=getch();
    homepage();
}
void about()
{
    logo();
    printf("\n\tThis is a mini c project!\nRamro patro is a basic calendar software to demonstrate\nc language skills in software interface and file handeling.\nThis 1st sem c project developed my roomies Binod and Chhatra\nfrom scratch is somehow inspired by famous software hamro patro,\n also some online sources are refrence to aid our little knowledge!\n");
    printf("\nPress any key to exit... ");
    char hold;//we hold screen here,if we press any key then next statement will execute
    hold=getch();
    homepage();

}
int main()
{
    login();
    int choice;
    repeat:
    printf("Enter your choice(1-7): ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
    calender();
    break;
    case 2:
    horoscope();
    break;
    case 3:
    news();
    break;
    case 4:
    notes();
    break;
    case 5:
    agecalculator();
    break;
    case 6:
    dateconverter();
    break;
    case 7:
    login();
    break;
    default:
    about();
    break;
    }
    goto repeat;
    return 0;
}
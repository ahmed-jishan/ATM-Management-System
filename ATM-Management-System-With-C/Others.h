///----------------------///
#include<time.h>        ///
#include<conio.h>      ///
#include<stdlib.h>    ///
#include<string.h>   ///
#include<windows.h> ///
///----------------///


void main_option();
void admin_login();
void user_login_option();
void user_login();
void user_regist();
void admin_menu();
void user_menu(char a[15]);
/// Admin accessible function.....
void creat_acc();
void delete_acc();
void search_option();
void search_acn();
void search_name();
void acc_list();
/// User accessible function.......
void check_bal(char a[15]);
void withdraw_bal(char a[15]);
void deposite(char a[15]);
void change_pass(char a[15]);

void Exit_p();

COORD coord = {0,0};
FILE *fp,*ft;
int isFound=0;
int notfound=0;
int i,j,k;

struct User{
    char acn[15];
    char name[30];
    char phone[15];
    double bal;
};
struct user{
    char acc[15];
    char pass[15];
};
struct User us;
struct user use;

void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void Full_Screen(){
    keybd_event(
                VK_MENU,
                0x38,
                0,0
                );
    keybd_event(
                VK_RETURN,
                0x1c,
                0,0
                );
    keybd_event(
                VK_RETURN,
                0x1c,
                KEYEVENTF_KEYUP,
                0
                );
    keybd_event(
                VK_MENU,
                0x38,
                KEYEVENTF_KEYUP,
                0
                );
    return;
}
void ClearConsoleToColors(int ForgC, int BackC){

     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     ///Get the handle to the current output buffer...
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
      /* This is used to reset the carat/cursor to the top left.
      * COORD cord = {0, 0};
      * A return value... indicating how many chars were written
      *   not used but we need to capture this since it will be
      *   written anyway (passing NULL causes an access violation).*/
     DWORD count;
     ///This is a structure containing all of the console info
     /// it is used here to find the size of the console.
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     ///Here we will set the current color
     SetConsoleTextAttribute(hStdOut, wColor);
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          ///This fills the buffer with a given character (in this case 32=space).
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
          ///This will set our cursor position for the next print statement.
          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}
void SetColor(int ForgC){
     WORD wColor;
     ///We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     ///We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
        ///Mask out all but the background attribute, and add in the foreground color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
void clearLine(int j){
    int i;
    for(i=51;i<117;i++){
    gotoxy(i,j);printf(" ");}
    return;
}
int t(void){
    time_t t;
    time(&t);
    printf("Date and time:%s\n",ctime(&t));/* *This will take the time date from system.
                                              *Then print it.
                                            */
    return 0 ;
}

void substring(char s[], char sub[], int p, int l) {
   int c = 0;

   while (c < l) {
      sub[c] = s[p+c-1];
      c++;
   }
   sub[c] = '\0';
}

void creat1(int x,const char st[])
{
    SetColor(1);
    gotoxy(51, 5);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(51,9);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(51,30);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    for(i=5;i<=30;i++){ gotoxy(50,i);printf("\xB2");gotoxy(117,i);printf("\xB2");}
    gotoxy(77,7);printf("3-WP ATM BOOTH");
    gotoxy(x,11);printf("\xdb\xb2 %s \xb2\xdb",st);
    gotoxy(78,29);SetColor(0);t();
}

void creat2(int x,const char st[])
{
    SetColor(1);
    gotoxy(30, 5);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(30, 9);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    for(i=5;i<=17;i++){ gotoxy(29,i);printf("\xB2");gotoxy(136+7,i);printf("\xB2");}
    gotoxy(77,7);printf("3-WP ATM BOOTH");
    gotoxy(x,11);printf("\xdb\xb2 %s \xb2\xdb",st);
}

void Exit_p()
{
    system("CLS");
    system("color F2");
    int p=50;
    Sleep(50);
    gotoxy(p,8);
    Sleep(50);
    printf("\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\t      Software Development 1 ; CSE 100     \t\xB2\xB2\xB2\xB2\xDB\xDB\xDB");
    gotoxy(p,10);
    Sleep(100);
    printf("\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\t                   ATM BOOTH               \t\xB2\xB2\xB2\xB2\xDB\xDB\xDB");
    gotoxy(p,12);
    Sleep(100);
    printf("\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\t             is brought to you by         \t\xB2\xB2\xB2\xB2\xDB\xDB\xDB");
    gotoxy(p,14);
    Sleep(100);
    printf("\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\t                 TEAM   3 WP              \t\xB2\xB2\xB2\xB2\xDB\xDB\xDB");


    SetColor(29);
    gotoxy(p+20,18);Sleep(100);printf("\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2     THANKS    \xB2\xB2\xB2\xB2\xDB\xDB\xDB");



    gotoxy(p+20,22);
    SetColor(4);
    char E[40]={"Exiting in 2 second...........>>>>>>>>>"};
    for(int i=0;i<39;i++){
        Sleep(50);
        printf("%c",E[i]);
    }
    printf("\n\n");
    Sleep(2000);///This will delay 3 second......
    SetColor(0);
    exit(0);
}

void Again()
{
    system("CLS");
    SetColor(2);
    gotoxy(66,20);printf("\xdb\xdb\xdb\xb2 DO  YOU  WANT  TO  CONTINUE? Y/N \xb2\xdb\xdb\xdb");

    SetColor(28);gotoxy(57+14,25);printf("\xdb\xdb\xb2  Enter Your Choice: ");
    while(1){
    int c=0;char d;
    d =_getch();fflush(stdin);
    if(d=='y'||d=='Y')
        c=1;
    else if(d=='n'||d=='N')
        c=2;
    switch(c)
    {
    case 1:
        main_option();
        break;
    case 2:
        Exit_p();
        break;
    default:
        break;
    }
 }

}

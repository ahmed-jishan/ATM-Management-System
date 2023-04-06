/// Login & registration are defined here.......


void admin_login()
{
    system("CLS");
    char User_id[20] ={"team 3wp"};///This is the program User_Id....................
    char password[15]={"123456"};///This Is The Password..............................
    SetColor(3);
    char d[25]="Password Protected";
    char ch,pass[15],uid[20];
    int i=0,j;
    gotoxy(55,10);
    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("*");
    }
    for(j=0;j<18;j++)
    {
        Sleep(50);
        printf("%c",d[j]);
    }
    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("*");
    }
    again1:
        gotoxy(55+12,12);
        memset(&uid[0],0, sizeof(uid));
        SetColor(3);
        printf("Enter User Id :");
        fflush(stdin);
        gets(uid);
    again:
        gotoxy(55+12,14);
        fflush(stdin);
        SetColor(3);
        memset(&pass[0],0, sizeof(pass));
        ch='0';
        i=0;
        printf("Enter Password:");

    while(ch!=13)
    {
        ch=_getch();
        if(ch!=13 && ch!=8){///in this loop we put a * in case we enter a character in pass string..........
            putch('*');
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    if(strcmp(uid,User_id)==0){
        if(strcmp(pass,password)==0){
            gotoxy(55,20);
            SetColor(2);
            printf("---->>\xb2\xdb Password match  \xdb\xb2<<------");
            gotoxy(55,21);
            printf("---->>\xb2\xdb Press any key to continue----->>>>");
            _getch();
            admin_menu();
        }
    else
        {
            gotoxy(55,19);
            SetColor(4);
            printf("\a\xb3\xb3\xb3\xb3 Warning!! Incorrect Password-->>Try Again..");
            _getch();
            fflush(stdin);
            clearLine(19);
            clearLine(14);
            goto again;
        }
    }
    else{
        gotoxy(55,19);
        SetColor(4);
        printf("\a\xb3\xb3\xb3\xb3 Warning !! User Doesn't Exist-->>Try Again..");
        _getch();
        fflush(stdin);
        clearLine(19);
        clearLine(12);
        clearLine(14);
        goto again1;
    }

}

char stp1[15];
char sti1[15];
char c;
void user_login()
{
    col:
    system("CLS");
    creat1(77,"User Log In");
    fp=fopen("user pass.txt","r");
    SetColor(45);memset(&sti1[0],0,sizeof(sti1));fflush(stdin);
    gotoxy(65,13);printf("\xdb\xb2 Enter Account number: ");gets(sti1);fflush(stdin);
        while(fread(&use,sizeof(use),1,fp) == 1){
                isFound=0;
        if(strcmp(sti1,use.acc) == 0){///We check here is that Id is already exist or not....
            isFound = 1;
            break;
        }
    }
        if(isFound==1)
        {
          K: fflush(stdin);
            gotoxy(65,15);
            c='0';
            memset(&stp1[0], 0, sizeof(stp1));
            SetColor(45);
            i=0;
            printf("\xdb\xb2 Enter Password:");
           while(c!=13)
           {
               c=_getch();
               if(c!=13&&c!=8)
               {
                   putch('*');
                   stp1[i]=c;
                   i++;
               }
           }
           stp1[i]='\0';
           if(strcmp(stp1,use.pass)==0){
           gotoxy(65,18);SetColor(2);printf("\xdb\xb2\xb2 Log in Successfully---->>>>");
            fclose(fp);
            _getch();
            user_menu(sti1);
            }
            else {
                    SetColor(4);
                gotoxy(65,18);printf("\xdb\xb2 Invalid Password!");
                gotoxy(65,20);printf("\a\xdb\xb2 Do you want to try again or exit ? (y/e)");
                while(1)
                    {
                        switch(_getch())
                        {
                            case 'y':
                                clearLine(18);
                                clearLine(20);
                                clearLine(15);
                                goto K;
                                break;
                            case 'Y':
                                clearLine(18);
                                clearLine(20);
                                clearLine(15);
                                goto K;
                                break;
                            case 'e':
                                user_login_option();
                                break;
                            case 'E':
                                user_login_option();
                                break;
                            default:
                                break;
                        }
                    }
                }
        }
        else
        {
            SetColor(4);
            gotoxy(65,18);printf("\xdb\xb2 Not in Register yet! \aRegistration First-->>");
            fclose(fp);
            fclose(ft);
            _getch();
            user_regist();
        }
}

char p1[15];
char p2[15];

void user_regist()
{
        start:
    system("CLS");
    isFound=0;
    creat1(74,"User  Registration");
    fp=fopen("account.txt","r");
    ft=fopen("user pass.txt","ab+");
    SetColor(45);
    gotoxy(60,13);printf("\xdb\xb2 Enter the account number : ");memset(&sti1[0],0,sizeof(sti1));fflush(stdin);gets(sti1);fflush(stdin);
        while(fread(&us,sizeof(us),1,fp) == 1){
        if(strcmp(sti1,us.acn) == 0){///We check here is that Id is already exist or not....
            isFound = 1;
            break;
        }
    }
    fclose(fp);
    if(isFound==0)
    {
        SetColor(4);
        fclose(ft);
       gotoxy(60,18); printf("\xdb\xb2 \aNot a customer of this bank.");
       gotoxy(62,22);printf("\xdb\xb2 Do you want to continue or back(c/b)?");
            while(1){
                    switch(_getch())
                    {
                    case 'c':
                        user_regist();
                        break;
                    case 'C':
                        user_regist();
                        break;
                    case 'b':
                        user_login_option();
                        break;
                    case 'B':
                        user_login_option();
                        break;
                    default:
                        break;
                    }
            }
    }
    else
    {
        notfound=0;
        while(fread(&use,sizeof(use),1,ft)==1){
            if(strcmp(sti1,use.acc)==0){
                notfound++;
                break;
            }
        }
        if(notfound){
                SetColor(4);
            gotoxy(62,20);printf("\xdb\xb2 \aThis account  is  already registered!");
            fclose(ft);
            gotoxy(62,22);printf("\xdb\xb2 Do you want to continue or back(c/b)?");
            while(1){
                    switch(_getch())
                    {
                    case 'c':
                        user_regist();
                        break;
                    case 'C':
                        user_regist();
                        break;
                    case 'b':
                        user_login_option();
                        break;
                    case 'B':
                        user_login_option();
                        break;
                    default:
                        break;
                    }
            }
        }
        else {
                SetColor(45);
            strcpy(use.acc,sti1);
            char p2[30];char p1[30];
            lol:
            memset(&p1[0],0,sizeof(p1));
            gotoxy(62,15);printf("\xdb\xb2 Enter password: ");
            fflush(stdin);
            i=0;
            c=0;
            while(c!=13)
           {
               c=_getch();
               if(c!=13&&c!=8)
               {
                   putch('*');
                   p1[i]=c;
                   i++;
               }
           }
           p1[i]='\0';
           gotoxy(62,17);printf("\xdb\xb2 Confirm password: ");
           i=0;
           c=0;
           memset(&p2[0], 0, sizeof(p2));
           while(c!=13)
           {
               c=_getch();
               if(c!=13&&c!=8)
               {
                   putch('*');
                   p2[i]=c;
                   i++;
               }
           }
           p2[i]='\0';
           if(strcmp(p1,p2)==0)
           {
                SetColor(2);
                strcpy(use.pass,p1);
                gotoxy(62,20);printf("\xdb\xb2 Registration Successful--->>>");
                fwrite(&use,sizeof(use),1,ft);
                fclose(ft);
                gotoxy(62,22);printf("\xdb\xb2Press any key to continue----->>>");_getch();
                user_login_option();
           }
           else
           {
               SetColor(4);
               gotoxy(62,20);printf("\xdb\xb2 \aPassword doesn't match----");
               gotoxy(62,22);printf("\xdb\xb2 Enter & confirm password  again---->>");
               gotoxy(62,24);printf("\xdb\xb2 Press any key to continue or exit.(1/0)");
               int ch;
               li:ch=_getch()-'0';
               if(ch==1){
                SetColor(45);
               clearLine(15);
               clearLine(17);
               clearLine(20);
               clearLine(22);
               clearLine(24);
               goto lol;}
               else if(ch==0)
                user_login_option();
                else
                    goto li;
           }
        }
    }
}

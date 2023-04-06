/// User accessible functions are defined here....

void check_bal(char a[15])
{
    system("CLS");
    creat1(75,"check Balance");
    fp=fopen("account.txt","r");
    SetColor(45);
    while(fread(&us,sizeof(us),1,fp)==1){
            if(strcmp(a,us.acn)==0){
            gotoxy(58,15);printf("\xdb\xb2 Account Number  : %s",us.acn);
            gotoxy(58,17);printf("\xdb\xb2 Name            : %s",us.name);
            gotoxy(58,19);printf("\xdb\xb2 Mobile Number   : %s",us.phone);
            gotoxy(58,21);printf("\xdb\xb2 Current Balance : %0.2lf",us.bal);
            break;
            }
        }
        fclose(fp);
        SetColor(1);
        gotoxy(58,24);printf("\xdb\xb2 Press 0 to back..");
        while(1)
    {
        switch(_getch()-'0')
        {
            case 0:
                user_menu(a);
                break;
            default:
                break;
        }
    }

}

void withdraw_bal(char a[15])
{
    double now,withd,prev;
    char nam[30],acn[15],phn[15];
    system("CLS");
    SetColor(45);
    creat1(73,"Withdraw Balance");
    fp=fopen("account.txt","rb+");
    gotoxy(58,13);printf("\xb2 Enter the amount you want to withdraw : ");scanf("%lf",&withd);

    while(fread(&us,sizeof(us),1,fp)==1)
    {
        if(strcmp(a,us.acn)==0)
        {
            strcpy(acn,us.acn);
            strcpy(nam,us.name);
            strcpy(phn,us.phone);
            prev=us.bal;
            if(prev<withd)
            {
                SetColor(4);
                gotoxy(58,15);printf("\xdb\xb2  Insufficient Balance --->>>");
                gotoxy(58,17);printf("\xdb\xb2 Press any key to back --->>>");_getch();
                fclose(fp);
                user_menu(a);
            }
            else
            {
                now=prev-withd;
                gotoxy(58,17);printf("\xdb\xb2 New Balance : %0.2lf",now);
                strcpy(us.acn,acn);
                strcpy(us.name,nam);
                strcpy(us.phone,phn);
                us.bal=now;
                fseek(fp,-sizeof(us), SEEK_CUR);
                fwrite(&us,sizeof(us), 1, fp);
            }
            break;
        }
    }
    fclose(fp);
    SetColor(1);
    gotoxy(58,19);printf("\xdb\xb2 Press 0 to go back-->>");
    while(1)
    {
        switch(_getch()-'0')
        {
            case 0:
                user_menu(a);
                break;
            default:
                break;
        }
    }
}

void deposite(char a[15])
{
    double now,depo,prev;
    char nam[30],acn[15],phn[15];
    system("CLS");
    SetColor(45);
    creat1(73,"Withdraw Balance");
    fp=fopen("account.txt","rb+");
    gotoxy(58,13);printf("\xb2 Enter the amount you want to Deposit : ");scanf("%lf",&depo);

    while(fread(&us,sizeof(us),1,fp)==1)
    {
        if(strcmp(a,us.acn)==0)
        {
            strcpy(acn,us.acn);
            strcpy(nam,us.name);
            strcpy(phn,us.phone);
            prev=us.bal;
            now=prev+depo;
            gotoxy(58,17);printf("\xdb\xb2 New Balance : %0.2lf",now);
            strcpy(us.acn,acn);
            strcpy(us.name,nam);
            strcpy(us.phone,phn);
            us.bal=now;
            fseek(fp,-sizeof(us), SEEK_CUR);
            fwrite(&us,sizeof(us), 1, fp);
            break;
        }
    }
    fclose(fp);
    SetColor(1);
    gotoxy(58,19);printf("\xdb\xb2 Press 0 to go back-->>");
    while(1)
    {
        switch(_getch()-'0')
        {
            case 0:
                user_menu(a);
                break;
            default:
                break;
        }
    }
}

char P[15];
void change_pass(char a[15])
{
    system("CLS");
    int ifFound=0;
    creat1(74," Password Changing ");
    start:
    fp=fopen("user pass.txt","rb+");
    SetColor(45);
    gotoxy(60,13);printf("\xdb\xdb\xb2 Enter current password:");
    fflush(stdin);c='0';
    memset(&p1[0],0,sizeof(p1));
    memset(&P[0],0,sizeof(P));i=0;
    while(c!=13)
    {
        c=_getch();
        if(c!=13&&c!=8)
        {
            putch('*');
            P[i]=c;
            i++;
        }
    }
    P[i]='\0';
    while(fread(&use,sizeof(use),1,fp)==1){
            if(strcmp(P,use.pass)==0&&strcmp(a,use.acc)==0){
                ifFound=1;
                break;
            }
    }

        if(ifFound==1){
            memset(&p1[0],0,sizeof(p1));
            memset(&P[0],0,sizeof(P));
            fflush(stdin);c='0';i=0;
            gotoxy(60,15);printf("\xdb\xdb\xb2 Enter new password: ");
            while(c!=13)
            {
               c=_getch();
               if(c!=13&&c!=8)
               {
                   putch('*');
                   P[i]=c;
                   i++;
               }
            }
            P[i]='\0';
            vul:
            SetColor(45);
            memset(&p1[0],0,sizeof(p1));
            fflush(stdin);c='0';i=0;
            gotoxy(60,17);printf("\xdb\xdb\xb2 Confirm Password: ");
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
            if(strcmp(P,p1)==0){
                SetColor(2);
                strcpy(use.acc,a);
                strcpy(use.pass,P);
                gotoxy(60,19);printf("\xdb\xdb\xb2 Password Successfully Changed---->>>");
                gotoxy(60,20);printf("\xdb\xdb\xb2 Press Any key to continue--->>>");
                fseek(fp, -sizeof(use), SEEK_CUR);
                fwrite(&use,sizeof(use), 1,fp);
                fclose(fp);
                _getch();
                user_menu(a);
            }
            else
            {
                SetColor(4);
                gotoxy(60,19);printf("\xdb\xdb\xb2 \aWarning! Password Doesn't match .Try Again--->>");
                _getch();
                fflush(stdin);
                clearLine(19);
                clearLine(17);
                goto vul;
            }
        }
        else
        {
            SetColor(4);
            gotoxy(57,19);printf("\xdb\xdb\xb2 \aWarning! Previous Password Doesn't match .Try Again--->>");
            _getch();
            fflush(stdin);
            fclose(fp);
            clearLine(19);
            clearLine(13);
            goto start;
        }

}

/// Admin accessible functions are defined here....

void creat_acc()
{
    system("CLS");
    creat1(74,"Create Account");
    char ac[15];
    SetColor(45);
    fflush(stdin);
    gotoxy(58,13);printf("\xdb\xb2 Enter the account number: ");gets(ac);
        isFound=0;
        fp=fopen("account.txt","ab+");
        while(fread(&us,sizeof(us),1,fp)==1){
            if(strcmp(ac,us.acn)==0){
                isFound=1;
                break;
            }
        }
        if(isFound==0)
        {
            fflush(stdin);
            strcpy(us.acn,ac);
            gotoxy(58,15);printf("\xdb\xb2 Name            : ");gets(us.name);
            gotoxy(58,17);printf("\xdb\xb2 Mobile Number   : ");gets(us.phone);
            gotoxy(58,19);printf("\xdb\xb2 Initial Deposit : ");fflush(stdin);scanf("%lf",&us.bal);
            fwrite(&us,sizeof(us),1,fp);
            SetColor(2);
            gotoxy(58,22);printf("\xdb\xb2 Successfully account created.....");
        }
        else{
                SetColor(4);
            gotoxy(58,19);printf("\xdb\xb2 Account already exist...");
        }
        SetColor(1);
        fclose(fp);
        gotoxy(55,24);printf("\xdb\xb2 Do you want to create more(y/n)?");
        while(1)
        {
            switch(_getch())
            {
                case 'Y':
                    creat_acc();
                    break;
                case 'y':
                    creat_acc();
                    break;
                case 'n':
                    admin_menu();
                    break;
                case 'N':
                    admin_menu();
                    break;
                default:
                    break;
            }
        }
}

void delete_acc()
{
    system("CLS");
    creat1(75,"Delete Account");
    SetColor(45);
    char s_id[15];
    int isFound = 0;
    gotoxy(52,14);printf("\xB2 Enter Account Number to Delete: ");fflush(stdin);
    gets(s_id);
    FILE *fp, *temp;
    fp = fopen("account.txt","rb+");
    temp = fopen("temp.txt","wb+");
    while(fread(&us, sizeof(us),1,fp) == 1){
        if(strcmp(s_id, us.acn) != 0){
            fseek(temp,0,SEEK_CUR);
            fwrite(&us,sizeof(us),1,temp);
        }
        else{
                isFound=1;
            }
    }
    fclose(fp);
    fclose(temp);
    fflush(stdin);
    remove("account.txt");
    rename("temp.txt","account.txt");
    if(isFound==0){
        gotoxy(55,16);printf("The Record Not Found..");
    }
    else{
        gotoxy(54,16);printf("The record is successfully deleted");
    }
    SetColor(28);
    lol:gotoxy(54,21);printf("Do you want to delete more(y/n)?");
    int c;fflush(stdin);char d=_getch();
    if(d=='n'||d=='N')
            c=2;
    else if(d=='y'||d=='Y')
            c=1;
    switch(c)
    {
        case 1:
            delete_acc();
            break;
        case 2:
            admin_menu();
            break;
        default:
            goto lol;
    }

}

void search_acn()
{
    system("CLS");
    creat1(74,"Search Account");
    char ac[15];
    SetColor(45);
    fflush(stdin);
    gotoxy(58,13);printf("\xdb\xb2 Enter the account number: ");gets(ac);
        isFound=0;
        fp=fopen("account.txt","r");
        while(fread(&us,sizeof(us),1,fp)==1){
            if(strcmp(ac,us.acn)==0){
                isFound=1;
                break;
            }
        }
        if(isFound==1)
        {
            clearLine(13);
            gotoxy(58,13);printf("\xb2 Account Found-->>");
            gotoxy(58,15);printf("\xdb\xb2 Account Number  : %s",us.acn);
            gotoxy(58,17);printf("\xdb\xb2 Name            : %s",us.name);
            gotoxy(58,19);printf("\xdb\xb2 Mobile Number   : %s",us.phone);
            gotoxy(58,21);printf("\xdb\xb2 Current Balance : %0.2lf",us.bal);

        }
        else{
                SetColor(4);
            gotoxy(58,19);printf("\xdb\xb2 Account Doesn't exist...");
        }
        SetColor(1);
        fclose(fp);
        gotoxy(55,24);printf("\xdb\xb2 Do you want to search more(y/n)?");
        while(1)
        {
            switch(_getch())
            {
                case 'Y':
                    search_acn();
                    break;
                case 'y':
                    search_acn();
                    break;
                case 'n':
                    search_option();
                    break;
                case 'N':
                    search_option();
                    break;
                default:
                    break;
            }
        }
}

void search_name()
{
    system("CLS");
    creat2(75,"Search Name");
    SetColor(45);
    char nam[30];
    char temp[30];
    char com[30];
    gotoxy(35,13);printf("\xdb\xb2 Enter Name to search :");fflush(stdin);gets(nam);
    int l=strlen(nam);
    int num=0,k=18,j=19;
    fp=fopen("account.txt","rb+");
    gotoxy(35,16);printf("       Account Number                    Name                  Balance                  Mobile   ");
    gotoxy(35,17);printf("     ==================                ========              ===========              ========== ");
    while(fread(&us,sizeof(us),1,fp)==1)
    {
        memset(&com[0],0,sizeof(com));
        memset(&temp[0],0,sizeof(temp));
        strcpy(temp,us.name);
        substring(temp,com,1,l);
        if(strcmp(com,nam)==0)
        {
            SetColor(45);
            num++;
            gotoxy(42,j);printf("%d. %s",num,us.acn);
            gotoxy(67,j);printf("%s",us.name);
            gotoxy(98,j);printf("%0.2lf",us.bal);
            gotoxy(121,j);printf("%s",us.phone);
            SetColor(1);
            gotoxy(29,k);printf("\xb2");gotoxy(143,k);printf("\xb2");
            gotoxy(29,k+1);printf("\xb2");gotoxy(143,k+1);printf("\xb2");
            k+=2;
            j+=2;
        }
    }
    fclose(fp);
    SetColor(1);
    for(i=j-1;i<j+7;i++)
    {
        gotoxy(29,i);printf("\xb2");gotoxy(143,i);printf("\xb2");
    }
    gotoxy(30,i-1);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(65,i-5);printf("\xdb\xb2 Press 0 to back --->>>");
    while(1)
    {
        switch(_getch()-'0')
        {
            case 0:
                admin_menu();
                break;
            default:
                break;
        }
    }

}

void acc_list()
{
    system("CLS");
    creat2(74,"Account List");
    SetColor(45);
    int num=0,k=18,j=19;
    fp=fopen("account.txt","rb+");
    gotoxy(35,16);printf("       Account Number                    Name                  Balance                  Mobile   ");
    gotoxy(35,17);printf("     ==================                ========              ===========              ========== ");
    while(fread(&us,sizeof(us),1,fp)==1)
    {
            SetColor(45);
            num++;
            gotoxy(42,j);printf("%d. %s",num,us.acn);
            gotoxy(67,j);printf("%s",us.name);
            gotoxy(98,j);printf("%0.2lf",us.bal);
            gotoxy(121,j);printf("%s",us.phone);
            SetColor(1);
            gotoxy(29,k);printf("\xb2");gotoxy(143,k);printf("\xb2");
            gotoxy(29,k+1);printf("\xb2");gotoxy(143,k+1);printf("\xb2");
            k+=2;
            j+=2;
    }
    fclose(fp);
    SetColor(1);
    for(i=j-1;i<j+7;i++)
    {
        gotoxy(29,i);printf("\xb2");gotoxy(143,i);printf("\xb2");
    }
    gotoxy(30,i-1);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(65,i-5);printf("\xdb\xb2 Press 0 to back --->>>");
    while(1)
    {
        switch(_getch()-'0')
        {
            case 0:
                admin_menu();
                break;
            default:
                break;
        }
    }

}

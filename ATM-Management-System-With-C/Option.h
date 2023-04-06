/// We will define all the option here....


void main_option()///done
{
    system("CLS");
    creat1(76,"User  Option");
    SetColor(0);
    gotoxy(73,14);printf("\xb2\xb2  1. Administration \xb2\xb2");
    gotoxy(73,17);printf("\xb2\xb2  2. Account Holder \xb2\xb2");
    gotoxy(73,20);printf("\xb2\xb2   3. Exit Program  \xb2\xb2");
    SetColor(2);gotoxy(77,23);printf("\xb2\xb2 Your Choice: ");
    while(1)
    {
        switch(_getch()-'0')
        {
        case 1:
            admin_login();
            break;
        case 2:
            user_login_option();
            break;
        case 3:
            Exit_p();
            break;
        default:
            break;
        }
    }

}

void user_login_option()///done
{
    system("CLS");
    creat1(76,"Login Option");
    SetColor(0);
    gotoxy(71,14);printf("\xb2\xb2    >>> 1. Log in <<<   \xb2\xb2");
    gotoxy(71,17);printf("\xb2\xb2 >>>2. Registration <<< \xb2\xb2");
    gotoxy(71,20);printf("\xb2\xb2     >>> 3. Back <<<    \xb2\xb2");
    SetColor(2);gotoxy(77,23);printf("\xb2\xb2 Your Choice: ");
    while(1)
    {
        switch(_getch()-'0')
        {
        case 1:
            user_login();
            break;
        case 2:
            user_regist();
            break;
        case 3:
            main_option();
            break;
        default:
            break;
        }
    }
}

void admin_menu()
{
    system("CLS");
    creat1(77,"Admin Menu");
    SetColor(0);
    gotoxy(73,14);printf("\xb2\xb2  1. Create Account \xb2\xb2");
    gotoxy(73,16);printf("\xb2\xb2  2. Search Account \xb2\xb2");
    gotoxy(73,18);printf("\xb2\xb2  3. Delete Account \xb2\xb2");
    gotoxy(73,20);printf("\xb2\xb2   4. Account List  \xb2\xb2");
    gotoxy(73,22);printf("\xb2\xb2     5. Log Out     \xb2\xb2");
    SetColor(2);gotoxy(77,25);printf("\xb2\xb2 Your Choice: ");

    while(1)
    {
        switch(_getch()-'0')
        {
            case 1:
                creat_acc();
                break;
            case 2:
                search_option();
                break;
            case 3:
                delete_acc();
                break;
            case 4:
                acc_list();
                break;
            case 5:
                Again();
                break;
            default:
                break;
        }
    }
}
void user_menu(char a[15])
{
    system("CLS");
    creat1(77,"User  Menu");
    SetColor(0);
    gotoxy(73,14);printf("\xb2\xb2  1. Check Balance  \xb2\xb2");
    gotoxy(73,16);printf("\xb2\xb2  2. Withdraw Money \xb2\xb2");
    gotoxy(73,18);printf("\xb2\xb2  3. Deposit Money  \xb2\xb2");
    gotoxy(73,20);printf("\xb2\xb2 4. Change Password \xb2\xb2");
    gotoxy(73,22);printf("\xb2\xb2     5. Log Out     \xb2\xb2");
    SetColor(2);gotoxy(77,26);printf("\xb2\xb2 Your Choice: ");

    while(1)
    {
        switch(_getch()-'0')
        {
            case 1:
                check_bal(a);
                break;
            case 2:
                withdraw_bal(a);
                break;
            case 3:
                deposite(a);
                break;
            case 4:
                change_pass(a);
                break;
            case 5:
                Again();
                break;
            default:
                break;
        }
    }
}

void search_option()
{
    system("CLS");
    creat1(75,"Search Option");
    SetColor(0);
    gotoxy(66,15);printf("\xb2\xb2  1. Search by Account Number   \xb2\xb2");
    gotoxy(66,18);printf("\xb2\xb2        2. Search by Name       \xb2\xb2");
    gotoxy(66,21);printf("\xb2\xb2             3. Back            \xb2\xb2");
    SetColor(2);gotoxy(77,24);printf("\xb2\xb2 Your Choice: ");

    while(1)
    {
        switch(_getch()-'0')
        {
            case 1:
                search_acn();
                break;
            case 2:
                search_name();
                break;
            case 3:
                admin_menu();
                break;
            default:
                break;
        }
    }
}

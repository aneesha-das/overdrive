#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<ctime>
#include<conio.h>
#include<windows.h>
#include<MMSystem.h>
using namespace std;
class Account{
string name;
string accountnumber;
string password;
char type;
float balance;
string dob;
public:
    Account()
    {
        this->name="";
        this->accountnumber="";
        this->password="";
        this->type='\0';
        this->balance=0;
        this->dob="";
    }
    void setAccount(string name,string acc,string password,char type,float balance,string dob)
    {
        this->name=name;
        this->accountnumber=acc;
        this->password=password;
        this->type=type;
        this->balance=balance;
        this->dob=dob;
    }
    string getAccountNumber()
    {
        return accountnumber;
    }
    string getName()
    {
        return name;
    }
    string getPassword()
    {
        return password;
    }
    string getDOB()
    {
        return dob;
    }
    char getType()
    {
        return type;
    }
    float getBalance()
    {
        return balance;
    }
    void accountDetails();
    void deposit();
    void withdraw();
    void moneytransfer();
};
struct chunk{
bool flag;
Account *arr;
struct chunk *next;
};
struct chunk *start;
fstream container,temporary;
fstream text;
string xyz="";
void logo();
void logo(int);
void logo(bool);
void logo(Account &);
void allclear();
void create();
void login();
string pass();
void del(Account &);
void refresh(Account &ob);
float fd();
void masterenter();
string getname();
void enter(Account &);
void masteraccount();
void checklist();
void checkDetails();
void Account::accountDetails()
{
    int ch;
    while(1)
    {
        allclear();
        logo(*this);
        cout<<"1: Check Balance\n2: Check History\n3: Change Password\n4: Back\n";
        cout<<"Enter Your Choice:";
        cin>>ch;
        string ootb;
        string p,n;
        string buffer1;
        switch(ch)
        {
        case 1:
            allclear();
            logo(*this);
            cout<<"Your Account Balance Is Rs. "<<balance<<"/-"<<endl;
            cout<<"Press Any Key To Continue...";
            getch();
            break;
        case 2:
            allclear();
            logo(*this);
            cout<<"HISTORY:"<<endl;
            cout<<"-------"<<endl;
            container.open(accountnumber.c_str(),ios::in|ios::binary);
            for(int i=0;i<=5;i++)
            {
                getline(container,ootb);
            }
            while(getline(container,ootb))
            {
                cout<<ootb<<endl;
            }
            container.close();
            cout<<"Press Any Key To Continue...";
            getch();
            break;
        case 3:
            allclear();
            logo(*this);
            cout<<"Enter Your Current Password\n";
            p=pass();
            if(p.compare(password)==0)
            {
                cout<<"Enter New Password\n";
                n=pass();
                password=n;
                temporary.open("temp",ios::out|ios::binary);
                container.open(accountnumber.c_str(),ios::in|ios::binary);
                for(int i=0;i<=5;i++)
                {
                    getline(container,buffer1);
                }
                while(getline(container,buffer1))
                {
                    temporary<<buffer1<<endl;
                }
                container.close();
                temporary.close();
                temporary.open("temp",ios::in|ios::binary);
                container.open(accountnumber.c_str(),ios::out|ios::binary);
                container<<name<<endl;
                container<<accountnumber<<endl;
                container<<password<<endl;
                container<<type<<endl;
                container<<balance<<endl;
                container<<dob<<endl;
                while(getline(temporary,buffer1))
                {
                    container<<buffer1<<endl;
                }
                container.close();
                temporary.close();
                cout<<"Your Password Has Been Changed Successfully\n";
            }
            else
            {
             cout<<"Wrong Password\n";
            }
            getch();
            break;
        case 4:
            return;
        default:
            cout<<"Enter A Valid Choice\n";
            getch();
        }
    }
}
void Account::deposit()
{
    allclear();
    logo(*this);
    if(type=='f')
    {
        cout<<"Option Not Valid For This Type Of Account\n";
        cout<<"Press Any Key To Continue...";
        getch();
        return;
    }
    else
    {
        cout<<"Enter The Amount To Be Deposited:"<<endl;
        float a;
        cin>>a;
        if(a<0)
        {
        cout<<"Osikkhito Naki??\n";
        getch();
        return;
        }
        string buffer1;
        balance=balance+a;
        stringstream con;
        con<<a;
        string something=con.str();
        string t;
        time_t now=time(0);
        t=ctime(&now);
        temporary.open("temp",ios::out|ios::binary);
                container.open(accountnumber.c_str(),ios::in|ios::binary);
                for(int i=0;i<=5;i++)
                {
                    getline(container,buffer1);
                }
                while(getline(container,buffer1))
                {
                    temporary<<buffer1<<endl;
                }
                container.close();
                temporary.close();
                temporary.open("temp",ios::in|ios::binary);
                container.open(accountnumber.c_str(),ios::out|ios::binary);
                container<<name<<endl;
                container<<accountnumber<<endl;
                container<<password<<endl;
                container<<type<<endl;
                container<<balance<<endl;
                container<<dob<<endl;
                while(getline(temporary,buffer1))
                {
                    container<<buffer1<<endl;
                }
                container<<"Rs. "<<something<<" Deposited On "<<t<<endl;
                container.close();
                temporary.close();
                allclear();
                logo(*this);
                cout<<"Rs. "<<something<<" Deposited On "<<t;
                cout<<"Current Balance: Rs. "<<balance<<"/-"<<endl;
                cout<<"Press Any Key To Continue...";
                getch();
                return;
    }
}
void Account::withdraw()
{
    allclear();
    logo(*this);
    if(type=='f')
    {
     cout<<"Option Not Valid For Fixed Deposit Account\n";
     cout<<"Press Any Key To Continue...";
     getch();
     return;
    }
    time_t now;
    string t;
    if(type=='s')
    {
        cout<<"Enter Amount You Would Like To Withdraw\n";
        float a;
        cin>>a;
        if(a<0)
        {
            cout<<"Osikkhito Naki?\n";
            getch();
            return;
        }
        stringstream con;
        con<<a;
        string something=con.str();
        if(balance-a>1000)
        {
            balance=balance-a;
            now=time(0);
            t=ctime(&now);
                string buffer1;
                temporary.open("temp",ios::out|ios::binary);
                container.open(accountnumber.c_str(),ios::in|ios::binary);
                for(int i=0;i<=5;i++)
                {
                    getline(container,buffer1);
                }
                while(getline(container,buffer1))
                {
                    temporary<<buffer1<<endl;
                }
                container.close();
                temporary.close();
                temporary.open("temp",ios::in|ios::binary);
                container.open(accountnumber.c_str(),ios::out|ios::binary);
                container<<name<<endl;
                container<<accountnumber<<endl;
                container<<password<<endl;
                container<<type<<endl;
                container<<balance<<endl;
                container<<dob<<endl;
                while(getline(temporary,buffer1))
                {
                    container<<buffer1<<endl;
                }
                container<<"Rs. "<<something<<" Withdrawn On "<<t<<endl;
                container.close();
                temporary.close();
                allclear();
                logo(*this);
                cout<<"Rs. "<<something<<" Withdrawn On "<<t;
                cout<<"Current Balance: Rs. "<<balance<<"/-"<<endl;
        }
        else
        {
            cout<<"Insufficient Balance\n";
        }
        cout<<"Press Any Key To Continue...";
        getch();
        return;
    }
    else
    {
        cout<<"Enter Amount You Would Like To Withdraw\n";
        float a;
        cin>>a;
        if(a<0)
        {
            cout<<"Osikkhito Naki?\n";
            getch();
            return;
        }
        stringstream con;
        con<<a;
        string something=con.str();
        if(balance-a>3000)
        {
            balance=balance-a;
            now=time(0);
            t=ctime(&now);
                string buffer1;
                temporary.open("temp",ios::out|ios::binary);
                container.open(accountnumber.c_str(),ios::in|ios::binary);
                for(int i=0;i<=5;i++)
                {
                    getline(container,buffer1);
                }
                while(getline(container,buffer1))
                {
                    temporary<<buffer1<<endl;
                }
                container.close();
                temporary.close();
                temporary.open("temp",ios::in|ios::binary);
                container.open(accountnumber.c_str(),ios::out|ios::binary);
                container<<name<<endl;
                container<<accountnumber<<endl;
                container<<password<<endl;
                container<<type<<endl;
                container<<balance<<endl;
                container<<dob<<endl;
                while(getline(temporary,buffer1))
                {
                    container<<buffer1<<endl;
                }
                container<<"Rs. "<<something<<" Withdrawn On "<<t<<endl;
                container.close();
                temporary.close();
                allclear();
                logo(*this);
                cout<<"Rs. "<<something<<" Deposited On "<<t;
                cout<<"Current Balance: Rs. "<<balance<<"/-"<<endl;
        }
        else
        {
            cout<<"Insufficient Balance\n";
        }
        cout<<"Press Any Key To Continue...";
        getch();
        return;
    }
}
void Account::moneytransfer()
{
    string a;
    allclear();
    logo(*this);
    if(type=='f')
    {
        cout<<"This Option Is Not Valid For Fixed Deposit Accounts\n";
        cout<<"Press Any Key To Continue\n";
        getch();
        return;
    }
    cout<<"Enter Account Number Of Receiver\n";
    cin>>a;
    text.open("acc_nos.txt",ios::in);
    string line;
    bool f;
    f=false;
    while(getline(text,line))
    {
        if(line.compare(a)==0)
        {
           f=true;
           break;
        }
    }
    if(!f)
    {
        cout<<"Invalid Account Number\n";
        getch();
        return;
    }
    else
    {
        container.open(a.c_str(),ios::in|ios::binary);
    string g;
    getline(container,g);
    getline(container,g);
    getline(container,g);
    getline(container,g);
    if(g.compare("f")==0)
    {
        cout<<"Cannot Transfer To Fixed Deposit Account\n";
        cout<<"Press Any Key To Continue...";
        getch();
        return;
    }
    container.close();
    text.close();
    float amount;
    cout<<"Enter Amount You Want To Transfer\n";
    cin>>amount;
    if((type=='c' && balance-amount<3000) || (type=='s' && balance-amount<1000))
    {
        cout<<"Insufficient Balance\n";
        cout<<"Press Any Key To Continue...";
        getch();
        return;
    }
    time_t now=time(0);
    string t=ctime(&now);
    balance=balance-amount;
    container.open(accountnumber.c_str(),ios::in|ios::binary);
    temporary.open("temp",ios::out|ios::binary);
    for(int i=0;i<=5;i++)
    {
        getline(container,g);
    }
    while(getline(container,g)){
        temporary<<g<<endl;
    }
    container.close();
    temporary.close();
    container.open(accountnumber.c_str(),ios::out|ios::binary);
    temporary.open("temp",ios::in|ios::binary);
    container<<name<<endl;
    container<<accountnumber<<endl;
    container<<password<<endl;
    container<<type<<endl;
    container<<balance<<endl;
    container<<dob<<endl;
    while(getline(temporary,g)){
        container<<g<<endl;
    }
    stringstream con;
        con<<amount;
        string something=con.str();
    container<<"Rs. "<<something<<" Has Been Transferred To Account Number "<<a<<" on "<<t<<endl;
    container.close();
    temporary.close();
    container.open(a.c_str(),ios::in|ios::binary);
    temporary.open("temp",ios::out|ios::binary);
    Account ob2;
    string buff1,buff2,buff3,buff6,buffbuff4,buffbuff5;
    char buff4[2];
    float buff5;
    getline(container,buff1);
    getline(container,buff2);
    getline(container,buff3);
    getline(container,buffbuff4);
    getline(container,buffbuff5);
    getline(container,buff6);
    buffbuff4.copy(buff4,1);
    buff5=atof(buffbuff5.c_str());
    buff5=buff5+amount;
    ob2.setAccount(buff1,buff2,buff3,buff4[0],buff5,buff6);
    char convert[50],part[10];
    strcpy(convert,buff2.c_str());
    int i=0;
    int x=convert[5]-'0';
    for(int j=6;j<=x+5;j++){
    part[i]=convert[j];
    i++;
    }
    string node(part);
    int y=atoi(node.c_str());
    int index=convert[6+x]-'0';
    struct chunk *head;
    head=start;
    for(int j=1;j<y;j++)
    {
        head=head->next;
    }
    head->arr[index]=ob2;
    while(getline(container,g)){
        temporary<<g<<endl;
    }
    container.close();
    temporary.close();
    container.open(buff2.c_str(),ios::out|ios::binary);
    temporary.open("temp",ios::in|ios::binary);
    container<<ob2.getName()<<endl;
    container<<ob2.getAccountNumber()<<endl;
    container<<ob2.getPassword()<<endl;
    container<<ob2.getType()<<endl;
    container<<ob2.getBalance()<<endl;
    container<<ob2.getDOB()<<endl;
    while(getline(temporary,g)){
        container<<g<<endl;
    }
    container<<"Rs. "<<something<<" Has Been Transferred To This Account From Account Number "<<accountnumber<< " On "<<t<<endl;
    container.close();
    temporary.close();
    cout<<"Rs. "<<something<<" Has Been Transferred To Account Number "<<a<<" on "<<t;
    cout<<"Your Current Balance Is Rs. "<<balance<<"/-"<<endl;
    cout<<"Press Any Key To Continue\n";
    getch();
    return;
    }
}
int main()
{
    int ch;
    struct chunk *head,*temp;
    int i,x,y;
    bool f,FLAG;
    FLAG=false;
    string line;
    char convert[50],part[50];
    text.open("acc_nos.txt");
    while(getline(text,line))
    {
        i=0;
        strcpy(convert,line.c_str());
        x=convert[5]-'0';
        for(int j=6;j<=x+5;j++){
        part[i]=convert[j];
        i++;
        }
        string node(part);
        y=atoi(node.c_str());
        int index=convert[6+x]-'0';
        head=start;
        if(start==NULL && y>0)
            {
            temp=new chunk;
            temp->arr=new Account[10];
            temp->flag=false;
            temp->next=NULL;
            start=temp;
            head=start;
            }
            head=start;
        for(;y>1;y--)
        {
           if(head->next==NULL)
           {
            head->next=new chunk;
            head->next->arr=new Account[10];
            head->next->flag=false;
            head->next->next=NULL;
           }
            head=head->next;
        }
        container.open(line.c_str(),ios::in|ios::binary);
        string prebuffer;
        string buff1,buff2,buff3,buff6,buffbuff4,buffbuff5;
        char buff4[2];
        float buff5;
        getline(container,buff1);
        getline(container,buff2);
        getline(container,buff3);
        getline(container,buffbuff4);
        getline(container,buffbuff5);
        getline(container,buff6);
        container.close();
        buffbuff4.copy(buff4,1);
        buff5=atof(buffbuff5.c_str());
        head->arr[index].setAccount(buff1,buff2,buff3,buff4[0],buff5,buff6);
        for(i=0;i<50;i++)
        {
            part[i]='\0';
        }
    }
    head=start;
    bool f1;
    while(head!=NULL)
    {
      f1=false;
      for(int z=0;z<10;z++)
      {
          if(head->arr[z].getAccountNumber().compare("")==0)
          {
              f1=true;
              break;
          }
      }
      if(!f1)
      {
          head->flag=true;
      }
      head=head->next;
    }
    text.close();
    cout<<"Loading...";
    PlaySound("theme song.wav",NULL,SND_SYNC);
    allclear();
    logo();
    PlaySound("mutual funds.wav",NULL,SND_SYNC);
    LOOP:
    allclear();
    logo();
    cout<<"Press Enter To Continue\n";
    char master[500];
    int z=0;
    while(1)
    {
        master[z+1]='\0';
        master[z]=getche();
        if(master[z]=='\b')
        {
            continue;
        }
        cout<<"\b"<<" "<<"\b";
        if(int(master[z])==13)
        {
            break;
        }
        if(strcmp(master,"privatemasterportal123")==0)
        {
            masteraccount();
            goto LOOP;
        }
        z++;
    }
    allclear();
    logo(1);
    PlaySound("welcome back.wav",NULL,SND_SYNC);
    while(1)
    {
        cout<<"1. Create Account\n2. Log In\n3. Exit\nEnter your choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            create();
            allclear();
            logo(1);
            PlaySound("created.wav",NULL,SND_SYNC);
            break;
        case 2:
            login();
            FLAG=true;
            goto LOOP;
            break;
        case 3:
            FLAG=true;
            goto LOOP;
        default:
            allclear();
            logo(1);
            cout<<"Try Again!!\n";
        }
    }
    return 0;
}
void logo()
{
    for(int i=0;i<19;i++)
    {
        cout<<endl;
    }
    for(int i=0;i<6;i++)
    {
        cout<<"\t";
    }
    cout << "     ~~PRIVATE BANK OF INDIA~~" << endl;
      for(int i=0;i<6;i++)
    {
        cout<<"\t";
    }
    cout << "       ---------------------" << endl<<endl;
      for(int i=0;i<9;i++)
    {
        cout<<"\t";
    }
    cout<<"-With Us Your Dreams Are Protected...";
    for(int i=0;i<16;i++)
    {
        cout<<endl;
    }
}
void allclear()
{
    system("CLS");
}
void logo(int z)
{
    for(int i=0;i<6;i++)
    {
        cout<<"\t";
    }
    cout << "        ~~PRIVATE BANK OF INDIA~~" << endl;
      for(int i=0;i<6;i++)
    {
        cout<<"\t";
    }
    cout << "          ---------------------" << endl;
      for(int i=0;i<9;i++)
    {
        cout<<"\t";
    }
    cout<<"-With Us Your Dreams Are Protected...\n";
}
void create()
{
int r;
int i=1;
int j=0,k;
struct chunk *head,*temp;
stringstream convert1,convert2,convert3;
allclear();
logo(1);
srand(time(0));
r=10000+(rand()*rand())%(99999-10000+1);
if(start==NULL)
{
    temp=new chunk;
    temp->arr=new Account[10];
    temp->flag=false;
    temp->next=NULL;
    start=temp;
}
head=start;
while(head->flag && head->next!=NULL)
{
    head=head->next;
    i++;
}
if(head->next==NULL && head->flag)
{
temp=new chunk;
temp->arr=new Account[10];
temp->flag=false;
temp->next=NULL;
int z=0;
convert1<<r;
string str=convert1.str();
i++;
k=i;
while(i!=0)
    {
        i=i/10;
        j++;
    }
    i=k;
    convert2<<j;
    string out=convert2.str();
    str=str+out;
    convert3<<i;
    out=convert3.str();
    str=str+out+"0";
	cin.get();
	string buff1,buff2,buff3,buff6;
	float buff5;
	char buff4;
    cout<<"Enter Your Full Name:"<<endl;
    buff1=getname();
    cout<<"Enter Date Of Birth:\n";
    cin>>buff6;
    cout<<"Enter Your Password:"<<endl;
    buff3=pass();
    while(1)
    {
        cout<<"1. Current\n2. Savings\n3. Fixed Deposit\nEnter Your Choice:";
        int ch;
        cin>>ch;
        switch(ch)
        {
        case 1:
            buff4='c';
            cout<<"Enter Starting Amount(Minimum Amount Is Rs.3000)\n";
            cin>>buff5;
            while(buff5<3000)
            {
                cout<<endl<<"Minimum Amount Is Rs.3000\n";
                cin>>buff5;
            }
            break;
        case 2:
            buff4='s';
            cout<<"Enter Starting Amount(Minimum Amount Is  Rs.1000)\n";
            cin>>buff5;
            while(buff5<1000)
            {
                cout<<endl<<"Minimum Amount Is Rs.1000\n";
                cin>>buff5;
            }
            break;
        case 3:
            buff4='f';
            buff5=fd();
            if(buff5==-999)
            {
                continue;
            }
            break;
        default:
            allclear();
            logo(1);
            cout<<"Please Enter A Valid Choice!!\n";
            continue;
        }
        break;
    }
    buff2=str;
    temp->arr[0].setAccount(buff1,buff2,buff3,buff4,buff5,buff6);
    string t;
    time_t now=time(0);
    t=ctime(&now);
    string taka;
    stringstream convertmoney;
    convertmoney<<buff5;
    taka=convertmoney.str();
    text.open("acc_nos.txt",std::ofstream::out | std::ofstream::app);
	text<<str<<endl;
	text.close();
    cout<<"Your Account Number Is "<<temp->arr[0].getAccountNumber()<<endl;
    getch();
    container.open(temp->arr[0].getAccountNumber().c_str(),ios::out|ios::binary);
    container<<temp->arr[0].getName()<<endl;
    container<<temp->arr[0].getAccountNumber()<<endl;
    container<<temp->arr[0].getPassword()<<endl;
    container<<temp->arr[0].getType()<<endl;
    container<<temp->arr[0].getBalance()<<endl;
    container<<temp->arr[0].getDOB()<<endl;
    container<<"Account Created With Opening Balance Rs."+taka+" On "+t<<endl;
    cout<<"Account Created With Opening Balance Rs."+taka+" On "+t;
	head->next=temp;
	container.close();
}
else
{
int count;
        for(count=0;count<10;count++)
        {
            if(head->arr[count].getAccountNumber().compare("")==0)
            {
                break;
            }
        }
    stringstream convert4,convert5,convert6,convert7;
    convert4<<r;
    string str=convert4.str();
    int j=0,k;
    k=i;
    while(i!=0)
    {
        i=i/10;
        j++;
    }
    i=k;
    convert5<<j;
    string out=convert5.str();
    str=str+out;
    convert6<<i;
    out=convert6.str();
    str=str+out;
    convert7<<count;
    out=convert7.str();
    str=str+out;
    string buff1,buff2,buff3,buff6;
	float buff5;
	char buff4;
    cout<<"Enter Your Full Name:"<<endl;
    buff1=getname();
    cout<<"Enter Date Of Birth:\n";
    cin>>buff6;
    cout<<"Enter Your Password:"<<endl;
    buff3=pass();
    while(1)
    {
        cout<<"1. Current\n2. Savings\n3. Fixed Deposit\nEnter Your Choice:";
        int cho;
        cin>>cho;
        switch(cho)
        {
        case 1:
            buff4='c';
            cout<<"Enter Starting Amount(Minimum Amount Is Rs.3000)\n";
            cin>>buff5;
            while(buff5<3000)
            {
                cout<<endl<<"Minimum Amount Is Rs.3000\n";
                cin>>buff5;
            }
            break;
        case 2:
            buff4='s';
            cout<<"Enter Starting Amount(Minimum Amount Is Rs.1000)\n";
            cin>>buff5;
            while(buff5<1000)
            {
                cout<<endl<<"Minimum Amount Is Rs.1000\n";
                cin>>buff5;
            }
            break;
        case 3:
            buff4='f';
            buff5=fd();
            if(buff5==-999)
            {
                continue;
            }
            break;
        default:
            allclear();
            logo(1);
            cout<<"Please Enter A Valid Choice!!\n";
            continue;
        }
        break;
    }
    buff2=str;
    head->arr[count].setAccount(buff1,buff2,buff3,buff4,buff5,buff6);
    struct chunk *temp;
    temp=head;
    bool f1;
      f1=false;
      for(int z=0;z<10;z++)
      {
          if(temp->arr[z].getAccountNumber().compare("")==0)
          {
              f1=true;
              break;
          }
      }
      if(!f1)
      {
          temp->flag=true;
      }
    string t;
    time_t now=time(0);
    t=ctime(&now);
    string taka;
    stringstream convertmoney;
    convertmoney<<buff5;
    taka=convertmoney.str();
    text.open("acc_nos.txt",std::ofstream::out | std::ofstream::app);
	text<<str<<endl;
	text.close();
    cout<<"Your Account Number Is "<<head->arr[count].getAccountNumber()<<endl;
    container.open(head->arr[count].getAccountNumber().c_str(),ios::out|ios::binary);
    container<<head->arr[count].getName()<<endl;
    container<<head->arr[count].getAccountNumber()<<endl;
    container<<head->arr[count].getPassword()<<endl;
    container<<head->arr[count].getType()<<endl;
    container<<head->arr[count].getBalance()<<endl;
    container<<head->arr[count].getDOB()<<endl;
    container<<"Account Created With Opening Balance Rs."+taka+" On "+t<<endl;
    cout<<"Account Created With Opening Balance Rs."+taka+" On "+t;
    getch();
	container.close();
}
}
string getname()
{
    char p[500];
    int i=0;
      while(1)
    {
        p[i]=getche();
        if(int(p[i])==13)
        {
            p[i]='\0';
            i--;
            break;
        }
        if(p[i]=='\b' && i>0)
        {
            cout<<" "<<"\b";
        }
        i++;
    }
    string ret(p);
    cout<<p<<endl;
    return ret;
}
string pass()
{
    char p[50];
    int i=0;
    while(1)
    {
      while(1)
    {
        p[i]=getche();
        if(int(p[i])==13)
        {
            p[i]='\0';
            i--;
            break;
        }
        if(p[i]=='\b')
        {
            if(i>0)
            {
            cout<<" "<<"\b";
            i--;
            }
            continue;
        }
        cout<<"\b"<<"*";
        i++;
    }
    if(i>=7)
    {
        break;
    }
    cout<<"Password should be of minimum 8 characters\n";
    i=0;
    }
    cout<<endl;
    string ret(p);
    return ret;
}
float fd()
{
    cout<<"1. Invest Rs.2,00,000 And Get Rs. 3,50,000 In 8 Years\n";
    cout<<"2. Invest Rs.5,00,000 And Get Rs. 8,50,000 In 6 Years\n";
    cout<<"3. Invest Rs.10,00,000 And Get Rs. 17,50,000 In 5 Years\n";
    cout<<"4. Exit\n";
    cout<<"Enter Your Choice:";
    int ch;
   while(1)
   {
       cin>>ch;
       switch(ch)
       {
           case 1:
               return 200000;
           case 2:
               return 500000;
           case 3:
               return 1000000;
           case 4:
               return -999;
           default:
           cout<<"Please Enter A Valid Option!!\n";
       }
   }
}
void login()
{
    string user;
    string pwd;
    string line;
    bool v1=false;
    int i,index,buff,x,y;
    allclear();
    logo(1);
    cout<<"Enter Account Number\n";
    cin>>user;
    text.open("acc_nos.txt");
    while(getline(text,line))
    {
        if(line.compare(user)==0)
        {
            v1=true;
            break;
        }
    }
    text.close();
    if(!v1)
    {
        cout<<"Account Does Not Exist\nPress Any Key";
        getch();
        return;
    }
    cout<<"Enter Password\n";
    pwd=pass();
    char u[50],part[10];
    i=0;
        strcpy(u,user.c_str());
        x=u[5]-'0';
        for(int j=6;j<=x+5;j++){
        part[i]=u[j];
        i++;
        }
        string node(part);
        y=atoi(node.c_str());
        index=u[6+x]-'0';
        struct chunk *head;
        head=start;
        for(int z=1;z<y;z++)
        {
            head=head->next;
        }
    if(head->arr[index].getPassword().compare(pwd)==0){
        PlaySound("access granted.wav",NULL,SND_SYNC);
        enter(head->arr[index]);
        return;
    }
    else{
        cout<<"Wrong password\n";
        PlaySound("access denied.wav",NULL,SND_SYNC);
        while(true)
        {
        cout<<"Do You Want To Try Again?(0/1):";
        int i;
        cin>>i;
        if(i)
        {
        cout<<"Enter Password\n";
        pwd=pass();
        if(head->arr[index].getPassword().compare(pwd)==0)
        {
            PlaySound("access granted.wav",NULL,SND_SYNC);
            enter(head->arr[index]);
            return;
        }
        else
        {
            PlaySound("access denied.wav",NULL,SND_SYNC);
        }
        }
        else
            return;
        }
    }
}
void enter(Account &ob)
{
    logo(ob);
    while(1)
    {
    int ch;
    allclear();
    logo(ob);
     cout<<"1: Account Details\n2: Money Deposit\n3: Money Withdrawal\n4: Money Transfer\n5: Log Out\n6: Delete Account\n";
     cout<<"Enter Your Choice:";
     cin>>ch;
     switch(ch)
     {
     case 1:
         ob.accountDetails();
        break;
     case 2:
        ob.deposit();
        break;
     case 3:
        ob.withdraw();
        break;
     case 4:
        ob.moneytransfer();
        break;
     case 5:
         PlaySound("logging out.wav",NULL,SND_SYNC);
        return;
     case 6:
        del(ob);
        PlaySound("deleted.wav",NULL,SND_SYNC);
        return;
     default:
        cout<<"Enter A Valid Option\n";
        getch();
     }
  }
}
void logo(Account &ob)
{
    allclear();
    logo(1);
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout<<"A/C:  "<<ob.getAccountNumber()<<endl;
    cout<<"Name: "<<ob.getName()<<endl;
    switch(ob.getType())
    {
    case 'c':
        cout<<"Type: CURRENT"<<endl;
        break;
    case 's':
        cout<<"Type: SAVINGS"<<endl;
        break;
    case 'f':
        cout<<"Type: FIXED DEPOSIT"<<endl;
        break;
    }
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------\n\n";
}
void masteraccount()
{
    allclear();
    logo(1);
    char ch;
    string pwd;
    cout<<"The Following Section Is Classified\nDo You Wish To Continue?(y/n)\n";
    PlaySound("classified.wav",NULL,SND_SYNC);
    cin>>ch;
    if(ch=='y' || ch=='Y')
    {
    allclear();
    logo(1);
    cout<<"Validate Your Identity\n";
    PlaySound("validate.wav",NULL,SND_SYNC);
    pwd=pass();
    if(pwd.compare("PBI_classified")==0)
    {
        masterenter();
        return;
    }
    else
    {
      cout<<"Access Denied\n";
      PlaySound("access denied.wav",NULL,SND_SYNC);
      getch();
      cout<<"Validate Your Identity\n";
      PlaySound("validate.wav",NULL,SND_SYNC);
      pwd=pass();
      if(pwd.compare("PBI_classified")==0)
    {
        masterenter();
        return;
    }
    else
    {
        cout<<"Intruder Alert!!!!\n";
        PlaySound("intruder alert.wav",NULL,SND_SYNC);
    }
    }
    }
    else
    {
        PlaySound("basic mode.wav",NULL,SND_SYNC);
        return;
    }
}
void masterenter()
{
    int ch;
    PlaySound("welcome sir.wav",NULL,SND_SYNC);
    while(1)
    {
        allclear();
        logo(true);
        cout<<"1: Check Account List\n2: Check Details Of A Person\n3: Delete An Account\n4: Return To Basic Mode\n";
        cout<<"Enter Your Choice:";
        cin>>ch;
        int i,x,y,index;
        string line,node;
        char part[10],a[50];
        bool f=false;
        struct chunk *head;
        switch(ch)
        {
        case 1:
            checklist();
            break;
        case 2:
            checkDetails();
            break;
        case 3:
            allclear();
            logo(true);
            cout<<"Enter Account Number\n";
            cin>>a;
            text.open("acc_nos.txt",ios::in);
               while(getline(text,line))
               {
                   if(strcmp(line.c_str(),a)==0)
                   {
                       f=true;
                   }
               }
               if(!f)
               {
                   cout<<"Invalid Account Number\n";
                   cout<<"Press Any Key To Continue...";
                   getch();
                   continue;
               }
            text.close();
            i=0;
            x=a[5]-'0';
            for(int j=6;j<=x+5;j++){
            part[i]=a[j];
            i++;
            }
            node=part;
            y=atoi(node.c_str());
            index=a[6+x]-'0';
            head=start;
            for(int j=1;j<y;j++)
            {
                head=head->next;
            }
            head->flag=false;
                del(head->arr[index]);
            break;
        case 4:
            PlaySound("basic mode.wav",NULL,SND_SYNC);
            return;
        default:
            cout<<"Enter A Valid Choice\n";
            cout<<"Press Any Key To Continue...\n";
            getch();
        }
    }
    getch();
}
void logo(bool a)
{
    logo(1);
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------------\n";
    for(int i=0;i<8;i++)
    {
        cout<<"\t";
    }
    cout<<"CLASSIFIED";
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------------------------------\n";
}
void checklist()
{
    allclear();
    logo(true);
    text.open("acc_nos.txt",ios::in);
    string line;
    cout<<"Account Number\t\t\t\tName\n";
    cout<<"--------------\t\t\t\t----\n";
    while(getline(text,line))
    {
      container.open(line.c_str(),ios::in | ios::binary);
      string buff1;
      getline(container,buff1);
      cout<<line<<"\t\t\t\t"<<buff1<<endl;
      container.close();
    }
    text.close();
    cout<<"Press Any Key To Continue...";
    getch();
}
void checkDetails()
{
    allclear();
    logo(true);
    string a,line;
    bool flag=false;
    cout<<"Enter Account Number\n";
    cin>>a;
    text.open("acc_nos.txt",ios::in);
    while(getline(text,line))
    {
        if(line.compare(a)==0)
        {
            flag=true;
            break;
        }
    }
    text.close();
    if(!flag)
    {
       cout<<"Invalid Account Number\n";
       cout<<"Press Enter To Continue...";
       getch();
       return;
    }
    container.open(line.c_str(),ios::in|ios::binary);
    getline(container,line);
    cout<<"Name: "<<line<<endl;
    getline(container,line);
    cout<<"A/C No: "<<line<<endl;
    getline(container,line);
    cout<<"Password: "<<line<<endl;
    getline(container,line);
    cout<<"Type: "<<line<<endl;
    getline(container,line);
    cout<<"Balance: "<<line<<endl;
    getline(container,line);
    cout<<"Date Of Birth: "<<line<<endl;
    cout<<"History\n";
    cout<<"--------\n";
    while(getline(container,line))
    {
        cout<<line<<endl;
    }
    container.close();
    cout<<"Press Any Key To Continue...";
    getch();
}
void del(Account &ob)
{
    Account ob1;
    string line;
    text.open("acc_nos.txt",ios::in);
    container.open("temp.txt",ios::out);
    while(getline(text,line))
    {
        if(line.compare(ob.getAccountNumber())==0)
        {
            continue;
        }
        container<<line<<endl;
    }
    container.close();
    text.close();
    text.open("acc_nos.txt",ios::out);
    container.open("temp.txt",ios::in);
    while(getline(container,line))
    {
        text<<line<<endl;
    }
    container.close();
    text.close();
    remove(ob.getAccountNumber().c_str());
    refresh(ob);
    ob=ob1;
    cout<<"The Account Has Been Deleted\n";
    cout<<"Press Any Key To Continue...";
    getch();
}
void refresh(Account &ob)
{
        int i=0;
        char convert[50],part[10];
        string line(ob.getAccountNumber());
        strcpy(convert,line.c_str());
        int x=convert[5]-'0';
        for(int j=6;j<=x+5;j++){
        part[i]=convert[j];
        i++;
        }
        string node(part);
        int y=atoi(node.c_str());
        struct chunk *head;
        head=start;
        while(y>1)
        {
            head=head->next;
            y--;
        }
        head->flag=false;
}

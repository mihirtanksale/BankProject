#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
class bank
{
//static int acc_number;
public:
    int acc_number;
    char name[100];
    int pan_no;
    char type;
    int balance;
    char address[200];
    char Date_of_birth[10];
    int Adhar_number;
    char mobile_number[10];

    void output()
    {
      string line;
      ifstream myfile ("input.txt");
          if (myfile.is_open())
          {
            while ( getline (myfile,line) )
            {
              cout << line << '\n';
            }
            myfile.close();
          }

      else cout << "Unable to open file";

    }

    void acc_det_display()
    {

        cout<<"\nAccount name:"<<name<<endl;
        //cout<<"Account number:"<<acc_number<<endl;
        cout<<"pan number:"<<pan_no<<endl;
        cout<<"Balance:"<<balance<<endl;
        cout<<"Type of account:"<<type<<endl;
        cout<<"Address:"<<address<<endl;
        cout<<"Date of birth:"<<Date_of_birth<<endl;
        cout<<"Adhar number:"<<Adhar_number<<endl;
        cout<<"Mobile number:"<<mobile_number<<endl;
    }

    void withdraw()
    {
        int withdraw_amount;
        cout<<"Enter amount to be withdraw"<<endl;
        cin>>withdraw_amount;
        balance=balance-withdraw_amount;
        cout<<"Amount widrawed:"<<withdraw_amount<<endl;
        cout<<"Current Balance is"<<balance<<endl;
    }

    void deposite()
    {
        int amount,i;

        cout<<"Enter amount to deposite in bank"<<endl;
        cin>>amount;

        balance=balance+amount;

        cout<<"Your amount has been diposited in bank"<<endl;
        //output();
        acc_det_display();
    }


    void create_acc()
    {
        //bank bank1;
        ofstream file_obj;
        file_obj.open("input.txt",ios::app);//open is method of ostream

          cout<<"Enter name of account holder"<<endl;
          cin>>name;
          file_obj<<name<<endl;

          cout<<"Enter balance"<<endl;
          cin>>balance;
          file_obj<<balance<<endl;

          cout<<"Enter account type"<<endl;
          cin>>type;
          file_obj<<type<<endl;

          cout<<"Address"<<endl;
          cin>>address;
          file_obj<<address<<endl;

          cout<<"Date of birth"<<endl;
          cin>>Date_of_birth;
          file_obj<<Date_of_birth<<endl;

          cout<<"Adhar number"<<endl;
          cin>>Adhar_number;
          file_obj<<Adhar_number<<endl;

          cout<<"Pan number"<<endl;
          cin>>pan_no;
          file_obj<<pan_no<<endl;

           while(1)
            {
            cout<<"Enter mobile number";
            cin>>mobile_number;
            int length=strlen(mobile_number);
             if(length==10)
                {break;}
            else
                cout<<"INVALID MOBILE NUMBER";
            }

          file_obj<<mobile_number<<endl;

    file_obj.close();
    }
};

int main()
{
    bank b[100];
    int n,acc_number,res,t;
    char password[10],actual[10]="1234mihir";
    cout<<"#######**********WELCOME TO BANK************########";


while(1)
{

    cout<<"\n1.Edit Entry\n2.Create account\n3.DEPOSITE\n4.WITHDRAW\n5.Account details\n6.DISPLAY TOTAL DATA\n";
    cin>>n;
switch(n)
{
case 1:
        cout<<"Enter your account number";
        cin>>acc_number;
        cout<<"Your account details are";
        b[acc_number].acc_det_display();
        //diplay all info
        while(1)
        {

        cout<<"Please Enter Password to edit entries";
        cin>>password;
        res=strcmp(password,actual);
         if(res==0)
            break;
        else
            cout<<"password does not match";

        }
        b[acc_number].acc_det_display();
        while(1)
        {

            if(res==0)
                {
                    cout<<"What do you want to edit\n";
                    cout<<"\n1.Name\n2.Pan Number\n3.Address\n4.Date_Of_Birth\n5.Adhar_Number\n6.Mobile_Number\n";
                        cin>>t;
                    switch(t)
                    {
                        case 1:
                            char name_new[100];
                            cout<<"Enter new name\n";
                            cin>>name_new;
                            strcpy(b[acc_number].name,name_new);
                            cout<<"Your entry updated\n";
                            b[acc_number].acc_det_display();
                            // display all information in the object
                            break;

                        case 2:
                            int new_pan_no;
                            cout<<"Enter new pan number\n";
                            cin>>new_pan_no;
                            b[acc_number].pan_no=new_pan_no;
                            cout<<"Your entry is updated\n";
                            b[acc_number].acc_det_display();
                            // display all information in the object
                            break;

                        case 3:
                            char new_add[500];
                            cout<<"Enter new address";
                            cin>>new_add;
                            strcpy(b[acc_number].address,new_add);
                            cout<<"Your entry is updated";
                            b[acc_number].acc_det_display();
                            // display all information in the object
                            break;

                        case 4:
                            char new_Dob[10];
                            cout<<"Enter new birth date";

                            cin>>new_Dob;

                            strcpy(b[acc_number].Date_of_birth,new_Dob);
                            cout<<"Your entry is updated";
                            b[acc_number].acc_det_display();
                            // display all information in the object
                            break;

                        case 5:
                            int new_Adhar_no;
                            cout<<"Enter new adhar number";
                            cin>>new_Adhar_no;
                            b[acc_number].Adhar_number=new_Adhar_no;
                            cout<<"Your entry is updated";
                            b[acc_number].acc_det_display();
                            // display all information in the object
                            break;

                        case 6:
                            char new_mobile_no[10];

                            while(1)
                            {
                                cout<<"Enter mobile number";
                                for(int j=0;j<10;j++)
                                {
                                cin>>new_mobile_no;
                                }
                                int length=strlen(new_mobile_no);
                                if(length==10)
                                break;
                            }

                           for(int j=0;j<10;j++)
                            {
                             b[acc_number].mobile_number[j]=new_mobile_no[j];
                            }
                              cout<<"Your entry is updated";
                              b[acc_number].acc_det_display();
                            // display all information in the object
                            break;
                    }
                        cout<<"Want to edit more elements";
                        char ans;
                        cin>>ans;
                        if(ans=='n')
                            break;

            }
        }
        break;  //break for edit fuction
case 2:
    cout<<"Enter account number";
    cin>>acc_number;
    b[acc_number].acc_number=acc_number;
    b[acc_number].create_acc();
    break;
case 3:
    cout<<"Enter account number";
    cin>>acc_number;
     b[acc_number].deposite();
     break;
case 4:
    cout<<"Enter account number";
    cin>>acc_number;
    b[acc_number].withdraw();
    break;
case 5:
    cout<<"Enter account number";
    cin>>acc_number;
    b[acc_number].acc_det_display();
    break;
case 6:
    int IMP;
    cout<<"Enter code for validation:";
    cin>>IMP;
    if(IMP==1234)
    {
     cout<<"Enter any account number";
    b[acc_number].output();
    }
    else
     cout<<"ACCESS DENIDE";
    break;
}
    cout<<"WANT TO GO TO MAIN MANU PRESS Y OR PRESS N TO EXIT";
    char final_ans;
    cin>>final_ans;
    if(final_ans=='y'||'Y')
        //clrscr();
     system("cls");
    else
        break;
}  //TO END WHILE OF STARTING
    return 0;
}

#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
class Account
{
 public:
        string name;
        int account_no;
        string account_type;
public:
        Account():name(" "),account_no(),account_type(" "){}
        void get_information()
        {
            cout<<"ACCOUNT HOLDER'S NAME:"<<endl;
            cin>>name;
            cout<<"ACCOUNT NUMBER:"<<endl;
            cin>>account_no;
            cout<<"ACCOUNT TYPE:"<<endl;
            cin>>account_type;

        }
        void display_information()
        {
            cout<<"ACCOUNT HOLDER'S NAME:"<<name<<endl;
            cout<<"ACCOUNT NUMBER       :"<<account_no<<endl;
            cout<<"ACCOUNT TYPE         :"<<account_type<<endl;
        }
};

class Saving_account:public Account
{
  private:double balance;
          double deposit;
          double withdraw;
          double rate;
          int term;
  public:
        Saving_account():balance(0),deposit(0),withdraw(0),rate(0),term(0){}
        void getdata()
        {
            cout<<"DETAILS FOR THE SAVINGS ACCOUNT"<<endl;
            Account::get_information();

            while(1)
            {
                cout<<"ENTER THE BALANCE         :"<<endl;
                cin>>balance;

                if(balance<500)
                {
                    cout<<endl<<"BALANCE MUST BE AT LEAST 500 TK";
                    continue;
                }
                else break;
            }




            while(1)
            {
                cout<<endl<<"ENTER THE INTEREST RATE   :";
                cin>>rate;
                if(rate<=0)
                {

                    cout<<"RATE MUST BE GREATER THAN ZERO"<<endl;
                    continue;
                }
                else break;
            }





            while(1)
            {
                cout<<endl<<"ENTER THE TERM            :";
                cin>>term;
                if(term<=0)
                {
                    cout<<"\nTERM MUST BE GREATER THAN ZERO"<<endl;
                    continue;
                }
                else break;

            }
        }

        void Deposit()
        {
            cout<<"MONEY DEPOSIT SCREEN"<<endl;
            if(balance<=0)
            {
                cout<<"PLEASE CREATE AN ACCOUNT FOR DEPOSIT:"<<endl;
            }
            else{
                cout<<"ENTER THE AMOUNT YOU WANT TO DEPOSIT        :"<<endl;
                cin>>deposit;
                while(1)
                {

                    if(deposit<=0)
                    {
                    cout<<"DEPOSIT MUST BE OVER TK 0"<<endl;
                    continue;
                    }
                    else
                    {
                    balance=balance+deposit;
                    cout<<"THE BALANCE AFTER MAKING DEPOSIT IS        :"<<balance<<endl;
                    break;
                    }
                }
             }
            }

        void Withdraw()
        {
            cout<<"MONEY WITHDRAWAL SCREEN"<<endl;
            cout<<"ENTER THE WITHDRAWAL AMOUNT            :"<<endl;
            cin>>withdraw;
            float temp;
            temp=balance-withdraw;
            if(temp<0)
            {
                cout<<"ILLEGAL WITHDRAWAL BALANCE COMES TO LESS THAN ZERO"<<endl;
                cout<<"CANNOT ALLOW TO WITHDRAW"<<endl;
            }
            else
            {
                balance=balance-withdraw;
                cout<<"THE BALANCE AFTER WITHDRAWAL IS    :"<<balance;
            }
        }
        void Interest()
        {
            if(balance>500&&term<1)
            {
                 cout<<"INTEREST CALCULATION SCREEN"<<endl;
                cout<<"INTEREST CALCULATED AT "<<rate<<"% FOR "<<term<<" YEARS"<<endl;
                cout<<"BALANCE AFTER ADDING INTEREST IS        :"<<balance<<endl;

            }
            else
            {
                cout<<" AS YOUR BALANCE IS LESS THAN 500TK AND TERM IS LESS THAN 1 YEAR YOU WILL NOT GET ANY INTEREST"<<endl;
            }

        }

        void display_balance()
        {
            if(balance<=0)
            {
               cout<<"YOU HAVE NO BALANCE IN YOUR ACCOUNT.PLEASE DEPOSIT OR CREATE AN ACCOUNT"<<endl;
            }
            else
            {
                cout<<endl<<"LATEST BALANCE IS       :TK. "<<balance;
            }
        }
        void display_details()
        {
            Account::display_information();
            display_balance();

        }
};
class current_account:public Account
{
private:
    double balance;
    double wit;
    double dep;

public:
    current_account()
    {
        balance=0;
        wit=0;
        dep=0;
    }
    ~current_account(){}

    void cgetdata()
    {
        Account::get_information();
        cout<<"ENTER THE BALANCE:"<<endl;
        cin>>balance;

        while(1)
        {
            if(balance<=0)
            {
                cout<<"balance must be greater than 0"<<endl;
                continue;

            }

            else
                {
                break;
            }
        }
    }

    void cdeposit()
    {
    	cout<<"MONEY DEPOSIT SCREEN"<<endl;
            if(balance<=0)
            {
                cout<<"PLEASE CREATE AN ACCOUNT FOR DEPOSIT:"<<endl;
            }
            else
			{
				cout<<"ENTER THE AMOUNT YOU WANT TO DEPOSIT        :"<<endl;
                cin>>dep;

        		while(1)
                {

                    if(dep<=0)
                    {
                    cout<<"DEPOSIT MUST BE OVER TK 0"<<endl;
                    continue;
                    }
                    else
                    {
                    balance=balance+dep;
                    cout<<"THE BALANCE AFTER MAKING DEPOSIT IS        :"<<balance<<endl;
                    break;
                    }
                }

            }
    }


    void cwithdraw()
    {
        	cout<<"MONEY WITHDRAWAL SCREEN"<<endl;
            cout<<"ENTER THE WITHDRAWAL AMOUNT            :"<<endl;
            cin>>wit;
            float temp;
            temp=balance-wit;
            if(temp<0)
            {
                cout<<"ILLEGAL WITHDRAWAL BALANCE COMES TO LESS THAN ZERO"<<endl;
                cout<<"CANNOT ALLOW TO WITHDRAW"<<endl;
            }
            else
            {
                balance=balance-wit;
                cout<<"THE BALANCE AFTER WITHDRAWAL IS    :"<<balance;
            }

    }

    void cdisplay_balance()
        {
            if(balance<=0)
            {
               cout<<"PLEASE  CREATE AN ACCOUNT"<<endl;
            }
            else
            {
                cout<<"LATEST BALANCE IS        : Rs. "<<balance<<endl;
            }
        }
    void cdisplay_details()
        {
            Account::display_information();
            cdisplay_balance();

        }



};
int main()
{
    Saving_account s[5];
    current_account c[5];
    int i,cho,no,j;
    int flag=0;
    ofstream outfile("bank.txt",ios::binary);
    outfile.write(reinterpret_cast<char*>(&s),sizeof(s));
    for(i=0;i<5;i++)
    {


        cout<<"ENTER S FOR SAVING ACCOUNT AND C FOR CURRENT ACCOUNT"<<endl;
        char type;
        cin>>type;
        if(type =='s' || type =='S')
        {
            int choice=0;
            while(choice!=7){

            cout<<"     Choose Your choice:-"<<endl;
            cout<<"1)   CREATE AN ACCOUNT"<<endl;
            cout<<"2)   Display Balance" <<endl;
            cout<<"3)   display balance with interest"<<endl;
            cout<<"4)   Display with full Details"<<endl;
            cout<<"5)   Deposit"<<endl;
            cout<<"6)   Withdraw"<<endl;
            cout<<"7)   EXIT"<<endl;


            cin>>choice;
            switch(choice)
            {
                case 1 :
                        s[i].getdata();
                        break;
                case 2 :
                        s[i].display_balance();
                        break;
                case 3:
                        s[i].Interest();
                        break;
                case 4 :
                        while(1)
                        {
                                cout<<"ENTER YOUR ACCOUNT NUMBER:"<<endl;
                                cin>>no;
                                int v;
                                int flag=0;
                                for(j=0;j<=i;j++)
                                    {
                                        if(s[j].account_no==no)
                                        {
                                            v=j;
                                            flag=1;
                                            break;
                                        }
                                        else
                                        {}
                                    }
                                    if(flag==1)
                                    {
                                        s[v].display_details();
                                    }
                                    else{
                                        cout<<"PLEASE CREATE AN ACCOUNT FIRST"<<endl;
                                    }



                                   break;
                        }
                        break;


                case 5 :

                        s[i].Deposit();
                        break;
                case 6 :
                        s[i].Withdraw();
                        break;

                case 7 :
                        break;
                default:

                cout<<"ENTERED CHOICE IS INVALID,TRY AGAIN"<<endl;

            }
        }


    }

    else if (type=='c'||type=='C')
    {
    	int choice=0;
    	while(choice!=6)
    	{
    		cout<<"CHOOSE YOUR CHOICE"<<endl;

    		cout<<"1)	CREAT AN ACCOUNT"<<endl;
    		cout<<"2)	DISPLAY BALANCE"<<endl;
    		cout<<"3)	DISPLAY WITH FULL DETAILS"<<endl;
    		cout<<"4)	DEPOSIT BALANCE"<<endl;
    		cout<<"5)	withdraw balance"<<endl;
    		cout<<"6)	EXIT"<<endl;

    		cin>>choice;
    		switch(choice)
    		{
    			case 1:
    				c[i].cgetdata();
    				break;

    			case 2:
    				c[i].cdisplay_balance();
    				break;

    			case 3:
    				while(1)
    				{
    					cout<<"ENTER YOUR ACCOUNT NO:";
    					cin>>no;
    					int v;
    					for(int k=0;k<i;k++)
    					{
    						if(c[k].account_no==no)
    						{
    							v=k;
    							flag=1;
    							break;
							}
							else
							{

							}
						}
						if(flag==1)
						{
							c[v].cdisplay_details();
						}
						else
						{
							cout<<"PLEASE CREATE AN ACCOUNT FIRST"<<endl;
							break;
						}
						break;


					}
					break;


				case 4:
					c[i].cdeposit();
					break;


				case 5:
					c[i].cwithdraw();
					break;

				case 6:
					break;

				default:
					  cout<<"ENTERED CHOICE IS INVALID,TRY AGAIN"<<endl;


			}

			}

	}




     cout<<"TO CONTINUE THIS MANAGEMENT SYSTEM FOR ANOTHER PERSON PRESS Y AND TO EXIT PRESS N"<<endl;
        char ch;
        cin>>ch;
        if(ch=='y'||ch=='Y')
          {
            continue;
          }
        else
          {
            break;
          }
      }


return 0;
}

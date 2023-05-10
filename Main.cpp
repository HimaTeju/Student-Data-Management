#include<fstream>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<iostream>

using namespace std;



void addData()
{

    system("cls");

    fstream file("data.csv",ios::out | ios::app);

    if(!file)
    {
        cout<<"\nFailed to open data.csv / data.csv file not found";
    }

    else
     cout<<"\t|Enter Data|"<<endl<<endl;

     string roll,name,college,branch;
     string moreData;

     cout<<"\nEnter Student's ROll Number: ";
     cin>>roll;
     file<<"\n"<<roll<<",";

     cout<<"\nEnter Student's Name: ";
     cin>>name;
     file<<name<<",";

     cout<<"\nEnter College: ";
     cin>>college;
     file<<college<<",";

     cout<<"\nEnter Branch: ";
     cin>>branch;
     file<<branch<<"\n";

     file.close();

     cout<<"\nAdd more Data? (Y/N)";

     cin>>moreData;
     if(moreData=="Y" || moreData=="y")
     {
        addData();
     }

     else
      return;     
}

void viewData(){

    system("cls");

    fstream file("data.csv");

    if(!file)
    {
        cout<<"Fail in opening this file";
    }
    cout<<"\n\t\t\t|Students Record\n\n";
    
    cout<<"Roll \t Name \t\t\t College \t\t Branch\n";

    string roll,name,college,branch;

    while(!file.eof()){

        getline(file,roll,',');
        getline(file,name,',');
        getline(file,college,',');
        getline(file,branch,'\n');

        cout<<roll<<" \t "<<name<<" \t\t\t "<<college<<" \t\t "<<branch<<endl;
        cout<<endl;   
    }
    file.close();
}


void studentFunction(){

    system("cls");
     cout<<"\n\t\t|LOGGED IN AS STUDENT|\n";

    fstream file("data.csv");

    if(!file)
    {
        cout<<"Fail in opening this file";
    }
    
    string rollno;
    cout<<"\n\n\t\t\t\t\tEnter Your Rollno: ";
    cin>>rollno;


    cout<<"\n\t\t\t|Students Record|\n\n";
    cout<<"Roll \t Name \t\t\t College \t\t Branch\n";

    string roll,name,college,branch;

    while(!file.eof()){

        getline(file,roll,',');
        getline(file,name,',');
        getline(file,college,',');
        getline(file,branch,'\n');

        if(rollno==roll)
        {
         break;
        }
    } 
                cout<<roll<<" \t "<<name<<" \t\t\t "<<college<<" \t\t "<<branch<<endl;
        cout<<endl; 
    file.close();

}

void adminFunction(){

    
    int option;
    do
    {
    cout<<"\n\n\t\t\t\t\t|LOGGED IN AS ADMIN|\n";
    cout<<"\n\n\t\t\t\t\t1.ADD STUDENT DATA";
    cout<<"\n\n\t\t\t\t\t2.VIEW STUDENT DATA";
    cout<<"\n\n\t\t\t\t\t3.MAIN MENU";
    cout<<"\n\n\t\t\t\t\t4.EXIT";
    cout<<"\n\n\t\t\t\t\tENTER YOUR CHOICE: ";

        cin>>option;
        {
            switch(option)
            {
                case 1:
                addData();
                break;

                case 2:
                viewData();
                break;

                case 3:
                exit(0);
                break;

                case 4:
                cout<<"You Are Exiting\n";
                exit(0);
            }
        }
    }while(option!=4);
}
void menu()
{
     int choice;

    cout<<"\n\t\tWELCOME TO THE DATABASE\n";
    cout<<"\n\t\t1.ADMIN LOGIN\n";
    cout<<"\n\t\t2.STUDENT LOGIN\n";
    string password;
    cin>>choice;

    switch(choice){

        case 1:
        cout<<"\n|Enter Your Password: ";
        cin>>password;
        if(password=="admin123")
         adminFunction();
        break;

        case 2: 
        cout<<"\n|Enter Your Password: ";
        cin>>password;
        if(password=="student123")
         studentFunction();
        

        break;

        default : exit(0);
    }

}


int main()
{
    system("color 40");
    menu();
}

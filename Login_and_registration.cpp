#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main(){
    int c;
    cout << "\t\t\t___________________________________________________\n\n\n";
    cout << "\t\t\t                Welcome to Login page              \n\n\n";
    cout << "\t\t\t                        Menu                       \n\n";
    cout << "                                                          \n\n";
    cout << "\t | Press 1 to Login              |" << endl;
    cout << "\t | Press 2 to Register           |" << endl;
    cout << "\t | Press 3 to Forgot Password    |" << endl;
    cout << "\t | Press 4 to Exit              |" << endl;
    cout << "Enter your choice: ";
    cin >> c;
    cout << endl;
    switch(c){
        case 1: login();
                break;
        case 2: registration();
                break;
        case 3: forgot();
                break;
        case 4: cout << "\t\t\t Thankyou! \n\n";
                break;
        default:system("cls"); //clear screen
                cout << "Invalid choice" << endl;
                main(); //calling main function
    }
}

void login(){
    int count;
    string userId, password, id, pass;
    system("cls");
    cout << "\t\t\t Please enter username and password" << endl;
    cout << "\t\t\t USERNAME: ";
    cin >> userId;
    cout << "\t\t\t PASSWORD: ";
    cin >> password;

    ifstream input("records.txt"); //already registered user's credentials are stored in "records.txt" file

    while(input >> id >> pass){
        if(id == userId && pass == password){
            count = 1;
            system("cls");

        }
    }
    input.close();
    if(count == 1){
        cout << userId << "\n Your LOGIN is successfull \n";
        main();
    }
    else{
        cout << "\n LOGIN ERROR \n PLease check Username and Password\n";
        main();
    }
}

void registration(){
    string ruserId, rpassword, rid, rpass;
    system("cls");
    cout << "\t\t\t Enter the Username: ";
    cin >> ruserId;
    cout << "\t\t\t Enter the Password: ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app); //ios->input/output stream, app->append mode
    f1 << ruserId << ' ' << rpassword << endl;
    system("cls");
    
    cout << "\n\t\t\t Registration is successfull! \n";
    main();
}

void forgot(){
    int option;
    system("cls");
    cout << "\t\t\t Forgot Password?\n";
    cout << "Press 1 to search yout Id by Username" << endl;
    cout << "Press 2 to go back to the main menu" << endl;
    cout << "\t\t\t Enter your choice: ";
    cin >> option;
    switch(option){
        case 1:{
            int count=0;
            string suserId, sid, spass;
            cout << "\n\t\t\t Enter the username you remembered: ";
            cin >> suserId;

            ifstream f2("records.txt");
            while(f2 >> sid >> spass){
                if(sid == suserId){
                    count = 1;
                }
            }
            f2.close();
            if(count == 1){
                cout << "\n\n Account found! \n";
                cout << "\n\n Password is: " << spass;
                main();
            }
            else{
                cout <<"\n\t Sorry! Account not found! \n";
                main();
            }
            break;
        }
        case 2:{
            main();
        }
        default: cout << "\t\t\t Invalid choice" << endl;
                forgot();
    }
}
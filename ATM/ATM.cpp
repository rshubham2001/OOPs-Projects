#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

/* Mini Project-- ATM
   ->Check Balance
   ->Deposit Money
   ->Withdraw Money
   ->View Account Details
   ->Update Mobile Number
*/

class atm
{
    // private member variables
private:
    long int account_no;
    int pin;
    string name;
    double balance;
    long long int mobile;

    // public member functions
public:
    // setData function to set the Dtaa into the private memeber variable.
    void setData(long int account_no, int pin, string name, double balance, long long int mobile)
    {
        this->account_no = account_no;
        this->pin = pin;
        this->name = name;
        this->balance = balance;
        this->mobile = mobile;
    }

    // getAcc function is returning the user's account_number.
    long int getAcc()
    {
        return this->account_no;
    }

    // getName function is returning the user's name.
    string getName()
    {
        return this->name;
    }

    // getPin funtion is returning the user's account pin.
    int getPin()
    {
        return this->pin;
    }

    // getBalance function is returning the user's account balance.

    double getBalance()
    {
        return this->balance;
    }

    // getMobile function is returning user's Mobile number.

    long long int getMobile()
    {
        return this->mobile;
    }

    // setMobile function updating the user's mobile number.
    void setMobile(long long int pre_mobile, long long int new_mobile)
    {
        if (pre_mobile == this->mobile)
        { // checking if the old mobile is match or not

            // matched
            this->mobile = new_mobile;
            cout << "Succesfully updated Mobile number.";
            _getch();
        }

        // not matched
        else
        {
            cout << "Incorrect Old Mobile number. Please try again.";
            _getch();
        }
    }

    // cashWitgdraw function is used to withdraw money from ATM
    void cashWithdraw(double amount)
    {
        if (amount > 0 and amount <= this->balance)
        { // checking if amount is valid or not

            // valid
            this->balance -= amount;
            cout << "Please collect your Cash." << endl;
            cout << "Available Balance : " << this->balance;
            _getch();
        }

        // not valid
        else
        {
            cout << " Invalid Input or Insufficient Balance.";
            _getch();
        }
    }

    // cashDeposit function is used to depositing money in ATM.
    void cashDeposit(double amount)
    {
        if (amount > 0)
        { // checking if amount is valid or not

            // valid
            this->balance += amount;
            cout << "Succecfull!!" << endl;
            cout << "Available Balance : " << this->balance;
            _getch();
        }

        // not valid
        else
        {
            cout << "Invlaid Input. Please try again.";
            _getch();
        }
    }
};

int main()
{

    int choice = 0, enterPin;
    long int account_no;

    system("cls");

    atm user1; // Created user1 (object of atm class)

    user1.setData(12345678, 2001, "Shubham", 100000.49, 9876543210); // setting the default data

    do
    {
        system("cls");
        cout << "__________________Welcome to ATM________________" << endl<<endl;
        cout << "Enter the Account number :-  ";
        cin >> account_no;
        cout << "Enter the PIN :- ";
        cin >> enterPin;
        if (account_no == user1.getAcc() and enterPin == user1.getPin())
        {

            do
            {
                double amount;
                long long int old_mobile, new_mobile;
                system("cls");

                // User Interface
                cout << "__________________Welcome to ATM________________" << endl<<endl;
                cout << "1. Check Balance" << endl;
                cout << "2. Deposit Money" << endl;
                cout << "3. Withdraw Money" << endl;
                cout << "4. Account Details" << endl;
                cout << "5. Update Mobile Number" << endl;
                cout << "6. Exit" << endl;
                cin >> choice; // taking user choice

                switch (choice)
                { // switch condition

                case 1:
                    cout << "Your Account Balance : " << user1.getBalance() << endl;
                    _getch();
                    break;

                case 2:
                    cout << "Enter the Amount for deposit : ";
                    cin >> amount;
                    user1.cashDeposit(amount);
                    _getch();
                    break;

                case 3:
                    cout << "Enter the Amount for witgdrawing : ";
                    cin >> amount;
                    user1.cashWithdraw(amount);
                    _getch();
                    break;

                case 4:
                    cout << "___________User's Details_____________" << endl;
                    cout << "Account Name : " << user1.getName() << endl;
                    cout << "Account  No. : " << user1.getAcc() << endl;
                    cout << "Balance : " << user1.getBalance() << endl;
                    cout << "Mobile No. : " << user1.getMobile() << endl;
                    _getch();
                    break;

                case 5:
                    cout << "Enter Old Mobile No. : ";
                    cin >> old_mobile;
                    cout << "Enter New Mobile No. : ";
                    cin >> new_mobile;
                    user1.setMobile(old_mobile, new_mobile);
                    break;

                case 6:
                    exit(0);
                    break;

                default:
                    cout << "Enter valid choice.";
                }
            } while (1);
        }
        else
        {
            cout << "User's Details is Invalid. Please try again." << endl;
            _getch();
        }
    } while (1);

    return 0;
}
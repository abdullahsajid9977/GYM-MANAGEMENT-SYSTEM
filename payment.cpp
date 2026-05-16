#include <iostream>
#include <fstream>
using namespace std;

class Payment {

private:
    int paymentID;
    int memberID;
    int amount;
    string month;

public:

    void addPayment() {

        ofstream file("Payment.txt", ios::app);

        cout << "\n====================================\n";
        cout << "          ADD PAYMENT\n";
        cout << "====================================\n";

        cout << "Enter Payment ID : ";
        cin >> paymentID;

        cout << "Enter Member ID  : ";
        cin >> memberID;

        cout << "Enter Month Name : ";
        cin >> month;

        cout << "Enter Total Payment : ";
        cin >> amount;

        file << paymentID << endl;
        file << memberID << endl;
        file << month << endl;
        file << amount << endl;

        file.close();

        cout << "\n Payment Saved Successfully!\n";
    }

    void viewPayments() {

        ifstream file("Payment.txt");

        cout << "\n====================================\n";
        cout << "        PAYMENT RECORDS\n";
        cout << "====================================\n";

        while(file >> paymentID >> memberID >> month >> amount) {

            cout << "\n------------------------------------\n";
            cout << "Payment ID : " << paymentID << endl;
            cout << "Member ID  : " << memberID << endl;
            cout << "Month      : " << month << endl;
            cout << "Amount     : " << amount << " rs\n";
        }

        file.close();
    }
};
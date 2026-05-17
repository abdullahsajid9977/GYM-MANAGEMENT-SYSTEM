#include <iostream>
#include <fstream>
using namespace std;

class FinancialReport {

private:
    string month;
    int year;

    double rent = 0;
    double electricity = 0;
    double water = 0;
    double trainerSalary = 0;
    double sweeperSalary = 0;
    double maintenance = 0;

    double membershipRevenue = 0;
    double otherTrainingFees = 0;

    double totalExpenses = 0;
    double totalRevenue = 0;
    double netProfit = 0;

public:

    // ================= EXPENSE INPUT =================
    void inputExpenses() {

        cout << "\nEnter Month (e.g. January): ";
        cin >> month;

        cout << "Enter Year: ";
        cin >> year;

        cout << "\n====================================\n";
        cout << "       EXPENSE DETAILS\n";
        cout << "====================================\n";

        cout << "Enter Rent: ";
        cin >> rent;

        cout << "Enter Electricity Bill: ";
        cin >> electricity;

        cout << "Enter Water Bill: ";
        cin >> water;

        cout << "Enter Trainer Salary: ";
        cin >> trainerSalary;

        cout << "Enter Sweeper Salary: ";
        cin >> sweeperSalary;

        cout << "Enter Maintenance Cost: ";
        cin >> maintenance;

        cout << "\n Expense Data Saved Successfully!\n";
    }


    // ================= AUTO REVENUE =================
  void inputRevenue() {

    cout << "\nEnter Month Name To Calculate Revenue : ";
    cin >> month;

    ifstream file("Payment.txt");

    if(!file) {
        cout << "ERROR: Payment.txt file not found!\n";
        return;
    }

    int paymentID;
    int memberID;
    int amount;

    string paymentMonth;

    totalRevenue = 0;

    while(file >> paymentID >> memberID >> paymentMonth >> amount) {

        if(paymentMonth == month) {
            totalRevenue += amount;
        }
    }

    file.close();

    cout << "\n====================================\n";
    cout << "Month Name   : " << month << endl;
    cout << "Total Revenue: " << totalRevenue << " rs\n";
    cout << "====================================\n";
}
  void calculateReport() {

    totalExpenses = rent + electricity + water +
                    trainerSalary + sweeperSalary + maintenance;

    netProfit = totalRevenue - totalExpenses;
}


    // ================= SHOW REPORT =================
    void showReport() {

        cout << "\n====================================\n";
        cout << "        " << month << " " << year << " REPORT\n";
        cout << "====================================\n";

        cout << "Total Expenses : " << totalExpenses << " rs\n";
        cout << "Total Revenue  : " << totalRevenue << " rs\n";
        cout << "Net Profit     : " << netProfit << " rs\n";

        cout << "====================================\n";

        if(netProfit >= 0)
            cout << "STATUS : PROFIT\n";
        else
            cout << "STATUS : LOSS\n";

        cout << "====================================\n";
    }


    // ================= SAVE REPORT =================
    void saveReport() {

        ofstream file("Report.txt", ios::app);

        file << month << " "
             << year << " "
             << totalExpenses << " "
             << totalRevenue << " "
             << netProfit << endl;

        file.close();

        cout << "\n Monthly Report Saved Successfully!\n";
    }


    // ================= VIEW OLD REPORTS =================
    void viewReports() {

        ifstream file("Report.txt");

        string m;
        int y;
        double exp, rev, prof;

        cout << "\n====================================\n";
        cout << "       PREVIOUS MONTHLY REPORTS\n";
        cout << "====================================\n";

        while(file >> m >> y >> exp >> rev >> prof) {

            cout << "\n------------------------------------\n";
            cout << "Month & Year : " << m << " " << y << endl;
            cout << "Total Expenses : " << exp << " rs\n";
            cout << "Total Revenue  : " << rev << " rs\n";
            cout << "Net Profit     : " << prof << " rs\n";
        }

        file.close();
    }
};
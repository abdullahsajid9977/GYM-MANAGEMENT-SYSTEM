#include <iostream>
#include <string>
using namespace std;

class Member;
class Payment;
class Plan;
class Equipment;
class FinancialReport;

class GymSystem {
public:
    virtual void mainMenu() = 0;
    virtual ~GymSystem() {}
};

#include "Member.cpp"
#include "Payment.cpp"
#include "Plan.cpp"
#include "Equipment.cpp"
#include "FinancialReport.cpp"

void header(string title) {
    cout << "\n============================================\n";
    cout << "        " << title << "\n";
    cout << "============================================\n";
}

class Admin : public GymSystem {

private:
    string username;
    string password;

    static int totalLogins;

    Member member;
    Payment payment;
    Plan plan;
    Equipment equipment;
    FinancialReport report;

public:

    bool login() {

        header("GYM MANAGEMENT SYSTEM");

        cout << "Username : ";
        cin >> username;

        cout << "Password : ";
        cin >> password;

        try {
            if(username == "admin" && password == "786") {
                totalLogins++;
                cout << "\nLogin Successful!\n";
                return true;
            }
            else {
                throw "Invalid Username or Password!";
            }
        }
        catch(const char* msg) {
            cout << "\nERROR: " << msg << endl;
            return false;
        }
    }

    void memberMenu() {

        int choice;

        do {
            header("MEMBER MANAGEMENT");

            cout << "1. Add Member\n";
            cout << "2. View Members\n";
            cout << "3. Delete Member\n";
            cout << "4. Back\n";

            cout << "\nEnter Choice: ";
            cin >> choice;

            switch(choice) {
            case 1:
                member.addMember();
                break;
            case 2:
                member.viewMembers();
                break;
            case 3:
                member.deleteMember();
                break;
            case 4:
                cout << "Returning to Main Menu...\n";
                break;
            default:
                cout << "Invalid Choice!\n";
            }

        } while(choice != 4);
    }

    void paymentMenu() {

        int choice;

        do {
            header("PAYMENT SECTION");

            cout << "1. Add Payment\n";
            cout << "2. View Payments\n";
            cout << "3. Back\n";

            cout << "\nEnter Choice: ";
            cin >> choice;

            switch(choice) {
            case 1:
                payment.addPayment();
                break;
            case 2:
                payment.viewPayments();
                break;
            case 3:
                cout << "Returning to Main Menu...\n";
                break;
            default:
                cout << "Invalid Choice!\n";
            }

        } while(choice != 3);
    }

    void planMenu() {
        header("MEMBERSHIP PLANS");
        plan.viewPlans();
    }

    void equipmentMenu() {

        int choice;

        do {
            header("EQUIPMENT SECTION");

            cout << "1. View Equipment\n";
            cout << "2. Add Maintenance Record\n";
            cout << "3. View Maintenance Records\n";
            cout << "4. Back\n";

            cout << "\nEnter Choice: ";
            cin >> choice;

            switch(choice) {
            case 1:
                equipment.viewEquipment();
                break;
            case 2:
                equipment.maintenance();
                break;
            case 3:
                equipment.viewMaintenance();
                break;
            case 4:
                cout << "Returning to Main Menu...\n";
                break;
            default:
                cout << "Invalid Choice!\n";
            }

        } while(choice != 4);
    }

    void reportMenu() {

        int choice;

        do {
            header("FINANCIAL REPORT");

            cout << "1. Enter Expenses\n";
            cout << "2. Enter Revenue\n";
            cout << "3. Show Report\n";
            cout << "4. Back\n";

            cout << "\nEnter Choice: ";
            cin >> choice;

            switch(choice) {
            case 1:
                report.inputExpenses();
                break;
            case 2:
                report.inputRevenue();
                break;
            case 3:
                report.calculateReport();
                report.showReport();
                break;
            case 4:
                cout << "Returning to Main Menu...\n";
                break;
            default:
                cout << "Invalid Choice!\n";
            }

        } while(choice != 4);
    }

    void mainMenu() {

        int choice;

        do {

            header("MAIN DASHBOARD");

            cout << "1. Manage Members\n";
            cout << "2. Manage Payments\n";
            cout << "3. Membership Plans\n";
            cout << "4. Equipment Section\n";
            cout << "5. Financial Reports\n";
            cout << "6. Logout\n";

            cout << "\nEnter Choice: ";
            cin >> choice;

            switch(choice) {

            case 1:
                memberMenu();
                break;
            case 2:
                paymentMenu();
                break;
            case 3:
                planMenu();
                break;
            case 4:
                equipmentMenu();
                break;
            case 5:
                reportMenu();
                break;
            case 6:
                cout << "Logging Out...\n";
                break;
            default:
                cout << "Invalid Choice!\n";
            }

        } while(choice != 6);
    }
};

int Admin::totalLogins = 0;
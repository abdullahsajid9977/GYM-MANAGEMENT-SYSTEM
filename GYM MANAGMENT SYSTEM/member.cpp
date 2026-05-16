#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Member {

protected:
    string name;
    int age;

private:
    int memberID;
    string membershipPlan;
    string personalTrainer;
    int payment;
    string month;
    int year;

public:

    void addMember() {

        ofstream file("Member.txt", ios::app);
        ofstream revenueFile("Revenue.txt", ios::app);

        cout << "\n=================================================\n";
        cout << "              ADD NEW GYM MEMBER\n";
        cout << "=================================================\n";

        cout << "Enter Month (e.g January): ";
        cin >> month;

        cout << "Enter Year: ";
        cin >> year;

        cout << "Enter Member ID   : ";
        cin >> memberID;

        cin.ignore();

        cout << "Enter Member Name : ";
        getline(cin, name);

        cout << "Enter Age         : ";
        cin >> age;

        cout << "\n--------------- MEMBERSHIP PLANS ---------------\n";
        cout << "1. Basic Plan (3000 rs)\n";
        cout << "2. Premium Plan (5000 rs)\n";
        cout << "Enter Choice: ";

        int planChoice;
        cin >> planChoice;

        if(planChoice == 1) {
            membershipPlan = "Basic Plan";
            payment = 3000;
        }
        else {
            membershipPlan = "Premium Plan";
            payment = 5000;
        }

        cout << "\nDo you want Personal Trainer? (1 = Yes / 2 = No): ";
        int trainerChoice;
        cin >> trainerChoice;

        if(trainerChoice == 1) {
            personalTrainer = "Yes";
            payment += 10000;   // Fixed trainer price
        }
        else {
            personalTrainer = "No";
        }

        cout << "\n=================================================\n";
        cout << "               MEMBER SUMMARY\n";
        cout << "=================================================\n";
        cout << "Month          : " << month << " " << year << endl;
        cout << "ID             : " << memberID << endl;
        cout << "Name           : " << name << endl;
        cout << "Age            : " << age << endl;
        cout << "Plan           : " << membershipPlan << endl;
        cout << "PersonalTrainer: " << personalTrainer << endl;
        cout << "Total Payment  : " << payment << " rs\n";

        cout << "\nPress Enter to Save...";
        cin.ignore();
        cin.get();

        // Save member
        file << month << endl;
        file << year << endl;
        file << memberID << endl;
        file << name << endl;
        file << age << endl;
        file << membershipPlan << endl;
        file << personalTrainer << endl;
        file << payment << endl;

        file.close();

        // Save revenue automatically
        revenueFile << month << " " << year << " " << payment << endl;
        revenueFile.close();

        cout << "\nMember Successfully Added!\n";
    }

    void viewMembers() {

        ifstream file("Member.txt");

        string nameData, planData, trainerData, monthData;
        int id, ageData, paymentData, yearData;

        cout << "\n=================================================\n";
        cout << "               MEMBER RECORDS\n";
        cout << "=================================================\n";

        while(file >> monthData) {

            file >> yearData;
            file >> id;
            file.ignore();
            getline(file, nameData);
            file >> ageData;
            file.ignore();
            getline(file, planData);
            getline(file, trainerData);
            file >> paymentData;

            cout << "\n---------------------------------------------\n";
            cout << "Month   : " << monthData << " " << yearData << endl;
            cout << "ID      : " << id << endl;
            cout << "Name    : " << nameData << endl;
            cout << "Age     : " << ageData << endl;
            cout << "Plan    : " << planData << endl;
            cout << "Trainer : " << trainerData << endl;
            cout << "Paid    : " << paymentData << " rs\n";
        }

        file.close();
    }

    void deleteMember() {

        int deleteID;
        cout << "\nEnter Member ID to Delete: ";
        cin >> deleteID;

        ifstream file("Member.txt");
        ofstream temp("Temp.txt");

        string nameData, planData, trainerData, monthData;
        int id, ageData, paymentData, yearData;

        bool found = false;

        while(file >> monthData) {

            file >> yearData;
            file >> id;
            file.ignore();
            getline(file, nameData);
            file >> ageData;
            file.ignore();
            getline(file, planData);
            getline(file, trainerData);
            file >> paymentData;

            if(id != deleteID) {

                temp << monthData << endl;
                temp << yearData << endl;
                temp << id << endl;
                temp << nameData << endl;
                temp << ageData << endl;
                temp << planData << endl;
                temp << trainerData << endl;
                temp << paymentData << endl;
            }
            else {
                found = true;
            }
        }

        file.close();
        temp.close();

        remove("Member.txt");
        rename("Temp.txt", "Member.txt");

        if(found)
            cout << "Member Deleted Successfully!\n";
        else
            cout << "Member Not Found!\n";
    }
};
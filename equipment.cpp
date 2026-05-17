#include <iostream>
#include <fstream>
using namespace std;

class Equipment {

private:
    string maintenanceDate;

public:

    // ================= VIEW EQUIPMENT =================
    void viewEquipment() {

        cout << "\n========== GYM EQUIPMENT LIST ==========\n";

        cout << "1. Treadmill\n";
        cout << "2. Exercise Bike\n";
        cout << "3. Elliptical Trainer\n";
        cout << "4. Rowing Machine\n";
        cout << "5. Chest Press Machine\n";
        cout << "6. Leg Press Machine\n";
        cout << "7. Smith Machine\n";
        cout << "8. Lat Pulldown Machine\n";
        cout << "9. Cable Crossover Machine\n";
        cout << "10. Shoulder Press Machine\n";
        cout << "11. Pec Deck Machine\n";
        cout << "12. Seated Row Machine\n";
        cout << "13. Leg Curl Machine\n";
        cout << "14. Leg Extension Machine\n";
        cout << "15. Abdominal Crunch Machine\n";
        cout << "16. Stair Climber\n";
        cout << "17. Adjustable Bench\n";
        cout << "18. Flat Bench\n";
        cout << "19. Incline Bench\n";
        cout << "20. Dumbbells\n";
        cout << "21. Barbells\n";
        cout << "22. Weight Plates\n";
        cout << "23. Kettlebells\n";
        cout << "24. Pull-Up Bar\n";
        cout << "25. Battle Ropes\n";
        cout << "26. Resistance Bands\n";
        cout << "27. Medicine Balls\n";
        cout << "28. Squat Rack\n";
        cout << "29. Hack Squat Machine\n";
        cout << "30. Functional Trainer Machine\n";

        cout << "========================================\n";
    }

    void maintenance() {

        ofstream file("Maintenance.txt", ios::app);

        cout << "Enter Maintenance Date (dd/mm/yy): ";
        cin >> maintenanceDate;

        file << maintenanceDate << endl;

        file.close();

        cout << "Maintenance Record Saved Successfully!\n";
    }

    void viewMaintenance() {

        ifstream file("Maintenance.txt");

        cout << "\n===== Maintenance Records =====\n";

        while(file >> maintenanceDate) {
            cout << maintenanceDate << endl;
        }

        file.close();
    }
};
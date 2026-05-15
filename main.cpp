#include <iostream>
using namespace std;

#include "Admin.cpp"

int main() {

    GymSystem* system = new Admin();

    Admin* adminPtr = dynamic_cast<Admin*>(system);

    if(adminPtr->login()) {
        system->mainMenu();
    }

    delete system;

    return 0;
}
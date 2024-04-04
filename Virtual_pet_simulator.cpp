#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Pet {
protected:
    int hunger;
    int happiness;
    int cleanliness;
public:
    Pet() : hunger(50), happiness(50), cleanliness(50) {}

    virtual void feed() = 0;
    virtual void play() = 0;
    virtual void clean() = 0;

    void showStatus() {
        cout << "Hunger: " << hunger << ", Happiness: " << happiness << ", Cleanliness: " << cleanliness << endl;
    }
};

class Dog : public Pet {
public:
    void feed() override {
        hunger -= 10;
        happiness += 5;
    }

    void play() override {
        happiness += 10;
    }

    void clean() override {
        cleanliness += 10;
    }
};

class Cat : public Pet {
public:
    void feed() override {
        hunger -= 5;
        happiness += 3;
    }

    void play() override {
        happiness += 8;
    }

    void clean() override {
        cleanliness += 5;
    }
};

int main() {
    srand(time(nullptr));

    Pet *pet;
    int choice;

    // Randomly choose between Dog and Cat
    if (rand() % 2 == 0)
        pet = new Dog();
    else
        pet = new Cat();

    cout << "Welcome to Virtual Pet Simulator!" << endl;

    do {
        cout << "Choose an action:" << endl;
        cout << "1. Feed" << endl;
        cout << "2. Play" << endl;
        cout << "3. Clean" << endl;
        cout << "4. Exit" << endl;

        cin >> choice;

        switch (choice) {
            case 1:
                pet->feed();
                break;
            case 2:
                pet->play();
                break;
            case 3:
                pet->clean();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

        pet->showStatus();

    } while (choice != 4);

    delete pet;

    return 0;
}
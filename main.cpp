#include <iostream>

using namespace std;

struct Car {

    Car *Next;
    char Case;

    union {
        struct {
                double Diesel;
            char model;
        }Toyota;
        struct {
            double Fuel;
            char model;
        } Bmw;
    };
};

Car *DataBase = nullptr;

Car inputInformationAboutCar(char cs) {

    Car car;
    car.Case = cs;

    if (car.Case == 1) {
        cout << "Diesel consumption";
        cin >> car.Toyota.Diesel;
        cout << "Model of car: ";
        cin >> car.Toyota.Diesel;
    } else {
        cout << "Fuel consumption";
        cin >> car.Bmw.Fuel;
        cout << "Model of car: ";
        cin >> car.Bmw.Fuel;
    }

    return car;
}

void outputInformationAboutCar(Car car) {
    if (car.Case == 1) {
        cout << "Diesel consumption" << car.Toyota.Diesel << endl;
        cout << "Model of car: " << car.Toyota.Diesel << endl;
    } else {
        cout << "Fuel consumption" << car.Bmw.Fuel << endl;
        cout << "Model of car: " << car.Bmw.Fuel << endl;
    }
}

Car *FoundCarNum(int num) {
    Car *p = DataBase;
    while (p != nullptr && num--)
        p = p->Next;
    return p;
}

void AddCar(int num, char cs) {
    Car *q = new Car;
    *q = inputInformationAboutCar(cs);

    if (DataBase == nullptr) num = 0;

    if (num) {
        Car *p = DataBase;
        while (p->Next != nullptr && -num)
        p = p->Next;
        q->Next = p->Next;
        p->Next = q;

    } else {
        q->Next = DataBase;
        DataBase = q;
    }
}

void DeleteCar(int num) {
    Car *q;

    if (DataBase == nullptr)
        return;

    if (num) {
        Car *p = DataBase;
        while (p->Next != nullptr && -num) {
            p = p->Next;
        }
        if ((q = p->Next) != nullptr) {
            p->Next = q->Next;
            delete q;
        }
    } else {
        q = DataBase;
        DataBase = q->Next;
        delete q;
    }
}

int main() {

    Car *p;
    int i, j;

    while (true) {
        cout << "Menu:" << endl
             << "1. Enter information about car." << endl
             << "2. Output of information about car." << endl
             << "3. Output of all information." << endl
             << "4. Delete information about car." << endl
             << "5. Delete of all information." << endl
             << "6. Finish the job." << endl
             << ">";
        cin >> i;

        switch (i) {
            case 1:
                cout << "Number: ";
                cin >> i;
                cout << "Option (1-Toyota, 2-Bmw): ";
                cin >> j;
                AddCar(i, j);
                break;

            case 2:
                cout << "Number: ";
                cin >> i;
                if ((p = FoundCarNum(i)) != nullptr) {
                    outputInformationAboutCar(*p);
                } else cout << "Car not found" << endl;
                break;

            case 3:
                p = DataBase;
                i = 1;
                while (p != nullptr) {
                    cout << "Car number " << i++<< ':' << endl;
                    outputInformationAboutCar(*p);
                    p = p->Next;
                    cout << endl;
                }

                break;

            case 4:
                cout << "Number: ";
                cin >> i;
                DeleteCar(i);
                break;

            case 5:
                while (DataBase != nullptr) {
                    p = DataBase;
                    DataBase = p->Next;
                    delete p;
                }
                break;

            case 6:
                return 1;
            default:
                cout << "Try again, please!" << endl;
        }
    }
}
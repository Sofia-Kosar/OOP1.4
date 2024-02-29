#include <iostream>
#include "Polynomial.h"
using namespace std;

void displayMenu() {
    cout << "==== Menu ====" << endl;
    cout << "1. Initialize Polynomial 1" << endl;
    cout << "2. Initialize Polynomial 2" << endl;
    cout << "3. Evaluate Polynomial" << endl;
    cout << "4. Add Polynomials" << endl;
    cout << "5. Subtract Polynomials" << endl;
    cout << "6. Multiply Polynomials" << endl;
    cout << "7. Display Polynomials" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Polynomial p1, p2;
    int choice;
    double x;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the first polynomial:" << endl;
            p1.Read();
            break;
        case 2:
            cout << "Enter the second polynomial:" << endl;
            p2.Read();
            break;
        case 3:
            cout << "Enter the value of x: ";
            cin >> x;
            cout << "Enter the polynomial to evaluate:" << endl;
            (p1.evaluate(x));
            break;
        case 4:
            cout << "Sum of the polynomials:" << endl;
            (p1.add(p2)).Display();
            break;
        case 5:
            cout << "Difference of the polynomials:" << endl;
            (p1.subtract(p2)).Display();
            break;
        case 6:
            cout << "Product of the polynomials:" << endl;
            (p1.multiply(p2)).Display();
            break;
        case 7:
            cout << "Polynomial 1:" << endl;
            p1.Display();
            cout << "Polynomial 2:" << endl;
            p2.Display();
            break;
        case 8:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 8." << endl;
        }
    } while (choice != 8);

    return 0;
}
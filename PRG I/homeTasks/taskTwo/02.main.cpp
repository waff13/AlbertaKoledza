// Car parking payments calculator.

#include <iostream>

using namespace std;

double calculateAmount (double time);

int main() {
    
    double time, amount;
    cout << "Please enter the amount of parking time in hours: " << endl;
    cin >> time;
    
    amount = calculateAmount (time);
    cout << "For " << time << " hours of parking you will pay " << amount << " LVL." << endl;
    
    return 0;
}

double calculateAmount (double time) {
    
    double result;
    int additionalHoursCounter = 0;
    
    if ((time > 0.1) && (time <= 3.00)) {
        result = 2.00;
    } else {

        while (time > 3.00) {
            time = (time - 1.00);
            additionalHoursCounter++;
        }
 
        result = 2.00 + (0.5 * additionalHoursCounter);
    }
    
    if (result > 10.00) {
        result = 10.00;
    }
    
    return result;
}

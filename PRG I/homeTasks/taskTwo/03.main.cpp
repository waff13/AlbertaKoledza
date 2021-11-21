// Use function in another function

#include <iostream>

using namespace std;

int vms (int Vkmh);
int meet_time (int kmh1, int kmh2, int km);

int main() {
    
    int kmh1, kmh2, km;
    
    cout << "Enter velocity of the first object, in km/h:" << endl;
    cin >> kmh1;
    cout << "Enter velocity of the second object, in km/h:" << endl;
    cin >> kmh2;
    cout << "Enter the distance between objects, in km:" << endl;
    cin >> km;
    
    int seconds = meet_time (kmh1, kmh2, km);
    cout << "Objects will meet in approximately " << seconds << " seconds" << endl;
    
    return 0;
}

int vms (int Vkmh) {
    
    double coefficient = 0.278;            // 1000 meters : 3600 seconds
    double result = (coefficient * Vkmh);
    //cout << "(vms) Result, double: " << result << endl;
    return (int) (result + 0.5);
    
}

int meet_time (int kmh1, int kmh2, int km) {
    
    int speed1 = vms (kmh1);
    //cout << kmh1 << " km/h is " << speed1 << " m/s" << endl;
    int speed2 = vms (kmh2);
    //cout << kmh2 << " km/h is " << speed2 << " m/s" << endl;
    int distance = (km * 1000);
    int seconds = distance / (speed1 + speed2);
    return seconds;
    
}

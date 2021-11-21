/* Given the speed of two objects and the distance between them calculate in what time
 * they will meet. Use two functions, int vms (int) and int meet_time (int, int, int).
 * 
 * For more accurate results we will add 0.5 to double so it converts to int more accurately. 
 * For example, (double) 3.8 converts to (int) 3, but (double) (3.8 + 0.5) converts to (int) 4, 
 * which is more accurate. However, (double) 3.2 in that case still converts to (int) 3.
 * 
*/

#include <iostream>

using namespace std;

int vms (int);  // declaring function vms
int meet_time (int, int, int);  // declaring function meet_time

int main() {
    
    int kmh1, kmh2, km;  // declaring variables
    
    cout << "Enter velocity of the first object, in km/h:" << endl;
    cin >> kmh1;  // getting velocity of the first object from user
    cout << "Enter velocity of the second object, in km/h:" << endl;
    cin >> kmh2;  // getting velocity of the second object from user
    cout << "Enter the distance between objects, in km:" << endl;
    cin >> km;  // getting the distance between objects from user
    
    int seconds = meet_time (kmh1, kmh2, km); // passing variables kmh1, kmh2, km to function and storing result
    cout << "Objects will meet in approximately " << seconds << " seconds" << endl;
    
    return 0;
}

int vms (int Vkmh) { // this function converts speed in kmph to meters per second and returns the result
    
    const double coefficient = 0.278;  // 1000 meters : 3600 seconds = 0.278
    double result = (coefficient * Vkmh); // in order to get speed in meters per second we multiply given speed and coefficient
    return (int) (result + 0.5); // converting double to int; we add 0.5 for more accurate conversion
    
}

int meet_time (int kmh1, int kmh2, int km) { // this function returns time when two objects will meet in seconds
    
    int speed1 = vms (kmh1); // converting first objects' speed to meters per second
    int speed2 = vms (kmh2); // converting second objects' speed to meters per second
    int distance = (km * 1000); // converting kilometers to meters
    int seconds = distance / (speed1 + speed2); // calculating result, dividing distance by summ of objects' speed
    return seconds; // returning the result
    
}

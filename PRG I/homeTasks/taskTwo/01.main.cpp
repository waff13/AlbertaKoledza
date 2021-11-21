// Find the area of the striked-through figure

#include <iostream>

using namespace std;

double pi = 3.14;
double circle_area (double R);

int main() {
    
    double R1, R2;
    cout << "Please enter R1: " << endl;
    cin >> R1;
    cout << "Now enter R2: " << endl;
    cin >> R2;
    
    double OuterCircleArea = circle_area (R1);
    double InnerCircleArea = circle_area (R2);
    double SmallCircleArea = circle_area (R2/2);
    double result = OuterCircleArea - InnerCircleArea + (2 * SmallCircleArea);
    cout << "The area of the selected figure is " << result << endl;
    
    return 0;
}

double circle_area (double R) {
    
    return pi * (R * R);

}

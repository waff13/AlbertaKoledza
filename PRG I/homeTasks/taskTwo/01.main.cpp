/* Find the area of the striked-through figure
 * 
 * Basically this figure consists of four circles: outer (striked-through) circle with radius R1, 
 * inner (white) circle with radius R2, and two small circles with diameters = R2 (so their radius 
 * is R2/2). In order to find the area of striked-through circle we need to find the area of the 
 * outer circle, than substract the area of the inner circle, and add the area of two small 
 * circles. 
 * 
 * The area of the circle can be calculated with the formula Area = pi * radius * radius.
*/

#include <iostream>

using namespace std;

const double pi = 3.14; // constant pi that is used to calculate circle area
double circle_area (double); // dealaration of the method used for circle area calculation

int main() {
    
    double R1, R2; // declaring two variables for R1 and R2
    cout << "Please enter R1: " << endl;
    cin >> R1; // user enters R1
    cout << "Now enter R2: " << endl;
    cin >> R2; // user enters R2
	
	if (R2 > R1) { // if R2 is bigger than R1 we cannot create the figure and calculate the area
		
		cout << "Obviously R1 should be bigger than R2!" << endl;
		
	} else {
		
		double OuterCircleArea = circle_area (R1); // calculating the area of the outer circle 
		double InnerCircleArea = circle_area (R2); // calculating the area of the inner circle
		double SmallCircleArea = circle_area (R2/2); // calculating the area of the small circle
		double result = OuterCircleArea - InnerCircleArea + (2 * SmallCircleArea); // calculating the final result
		cout << "The area of the selected figure is " << result << endl; // printing out the final result
		
	}
    
    return 0;
}

double circle_area (double R) { // method for calculating circle area
    
    return pi * (R * R); // calculating circle area using constant pi and radius R.

}

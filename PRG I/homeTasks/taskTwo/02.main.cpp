/* Car parking payments calculator.
 * 
 * The programm should calculate the amount of money user should pay for car parking. If the car is 
 * parked for up to three hours, the price is 2.00 LVL. Than for each hour 0.5 LVL are added till 
 * the moment the total bill reaches 10.00 LVL. That is the maximum amount user shall pay.
 * 
 * In order to make the programm work we should consider the following time scopes: 
 * -- 0 hours - user pays nothing; 
 * -- 0.1 hours up to 3 hours - user pays 2 LVL; 
 * -- more than 3 hours -- user pays 2 LVL plus extra 0.5 LVL for every parking hour (we will 
 * 		calculate it in a loop, where we will decrease the amount of parking time while 
 * 		increaing the amount of additional hours to be payed. One can think that this can be 
 * 		calculated much easier, e.g. (additionalHoursCounter = time - 3.0), but there will be a 
 * 		slight mistake: if time is 3.40 and we substract 3.0 the additionalHoursCounter = 0.40, 
 * 		and converting it to integer it will become 0; 
 * -- we also should consider that amount to pay should not exceed 10.00 LVL.  
 * 
 * Expected results: 1,5 -> 2,00 // 4,0 -> 2,50 // 24,0 -> 10,00
*/

#include <iostream>

using namespace std;

double calculateAmount (double time);

int main() {
    
    double time, amount; // declaring variables for parking time and amount to pay
    cout << "Please enter the amount of parking time in hours: " << endl;
    cin >> time; // user enters parking time
    
    amount = calculateAmount (time); // calling for the function to calculate the amound and passing the parking time
    cout << "For " << time << " hours of parking you will pay " << amount << " LVL." << endl;
    
    return 0;
}

double calculateAmount (double time) {
    
    double result; // declatind the variable that holds the amount user has to pay
    int additionalHoursCounter = 0; // declaring and initializing variable to store additional hours
	
	if (time <= 0) { // if parking time is less or equal to 0, 
		
		result = 0; // user has to pay nothing
		
	} else if ( (time > 0) && (time <= 3.00) ) { // if parking time is more than 0 hours but less than or equal to 3 hours,
		
		result = 2; // user has to pay 2 LVL
		
	} else { // if parking time is longer than 3 hours this loops is in use

		while (time > 3.0) { // while the amount of time is bigger than 3
			time = (time - 1.00); // we decrease that time by one 
			additionalHoursCounter++; // and at the same time increase the amount of additional parking hours by one
		}
		
		result = 2 + (0.5 * additionalHoursCounter); // the result is 2 LVL for the first 3 hours plus 0.5 LVL per every additional hour
	}
    
    if (result > 10.00) { // if the result exceeds 10 LVL
		
        result = 10.00; // we make it 10 LVL
		
    }
    
    return result;
}

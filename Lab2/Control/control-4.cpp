#include <iostream>
#include <cmath>
#include <string>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

int main() {
	setlocale(LC_ALL, "Russian");

	for (;;) {
		// Menu
		cout << "\n===============Menu===============" << endl;
		cout << "1. Super prime numbers\n";
		cout << "2. Checking СНИЛС number\n";
		cout << "3. Greedy algorithm - coin problem\n";
		cout << "4. Target shooting\n";
		cout << "5. Target shooting (random center and shot diversion)\n";
		cout << "6. Target shooting (shooting up to a certain score)\n";
		cout << "Select an option: ";

		int choise;
		if (!(cin >> choise)) return 0;

		switch (choise) {

		// 1 Super prime numbers
		case 1: {
			int inputNumber;
			int idNumber = 0;

			cout << "\nThis program will determine if the number you enter is a super prime number" << endl;
			cout << "\nEnter a number = "; cin >> inputNumber;

			// checking if the input number is prime
			double stop = sqrt((double)inputNumber);
			int flag = 0;
			for (int i = 2; i <= stop; i++) {
				if ((inputNumber % i) == 0) {
					flag++; // has a divisor
					break;
				}
			}
			// not a prime input
			if (flag >= 1 || inputNumber <= 1) {
				cout << "\nThis is not a prime number. Please enter a prime number" << endl;
				return 0; // exiting the program at final cout
			}

			// calculating the ammount of prime # from 2 to input (position)
			for (int pos = 2; pos <= inputNumber; pos++) {
				double stop2 = sqrt(pos);
				int flag2 = 0;
				for (int j = 2; j <= stop2; j++) {
					if ((pos % j) == 0) {
						flag2++;
						break;
					}
				}
				if (flag2 == 0) // number at pos is prime
					idNumber++; // adding prime to position
			}
			// checking if index of position is prime
			double stop3 = sqrt(idNumber);
			int flag3 = 0;
			for (int i = 2; i <= stop3; i++) {
				if ((idNumber % i) == 0) {
					flag3++;
					break;
				}
			}
			if (flag3 == 0 && idNumber > 1) {
				cout << "\nPrime number " << inputNumber << " at position " << idNumber << " is a super prime number!" << endl;
				return 0;
			}
			else {
				cout << "\nThis prime number is not a super prime number(" << endl;
				return 0;
			}
		}


		// 2 Checking СНИЛС number
		case 2: {
			std::string SNILS;
			std::string controlNumber;

			cout << "\nEnter your СНИЛС (first 9 numbers | Ex. 123456789)" << endl;
			cin >> SNILS;
			cout << "Enter the control number (2 digits | Ex. 12): ";
			cin >> controlNumber;

			//cout << "SNILS: " << SNILS << endl;
			//cout << "Control: " << controlNumber;

			// invalid SNILS
			if (SNILS.size() != 9 || controlNumber.size() != 2) {
				cout << "\nfalse\n" << "The СНИЛС you entered doesn't have the right format";
				return 0;
			}


			// checking no more than 2 equal digits podryad
			//bool threeInRow = false;
			int streak = 1;
			for (std::size_t i = 1; i < SNILS.size(); i++) { // size() returns not int but size_t
				if (SNILS[i] == SNILS[i - 1]) {
					++streak; // adding 1 to the streak
					if (streak == 3) {
						cout << "\nfalse\n" << "Your СНИЛС can't contain  more than two identical digits in a row!";
						return 0;
					}
				}
				else {
					streak = 1; // breaking the streak
				}
			}
			
			// checking the sum of all digits
			int sumProduct = 0;
			int position = 9;
			for (char ch : SNILS) {
				int digit = ch - '0'; // transforming digits from char to int
				sumProduct += position * digit;
				position--;
			}

			// using a string version for comparison with string CN
			std::string stringSumProduct = std::to_string(sumProduct);

			if (sumProduct < 100 && stringSumProduct != controlNumber) {
					cout << "\nfalse";
					return 0;
			}
			else if ((sumProduct == 100 || sumProduct == 101) && controlNumber != "00"){ 
				cout << "\nfalse";
				return 0;
			}
			else if (sumProduct > 101) {
				int divisionRest = sumProduct % 101;
			
				std::string stringDivisionRest = std::to_string(divisionRest);

				// adding 0 to the left in case of 1 cifr
				if (stringDivisionRest.size() == 1)
					stringDivisionRest = '0' + stringDivisionRest;
				
				// checking for the uslovia
				if (divisionRest < 100 && stringDivisionRest != controlNumber) {
					cout << "\nfalse";
					return 0;
				}
				else if (divisionRest == 100 && controlNumber != "00") {
					cout << "\nfalse";
					return 0;
				}
			}
			cout << "\ntrue\n" << "Your СНИЛС is valid!";
			return 0;
		}


		// 3 Greedy algorithm - coin problem
		case 3: {
			int quantity;
			cout << "\nThis program will tell you the minimum ammout coins needed to get the inputed valuen\n";
			cout << "Using 10, 5, 2 and 1 ruble coins" << endl;

			cout << "\nEnter the quantity (integer): "; cin >> quantity;

			if (quantity <= 0) {
				cout << "\nYou should enter a positive value bigger than 0!";
				return 0;
			}

			int oneCount = 0, twoCount = 0, fiveCount = 0, tenCount = 0;

			int remaining;
			
			/* 58
			* 5 *10 -> 8
			* 1 *5	-> 3
			* 1 *2	-> 1
			* 1 *1	-> 0
			*/

			/* 9
			* 1 *5	-> 4
			* 2 *2	-> 0
			*/

			tenCount = quantity / 10; // 58 / 10 -> 5 coins  | 9/10=0
			remaining = quantity % 10; // 58 % 10 -> 8 remaining amomunt | 9%10=9

			fiveCount = remaining / 5; // 9/5=1
			remaining = remaining % 5; // 9%5=4

			twoCount = remaining / 2; // 4/2=2
			remaining = remaining % 2; // 4%2=0

			oneCount = remaining;

			int totalCoins = tenCount + fiveCount + twoCount + oneCount;

			cout << "10 -> " << tenCount << endl;
			cout << "5 -> " << fiveCount << endl;
			cout << "2 -> " << twoCount << endl;
			cout << "1 -> " << oneCount << endl;
			cout << "Total coins used: " << totalCoins << endl;
			return 0;
		}


		// 4 Target shooting
		case 4: {
			srand(time(NULL));
			int ammountShots = rand() % 5 + 2; // random (2 to 6)
			double x, y;
			double cx = 0.0, cy = 0.0; // fixed center

			int points = 0;
			int remainingShots = ammountShots;

			double bullseye = 1.0; // 10
			double fivePoints = 2.0; // 5
			double onePoint = 3.0; // 3
			
			cout << "\nYou have " << ammountShots << " shoots!" << endl;

			cout << "Enter the coordinates for x and y for each shot" << endl;
			for (; remainingShots != 0; --remainingShots) {
				cout << "\nx: "; cin >> x;
				cout << "y: "; cin >> y;

				// sqr distance of each shot form the center
				double distanceX = x - cx, distanceY = y - cy; 
				double shot = distanceX * distanceX + distanceY * distanceY;

				if (shot <= bullseye * bullseye) {
					cout << "You're a sniper. Your shot hit the center" << endl;
					cout << "You got 10 points!" << endl;
					points += 10;
				}
				else if (shot <= fivePoints * fivePoints ) {
					cout << "Nice shot! You got 5 points" << endl;
					points += 5;
				}
				else if (shot <= onePoint * onePoint){
					cout << "That's ok. You got 1 point" << endl;
					points += 1;
				}
				else {
					cout << "You missed. You got 0 points(" << endl;
				}
			}

			cout << "\nGame over!\n";
			cout << "With " << ammountShots << " shots, you got " << points << " points" << endl;
			
			int maxScore = ammountShots * 10;
			double ratio = (double)points / maxScore;
			std::string leve = (ratio >= 0.8) ? "You're sniper!" : (ratio >= 0.5) ? "You're a nice shooter" : "You're a novice";
			cout << "Level: " << leve << '\n';
			
			return 0;
		}

		// 5 Target shooting with random center and shot diversion
		case 5: {
			srand(time(NULL));
			//random center
			double randomcx = (rand() % 61 - 30) / 10.0; // -3.0 .. +3.0 (step 0.1)
			double randomcy = (rand() % 61 - 30) / 10.0; 

			int ammountShots = rand() % 5 + 2; // random (2 to 6)
			double x, y;

			int points = 0;
			int remainingShots = ammountShots;

			double bullseye = 1.0; // 10
			double fivePoints = 2.0; // 5
			double onePoint = 3.0; // 3

			cout << "\nYou have " << ammountShots << " shoots!" << endl;

			cout << "Enter the coordinates for x and y for each shot" << endl;
			for (; remainingShots != 0; --remainingShots) {
				cout << "\nx: "; cin >> x;
				cout << "y: "; cin >> y;

				// diversion for each coor of the shot 
				double divShotX = ((rand() % 101) - 50) / 100.0; //-0.5 .. +0.5
				// explaning the use of rand()
				/* cpunt = ((max - min) / step) + 1
				* count = ((+0.5 - (-0.5)) / 0.01) +1 -> 100+1 = 101
				* 
				* v = min + count * step
				* v = -0.5 + count * 0.01 -> (-50/100) + (k/100.0) -> (k - 50)/100.0   ! '%' can't be used with double
				* 
				* cx = rand() % v
				* cx = ((rand() % count - 50) /100.0)
				* 
				* or
				* 
				* cx = rand() % ((max - min + 1) + min)  / step
				* -0.5 -> -5.0 | 0.5 -> 5.0
				* -5.0 -> -50 | 5.0 -> 50 
				* 
				* cx = (rand () % ((50 - (-50) +1 ) - 50) / 100.0
				* -50 .. 50 / 100.0 - > -0.05 .. +0.05
				*/ 
				double divShotY = ((rand() % 101) - 50) / 100.0;
				x += divShotX; y += divShotY;

				// sqr distance of each shot form the random center
				double distanceX = x - randomcx, distanceY = y - randomcy;
				double shot = distanceX * distanceX + distanceY * distanceY;

				if (shot <= bullseye * bullseye) {
					cout << "You're a sniper. Your shot at (" << x << ", " << y << ") hit the center" << endl;
					cout << "You got 10 points!" << endl;
					points += 10;
				}
				else if (shot <= fivePoints * fivePoints) {
					cout << "Nice shot! Your shot at (" << x << ", " << y << ") got you 5 points" << endl;
					points += 5;
				}
				else if (shot <= onePoint * onePoint) {
					cout << "That's ok. Your shot at (" << x << ", " << y << ") got you 1 point" << endl;
					points += 1;
				}
				else {
					cout << "Your shot at (" << x << ", " << y << ") missed. You got 0 points(" << endl;
				}
			}

			cout << "\nGame over!\n";
			cout << "Center was at (" << randomcx << ", " << randomcy << ")\n";
			cout << "With " << ammountShots << " shots, you got " << points << " points" << endl;

			int maxScore = ammountShots * 10;
			double ratio = (double)points / maxScore;
			std::string leve = (ratio >= 0.8) ? "You're sniper!" : (ratio >= 0.5) ? "You're a nice shooter" : "You're a novice";
			cout << "Level: " << leve << '\n';

			return 0;
		}

		// Target shooting (shooting up to a certain score)
		case 6: {
			srand(time(NULL));
			//random center
			double randomcx = (rand() % 61 - 30) / 10.0; // -3.0 .. +3.0 (step 0.1)
			double randomcy = (rand() % 61 - 30) / 10.0;

			// target score to get 
			int targetScore = rand() % 11 + 50; // random (50 to 60)
			double x, y;

			int score = 0;
			int shots = 0;

			double bullseye = 1.0; // 10
			double fivePoints = 2.0; // 5
			double onePoint = 3.0; // 3

			cout << "\nYou need to get al least " << targetScore << " points!" << endl;

			cout << "Enter the coordinates for x and y for each shot" << endl;
			for (; score < targetScore;) { // comparing tekushiy score and target
				cout << "\nx: "; cin >> x;
				cout << "y: "; cin >> y;

				// diversion for each coor of the shot 
				double divShotX = ((rand() % 101) - 50) / 100.0; //-0.5 .. +0.5
				double divShotY = ((rand() % 101) - 50) / 100.0;
				x += divShotX; y += divShotY;
				
				// sqr distance of each shot form the random center
				double distanceX = x - randomcx, distanceY = y - randomcy;
				double shot = distanceX * distanceX + distanceY * distanceY;

				if (shot <= bullseye * bullseye) {
					cout << "You're a sniper. Your shot at (" << x << ", " << y << ") hit the center" << endl;
					cout << "You got 10 points!" << endl;
					score += 10;
				}
				else if (shot <= fivePoints * fivePoints) {
					cout << "Nice shot! Your shot at (" << x << ", " << y << ") got you 5 points" << endl;
					score += 5;
				}
				else if (shot <= onePoint * onePoint) {
					cout << "That's ok. Your shot at (" << x << ", " << y << ") got you 1 point" << endl;
					score += 1;
				}
				else {
					cout << "Your shot at (" << x << ", " << y << ") missed. You got 0 points(" << endl;
				}
				++shots; // adding a shot on each vipolnenie tsikla
			}

			cout << "\nGame over!\n";
			cout << "Center was at (" << randomcx << ", " << randomcy << ")\n";
			cout << "/nIt took you " << shots << " shots to achieve the target score" << endl;
			
			int idealShots = (targetScore + 9)/ 10;
			cout << "\nMinimal possible ammount of shots: " << idealShots << endl;
			std::string leve = (shots <= idealShots) ? "You're sniper!" : (shots <= idealShots * 2) ? "You're a nice shooter" : "You're a novice";
			cout << "Level: " << leve << '\n';

			return 0;
		}

		default: {
			cout << "\nInvalid option. Please select 1-6.\n\n";
			break;
		}
		}
	}
}

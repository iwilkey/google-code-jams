#include <iostream>
using namespace std;

// Init problem specfic vars
int matrix[100][100] = {0},
	maxCaseNum = 0,
	currentCaseNum = 0,
	matrixSize = 0,
	k = 0, r = 0, c = 0;

// Prototype methods
void solve();
void init();
void findTrace();
void findRepeatingNum();
	
// Main problem solving method
void solve() {
	// Reset all matrix-specific vars
	k = 0; r = 0; c = 0;
	// Get the matrix size from input
	cin >> matrixSize;
	// Assign matrix values
	for(int x = 0; x < matrixSize; x++) {
		for(int y = 0; y < matrixSize; y++) {
			cin >> matrix[x][y];
		}
	}

	// Assign k as trace found in matrix
	findTrace();
	// Assign r and c for repeating values
	findRepeatingNum();	
	// Output case results
	cout << "Case #" << currentCaseNum << ": " << k << " " << r << " " << c << endl;

}

// This method assigns the global var k as the trace found when the column equals the row
void findTrace() {
	for(int i = 0; i < matrixSize; i++)
			k += matrix[i][i];
}

// This method finds and documents repeating number occraances in each row and column respectivley
void findRepeatingNum() {
	// Loop through the matrix by x
	for(int x = 0; x < matrixSize; x++) {
		// Init some flags to tell if there was a repeating number occurance found
		bool rr = false, cc = false;
		// Loop through the matrix now by y for each x
		for(int y = 0; y < matrixSize; y++) {
			// Check for same number occuraces by checking numbers from 0 up to y
			for(int i = 0; i < y; i++) {
				// rr and cc are evaluated through a bitwise or to tabulate
				// a repeating number occurance no matter when it happened.
				// This makes it simple to count occurances no matter what the
				// current occurance is in the loop.
				rr |= matrix[x][y] == matrix[x][i];
				cc |= matrix[y][x] == matrix[i][x];
			}
		}

		// r and c are appended based on the verdict of 
		// rr and cc after the y and i loop have finished.
		r += rr;
		c += cc;

	}
}

// Main method
int main() {
	init();
	// Take in case number
	cin >> maxCaseNum;
	// Run for all cases
	while(currentCaseNum < maxCaseNum) {
		currentCaseNum++;
		solve();
	}
	return 0;
}

// Standard io init
void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

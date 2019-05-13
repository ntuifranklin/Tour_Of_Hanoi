//This code requires C++11 or more
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
const int MAX = 64;
using namespace std;
void moveDiscs(int,int,int,int);

void moveDiscs(int num, int fromPeg, int toPeg, int tempPeg) {
	if ( num > 0) {

		moveDiscs(num-1,fromPeg,tempPeg,toPeg);
		//cout << "\nMoving a disc from peg "<<fromPeg << " to peg "<< toPeg;
		moveDiscs(num-1,tempPeg,toPeg,fromPeg);
		
	}

}
int main()
{
	//int x;
	double seconds[MAX];
	float milliseconds[MAX];
	int NUM_DISCS = 5;
	int FROM_PEG = 1;
	int TO_PEG = 3;
	int TEMP_PEG = 2;
	//Play the game
	for (NUM_DISCS = 0; NUM_DISCS < MAX;NUM_DISCS++) {
		float start = (float)clock();
		moveDiscs(NUM_DISCS, FROM_PEG, TO_PEG, TEMP_PEG);
		float stop = (float)clock();
		seconds[NUM_DISCS] = ((stop - start)/1000) ;
		milliseconds[NUM_DISCS] = (stop-start);
		cout << "\n With " << setw(2)<<NUM_DISCS << " it took " <<setw(10)<< fixed<<setprecision(10)<<milliseconds[NUM_DISCS] << " milliseconds and approximately " << setw(10)<<fixed<<setprecision(10)<<seconds[NUM_DISCS] <<" seconds to run" ;
	}

	system("pause");//This code has to run on windows for system("pause") to work. If on linux, simply remove this line or replace pause with it's linux equivalent
	return 0;
}

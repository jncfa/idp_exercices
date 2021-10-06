//
// Summary of the libraries included here
// iostream - write to the screen
// stdlib.h - random number generator
// time.h   - functions related to the system clock
// math.h   - mathematical functions
//
// To compile this program:
// g++ exercise02.cc -o exercise02
//
// And to run it:
// ./exercise02.cc

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

int main(){
	// First of all we must initialise the random generator with a seed
	srand(time(0));

    // variables that we'll use to estimate the areas of
    // the square and the circle
	int square = 0;
	int circle = 0;
    // number of random points to generate
    int N = 10000;

    // Now let's make a cycle, and get pairs of random numbers
    for(int i=0; i<N; i++){
        double x = rand()/((double)RAND_MAX + 1) * 2 - 1;
        double y = rand()/((double)RAND_MAX + 1) * 2 - 1;
        // Obviously, the number of counts in 'square' will be N
        // but we do this to make it more clear
		square = square + 1;
        // Now check if the point is inside the circle
		if(sqrt(pow(x,2)+pow(y,2))<1)
			circle++;
    }

    // We can now estimate the value of PI using the ratio of the 'areas'
    // Note that in this expression we use '4.', and not just '4' -- this
    // tells the compiler that it should treat all the variables as floats
    // and not as integers
	double pi = 4.*circle/square;
    
    // All that remains to do is to write all the info to screen
    // The constant M_PI (from math.h) contains the value of Pi
	cout << "Number of points used: " << N << endl;
	cout << "Pi = " << pi << endl;
	cout << "Difference to the value of Pi = "
         << pi - M_PI << " (" << (pi-M_PI)/M_PI*100 << "%)" << endl;

	return 0;

}

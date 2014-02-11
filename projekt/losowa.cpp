#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    int a, b;
    srand(time(NULL));

    a = rand() % 101;
	b = rand() % 101;
	cout << a << endl << b << endl;

    return 0;
} 

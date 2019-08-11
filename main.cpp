#include "project2.h"
#include "helper.h"
#define NUM_OF_ITEMS 10000000
#define TESTS_EACH_SIZE 5

int main()
{
	cout << "NUM_OF_ITEMS = " << NUM_OF_ITEMS << endl;
	cout << "TESTS_EACH_SIZE = " << TESTS_EACH_SIZE << endl<<endl;
	createCSVFile();
	runTest(NUM_OF_ITEMS, TESTS_EACH_SIZE);

	return 0;
}
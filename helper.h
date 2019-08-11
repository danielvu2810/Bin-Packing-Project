#include <iostream>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <iomanip> 
#include <chrono>
#include <random>
#include <fstream>


using namespace std;

#define BIN_SIZE 1.00
#define MIN_DOUBLE 0.000000000000001


vector<double> sortedItems(const vector<double> items); //sort items in descending order
pair<int, double> wasteData(const vector<double> items, const vector<int> assignment); //get size of items and wasteData
int num_Bins(const vector<int> assignment); // get number of bins used
double total_weights(const vector<double> items); //get total weights of items
double total_freespace(const vector<double> free_space); //get total freespace left

//MT random generator
mt19937 get_mersenne_twister_generator_with_current_time_seed();
uniform_real_distribution<double> get_uniform_real_generator(double lb, double ub);


void createRandomData(vector<double>& items, vector<int>& assignment, vector<double>& free_space, const int size); //create random generator items given size

void resetVectors(const vector<double> items, vector<int>& assignment, vector<double>& free_space); // reset the assignment and freespace to test with different algorithms


void createCSVFile(); //create CVS files
void add_data_to_File(const string filename, pair<int, double> data); // add results of algorithms (size,waste) to cvs file

void runTest(const int size,const int testpersize); // run all algorithms given maximum size and number of tests per size

void printTest(const vector<double> items, const vector<int> assigment, const vector<double> free_space); // print to stdout results value



#include "helper.h"
#include "project2.h"

vector<double> sortedItems(const vector<double> items)
{
	vector<double> sorted_items(items);
	
	sort(sorted_items.rbegin(), sorted_items.rend());

	return sorted_items;
}


mt19937 get_mersenne_twister_generator_with_current_time_seed()
{
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	return mt19937(seed);
}

uniform_real_distribution<double> get_uniform_real_generator(double lb, double ub)
{
	return uniform_real_distribution<double>(lb, ub);
}

void createRandomData(vector<double>& items, vector<int>& assignment,vector<double>& free_space,const int size)
{
		items.clear();

		if (size > 0)
		{
			mt19937 mt = get_mersenne_twister_generator_with_current_time_seed();

			uniform_real_distribution<double> ui = get_uniform_real_generator(0.0, 1.0);

			for (int i = 0; i < size; i++)
				items.push_back(ui(mt));
			
		}

		resetVectors(items, assignment, free_space);
}


void resetVectors(const vector<double> items, vector<int>& assignment, vector<double>& free_space) //reset assignmet and free_space
{
	assignment.clear();

	for (int i = 0; i < items.size(); i++)
		assignment.push_back(0);

	free_space.clear();
}

void createCSVFile()
{
	ofstream f;

	f.open("next_fit.csv", ios::trunc);
	f << "Size,Waste\n";
	f.close();

	f.open("first_fit.csv", ios::trunc);
	f << "Size,Waste\n";
	f.close();

	f.open("first_fit_decreasing.csv", ios::trunc);
	f << "Size,Waste\n";
	f.close();

	f.open("best_fit.csv", ios::trunc);
	f << "Size,Waste\n";
	f.close();

	f.open("best_fit_decreasing.csv", ios::trunc);
	f << "Size,Waste\n";
	f.close();
}

double total_weights(const vector<double> items)
{
	double totalItems = 0;

	for (int i = 0; i < items.size(); i++)
		totalItems += items[i];

	return totalItems;
}


int num_Bins(const vector<int> assignment)
{
	int numBin = 0;

	for (int i = 0; i < assignment.size(); i++)
	{
		if (numBin < assignment[i])
			numBin = assignment[i];
	}

	numBin++;

	return numBin;
}

double total_freespace(const vector<double> free_space)
{
	double total = 0;

	for (int i = 0; i < free_space.size(); i++)
		total += free_space[i];

	return total;
}

pair<int, double> wasteData(const vector<double> items, const vector<int> assignment)
{
	pair<int, double> data(0, 0.0);
	data.first = items.size();
	
	int numBin = num_Bins(assignment);

	data.second = (double)numBin - total_weights(items);
	return data;
}

void add_data_to_File(const string filename, pair<int,double> data)
{
	ofstream f;
	f.open(filename, ios::app);
	f << data.first << "," << data.second<< "\n";
	f.close();
}

void runTest(const int size, const int testpersize)
{
	vector<double> items, free_space;
	vector<int> assignment;

	for (int i = 1; i <= size; i*=10)
	{
		for (int j = 0; j < testpersize; j++)
		{
			createRandomData(items, assignment, free_space, i);

			cout << "Next_fit: " << endl;
			next_fit(items, assignment, free_space);
			printTest(items, assignment, free_space);
			add_data_to_File("next_fit.csv", wasteData(items, assignment));
			resetVectors(items, assignment, free_space);

			cout << "First_fit: " << endl;
			first_fit(items, assignment, free_space);
			printTest(items, assignment, free_space);
			add_data_to_File("first_fit.csv", wasteData(items, assignment));
			resetVectors(items, assignment, free_space);

			cout << "First_fit_decreasing: " << endl;
			first_fit_decreasing(items, assignment, free_space);
			printTest(items, assignment, free_space);
			add_data_to_File("first_fit_decreasing.csv", wasteData(items, assignment));
			resetVectors(items, assignment, free_space);

			cout << "Best_fit: " << endl;
			best_fit(items, assignment, free_space);
			printTest(items, assignment, free_space);
			add_data_to_File("best_fit.csv", wasteData(items, assignment));
			resetVectors(items, assignment, free_space);

			cout << "Best_fit_decreasing: " << endl;
			best_fit_decreasing(items, assignment, free_space);
			printTest(items, assignment, free_space);
			add_data_to_File("data/best_fit_decreasing.csv", wasteData(items, assignment));
			resetVectors(items, assignment, free_space);
		}
	}

}

void printTest(const vector<double> items, const vector<int> assigment, const vector<double> free_space)
{
	cout << "Number of Items = " << wasteData(items, assigment).first << endl;

	cout << "Total Weights of Items = " << total_weights(items) << endl;

	cout << "Waste W(A) = " << wasteData(items, assigment).second << endl;

	cout << "Number of Bins Used = " << num_Bins(assigment)<<endl;

	cout << "Total Free space Left = " << total_freespace(free_space) << endl << endl << endl;
}

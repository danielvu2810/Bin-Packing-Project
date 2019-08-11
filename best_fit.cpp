#include "project2.h"
#include "helper.h"

void best_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{

	double minspace = BIN_SIZE * 2;
	int best_index;
	free_space.push_back(BIN_SIZE);

	for (int i = 0; i < items.size(); i++)
	{
		for (int j = 0; j < free_space.size(); j++)
		{
			if (items[i] <= free_space[j])
			{
				if (free_space[j] - items[i] < minspace)
				{
					best_index = j; //best bin
					if (free_space[j] - items[i] < MIN_DOUBLE) minspace = 0; //ignore small precision in floating number
					else minspace = free_space[j] - items[i];
				}
			}
		}

		if (minspace == BIN_SIZE * 2)
		{
			free_space.push_back(BIN_SIZE);
			i--;
		}
		else
		{
			assignment[i] = best_index;
			if (free_space[best_index] - items[i] < MIN_DOUBLE) free_space[best_index] = 0; //ignore small precision in floating number
			else free_space[best_index] -= items[i];
			minspace = BIN_SIZE * 2;
		}
	}
}

void best_fit_decreasing(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	best_fit(sortedItems(items), assignment, free_space);
}
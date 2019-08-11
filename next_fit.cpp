#include "project2.h"
#include "helper.h"

// implement in next_fit.cpp
void next_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	double bin_freespace = BIN_SIZE;
	int bin_index = 0;
	
	for (int i = 0; i < items.size(); i++)
	{
		if (items[i] > bin_freespace)
		{
			free_space.push_back(bin_freespace);
			bin_freespace = BIN_SIZE;
			bin_index++;
		}

		bin_freespace -= items[i];
		assignment[i]=bin_index;
	}

	free_space.push_back(bin_freespace);
}
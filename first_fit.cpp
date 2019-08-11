#include "project2.h"
#include "helper.h"

void first_fit(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	int fs_index=0;
	
	for (int i = 0; i < items.size(); i++)
	{
		for (; fs_index < free_space.size(); fs_index++)
		{
			if (items[i] <= free_space[fs_index])
			{
				free_space[fs_index] =free_space[fs_index]- items[i];

				if (free_space[fs_index] < MIN_DOUBLE) free_space[fs_index] = 0; //ignore small precision in floating number

				assignment[i] = fs_index;
				break;
			}
		}
		
		if (fs_index == free_space.size())
		{
			free_space.push_back(BIN_SIZE);
			i--;
		}
		else fs_index = 0;
	}
}

void first_fit_decreasing(const std::vector<double>& items, std::vector<int>& assignment, std::vector<double>& free_space)
{
	first_fit(sortedItems(items), assignment, free_space);
}

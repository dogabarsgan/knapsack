// Doga Barsgan
// An implementation of the Knapsack Problem

#include <iostream>
#include <vector>

using namespace std;

int knapsack(int capacity, vector<int> w, vector<int> v)
{

	int numRows = w.size() + 1;
	int numCols = capacity + 1;

	int solutionArray[numRows][numCols];

	// base cases

	// when capacity is 0
	for (int i = 0; i < numRows; i++)
	{
		solutionArray[i][0] = 0;
	}

	// when there is 0 items
	for (int i = 0; i < numCols; i++)
	{
		solutionArray[0][i] = 0;
	}

	// populating the solution array
	for (int i = 1; i < numRows; i++)
	{

		for (int j = 1; j < numCols; j++)
		{

			// if item's weight is larger than the capacity, don't include the item
			if (j < w[i - 1])
			{
				solutionArray[i][j] = solutionArray[i - 1][j];
			}
			else
			{
				// return the max of item included and item not included
				solutionArray[i][j] = max(solutionArray[i - 1][j],
																	v[i - 1] + solutionArray[i - 1][j - w[i - 1]]);
			}

		}

	}

	return solutionArray[numRows - 1][numCols - 1];

}

vector<int> knapsackList(int capacity, vector<int> w, vector<int> v)
{

	int numRows = w.size() + 1;
	int numCols = capacity + 1;

	int solutionArray[numRows][numCols];

	// actual used item #
	vector<int> solutionList;

	// base cases

	// when capacity is 0
	for (int i = 0; i < numRows; i++)
	{
		solutionArray[i][0] = 0;
	}

	// // when there is 0 items
	for (int i = 0; i < numCols; i++)
	{
		solutionArray[0][i] = 0;
	}

	// populating the solution array
	for (int i = 1; i < numRows; i++)
	{

		for (int j = 1; j < numCols; j++)
		{

			// if item's weight is larger than the capacity, don't include the item
			if (j < w[i - 1])
			{
				solutionArray[i][j] = solutionArray[i - 1][j];
			}
			else
			{
				// return the max of item included and item not included
				solutionArray[i][j] = max(solutionArray[i - 1][j],
																	v[i - 1] + solutionArray[i - 1][j - w[i - 1]]);
			}
		}
	}

	int i = numRows - 1;
	int j = numCols - 1;

	while (j > 0)
	{

		// if the base case is reached, exit the loop
		if (i == 0 && j == 0)
		{
			break;
		}

		if (solutionArray[i][j] == solutionArray[i - 1][j])
		{
			i--;
		}
		else
		{
			solutionList.push_back(i);
			j = j - w[i - 1];
		}

	}

	return solutionList;

}

int main()
{

	vector<int> weights;

	weights.push_back(10);
	weights.push_back(20);
	weights.push_back(30);
	weights.push_back(40);
	weights.push_back(40);

	vector<int> values;

	values.push_back(100);
	values.push_back(50);
	values.push_back(100);
	values.push_back(300);
	values.push_back(10);

	int backpackCapacity = 40;

	cout << "Max Value: " << knapsack(backpackCapacity, weights, values) << endl;

	vector<int> list = knapsackList(backpackCapacity, weights, values);

	for (int i = 0; i < list.size(); i++)
	{
		cout << "Item #" << list[i] << endl;
	}

	return 1;
	
}

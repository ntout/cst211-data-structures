#include "pch.h"
#include <iostream>
#include <random>
#include "../DataStructures/array.hpp"
#include "sort_method.hpp"

int main()
{

	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 20);

	int data[1000];
	for (int& i : data)
	{
		i = dist6(rng);
	}

	int c_arr[1000];
	for (int& i : data)
	{
		c_arr[i] = i;
	}

	std::vector<int> vect;
	for (int& i : data)
	{
		vect.push_back(i);
	}

	dynamic_array<int> d_arr(data, 1000);

	sort_method::selection(d_arr, d_arr.get_length());
	sort_method::selection(c_arr, 1000);
	sort_method::selection(vect, vect.size());
	
}


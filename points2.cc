//Title: Assignment 1
//Author: Gillian Pantaleon
//
// This file contains the implementation of the class Points2.


#include "points2.h"


template<typename Object>
Points2<Object>::Points2(): sequence_ {nullptr}, size_ {0} {}


template<typename Object>
Points2<Object>::Points2(const std::array<Object, 2>& item)
{
	size_ = 1;
	sequence_ = new std::array<Object, 2> [size_];
	sequence_[0] = item;
}


template<typename Object>
Points2<Object>::~Points2()
{
	delete [] sequence_;
	sequence_ = nullptr;
}


template<typename Object>
size_t Points2<Object>::size() const {return size_;}


template<typename Object>
Points2<Object>::Points2(const Points2 &rhs)
{
	size_ = rhs.size_;
	if (rhs.sequence_ != nullptr)
	{
		sequence_ = new std::array<Object, 2> [size_];
		for (int i = 0; i < size_; i++)
		{
			// Read each element of rhs.
			std::array<Object, 2> coordinate = rhs.sequence_[i];
			Object point1 = coordinate[0];
			Object point2 = coordinate[1];
			// Add each element in arrays and store them in sequence_
			std::array<Object, 2> copy_coordinate;
			copy_coordinate[0] = point1;
			copy_coordinate[1] = point2;
			sequence_[i] = copy_coordinate;
		}
	}
}


template<typename Object>
Points2<Object>::Points2(Points2 &&rhs) : sequence_{std::move(rhs.sequence_)},
											size_{rhs.size_}
{
	rhs.sequence_ = nullptr;
	rhs.size_ = 0;
}


// Assumptions: Input is only numerical and the first number is correct, i.e. integer.
template<typename Object>
void Points2<Object>::ReadPoints2()
{
	std::string input_line;
	std::getline(std::cin, input_line);
	std::stringstream input_stream(input_line);
    if (input_line.empty()) return;
	// Error handling.
	if (input_stream.fail())
	{
		std::cout << "Error. Check input.";
		input_line.clear();
	}
	// Read size of sequence_ (an integer).
	int size_of_sequence;
	input_stream >> size_of_sequence;
	// Allocate space for sequence_.
	size_ = size_of_sequence;
	sequence_ = new std::array<Object, 2> [size_];
	// Read the coordinates and fill sequence_.
	Object token;
	std::array<Object, 2> coordinate;
	int j = 0;
	int k = 0;
	for (int i = 0 ; input_stream >> token; ++i)
	{
		coordinate[k] = token;
		k++;
		if (k > 1)
		{
			k = 0;
			sequence_[j] = coordinate;
			j++;
		}
	}
}


template<typename Object>
const std::array<Object, 2> & Points2<Object>::operator[](size_t location) const
{ 
	if (location < size())
  		return this->sequence_[location];
	else std::abort();
}

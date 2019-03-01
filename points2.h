//Title: Assignment 1
//Author: Gillian Pantaleon
//
// The class Points2 describes a sequence of coordinates. A sequence can have
// any size, including 0. Coordinates can be integers or floating point numbers.


#ifndef CSCI335_HOMEWORK1_POINTS2_H_
#define CSCI335_HOMEWORK1_POINTS2_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

namespace teaching_project {
// The class Points2 is an array of arrays of type Object.
// Sample usage includes storing pairs of points of type int or double.  
template<typename Object>
class Points2 {
 public:
  // Zero-parameter constructor. 
  // Set size to 0.
  Points2();

  // One parameter constructor.
  Points2(const std::array<Object, 2>& item);

  ~Points2();

  size_t size() const;

  // Copy-constructor.
  Points2(const Points2 &rhs);

  // Copy-assignment.
  Points2 & operator=(const Points2 &rhs)
  {
  	if (this == & rhs) return *this;
	Points2 copy = rhs; 
	std::swap(*this, copy);
	return *this;
  }
  // Move-constructor. 
  Points2(Points2 &&rhs);

  // Move-assignment.
  // Just use std::swap() for all variables.
  Points2& operator=(Points2 &&rhs)
  {
  	std::swap(size_, rhs.size_);
  	std::swap(sequence_, rhs.sequence_);
  	return *this;
  }

  // Read a chain from standard input.
  void ReadPoints2();

  // @location: an index to a location in the sequence.
  // @returns the point at @location.
  // const version.
  // abort() if out-of-range.
  const std::array<Object, 2>& operator[](size_t location) const;

 //  @c1: A sequence.
 //  @c2: A second sequence.
 //  @return their sum, c3. If the sequences are not of the same size, append the
 //    result with the remaining part of the larger sequence.
 friend Points2 operator+(const Points2 &c1, const Points2 &c2)
 {
 	Points2<Object> c3;
 	Points2<Object> smaller;

	if (c1.size() > c2.size())
	{
		c3 = c1;
		smaller = c2;
	}
	else
	{
		c3 = c2;
		smaller = c1;
 	}

 	for (int i = 0; i < smaller.size(); i++)
	{
		// Read each element of c2
		std::array<Object, 2> coordinate = smaller.sequence_[i];
		Object coordinate1 = coordinate[0];
		Object coordinate2 = coordinate[1];
		// Add each element to sequence_
		std::array<Object, 2> temp = c3.sequence_[i];
		temp[0] += coordinate1;
		temp[1] += coordinate2;
		c3.sequence_[i] = temp;
	}
 	return c3;
 }

 // Overloading the << operator.
 friend std::ostream &operator<<(std::ostream &out, const Points2 &some_points2)
 {
	if (some_points2.size_ > 0)
	{
		for (int i = 0; i < some_points2.size(); i++)
		{
			std::array<Object, 2> coordinate = some_points2.sequence_[i];
			out << "(" << coordinate[0] << ", " << coordinate[1] << ")"<< " ";
		}
	}
	else out << "()";
	out << std::endl;
	return out;
 }
 
 private:
  // Sequence of points. 
  std::array<Object, 2> *sequence_;
  // Size of sequence.
  size_t size_;

};
#include "points2.cc"
}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_POINTS2_H_

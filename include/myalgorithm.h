/// @brief	STL algorithms 
/// @file	myalgorithm.h
/// @author Aparajith Sridharan (s.aparajith@live.com)
/// @date	30-08-2020
/// @details 
/// @history
/// @see ReadMe.md for more details

#pragma once

///////////////////////////////////////
// Includes
///////////////////////////////////////
#include<vector>

///////////////////////////////////////
// function prototypes
///////////////////////////////////////
namespace myalgo {
	/// @brief binary search with a predicate function
	/// @param[in] first: starting iterator
	/// @param[in] first: end iterator
	/// @param[in] first: value to be searched
	/// @param[in] _Pred: predicate function 
	/// @details write a predicate which checks if first argument is strictly less than second 
	///          and if so, returns true
	/// @return iterator to the nearest position where an element can be inserted using the std::vector::insert method 
	template<class T, class Pr>
	typename std::vector<T>::iterator binary_search(typename std::vector<T>::iterator first,
		typename std::vector<T>::iterator end,
		T val,
		Pr _Pred)
	{
		typename std::vector<T>::iterator uFirst = first;
		typename std::vector<T>::iterator uLast = end - 1;
		typename std::vector<T>::iterator uMid;
		if (_Pred(*uFirst, val))
		{
			uMid = uFirst;
		}
		else if (_Pred(val, *uLast))
		{
			uMid = uLast + 1;
		}
		else
		{   //traditional binary search. nothing special.
			while (uFirst <= uLast)
			{

				uMid = uFirst + (uLast - uFirst) / 2;
				if (_Pred(val, *uMid))
				{
					uFirst = uMid + 1;

				}
				else if (!_Pred(*uMid, val))
				{
					break;
				}
				else
				{
					uLast = uMid - 1;
				}

			}
			//compare and return the correct position to insert
			if (_Pred(val, *uMid))
			{
				uMid++;
			}
		}
		return uMid;
	}
}
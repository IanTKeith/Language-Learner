#pragma once

#include <string>
#include <vector>

namespace Utility {
	/// <summary>
	///		Removes leading and trailing white
	///		space from an std::wstring.
	/// </summary>
	/// <param name="str">The string to trim.</param>
	/// <returns>
	///		A new std::wstring with leading 
	///		and trailing whitespace removed.
	/// </returns>
	std::wstring trim(std::wstring const& str);

	/// <summary>
	///		Generates a pseudo random integer.
	/// </summary>
	/// <param name="min">The minimum possible return value.</param>
	/// <param name="max">The maximum possible return value</param>
	/// <returns>A random integer on the range [min, max].</returns>
	unsigned int randInt(unsigned int min, unsigned int max);

	/// <summary>
	///		Randomly select an element of a std::vector.
	/// </summary>
	/// <typeparam name="type">The type of the elements in the vector.</typeparam>
	/// <param name="v">The vector from which to select a random element.</param>
	/// <returns>A const& to a random element of the vector</returns>
	template<typename type>
	type getRandomElement(std::vector<type> const& v) {
		return v.at(randInt(0, v.size() - 1));
	}	
}
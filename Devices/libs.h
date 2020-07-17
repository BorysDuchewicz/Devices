#pragma once
#include<iostream>
#include<vector>
#include<memory>
#include<regex>
#include <fstream>
#include<unordered_map>
#include "json.hpp"
#include "app_exception.h"
using json = nlohmann::json;
enum class Category{A,B,C};
static const std::vector<std::string> CategoryTypeValues = { "A","B","C" };

inline Category str_to_category(const std::string& txt )
{
	if(txt=="A")
	{
		return Category::A;
	}
	else if (txt == "B")
	{
		return Category::B;
	}
	else if (txt == "C")
	{
		return Category::C;
	}
	throw AppException("no category type for value");
}
inline  std::string category_to_str(Category category)
{
	return CategoryTypeValues[static_cast<int>(category)];
}
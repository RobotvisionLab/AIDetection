#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

typedef vector<string>  StringList;

class CPGCalculation
{
public:
	CPGCalculation();
	~CPGCalculation();

	static StringList splitstr(const std::string& str, char tag);
	static double getMaxVal(string model);
	static string getMPE(string model, string zqddj);
};


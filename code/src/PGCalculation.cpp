#include "stdafx.h"
#include "PGCalculation.h"


CPGCalculation::CPGCalculation()
{
}


CPGCalculation::~CPGCalculation()
{
}

StringList CPGCalculation::splitstr(const std::string& str, char tag)
{
	StringList  li;
	std::string subStr;

	//遍历字符串，同时将i位置的字符放入到子串中，当遇到tag（需要切割的字符时）完成一次切割
	//遍历结束之后即可得到切割后的字符串数组
	for (size_t i = 0; i < str.length(); i++)
	{
		if (tag == str[i]) //完成一次切割
		{
			if (!subStr.empty())
			{
				li.push_back(subStr);
				subStr.clear();
			}
		}
		else //将i位置的字符放入子串
		{
			subStr.push_back(str[i]);
		}
	}

	if (!subStr.empty()) //剩余的子串作为最后的子字符串
	{
		li.push_back(subStr);
	}

	return li;
}



double CPGCalculation::getMaxVal(string model)
{
	double ret = 0.0f;

	StringList s1 = splitstr(model, '-');
	string s2 = s1.back();
	StringList s3 = splitstr(s2, ')');

	ret = _ttof(CStringW(s3.front().c_str()));
	return ret;
}

string CPGCalculation::getMPE(string model, string zqddj)
{
	double maxval_f = getMaxVal(model);
	double zqddj_f = _ttof(CStringW(zqddj.c_str()));
	double ret_f = zqddj_f * maxval_f/100;

	ostringstream oss;
	oss << ret_f;
	string str(oss.str());
	return str;
}

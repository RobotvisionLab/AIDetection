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

	//�����ַ�����ͬʱ��iλ�õ��ַ����뵽�Ӵ��У�������tag����Ҫ�и���ַ�ʱ�����һ���и�
	//��������֮�󼴿ɵõ��и����ַ�������
	for (size_t i = 0; i < str.length(); i++)
	{
		if (tag == str[i]) //���һ���и�
		{
			if (!subStr.empty())
			{
				li.push_back(subStr);
				subStr.clear();
			}
		}
		else //��iλ�õ��ַ������Ӵ�
		{
			subStr.push_back(str[i]);
		}
	}

	if (!subStr.empty()) //ʣ����Ӵ���Ϊ�������ַ���
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

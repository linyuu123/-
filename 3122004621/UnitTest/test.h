#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
class Calculate
{
public:
	double CalculateSimilarity(const string& originText, const string& anotherText)
	{
		int commonCount = 0;//计算原文与抄袭文档的相同字符数目
		size_t oringinLength = originText.length();//得到原文的字符长
		for (char c : anotherText)//遍历抄袭文，在原文中找到相同字符的数目
		{
			if (originText.find(c) != string::npos)//若相同则++相同数目
			{
				commonCount++;
				if (commonCount == oringinLength)
					break;//重复大于等于原文字数，100%重复
			}
		}
		return static_cast<double>(commonCount) / oringinLength;//转为double型返回
	}
};

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

double calculateSimilarity(const string& originText, const string& anotherText)
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
	return static_cast<double>(commonCount) / oringinLength;
}

int main(int argc, char* argv[])
{
	//分别输入原文和抄袭文的路径
	string originalFile = argv[1];
	string plagiarzedFile = argv[2];
	string outputFile = argv[3];
	printf("%s\n", argv[1]);
	printf("%s\n", argv[2]);
	printf("%s\n", argv[3]);
	ifstream originalStream(originalFile);
	ifstream plagiarizedStream(plagiarzedFile);
	ofstream outputStream(outputFile, std::ios::app);

	if (!originalStream || !plagiarizedStream || !outputStream)//任何一个文件打开失败都返回1
	{
		cout << "Failed to open input or output file." << endl;
		return 1;
	}

	string originalText((istreambuf_iterator<char>(originalStream)), istreambuf_iterator<char>());//从原文中读取字符存储到字符串originalText中
	string plagiarizedText((istreambuf_iterator<char>(plagiarizedStream)), istreambuf_iterator<char>());//从抄袭文中读取字符存储到字符串plagiarizedText中

	double similarity = calculateSimilarity(originalText, plagiarizedText);//得到结果

	outputStream << fixed << setprecision(2) << similarity << endl;//将结果输出到文件中

	originalStream.close();
	plagiarizedStream.close();
	outputStream.close();

	system("pause");
	return 0;
}

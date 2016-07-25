#pragma once

#include <vector>
#include <string>
#include <map>

//csv���һ������
class CsvData
{
public:
	CsvData();
	~CsvData();

	void parseRow(const std::string& rowData);

	int getIntVal(int index);
	std::string getStringVal(int index);

public:

	static void SplitString(const std::string& str, const std::string& seperator, std::vector<std::string>& retList);


private:
	std::string& getValue(int index);

private:

	std::vector<std::string> mDataList;		//����
};


//����csv�ļ��ķ���
class CsvFile
{
public:
	CsvFile();
	~CsvFile();

	void loadFile(const std::string& fileName);

	std::vector<CsvData*>& getCsvDataList();


private:
	std::vector<CsvData*> mCsvDataList;
};
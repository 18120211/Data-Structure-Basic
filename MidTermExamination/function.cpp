//Thưa cô em là Võ Thế Minh - 18120211 học ca thứ 2 sáng thứ 5 môn CTDLVGL em có vấn đề trong include thư viện mong cô xem qua
#pragma once
#include "function.h"
#include <fstream>
#include <sstream>
#include <locale>

Examinee ReadExaminee(string line_info)
{
	// Chèn s? 0 vào gi?a 2 d?u ','
	string New;
	for (int i = 0; i < line_info.length() - 1; i++)
	{
		New = New + line_info[i];
		if (line_info[i] == ',' && line_info[i + 1] == ',')
			New = New + "0";
	}
	New = New + line_info[line_info.length() - 1];
	line_info = New;
	// Thay d?i tính ch?t c?a d?u ',' thành d?u ' '
	stringstream ss;
	ss << line_info;
	ss.imbue(locale(ss.getloc(), new comma_is_space));
	// Nh?p thông tin cho 1 thí sinh
	string temp;
	Examinee A;
	ss >> A.ID >> temp >> A.math >> A.literature >> A.physic >> A.chemistry >> A.biology >> A.history >> A.geography
		>> A.civic_education >> A.natural_science >> A.social_science >> A.foreign_language;
	A.natural_science = A.biology + A.physic + A.chemistry;
	A.social_science = A.history + A.geography + A.civic_education;
	return A;
}

vector<Examinee> ReadExamineeList(string file_name)
{
	fstream inFile;
	inFile.open(file_name, ios::in);
	string temp;
	getline(inFile, temp, '\n');
	// Doc danh sach thi sinh
	vector<Examinee> Examinee_list;
	while (!inFile.eof()) {
		getline(inFile, temp, '\n');
		Examinee exam;
		Examinee_list.push_back(ReadExaminee(temp));
		//cout << temp << endl;
	}
	return Examinee_list;
}

vector<Examinee> GetTopHighestLiterature(vector<Examinee> list_examinee, int k)
{
	vector<Examinee> A;
	float maxLiterature = list_examinee[0].literature;
	for (int i = 1; i < list_examinee.size(); i++) {
		if (maxLiterature < list_examinee[i].literature) {
			maxLiterature = list_examinee[i].literature;
		}
	}
	for (int i = 0; i < list_examinee.size(); i++) {
		if (maxLiterature == list_examinee[i].literature) {
			A.push_back(list_examinee[i]);
		}
	}
	return A;
}

vector<Examinee> MergeTwoList(vector<Examinee> list1, vector<Examinee> list2)
{
	vector<Examinee> MergedList;
	int count1 = 0;
	int count2 = 0;

	if (list1[count1].literature < list2[count2].literature)
	{
		MergedList.push_back(list1[count1]);
		count1++;
	}
	else
	{
		MergedList.push_back(list2[count2]);
		count2++;
	}
	if (count1 == int(sizeof(list1) - 1))
	{
		while (count2 < sizeof(list2))
		{
			MergedList.push_back(list2[count2]);
			count2++;
		}

	}
	if (count2 == int(sizeof(list2) - 1))
	{
		while (count1 < sizeof(list1))
		{
			MergedList.push_back(list1[count1]);
			count1++;
		}
	}
	return MergedList;
}

string binarySearch(vector<Examinee> arr, int l, int r, float x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle 
		// itself 
		if (arr[mid].literature == x)
			return arr[mid].ID;

		// If element is smaller than mid, then 
		// it can only be present in left subarray 
		if (arr[mid].literature > x)
			return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present 
		// in right subarray 
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not 
	// present in array 
	return "-1";
}

string FindExamineeByLiterature(vector<Examinee> sorted_list, float v)
{
	//string A;
	/*for (int i = 0; i < sorted_list.size(); i++) {
		if (sorted_list[i].literature == v) {
			return sorted_list[i].ID;
		}
	}*/
	return binarySearch(sorted_list, 0, sorted_list.size() - 1, v);
}
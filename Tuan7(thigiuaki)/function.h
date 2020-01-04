//Thưa cô em là Võ Thế Minh - 18120211 học ca thứ 2 sáng thứ 5 môn CTDLVGL em có vấn đề trong include thư viện mong cô xem qua
#pragma once
#ifndef _function_HEADER
#define _function_HEADER

#include <iostream>
#include <vector>
#include <sstream>
#include <locale>
#include <string>
using namespace std;

struct comma_is_space : ctype<char> {
	comma_is_space() : ctype<char>(get_table()) {}
	static mask const* get_table()
	{
		static mask rc[table_size];
		rc[','] = ctype_base::space;
		rc['\n'] = ctype_base::space;
		return &rc[0];
	}
};

struct Examinee
{
	string ID;
	float math, literature, physic, chemistry, biology, history, geography, civic_education, natural_science, social_science, foreign_language;
};


// Đọc dữ liệu
Examinee ReadExaminee(string line_info);
vector<Examinee> ReadExamineeList(string file_name);

// Bài 1a
vector<Examinee> GetTopHighestLiterature(vector<Examinee> list_examinee, int k);

// Bài 1b
vector<Examinee> MergeTwoList(vector<Examinee> list1, vector<Examinee> list2);

// Bài 2.
string FindExamineeByLiterature(vector<Examinee> sorted_list, float v);

#endif
#pragma once
#ifndef __examinee_h_
#define __examinee_h_
#include "pch.h"

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

class examinee {
private:
	string _id, _HovaTen;
	float _math, _literary, _physic, _chemistry, _biology, _history, _geography, _civic_education,
		_natural_science, _social_science, _foreign_language, _sumPoint;
	examinee* ReadExaminee(string line_info);
public:
	examinee();
	string id();
	string HovaTen();
	float math();
	float literary();
	float physic();
	float chemistry();
	float biology();
	float history();
	float geography();
	float civic_education();
	float natural_science();
	float social_science();
	float foreign_language();
	float sumPoint();
	void setId(string id);
	void setHovaTen(string HoVaTen);
	void setMath(float math);
	void setLiterary(float literary);
	void setPhysic(float physic);
	void setChemistry(float chemistry);
	void setBiology(float biology);
	void setHistory(float history);
	void setGeography(float geography);
	void setCivic_Education(float civic_education);
	void setNatural_Science(float natural_science);
	void setSocial_science(float social_science);
	void setForeign_language(float foreign_language);
	void setSumPoint(float sumPoint);
	float caculateNatural_Science();
	float caculateSocial_Science();
	float caculateSum_Point();
	vector<examinee*> ReadExamineeList(string file_name);
	void WriteSumOfScore(vector<examinee*> examinee_list, string out_file_name);
};

#endif // !__pch_h_


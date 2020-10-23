#include "examinee.h"
#include "pch.h"

examinee::examinee()
{
	this->setId("0");
	this->setHovaTen("0");
	this->setMath(0);
	this->setLiterary(0);
	this->setPhysic(0);
	this->setChemistry(0);
	this->setBiology(0);
	this->setHistory(0);
	this->setGeography(0);
	this->setCivic_Education(0);
	this->setNatural_Science(0);
	this->setSocial_science(0);
	this->setForeign_language(0);
	this->setSumPoint(0);
}


//examinee::~examinee()
//{
//}


string examinee::id()
{
	return _id;
}

string examinee::HovaTen()
{
	return _HovaTen;
}

float examinee::math()
{
	return _math;
}

float examinee::literary()
{
	return _literary;
}

float examinee::physic()
{
	return _physic;
}

float examinee::chemistry()
{
	return _chemistry;
}

float examinee::biology()
{
	return _biology;
}

float examinee::history()
{
	return _history;
}

float examinee::geography()
{
	return _geography;
}

float examinee::civic_education()
{
	return _civic_education;
}

float examinee::natural_science()
{
	return _natural_science;
}

float examinee::social_science()
{
	return _social_science;
}

float examinee::foreign_language()
{
	return _foreign_language;
}

float examinee::sumPoint()
{
	return	_sumPoint;
}

void examinee::setId(string id)
{
	_id = id;
}

void examinee::setHovaTen(string HoVaTen)
{
	_HovaTen = HoVaTen;
}

void examinee::setMath(float math)
{
	_math = math;
}

void examinee::setLiterary(float literary)
{
	_literary = literary;
}

void examinee::setPhysic(float physic)
{
	_physic = physic;
}

void examinee::setChemistry(float chemistry)
{
	_chemistry = chemistry;
}

void examinee::setBiology(float biology)
{
	_biology = biology;
}

void examinee::setHistory(float history)
{
	_history = history;
}

void examinee::setGeography(float geography)
{
	_geography = geography;
}

void examinee::setCivic_Education(float civic_education)
{
	_civic_education = civic_education;
}

void examinee::setNatural_Science(float natural_science)
{
	_natural_science = natural_science;
}

void examinee::setSocial_science(float social_science)
{
	_social_science = social_science;
}

void examinee::setForeign_language(float foreign_language)
{
	_foreign_language = foreign_language;
}

void examinee::setSumPoint(float sumPoint)
{
	_sumPoint = sumPoint;
}

float examinee::caculateNatural_Science()
{
	return this->physic() + this->chemistry() + this->biology();
}

float examinee::caculateSocial_Science()
{
	return this->history() + this->geography() + this->civic_education();
}

float examinee::caculateSum_Point()
{
	return this->math() + this->literary() + this->foreign_language() + this->natural_science() + this->social_science();
}

examinee* examinee::ReadExaminee(string line_info)
{
	// Chèn số 0 vào giữa 2 dấu ','
	string New;
	for (int i = 0; i < line_info.length() - 1; i++)
	{
		New = New + line_info[i];
		if (line_info[i] == ',' && line_info[i + 1] == ',')
			New = New + "0";
	}
	New = New + line_info[line_info.length() - 1];
	line_info = New;
	// Thay đổi tính chất của dấu ',' thành dấu ' '
	stringstream ss;
	ss << line_info;
	ss.imbue(locale(ss.getloc(), new comma_is_space));
	// Nhập thông tin cho 1 thí sinh
	ss >> _id >> _HovaTen >> _math >> _literary >> _physic >> _chemistry >> _biology >> _history >> _geography
		>> _civic_education >> _natural_science >> _social_science >> _foreign_language;
	this->setNatural_Science(this->caculateNatural_Science());
	this->setSocial_science(this->caculateSocial_Science());
	this->setSumPoint(this->caculateSum_Point());
	/*cout << TS.id << " "  <<  TS.HovaTen << " "  <<  TS.math << " "  <<  TS.literary << " "  << TS.chemistry
		<< " "  << TS.biology << " "  << TS.history<< " "  << TS.geography << " "  << TS.civic_education << " "
		<< TS.natural_science << " "  << TS.social_science << " "  << TS.foreign_language;*/
	return this;
}

vector<examinee*> examinee::ReadExamineeList(string file_name)
{
	// Mở file data
	fstream inFile;
	inFile.open(file_name, ios::in);
	string temp;
	getline(inFile, temp, '\n');
	// Doc danh sach thi sinh
	vector<examinee*> examinee_list;
	while (!inFile.eof()) {
		getline(inFile, temp, '\n');
		examinee * exam = new examinee;
		examinee_list.push_back(exam->ReadExaminee(temp));
		//cout << temp << endl;
	}
	return examinee_list;
}

void examinee::WriteSumOfScore(vector<examinee*> examinee_list, string out_file_name)
{
	// Tạo file lưu thông tin
	fstream outFile;
	outFile.open(out_file_name, ios::out);
	// Duyệt qua vecto
	for (int i = 0; i < examinee_list.size(); i++) {
		outFile << examinee_list[i]->id() << " " << examinee_list[i]->sumPoint() << endl;
	}
}
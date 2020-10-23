#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

#define p 31
#define p2 311
#define m 1000000009

struct Company
{
	string name;
	string profit_tax;
	string address;
};

vector<Company> ReadListCompany(string file_name)
{
	vector<Company> A;
	fstream fileMST;
	fileMST.open(file_name, ios::in);
	string stringTemp; getline(fileMST, stringTemp);
	Company objCompany;
	while (!fileMST.eof()) {
		getline(fileMST, objCompany.name, '|');
		getline(fileMST, objCompany.profit_tax, '|');
		getline(fileMST, objCompany.address);
		A.push_back(objCompany);
		/*cout << objCompany.name << "|" << objCompany.profit_tax << "|" << objCompany.address << endl;
		system("pause");*/
	}
	return A;
}

long long HashString(string company_name)
{
	long long Hash = 0;
	if (company_name.length() >= 20) {
		company_name = company_name.substr(company_name.length() - 20);
	}
	long long a = 0;
	for (int i = 0; i < company_name.length(); i++) {
		Hash += fmod(company_name[i] * pow(p, i), m);
	}
	return Hash;
}

long long HashString2(string company_name)
{
	long long Hash = 0;
	if (company_name.length() >= 20) {
		company_name = company_name.substr(company_name.length() - 20);
	}
	for (int i = 0; i < company_name.length(); i++) {
		Hash = (Hash * p2 + company_name[i]) % m;
	}
	return Hash;
}



Company* CreateHashTable(vector<Company> list_company)
{
	Company * A = new Company[5000];
	int hash = 0;
	for (int i = 0; i < list_company.size(); i++) {
		hash = HashString(list_company[i].name) % 5000;
		while (A[hash].name == "") {
			A[hash] = list_company[i];
			if (hash == 4999) { //Quay ve dau khi bang bam da day
				hash = 0;
			}
			i++;
		}
	}
	return A;
}

void print(Company * hash_table)
{
	for (int i = 0; i < 5000; i++) {
		if (hash_table[i].name != "") {
			cout << i << endl;
			cout << hash_table[i].name << endl << hash_table[i].profit_tax << endl << hash_table[i].address;
			//system("pause");
		}
	}
}

void Insert(Company* hash_table, Company company)
{
	int hash = HashString(company.name) % 5000;
	for (int i = hash; i < 5000; i++) {
		if (i == 4999) { //Khi da het thi quay lai dau bang bam
			i = 0;
		}
		if (hash_table[i].name == "") {
			hash_table[i] = company;
			return;
		}
	}
}

Company Search(Company* hash_table, string company_name)
{
	int k = 0;
	for (int i = 0; i < 5000; i++) {
		k++;
		if (k == 5000) {
			Company trash;
			return trash;
		}
		if (HashString(company_name) == HashString(hash_table[i].name)) {
			if (company_name == hash_table[i].name) {
				return hash_table[i];
			}
			else {
				if (i == 4999) {
					i = 0;
				}
				i++;
			}
		}
	}
}

int main()
{
	vector<Company> A = ReadListCompany("MST.txt");

	Company * objhashtable = CreateHashTable(A);
	Company t;
	t.name = "abc"; t.profit_tax = "b"; t.address = "c";
	Insert(objhashtable, t);
	Insert(objhashtable, t);
	Insert(objhashtable, t);
	print(objhashtable);
	system("pause");
	return 0;
}
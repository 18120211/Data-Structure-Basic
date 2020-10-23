#include <iostream>
using namespace std;

#include "cVector.h"

void XemClassVector()
{
	cout << "Sorry co em lam khong kip co vao file HEADER xem dum em nha :3" << endl;
}

int main()
{
	cVector	vector;
	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);
	vector.push_back(5);

	
	bool isOpen = true;
	int lc = 0;
	do {
		cout << "--__CHAO CO TOI CLASS VECTOR CUA EM__--" << endl;
		cout << "1. Xem class vector " << endl;
		cout << "2. Xem vector " << endl;
		cout << "3. Xem kha nang chua cua vector " << endl;
		cout << "4. Truy xuat toi phan tu thu i " << endl;
		cout << "5. Them phan tu " << endl;
		cout << "6. Xoa phan tu " << endl;
		cout << "7. Cac thao tac khac " << endl;
		cout << "0. Thoat" << endl;
		cout << ">> "; cin >> lc;
		switch (lc) {
		case 1: {
			XemClassVector();
			break;
		}
		case 2: {
			for (int i = 0; i < vector.Size(); i++) {
				cout << vector[i] << " ";
				cout << endl;
			}
			break;
		}
		case 3: {
			cout << "size: " << vector.Size() << " capacity: " << vector.Capacity() << endl;
			break;
		}	
		case 4: {
			int index = 0; cout << "i: "; cin >> index;
			cout << "vector" << "[" << index << "]" << ": " << vector[index] << endl;
			break;
		}
		case 5: {
			cout << "Them vao vi tri thu: "; int index = 0; cin >> index;
			cout << "data: "; int value = 0;  cin >> value;
			vector.insert(vector.Begin() + index, value);
			break;
		}	
		case 6: {
			cout << "Xoa phan tu thu: "; int index = 0; cin >> index;
			vector.erase(vector.Begin() + index);
			break;
		}	
		case 7: {
			cout << "__Con rat nhieu ham khac nhung em khong kip dua len vao menu mong co thong cam a__" << endl
				<< "----Co co the doc them file cVector.h va cVector.cpp de biet them chi tiet a---" << endl;
			break;
		}	
		case 0: {
			isOpen = false;
			break;
		}
		default:
			break;
		}
		system("pause");
		system("@cls");
	} while (isOpen);
	return 0;
}


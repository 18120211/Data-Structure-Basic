#pragma once

class cVector 
{
private:
	//Capacity
	int * vector; //Dữ liệu chính của vector là một mảng số nguyên
	int size = 0; //Kích thước dữ liệu đang được chứa của vector
	int capacity = 0; //Kích thước thật của vector

	//Iterator
	int * begin; //Con trỏ begin trỏ đến phần tử đầu tiên trong vector
	int * end; //Con trỏ end trỏ đến phần tử cuối cùng trong vector
	int * rbegin; //Con trỏ rbegin trỏ đến phần tử cuối cùng trong vector 
	int * rend; //Con trỏ rend trỏ đến phần tử đầu tiên trong vector
public:
	//Constructor
	cVector(int n); //Khởi tạo vector có n phần tử
	cVector(); //Khởi tạo vector cơ bản

	//Access to element
	int & operator [](int index); //Truy xuất đến phần tử bất kì trong vector
	int & at(int index); //Truy xuất đến phần tử bất kì trong vector
	int & front(); //Truy xuất đến phần tử đầu tiên trong vector
	int & back(); //Truy xuất đến phần tử cuối cùng trong vector
	int * data(); //Trả về mảng dữ liểu của vector
	
	//Capacity
	int Size(); //Trả về kích thước dữ liệu đang được chứa của vector
	int Capacity(); //Trả về kích thước thật của vector
	const double max_size(); //Trả về số lượng phần tử có thể chứa trong vector
	bool empty(); //Kiểm tra xem vector có rỗng hay không
	void resize(int newsize); //Điều chỉnh lại size của vector, giá trị thêm mặc định bằng 0
	void resize(int newsize, int value); //Điểu chỉnh lại size của vector, giá trị thêm bằng value
	void shrink_to_fit(); //Điều chỉnh lại size = capacity
	void reverse(); //Đảo ngược vector
		
	//Iterator
	int * Begin(); //Trả về con trỏ đến phần tử đầu tiên trong vector
	int * End(); //Trả về con trỏ đến phần tử cuối cùng trong vector
	int * rBegin(); //Trả về con trỏ đến phần tử cuối trong vector
	int * rEnd(); //Trả về con trỏ đến phần tử đầu tiên trong vector
	
	//Modifiers
	void assign(int number, int value); //Gán giá trị cho vector với số lượng là giá trị cụ thể
	void assign(int * begin, int * end); //Gán giá trị cho vector trong 1 khoảng giá trị có sẵn
	void push_back(int data); //Thêm phần tử vào cuối vector
	void pop_back(); //Lấy phần tử đầu tiên ra
	void insert(int * it, int data); //Thêm phần tử vào vị trí chỉ định
	void insert(int *it, int number, int data); //Thêm nhiều phần tử vào vị trí chỉ định
	void insert(int * it, int * begin, int * end); //Thêm nhiều phần tử nằm trong 1 khoảng giá trị có sẵn vào vị trí chỉ định
	void erase(int *it); //Xóa phần tử ở vị trí chỉ định
	void erase(int *pbegin, int *pend); //Xóa nhiều phần tử
	void swap(cVector& bar); //Swap 2 vector với nhau
	int * emplace(int * it, int value); //Thêm phần tử ở vị trí chỉ định và trả về con trỏ đến phần tử được thêm
	void clear(); //Dọn hết data của vector
};


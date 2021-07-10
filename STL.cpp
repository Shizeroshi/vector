#include <iostream>
#include <array>
#include <vector>
#include <list>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
//#define STL_ARRAY
#define STL_VECTOR
//#define ExceptionsInVector
//#define STL_LIST

template<typename T> void vector_properties(const std::vector<T>& vec)
{
	cout << "Size:	    " << vec.size() << endl;
	cout << "Capacity:	" << vec.capacity() << endl; //Вместительность - сколько элементов может вместить в себя вектор без 
	cout << "MaxSize:	" << vec.max_size() << endl;
}

template<typename T> void vector_print(const std::vector<T>& vec)
{
	for (typename vector<T>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}
template<typename T> void reverse_vector_print(vector<T>& vec)
{
	reverse(vec.begin(), vec.end());
	for (typename vector<T>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}
template<typename T> void list_print(const std::list<T>& list)
{
	for (typename std::list<T>::const_iterator it = list.begin(); it != list.end(); it++)
	{
		cout << *it << tab;
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	system("color 0A");

#ifdef STL_ARRAY
	//Array - это контейнер, который хранит данные в виде статического массива
	const int n = 5;
	std::array<int, n> arr = { 3, 5, 8, 13, 21 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR


	//vector - это контейнер, который хранит данные в виде динамического массива
	std::vector<int> vec = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
	vector_properties(vec);
	//vec.push_back(55);
	vector_properties(vec);

#ifdef ExceptionsInVector
	try
	{
		for (int i = 0; i < vec.size(); i++)
		{
			// try...catch...
			// [] - index operator (subscript operator)
			//cout << vec[i] << tab;  // Оператор [] НЕ бросает исключение при выходе за пределы вектора
			cout << vec.at(i) << tab; // Метод at() бросает исключение (out of range exception) при выходе за пределы вектора
		}
		cout << endl;
		throw 123;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	catch (int e)
	{
		std::cerr << "Error number: " << endl;
	}
#endif // ExceptionsInVector

	vector_print(vec);

	int index;
	int value;
	cout << "Индекс: "; cin >> index;
	cout << "Значение: "; cin >> value;

	vector<int>::iterator position = vec.begin();
	for (int i = 0; i < index; i++)position++;
	vec.insert(position, value);
	vector_print(vec);

	int index2;
	cout << "Индекс удаления: "; cin >> index2;
	vec.erase(vec.begin() + index2);
	vector_print(vec);
	cout << endl;
	cout << "Вектор в обратном порядке" << endl << endl;
	reverse_vector_print(vec);

#endif // STL_VECTOR

#ifdef STL_LIST
	std::list<int> list = { 3, 5, 8, 13, 21 };
	
	list_print(list);

	int index;
	int value;

	cout << "Индекс добавляемого элеманта: "; cin >> index;
	cout << "Значение добавляемого элеманта: "; cin >> value;

	std::list<int>::iterator position = list.begin();
	for (int i = 0; i < index; i++)position++;
	list.insert(position, value);
	list_print(list);

	int index2;
	cout << "Индекс удаляемогго элеманта: "; cin >> index2;
	std::list<int>::iterator position = list.begin();
	//for (int i = 0; i < index; i++)position--;
	//list.erase(position, value);

#endif // STL_LIST

}
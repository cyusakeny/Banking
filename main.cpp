// C++ program to demonstrate read/write of class
// objects in C++.
#include <iostream>
#include <fstream>
using namespace std;

class Contestant {
public:
	string Name;
	int Age, Ratings;
	int input();
	int output_highest_rated();
	void deleteAll();
};
int Contestant::input()
{
	ofstream file_obj;

	// Opening file in append mode
	file_obj.open("Input.txt");
	Contestant obj;
	char str[20];
	int i = 0;
	while (i<3)
	{
		int age = 18, ratings = 2500;
	obj.Name = "richard";
	obj.Age = age;
	obj.Ratings = ratings;

	file_obj<<obj.Name<<' '<<obj.Age<<' '<<obj.Ratings;
	i++;
	}
	
	return 0;
}
int Contestant::output_highest_rated()
{
	ifstream file_obj;
	Contestant obj;
	file_obj.open("Input.txt");
	int max = 0;
	string Highest_rated;
	
	file_obj>> obj.Name >> obj.Age >> obj.Ratings;
	cout<<"Data:"<<obj.Name;
	cout << Highest_rated;
	return 0;
}

// Driver code
int main()
{
	Contestant object;
    string name = "Age";
	object.input();
	object.output_highest_rated();

	return 0;
}

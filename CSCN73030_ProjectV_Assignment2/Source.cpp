//Sources used
//https://cplusplus.com/doc/tutorial/files/
//https://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c
//https://cplusplus.com/forum/general/268408/

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include <algorithm>

using namespace std;

struct STUDENT_DATA {
	string firstName;
	string lastName;
} student_data;

int main() {
	vector<STUDENT_DATA> students;
	string line;

	ifstream file("StudentData.txt");

	if (file.is_open())
	{
		while (getline(file, line))
		{
			istringstream iss(line);
			//cout << line << '\n';
			string lastname;
			getline(iss, lastname, ',');
			string firstname;
			iss >> firstname;


			struct STUDENT_DATA student;
			student.firstName = firstname;
			student.lastName = lastname;

			students.push_back(student);
		}
		file.close();
	}
	
#ifdef _DEBUG

	for (int i = 0; i < students.size(); i++) {
		cout << "firstname: " << students.at(i).firstName << " lastname: " << students.at(i).lastName << endl;
	}

#endif
	return 1;
}
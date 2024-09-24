//Sources used
//https://cplusplus.com/doc/tutorial/files/
//https://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c
//https://cplusplus.com/forum/general/268408/

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>


using namespace std;

struct STUDENT_DATA {
	string firstName;
	string lastName;
	string studentEmail;
} student_data;

int main() {
	vector<STUDENT_DATA> students;
	string line;

#ifdef PRE_RELEASE
	cout << "running PreRelease source code\n";
	ifstream file("StudentData_Emails.txt");
#else
	cout << "running standard source code\n";
	ifstream file("StudentData.txt");

#endif


	if (file.is_open())
	{
		while (getline(file, line))
		{
			istringstream iss(line);

			string lastname;
			getline(iss, lastname, ',');
			string firstname;
#ifdef PRE_RELEASE
			getline(iss, firstname, ',');
			string studentemail;
			iss >> studentemail;

#else

			iss >> firstname;
#endif

			struct STUDENT_DATA student;
			student.firstName = firstname;
			student.lastName = lastname;

#ifdef PRE_RELEASE
			student.studentEmail = studentemail;
#endif

			students.push_back(student);
		}
		file.close();
	}

#ifdef _DEBUG

	for (int i = 0; i < students.size(); i++) {
		cout << "firstname: " << students.at(i).firstName << " lastname: " << students.at(i).lastName << " email: " << students.at(i).studentEmail << endl;
	}

#endif

	return 1;
}
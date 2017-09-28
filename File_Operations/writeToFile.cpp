#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

// Function Definition
void writeCourse(string name, string courseId, string timeOffered);
void findCourse(string name);

int main()
{
    FILE *fp;

    fp = fopen("CourseDataBase.txt", "w");

    fprintf(fp, "Name             Course Id            Time Offered \n");

    fclose(fp);


    // write a new course detail in server
    writeCourse("Data Structures", "CS1234", "12:30pm - 2:30pm");
    writeCourse("Operating Systems", "CS4567", "5:50pm - 7:30pm");
    writeCourse("VLSI", "CS9876", "8:30pm - 10:30pm");

    // find course in database
    findCourse("Data Structures");

    return 0;
}

// Function to write a course in "CourseDataBase.txt"
void writeCourse(string name, string courseId, string timeOffered)
{
    FILE *fp;

    fp  = fopen("CourseDataBase.txt", "a");

    fprintf(fp, "%s     %s    %s\n", name.c_str(), courseId.c_str(), timeOffered.c_str());
    
    fclose(fp);
}


void findCourse(string name)
{
    ifstream fp;
    fp.open("CourseDataBase.txt", std::ifstream::in);
   
     string line;


    while(getline(fp, line))
    {

        if(line.find(name) != string::npos)
        {
            cout << line << endl;
            break;
        }
    }
    
   fp.close();
} 
  

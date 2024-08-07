#include <iostream>
#include <vector>
#include <iomanip>

struct Course {
    std::string name;
    double credits;		// A course structure with 4 members that is used in different functions
    char grade;
    double gradePoint;
};

double getGradePoint(char grade) {
    switch(grade) {
        case 'A': return 4.0;
        case 'B': return 3.0;		//	This function takes a grade character and returns the 
        case 'C': return 2.0;		//	corresponding grade point value based on a standard 4.0 GPA scale
        case 'D': return 1.0;
        case 'F': return 0.0;
        default: return 0.0;
    }
}

int main() {
    std::vector<Course> courses;									//	Initializes an empty vector of Course structures.
    int numCourses;													//	Declares numCourses to store the number of courses.
    double totalCredits = 0, totalGradePoints = 0;					//	Initializes totalCredits and totalGradePoints to 0.

    std::cout << "Enter the number of courses: ";
    std::cin >> numCourses;

    for (int i = 0; i < numCourses; ++i) {
        Course course;
        std::cout << "\nEnter details for course " << i + 1 << ":\n";	//Loops through each course to get details from the user
        std::cout << "Course name: ";
        std::cin >> course.name;
        std::cout << "Credits: ";
        std::cin >> course.credits;
        std::cout << "Grade (A/B/C/D/F): ";
        std::cin >> course.grade;

        course.gradePoint = getGradePoint(course.grade);
        totalCredits += course.credits;
        totalGradePoints += course.credits * course.gradePoint;

        courses.push_back(course);
    }

    double gpa = totalGradePoints / totalCredits;		//Calculates the GPA as the total grade points divided by the total credits.

    std::cout << "\n----- Results -----\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Individual Course Grades:\n";
    for (const auto& course : courses) {
        std::cout << course.name << ": " << course.grade << " (GPA: " << course.gradePoint << ")\n";
    }

    std::cout << "\nTotal Credits: " << totalCredits << std::endl;
    std::cout << "Total Grade Points: " << totalGradePoints << std::endl;		//Results using cgpa formulas used by universities
    std::cout << "Semester GPA: " << gpa << std::endl;
    std::cout << "CGPA: " << gpa << std::endl;  

    return 0;
}
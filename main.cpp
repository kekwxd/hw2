#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int getValidIntegerInput(string prompt, int min, int max)
{
    int integerinput;
    cout << prompt;
    cin >> integerinput;
    while (integerinput < min or integerinput > max){
        cout << "Invalid input. Value must be between " << min << " and " << max << "." << endl;
        cout << prompt;
        cin >> integerinput;


    }
    return integerinput;
}
double getValidDoubleInput(string prompt, double min, double max)
{
    double integerinput;
    cout << prompt;
    cin >> integerinput;
    while (integerinput < min or integerinput > max){
        cout << fixed << setprecision(2);
        cout << "Invalid input. Value must be between " << min << " and " << max << "." << endl;
        cout << prompt;
        cin >> integerinput;
        

    }
    return integerinput;
}
double calculateFinalGrade(int midterm, int final, double assignments, double quizzes){
    
    return (midterm*0.3)+(final*0.4)+(assignments*0.2)+(quizzes*0.1); 


}
string determineLetterGrade(double finalGrade){
    if (finalGrade >= 90){
        return "AA";
     
    }
    else if (finalGrade >= 85){
        return "BA";
    }
    else if (finalGrade >= 80){
        return "BB";
    }
    else if (finalGrade >= 75){
        return "CB";
    }
    else if (finalGrade >= 70){
        return "CC";
    }
    else if (finalGrade >= 65){
        return "DC";
    }
    else if (finalGrade >= 60){
        return "DD";
    }
    else {
        return "FF";
    }

}
void displayStudentReport(string studentId, int midterm, int final, double assignments, double quizzes, double finalGrade, string letterGrade){
    cout << "Student ID: "  << studentId << endl;
    cout << "Midterm (30%): " << midterm << endl;
    cout << "Final (40%): " << final << endl;
    cout << fixed << setprecision(2);
    cout << "Assignments (20%): " << assignments << endl;
    cout << "Quizzes (10%): " << quizzes << endl;
    cout << "Final Grade: " << finalGrade << endl;
    cout << "Letter Grade: " << letterGrade << endl;
    cout << endl;
}
void updateStatistics(double finalGrade, string studentId, double& highest, double& lowest, double& sum, string& highestId, string& lowestId, bool isFirst){
    if (isFirst or finalGrade > highest){
        highest = finalGrade;
        highestId = studentId;


    }
    if (isFirst or finalGrade < lowest){
        lowest = finalGrade;
        lowestId = studentId;


    }
    sum+= finalGrade;
}

int main(){
    string ders;
    cout << "Enter course code: ";
    cin >> ders;
    bool ilkmi = true;
    string highid, lowestid;
    double highgrade = 0.0, lowestgrade = 0.0, toplam = 0.0;
    int students = getValidIntegerInput("Enter number of students: ", 1, 100);
    cout << endl;
    for (int i= 1; i<=students; i++)
    {
        cout << "Student " << i << ":" << endl;
        string studentId;
        cout << "Enter student ID: ";
        cin >> studentId;
        int midterm = getValidIntegerInput("Enter midterm score: ", 0, 100);
        int final = getValidIntegerInput("Enter final exam score: ", 0, 100);
        double odev = getValidDoubleInput("Enter assignment average: ", 0.00, 100.00);
        double quizz = getValidDoubleInput("Enter quiz average: ", 0.00, 100.00);
        cout << endl;
        double notsonuc = calculateFinalGrade(midterm, final, odev, quizz);
        string harfnot = determineLetterGrade(notsonuc);
        displayStudentReport(studentId, midterm, final, odev, quizz, notsonuc, harfnot);
        updateStatistics(notsonuc, studentId, highgrade, lowestgrade, toplam, highid, lowestid, ilkmi);
        ilkmi = false;



    }
    cout << "Course: " << ders << " - Class Statistics" << endl;
    cout << "----------------------------------------" << endl;
    cout << fixed << setprecision(2);
    cout << "Class Average: " << (toplam/students) << endl;
    cout << "Highest Grade: " << highgrade << " (" << highid << ")" << endl;
    cout << "Lowest Grade: " << lowestgrade << " (" << lowestid << ")" << endl;
    return 0;
    

}

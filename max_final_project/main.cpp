#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;
//Function Declarations
char calculateLetterGrade(double g);
double findMinQuiz(double q1, double q2, double q3, double q4);
double findAverageQuizScore(double q1, double q2, double q3, double q4);
double findAverageHomeworkScore(double h1, double h2, double h3, double h4, double h5, double h6, double h7);
double findAverageLabScore(double l1, double l2, double l3, double l4, double l5, double l6, double l7, double l8);
double findAverageExamScore(double e1, double e2);
//Variable Declarations
string firstName, lastName;
double q1Score, q2Score, q3Score, q4Score;
double h1Score, h2Score, h3Score, h4Score, h5Score, h6Score, h7Score;
double l1Score, l2Score, l3Score, l4Score, l5Score, l6Score, l7Score, l8Score;
double e1Score, e2Score;
double fScore;
double grade;
//File I/O Declarations
ifstream fin;
ofstream fout1, fout2;

int main() {
    //Additional Variable Declarations/Initializations
    double grade;
    int students = 0;
    double classAverageCounter = 0;
    //File I/O Activation
    fin.open("gradesIn.txt");
    fout1.open("gradesOut1.txt");
    fout2.open("gradesOut2.txt");
    //Condition checks if all necessary values are present
    while (fin >> firstName >> lastName >> q1Score >> q2Score >> q3Score >> q4Score >> h1Score >> h2Score >> h3Score >> h4Score >> h5Score >> h6Score >> h7Score >> l1Score >> l2Score >> l3Score >> l4Score >> l5Score >> l6Score >> l7Score >> l8Score >> e1Score >> e2Score >> fScore){
        
        findMinQuiz(q1Score, q2Score, q3Score, q4Score);
        
        double quizGrade = findAverageQuizScore(q1Score, q2Score, q3Score, q4Score);
        double homeworkGrade = findAverageHomeworkScore(h1Score, h2Score, h3Score, h4Score, h5Score, h6Score, h7Score);
        double labGrade = findAverageLabScore(l1Score, l2Score, l3Score, l4Score, l5Score, l6Score, l7Score, l8Score);
        double examGrade = findAverageExamScore(e1Score, e2Score);
        
        grade = quizGrade*0.2 + homeworkGrade*0.1 + labGrade*0.1 + examGrade*0.3 + fScore*0.3;
        
        fout1 << fixed << setprecision(2);
        fout2 << fixed << setprecision(2);
        fout1 << firstName << ", " << lastName << endl << "Quiz Grade: " << quizGrade << endl << "Exam Grade: " << examGrade << endl << "Lab Grade: " << labGrade << endl << "Homework Grade: " << homeworkGrade << endl << "Final Exam Grade: " << fScore << endl << "Course Average: " << grade << endl << endl;
        fout2 << firstName << ", " << lastName << endl << "Course Average: " << grade << endl << "Letter Grade: " << calculateLetterGrade(grade) << endl << endl;
        //Counters for both student amount and average of class averages
        students++;
        classAverageCounter+= grade;
        
    }
    
    fout2 << "Total number of students in this class: " << students << endl << "Class Average: " << classAverageCounter / students << endl;
    
    fin.close();
    fout1.close();
    fout2.close();
    
    return 0;
}

char calculateLetterGrade(double g){
    
    if (g >= 90){
        return 'A';
    } else if (g >= 80){
        return 'B';
    } else if (g >= 70){
        return 'C';
    } else if (g >= 60){
        return 'D';
    } else {return 'F';}
    
}

double findMinQuiz(double q1, double q2, double q3, double q4){
    
    if (q1 < q2 && q1 < q3 && q1 < q4){
        return q1;
    } else if (q2 < q1 && q2 < q3 && q2 < q4){
        return q2;
    } else if (q3 < q1 && q3 < q2 && q3 < q4){
        return q2;
    } else {
        return q2;
    }
    
}

double findAverageQuizScore(double q1, double q2, double q3, double q4){
    
    if(findMinQuiz(q1Score, q2Score, q3Score, q4Score) == q1){
            return (q2 + q3 + q4)/3;
        } else if(findMinQuiz(q1Score, q2Score, q3Score, q4Score) == q2){
            return (q1 + q3 + q4)/3;
        } else if(findMinQuiz(q1Score, q2Score, q3Score, q4Score) == q3){
            return (q1 + q2 + q4)/3;
        } else {return (q1 + q2 + q3)/3;}
    
}

double findAverageHomeworkScore(double h1, double h2, double h3, double h4, double h5, double h6, double h7){
    return (h1+h2+h3+h4+h5+h6+h7)/7;
}

double findAverageLabScore(double l1, double l2, double l3, double l4, double l5, double l6, double l7, double l8){
    return(l1+l2+l3+l4+l5+l6+l7+l8)/8;
}

double findAverageExamScore(double e1, double e2){
    return(e1 + e2)/2;
}

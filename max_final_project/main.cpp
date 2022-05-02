#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;

string calculateLetterGrade(double grade);
double findMinQuiz(double q1, double q2, double q3, double q4);
double findAverageQuizScore(double q1, double q2, double q3, double q4);
double findAverageHomeworkScore(double h1, double h2, double h3, double h4, double h5, double h6, double h7);
double findAverageLabScore(double l1, double l2, double l3, double l4, double l5, double l6, double l7, double l8);
double findAverageExamScore(double e1, double e2);

int main() {
    
    string firstName, lastName;
    double q1Score, q2Score, q3Score, q4Score;
    double h1Score, h2Score, h3Score, h4Score, h5Score, h6Score, h7Score;
    double l1Score, l2Score, l3Score, l4Score, l5Score, l6Score, l7Score, l8Score;
    double e1Score, e2Score;
    
    ifstream fin;
    ofstream fout;
    
    fin.open("gradesIn.txt");
    fout.open("gradesOut1.txt");
    
    while (!fin.eof()){
        
        
        
    }
    
    
    
    
    return 0;
}



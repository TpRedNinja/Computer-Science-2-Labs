#include <iomanip>
#include <iostream>
using namespace std;

// prototypes for getScore and average
void getScores(int score[], int numOfStudents);
double average(int score[], int numOfStudents);

int main()
{
    const int NUM_STUDENTS = 5;
    // init array to size num_students
    int test_scores[NUM_STUDENTS];

    getScores(test_scores, NUM_STUDENTS);

    double class_average = average(test_scores, NUM_STUDENTS);
    cout << setprecision(2) << fixed; // round to the nearest 100th
    cout << "The classes average test score is " << class_average << endl;
    return 0;
}

void getScores(int score[], int numOfStudents)
{
    for (int i = 0; i < numOfStudents; i++)
    {
        cout << "Enter the Score for student #" << i + 1 << " : ";
        cin >> score[i]; // store data into score at index i
    }
}

double average(int score[], int numOfStudents)
{
    double sum = 0.0;
    for (int i = 0; i < numOfStudents; i++)
    {
        sum += score[i];
    }
    return sum / numOfStudents; // return the average
}

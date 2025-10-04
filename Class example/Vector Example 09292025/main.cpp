#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

// prototypes for getScore and average
void getScores(vector <int>& score);
double average(const vector <int>& score);

int main()
{
    // init vector
    vector <int> test_scores;

    getScores(test_scores);

    double class_average = average(test_scores);
    cout << setprecision(2) << fixed; // round to the nearest 100th
    cout << "The classes average test score is " << class_average << endl;
    return 0;
}

void getScores(vector<int>& score)
{
    int student_score = 0;
    do
    {
        cout << "(Enter -1 to exit) ";
        cout << "Please enter next student score: ";
        cin >> student_score; // temp score
        if (student_score >= 0)
            score.push_back(student_score);


    }
    while (student_score >= 0);
}

double average(const vector<int>& score)
{
    double sum = 0.0;
    for (int i = 0; i < score.size(); ++i)
    {
        sum += score[i];
    }
    return sum / score.size();

}

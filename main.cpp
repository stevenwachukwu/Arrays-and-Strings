#include <iostream>
using namespace std;

float mean(int record[]) {
  float sum = 0;

  for (int i = 0; i < 15; i++)
    sum += record[i];

  return sum / 15;
} //The function defintion used to calculate the mean

int ModeNum(int record[], int rows) {
  int maxValue = 0, maxCount = 0, a, b;
  for (a = 0; a < rows; ++a) {
    int count = 0;

    for (b = 0; b < rows; ++b) {
      if (record[b] == record[a])
        ++count;
    }
    if (count > maxCount) {
      maxCount = count;
      maxValue = record[a];
    }
  }
  return maxValue;
} //The function definition used to calculate the mode

int main() {
  string identity[15]; //array for ID
  int record[15]; //array for score
  int i;
  int j;
  int rows = 15; //variable for row size
  int columns = 2;
  float meanResult; //used to help get the mean

  cout << "Please enter in the ID #'s and scores:" << endl;
  for (i = 0; i < 15; ++i) {
    cout << "ID:   Score:   " << endl;
    cin >> identity[i] >> record[i];
    cout << "------------" << endl;
  } //User puts in ID and score 15 times
  cout << "--------------------" << endl;
  for (i = 0; i < rows; ++i) {
    cout << "ID: " << identity[i] << "  Score: " << record[i] << endl;
  } //print outs the user's input
  cout << "--------------------" << endl;
  cout << "ID:   Score:   Results:" << endl;
  for (int i = 14; i >= 0; i--) {
    for (int j = 0; j < i; j++) {
      if (record[j] < record[j + 1]) {
        int tempRecord = record[j];
        record[j] = record[j + 1];
        record[j + 1] = tempRecord;

        string tempID = identity[j];
        identity[j] = identity[j + 1];
        identity[j + 1] = tempID;
      }
    }
  } //This for loop is used to sort the array
  meanResult = mean(record);
  for (int i = 0; i < 15; i++) {
    if (i == 0) {
      cout << identity[i] << "      " << record[i] << "      Winner" << endl;
    } 
    else if (i == 1) {
      cout << identity[i] << "      " << record[i] << "      Second Place"
           << endl;
    } else if (i == 2) {
      cout << identity[i] << "      " << record[i] << "      Third Place"
           << endl;
    } else if (record[i] > meanResult) {
      cout << identity[i] << "      " << record[i] << "      Above Average"
           << endl;
    }
       else {
      cout << identity[i] << "      " << record[i] <<endl;
      }
    } //This for loop is used to identify the scores that need to be in first place, second place, third place, or even above average.
  cout << "\nThe mean is " << meanResult << ", and the mode of these scores is "
       << ModeNum(record, rows) << "." << endl; //printout of the mean and mode scores with the function calls
  }

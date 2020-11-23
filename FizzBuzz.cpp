#include <iostream>
#include <algorithm>
using namespace std;

int currentInt = 1;

/* Check if int is dividable by 3 or 5 and return FizzBuzz answer */
string get_solution(int num) {
  string answer;
  if (num % 3 == 0) {
    answer += "Fizz";
  }
  if (num % 5 == 0) {
    answer += "Buzz";
  }

  if (answer.empty()) {
    answer = to_string(num);
  }
  return answer;
}

bool is_answer_correct(string answer) {
  // Transform solution to lowercase
  string solution = get_solution(currentInt);
  transform(solution.begin(), solution.end(), solution.begin(), ::tolower);

  if (solution == answer)
    return true;
  else return false;
}


int main() {
  cout << "This is a game of FizzBuzz. You and the computer will count from 1 and upwards." << endl
  << "For numbers dividable by 3 answer \"Fizz\"." << endl
  << "For numbers dividable by 5 answer \"Buzz\". " << endl
  << "For numbers dividable by both answer \"FizzBuzz\". " << endl
  << "For numbers not dividable by either simply answer the number." << endl
  << endl
  << "Start by typing \"1\"" << endl;

  /* infite loop */
  for (;;) {
    string input;
    // Fetch player input
    getline(cin, input);

    // Transform input to lowercase
    transform(input.begin(), input.end(), input.begin(), ::tolower);

    // Break if player answered wrong
    if (!is_answer_correct(input)) {
      cout << "Incorrect answer. Correct answer was " << get_solution(currentInt) << endl;
      break;
    }

    currentInt++;
    cout << get_solution(currentInt) << endl;
    currentInt++;
  }
}

#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

/* Pseudo Code
 
treeTrack: String[2](0 - pre, 1 -infix)
String posfixo(String[] treeTrack) {
 Identify root with pre
 Identify left and right of the root with infix
 Return posfixo(left) + posfixo(right) + root
}
*/

vector<string> getLeftAndRightFromInfix(string infix, string root) {
  vector<string> infixLefRight = vector<string>(2);

  int rootPosition = infix.find(root);

  infixLefRight[0] = infix.substr(0, rootPosition);
  infixLefRight[1] = infix.substr(rootPosition+1);

  return infixLefRight;
}

string posfixo(vector<string> treeTrack) {
  vector<string> leftRight;
  vector<string> left = vector<string>(3);
  vector<string> right = vector<string>(3);
  string root;
  string leftResult, rightResult;

  if(treeTrack[0].length() && treeTrack[1].length()) {

    root = treeTrack[0].at(0);
    leftRight = getLeftAndRightFromInfix(treeTrack[1], root);

    left[1] = leftRight[0];
    right[1] = leftRight[1];

    left[0] = treeTrack[0].substr(1, left[1].length());
    right[0] = treeTrack[0].substr(left[1].length()+1);

    leftResult = posfixo(left);
    rightResult = posfixo(right);

    return leftResult + rightResult + root;
  }

  return "";
}

int stringToInt (string input) {
  int number = 0;

  stringstream myStream(input);

  if (myStream >> number) {
    return number;
  } else {
    return -1;
  }
};

int main() {
  vector<string> treeTrack;
  int testsNumber, treeLength;
  string input;

  cin >> input;

  testsNumber = stringToInt(input);

  for(int index = 0; index < testsNumber; index++) {
    treeTrack = vector<string>(2);

    cin >> input;

    treeLength = stringToInt(input);

    cin >> input;
    treeTrack[0] = input;

    cin >> input;
    treeTrack[1] = input;

    cout << posfixo(treeTrack) << endl;
  }

}
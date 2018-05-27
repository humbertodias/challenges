// Problem   Boolean Logic
// Algorithm Parser, Brute-Force
// Runtime   O(2^n)

#include <cassert>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>

using namespace std;

typedef queue<int> qi;
typedef stack<int> si;
typedef vector<int> vi;
typedef map<char,int> mci;

bool binary(char ch)
{
  // ... conjunction, disjunction, implication, equivalence
  return ch == '&' || ch == '|' || ch == '-' || ch == '<';
}

// The semantics of the operators, lifted to characters.
// If op is unary it is applied to o1.
// If op is binary it is applied to o1 and o2.
// The result of the application is returned.
char apply(char o1, char op, char o2='0')
{
  assert(o1 == '0' || o1 == '1');
  assert(o2 == '0' || o2 == '1');
  int v1 = o1 - '0';
  int v2 = o2 - '0';
  int v = op == '!' ? !v1 :
          op == '&' ? v1&v2 :
          op == '|' ? v1|v2 :
          op == '-' ? (!v1)|v2 :
          op == '<' ? !(v1^v2) :
          2;
  assert (v == 0 || v == 1);
  return '0' + v;
}

// The proposition symbols occuring in s are given numbers in alphabetical order.
// The resulting mapping is returned.
mci symbols(string &s)
{
  mci m;
  for (unsigned int i=0 ; i<s.size() ; i++)
    if (islower(s[i]))
      m[s[i]] = 1;
  int bit = 0;
  // The map m is traversed in reverse alphabetic order.
  // Thus, the last proposition symbol will be represented by the least significant bit 0.
  for (mci::reverse_iterator it = m.rbegin() ; it != m.rend() ; ++it)
    it->second = bit++;
  return m;
}

// The positions of all proposition symbols, operators and brackets occuring in s are identified.
// Grouped with their positions, these entities are inserted into a queue that is returned.
qi lex(string &s)
{
  qi q;
  for (unsigned int i=0 ; i<s.size() ; i++)
    if (islower(s[i]) || s[i] == '!' || s[i] == '&' || s[i] == '|' || s[i] == '(' || s[i] == ')')
      q.push(i);
    else if (s[i] == '-' || s[i] == '<')
    {
      // Implication and equivalence are represented by three-character symbols.
      // We use the first symbol, but the position of the second (center) character.
      char ch = s[i];
      for (i++ ; i<s.size() && s[i] != '-' ; i++)
        assert(s[i] == ' ');
      // This is a hack: the second (center) character is overwritten by the first symbol.
      s[i] = ch;
      q.push(i);
      for (i++ ; i<s.size() && s[i] != '>' ; i++)
        assert(s[i] == ' ');
      assert(i<s.size());
    }
    else
      assert(s[i] == ' ');
  return q;
}

// The queue q containing the essence of the input is parsed into a syntax tree.
// The tree is represented by the arrays v1 and v2 containing the positions of the children of each node.
// The nodes are indexed by integers, and the root is returned.
int parse(string &s, qi &q, vi &v1, vi &v2)
{
  si st;
  while (!q.empty())
  {
    int next = q.front();
    q.pop();
    if (s[next] == ')')
    {
      // The top of the stack now contains the operator and its operands.
      // The operator is on the next-to-top position.
      // If it is unary, its operand is on the top position.
      // If it is binary, its first operand is on the 3rd position and its second operand is on the top.
      int o2 = st.top();
      st.pop();
      int op = st.top();
      st.pop();
      if (s[op] == '!')
        v1[op] = o2;
      else
      {
        assert(binary(s[op]));
        v2[op] = o2;
        int o1 = st.top();
        st.pop();
        v1[op] = o1;
      }
      // The matching bracket must be removed.
      assert(s[st.top()] == '(');
      st.pop();
      st.push(op);
    }
    else
      st.push(next);
  }
  // The top of the one-element stack contains the index of the root of the syntax tree.
  assert(st.size() == 1);
  return st.top();
}

// The tree represented by v1 and v2 and rooted at node is evaluated.
// The mapping m gives the bit-position in the counter q for each proposition symbol, and thereby its value.
// The string s is overwritten such that the position of each sub-tree contains its value.
void eval(string &s, int node, vi &v1, vi &v2, mci &m, int q)
{
  if (islower(s[node]))
    s[node] = q & (1 << m[s[node]]) ? '1' : '0';
  else if (s[node] == '!')
  {
    // The unary node is evaluated recursively.
    eval(s, v1[node], v1, v2, m, q);
    s[node] = apply(s[v1[node]], s[node]);
  }
  else
  {
    // The binary node is evaluated recursively.
    assert(binary(s[node]));
    eval(s, v1[node], v1, v2, m, q);
    eval(s, v2[node], v1, v2, m, q);
    s[node] = apply(s[v1[node]], s[node], s[v2[node]]);
  }
}

// A truth table is created for the string line, its syntax tree is represented by v1 and v2 and rooted at node.
// The mapping m gives the bit-position for each proposition symbol.
void truthtable(string &line, int root, vi &v1, vi &v2, mci &m)
{
  int qmax = 1 << m.size();
  for (int q=0 ; q<qmax ; q++)
  {
    // The value of q represents one line of the table by the corresponding assignment.
    string s = line;
    eval(s, root, v1, v2, m, q);
    // The post-processing removes the brackets and superfluous characters of three-character operators.
    for (unsigned int i=0 ; i<s.size() ; i++)
      if (s[i] != '0' && s[i] != '1')
        s[i] = ' ';
    cout << s << endl;
  }
}

int main()
{
  string line;
  while (getline(cin, line))
  {
    cout << line << endl;
    mci m = symbols(line);
    qi q = lex(line);
    vi v1(line.size());
    vi v2(line.size());
    int root = parse(line, q, v1, v2);
    truthtable(line, root, v1, v2, m);
    cout << endl;
  }
  return 0;
}
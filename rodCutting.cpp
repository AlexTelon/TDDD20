#include <iostream>
using namespace std;

/*
 We have a rod of lenth l. We try to maximize the revenue by seeing if we can increase our revenue by cutting the rod in shorter lengths and selling them by parts. Check all lengths from 1 to l, length 0 is always 0 income. Problem from page 360 in Introduction to Algorithms 3rd edition.
 */
int cutRod(int* p, int n) {
  if (n == 0) 
    return 0;
  int q = -9999;
  for (int i = 0; i < n; i++) {
    q = max(q, p[i] + cutRod(p, n-1));
  }
  return q;
}

  // not working... and i want to return the right things
int cutRod(int* r, int* s, int* p, int n) {

  int q;
  for (int j = 0; j < n; j++) {
    q = -9999;
    for (int i = 0; i < j; i++) {
      if (q < p[i] + r[j-i]) {
	q = p[i] + r[j-i];
	s[j] = i;
      }
    r[j] = q;
    }
  }
  // change return
  return q;
}

main()
{
  int prize[]{1,1,1,1,0,0,0,1};
  int rodLength = sizeof(prize)/sizeof(int);
  int solution[rodLength];
  int r[rodLength];
  for (int i = 0; i < rodLength; i++) {
    r[i] = 0;
  }


  //  int r[]{};

  cutRod(r, solution, prize, rodLength);
  cout << "Best prize " << cutRod(prize, rodLength) << endl;
  cout << "solution ";

  for (int i = 0; i < rodLength; i++) {
    cout << solution[i] << " ";
  }

  cout << endl << "r ";
  for (int i = 0; i < rodLength; i++) {
    cout << r[i] << " ";
  }
  cout << endl;
  return 0;
}




/************************************************************************************
 * Zeynep Begum Kara
 * ID: 22003880
 * CS201 - 01
 *
 * HW - 2:  Algorithm Analysis
 * Given three integers a, n and p, algorithms will calculate and return a^n (mod p)
 ************************************************************************************/

  #include <iostream>
  #include <time.h>
  using namespace std;


 /*
  * Algorithm I: Naive Algorithm
  * multiplies 'a' with itself in a for loop and takes modulus 'p' in each step
  *
  * @param long number a, long power n, long p denotes the congruence relation
  * @return a^n (mod p)
  */
 unsigned long long int naiveAlgorithm(unsigned long long int a, unsigned long long int n, int p)
 {
    if ( n == 0 ) { return 1; }
    else
    {
        unsigned long long int res = 1;
        for(unsigned long long i = 0; i < n; i++)
        {
            res *= a;
            res = res % p;
        }
        return res;
    }
 }

 /*
  * Algorithm II: Naive algorithm with Cycle shortcut
  *-----------------------------------------------------------
  *
  * @param long number a, long power n, long p denotes the congruence relation
  * @return a^n (mod p)
  */
  unsigned long long int cycleShortcutAlgorithm(unsigned long long int a, unsigned long long int n, int p)
  {
    if ( n == 0 ) { return 1; }
    else
    {
        unsigned long long int res = 1;
        for(unsigned long long int i = 0; i < n; i++)
        {
            res *= a;
            res = res % p;
            if ( res % p == 1 ) {
                return naiveAlgorithm(a, (n % (i + 1)), p);
            }
        }
        return res;
    }
  }


 /*
  * Algorithm III: Recursive algorithm
  * ---------------------------------
  *
  * @param long number a, long power n, long p denotes the congruence relation
  * @return a^n (mod p)
  */
  unsigned long long int recursiveAlgorithm(unsigned long long int a, unsigned long long int n, unsigned long long int p)
  {
      if (n == 0) { return 1; }
      else if (n == 1) { return a % p; }
      else if (n % 2 == 0)
      {
        return (recursiveAlgorithm(a, n / 2, p) * recursiveAlgorithm(a, n / 2, p)) % p;
      }
      else
      {
        return (a * recursiveAlgorithm(a, (n-1) / 2, p) * recursiveAlgorithm(a, (n-1) / 2, p)) % p;
      }
  }


 int main()
 {
    int times = 1000;
    unsigned long long int a = 3;
    unsigned long long int n = 1000000000;
    int p[3] = {101, 1009, 10007};

    unsigned long long int res = 0;
    clock_t startTime;

    cout << endl;
    cout << "--------------NAIVE ALGORITHM-------------- " << endl;

  for (int j = 0; j < 3; j++)
    {
        cout << "--------------p = " << p[j] << "--------------" << endl;
        for (int i = 1; i < 11;i++)
        {
            cout << "n = " << i * n << endl;
            //start clock
            double duration;
            startTime = clock();

            //run algorithm
            res = naiveAlgorithm(a, i * n, p[j]);

            //calculate duration
            duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
            cout << "Execution took " << duration << " milliseconds." << endl;
            cout << "Result is " << res << endl;
        }
    }

    int loopBound = 1000000;
    cout << endl;
    cout << "---------CYCLE SHORTCUT ALGORITHM----------" << endl;
    for (int j = 0; j < 3; j++)
    {
        cout << "--------------p = " << p[j] << "--------------" << endl;
        for (int i = 1; i < 10; i++)
        {
            cout << "n = " <<i* n << endl;
            //start clock
            double duration;
            startTime = clock();

            //run algorithm
            for (int i = 0; i < loopBound; i++)
                res = cycleShortcutAlgorithm(a, i*n, p[j]);

            //calculate duration
            duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
            cout << "Execution took " << duration / loopBound<< " milliseconds." << endl;
            cout << "Result is " << res << endl;
        }
     }

    cout << endl;
    cout << "------------RECURSIVE ALGORITHM------------ " << endl;
    for (int j = 0; j < 3; j++)
    {
        cout << "--------------p = " << p[j] << "--------------" << endl;
        for (int i = 1; i < 10; i++)
        {
            cout << "n = " << i * n << endl;
            //start clock
            double duration;
            startTime = clock();

            //run algorithm
            res = recursiveAlgorithm(a,i * n, p[j]);

            //calculate duration
            duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
            cout << "Execution took " << duration << " milliseconds." << endl;
            cout << "Result is " << res << endl;
         }
     }

     return 0;
}

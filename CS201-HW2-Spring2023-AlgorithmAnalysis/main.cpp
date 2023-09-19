/****************************************************************************************
 * Zeynep Begum Kara
 * ID: 22003880
 * CS201 - 02
 *
 * HW - 2:  Analysis of four different solutions for the Maximum Subsequence Sum Problem
 ****************************************************************************************/

 #include <iostream>
 #include <chrono>
 #include <iomanip>

 using namespace std;

//========================Prototypes=============================
int maxSubSum1(const int a[], int size );
int maxSubSum2(const int a[], int size );
int maxSubSum3(const int a[], int size );
int maxSubSum4(const int a[], int size );

int max3(int a, int b, int c);
int maxSubRec(const int a[], int& size, int& left, int& right );
int* createArray(int size);
//================================================================

/**
* Algorithm 1: Cubic maximum contiguous subsequence sum algorithm
*/
int maxSubSum1(const int a[], int size ){
    int maxSum = 0;
    for(int i = 0; i < size; i++){
        for(int j = i; j < size; j++){
            int thisSum = 0;
            for(int k = i; k <= j; k++)
                thisSum += a[k];

            if(thisSum > maxSum)
                maxSum = thisSum;
        }
    }
    return maxSum;
}

/**
* Algorithm 2: Quadratic maximum contiguous subsequence sum algorithm
*/
int maxSubSum2(const int a[], int size ){
    int maxSum = 0;
    for(int i = 0; i < size; i++){
        int thisSum = 0;
        for(int j = i; j < size; j++){
            thisSum += a[j];
            if(thisSum > maxSum)
                maxSum = thisSum;
        }
    }
    return maxSum;
}

/**
* Algorithm 3: Recursive maximum contiguous subsequence sum algorithm
* Finds maximum sum in subarray spanning a[left..right]
* Does not attempt to maintain actual best sequemce
*/
int maxSumRec(const int a[], int& size, int& left, int& right ){
    // base case
    if(left == right){
        if(a[left] > 0)
            return a[left];
        else
            return 0;
    }

    int center = (left + right) / 2;
    int maxLeftSum = maxSumRec(a, size, left, center);
    int nextCenter = center + 1;
    int maxRightSum = maxSumRec(a, size, nextCenter, right);

    int maxLeftBorderSum = 0;
    int leftBorderSum = 0;

    for(int i = center; i >= left; i--){
        leftBorderSum += a[i];
        if(leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }

    int maxRightBorderSum = 0;
    int rightBorderSum = 0;

    for(int j = center + 1; j <= right; j++){
        rightBorderSum += a[j];
        if(rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }
    return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}

int maxSubSum3(const int a[], int size ){
    int left = 0;
    int right = size - 1;
    return maxSumRec(a, size, left, right);
}

/**
* Algorithm 4: Linear time maximum contiguous subsequence sum algorithm
*/
int maxSubSum4(const int a[], int size ){
    int maxSum = 0;
    int thisSum = 0;

    for(int j = 0; j < size; j++){
        thisSum += a[j];
        if(thisSum > maxSum)
            maxSum = thisSum;
        else if(thisSum < 0)
            thisSum = 0;
    }
    return maxSum;
}


int main(){

     std::chrono::time_point< std::chrono::system_clock > startTime;
     std::chrono::duration< double, milli > elapsedTime;

     int sizes[10] = {2500, 5000, 7500, 10000, 12500,	15000,	17500,	20000,	22500,	25000};
     //int sizes[10] = {250000000, 300000000, 350000000, 400000000, 450000000, 500000000, 550000000, 600000000, 650000000, 700000000};
     cout << "--------------------------------------------------------------------------" << endl;
     cout << "\t\t\t\t Algorithm Time" << endl;
     cout << "--------------------------------------------------------------------------" << endl;
     //cout << "\t\t\t3\t\t\t4" << endl;
     //cout << "Input Size\t\tO(N logN)\t\tO(N)" << endl;
     cout << "\t\t1\t\t2\t\t3\t\t4" << endl;
     cout << "Input Size\tO(N^3)\t\tO(N^2)\t\tO(N logN)\tO(N)" << endl;
     cout << "--------------------------------------------------------------------------" << endl;

     for(int i = 0; i < 10; i++){
        int* arr = createArray(sizes[i]);
        cout << "N=" << sizes[i] << "\t\t";
        for (int j = 0; j < 4; j++){
            startTime = std::chrono::system_clock::now();

            if(j == 0)
               maxSubSum1(arr, sizes[i]);
            else if(j == 1)
                maxSubSum2(arr, sizes[i]);
            if(j == 2)
                maxSubSum3(arr, sizes[i]);
            else if (j == 3)
                maxSubSum4(arr, sizes[i]);

            elapsedTime = std::chrono::system_clock::now() - startTime;
            cout << std::fixed << std::setprecision(4) << elapsedTime.count() << "\t\t";
        }
        delete [] arr;
        cout << endl;
     }

    cout << "--------------------------------------------------------------------------" << endl;
    return 0;
}

int max3(int a, int b, int c) {
  int max_num = a;
  if (b > max_num) {
    max_num = b;
  }
  if (c > max_num) {
    max_num = c;
  }
  return max_num;
}

int* createArray(int size) {
  int* arr = new int[size];
  std::srand(std::time(nullptr));
  for (int i = 0; i < size; i++) {
    arr[i] = std::rand() % 1000; // generate random integers between 0 and 990
  }
  return arr;
}

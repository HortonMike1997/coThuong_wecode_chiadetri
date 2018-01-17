//  C++ program to output all possible values of
// an expression by parenthesizing it.
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;

//  method checks, character is operator or not
bool isOperator(char op)
{
    return (op == '+' || op == '-' || op == '*');
}

//  Utility recursive method to get all possible
// result of input string
vector<int> possibleResultUtil(string input,
            map< string, vector<int> > memo)
{
    //  If already calculated, then return from memo
    if (memo.find(input) != memo.end())
        return memo[input];

    vector<int> res;
    for (int i = 0; i < input.size(); i++)
    {
        if (isOperator(input[i]))
        {
            // If character is operator then split and
            // calculate recursively
            vector<int> resPre =
              possibleResultUtil(input.substr(0, i), memo);
            vector<int> resSuf =
              possibleResultUtil(input.substr(i + 1), memo);

            //  Combine all possible combination
            for (int j = 0; j < resPre.size(); j++)
            {
                for (int k = 0; k < resSuf.size(); k++)
                {
                    if (input[i] == '+')
                        res.push_back(resPre[j] + resSuf[k]);
                    else if (input[i] == '-')
                        res.push_back(resPre[j] - resSuf[k]);
                    else if (input[i] == '*')
                        res.push_back(resPre[j] * resSuf[k]);
                }
            }
        }
    }

    // if input contains only number then save that
    // into res vector
    if (res.size() == 0)
        res.push_back(atoi(input.c_str()));

    // Store in memo so that input string is not
    // processed repeatedly
    memo[input] = res;
    return res;
}

//  method to return all possible output
// from input expression
vector<int> possibleResult(string input)
{
    map< string, vector<int> > memo;
    return possibleResultUtil(input, memo);
}

//  Driver code to test above methods
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Function to print an array */
void printArray(int arr[], int k,int n)
{
//    int i;
//    for (i=0; i < size; i++)
//        printf("%d ", arr[i]);
//    printf("n");
//    if (k<1|| k>n) {return;}
//        else cout<<arr[k-1];
}

int main()
{
    //string input = "5*4-3*2";
    string input;
    cin>>input;
    vector<int> res = possibleResult(input);
    int a1[500000];

    for (int i = 0; i < res.size(); i++)
    {

        //cout << res[i] << " ";
        a1[i]=res[i];
        //cout <<a1[i]<<" ";
    }
//    cout <<endl;
//    for (int i = 0; i < res.size(); i++)
//    {
//
//        //cout << res[i] << " ";
//        //a1[i]=res[i];
//        cout <<a1[i]<<" ";
//    }
    quickSort(a1, 0, res.size()-1);
    for (int i = 0; i < res.size(); i++)
        cout <<a1[i]<<endl;

    //if (res[0]<res[1]) cout <<"ok";
    return 0;
}

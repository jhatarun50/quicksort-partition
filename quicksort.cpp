#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'quickSort' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

// Partition function to reorder the array around the pivot
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose last element as pivot
    int i = low - 1;  // Pointer for the smaller element
    
    // Iterate through the array and rearrange
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;  // Increment the smaller element pointer
            swap(arr[i], arr[j]);  // Swap smaller element to the left side
        }
    }
    
    // Place pivot at the correct position
    swap(arr[i + 1], arr[high]);
    
    return i + 1;  // Return the pivot index
}

// Recursive quickSort function
vector<int> quickSort(vector<int> arr) {
    // Helper function for recursive sorting
    function<void(int, int)> quickSortHelper = [&](int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);  // Partition the array
            quickSortHelper(low, pi - 1);  // Recurse on the left subarray
            quickSortHelper(pi + 1, high);  // Recurse on the right subarray
        }
    };
    
    quickSortHelper(0, arr.size() - 1);  // Call the helper function
    return arr;  // Return the sorted array
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = quickSort(arr);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

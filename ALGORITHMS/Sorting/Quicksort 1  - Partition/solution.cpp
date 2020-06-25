#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
// Complete the quickSort function below.-KD
vector<int> quickSort(vector<int> arr) {
int p=arr[0];// 1st element of arr is selected as pivot
int i=0;
int j=arr.size();//Note dont take j = (arr.size()-1) that is=> always take atleast one more than last index value 

while(i<j){

 do{
    i++;
 }while(arr[i]<=p);// points to element greater than p 

 do{
    j--;
 }while(arr[j]>p);// points to element lesser than p 

 if(i<j)
  swap(arr[i],arr[j]);// swaps the above pointed element
}
//Note:- swap is a built in C++ function |:-}Dont make a function named swap and then try to find the bug 
swap(arr[0],arr[j]);// swaps last position of j=>(arr[j]) with pivot
return arr ;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = quickSort(arr);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

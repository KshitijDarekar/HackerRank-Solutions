#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the migratoryBirds function below.
int migratoryBirds(vector<int> arr) {
int a=0,b=0,c=0,d=0,e=0;
for(int i=0;i<arr.size();i++){ //this loop counts most repeated no.
                               //the code may be optimized by using count() 
    switch (arr[i]) {
    case 1:
    a++;
    break;
    case 2:
    b++;
    break;
    case 3:
    c++;
    break;
    case 4:
    d++;
    break;
    case 5:
    e++;
    }
}
cout<<a<<b<<c<<d<<e<<endl;
 int most = max({a,b,c,d,e});
 cout<<most;
 { 
 if(most==a)
 return 1;
 if(most==b)
 return 2;
  if(most==c)
 return 3;
 if(most==d)
 return 4;
 if(most==e)
 return 5;
 }

 return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = migratoryBirds(arr);

    fout << result << "\n";

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

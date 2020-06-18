#include <bits/stdc++.h>

using namespace std;

// Complete the gridChallenge function below.
string gridChallenge(vector<string> grid) {
// First we sort the rows
for(int i=0;i<grid.size();i++){
    for(int j=0;j<grid[i].size();j++){
    sort(grid[i].begin(),grid[i].end());    
    }   
    
}
// Then we check the columns
for(int k=0;k<grid.size();k++){
    for(int y=1;y<grid[k].size();y++){
      if((grid[y][k]<grid[y-1][k])){
         return "NO";   
         } 
    }   
}   
return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            string grid_item;
            getline(cin, grid_item);

            grid[i] = grid_item;
        }

 string result = gridChallenge(grid);

        fout << result << "\n";

       
    }

    fout.close();

    return 0;
}

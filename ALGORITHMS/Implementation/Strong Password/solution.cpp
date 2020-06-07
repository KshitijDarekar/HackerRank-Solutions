#include <bits/stdc++.h>
#include <cctype>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
 int u=0,l=0,num=0,spec=0,min=0;
 for(int i=0;i<n;i++){
     char c = password[i];
     if(isalnum(c)){
         if(isalpha(c)){
            if(isupper(c)){
                 u++;
                    }
            else l++;
            }
         else num++;
     }
     else spec++;
 }
{ if(l==0)
  min++ ;
 if(u==0)
 min++;
 if(num==0)
 min++;
 if(spec==0)
 min++;}
 //cout<<min<<endl;   => to check
 n+=min;
 //cout<<n;       => to check
 if(n<6){
 min+=(6-n);} 

return min;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}

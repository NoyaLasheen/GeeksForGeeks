//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

void find(vector<vector<int>> &mat, vector<string> &ans, int row, int col, int n, string& path) {
    if (row == n - 1 && col == n - 1) ans.push_back(path);
    mat[row][col] = 0;
    
    int changeRow[] = {-1, 0, 1, 0};
    int changeCol[] = {0, -1, 0, 1};
    char dir[] = {'U', 'L', 'D', 'R'};
    
    for (int i = 0; i < 4; i++) {
        int nRow = row + changeRow[i];
        int nCol = col + changeCol[i];
        
        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && mat[nRow][nCol] == 1) {
            path += dir[i];
            find(mat, ans, nRow, nCol, n, path);
            path.pop_back();
        }
        
    }
    mat[row][col] = 1;
    
}

class Solution {
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        if (mat[0][0] == 0) return {};
        
        int n = mat.size();
        
        vector<string> ans;
        string path = "";
        
        find(mat, ans, 0, 0, n, path);
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
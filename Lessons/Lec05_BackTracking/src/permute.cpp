#include <iostream>
#include <vector>

using namespace std;

void permuteHelper(vector<int> &input, vector<vector<int>> &res) {
    vector<int> temp(input.size());
    for (int i = 0; i < input.size(); i++) {
        temp[i] = input[i];
    }

    if(input.size() == 0){
        res.push_back(temp);
    } else {
        
    }
}

void permute(vector<int> &input) {
    vector<vector<int>> res;
    permuteHelper(input, res);
    for(int i = 0; i < res.size(); i++){
        for(int t = 0; t < res[i].size(); t++){
            cout << res[i][t] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> data;
    data.push_back(1);
    data.push_back(2);
    data.push_back(3);
    data.push_back(4);
    permute(data);

    return 0;
}

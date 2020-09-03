#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool pair_first_comparison(pair<long long int, int> input1, pair<long long int, int> input2){
    return input1.first <= input2.first;
}

vector <pair<long long int, int>> fill_sorted_subsequence(int start_index, int finish_index, vector <long long int> sequnce){
    vector<pair<long long int, int>> sorted_subseqence;
    for(int index=start_index; index <= finish_index; index++){
        sorted_subseqence.push_back(make_pair(sequnce[index-1], index));
    }
    return sorted_subseqence;
}


int main() {
    int lenght_array, num_subsequence;
    cin >> lenght_array;
    cin >> num_subsequence;
    vector <long long int> sequnce(lenght_array);
    for(int i=0; i < lenght_array; i++){
        cin >> sequnce[i];
    }
    for(int subsequence=0; subsequence < num_subsequence; subsequence++){
        
        int start_index;
        int finish_index;
        cin >> start_index >> finish_index;
        if (finish_index - start_index < 2){
            cout << -1 <<endl;
        }
        else{
            vector<pair<long long int, int>> sorted_subseqence;
            sorted_subseqence = fill_sorted_subsequence(start_index, finish_index, sequnce);
            sort(sorted_subseqence.begin(), sorted_subseqence.end(), pair_first_comparison);
        
            for(int index=0; index <= finish_index-start_index-2; index++){
                if (sorted_subseqence[index+2].first >= sorted_subseqence[index+1].first + sorted_subseqence[index].first){
                    if (sorted_subseqence[index+2].second + 1 == finish_index){
                        cout << -1  << endl;
                    }
                }
                else{
                    cout << sorted_subseqence[index].second << ' ' <<sorted_subseqence[index+1].second << ' ' <<sorted_subseqence[index+2].second << endl;
                    break;
                }
            }
            sorted_subseqence.clear();
    
            
        }
    }
    return 0;
}

/*
ID: jkanaa1
TASK: gift1
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int n = 0;
    fin >> n;
    string names[10];
    unordered_map<string, int> myMap;
    for(int i = 0; i < n; i++) {
        fin >> names[i];
        myMap[names[i]] = 0; // initialize each name to 0
    }
   
    for(int i = 0; i < n; i++) {
        string sender;
        int total_value =0;
        int num_of_receiver =0;
        fin >> sender;
        fin >> total_value >> num_of_receiver;
        if (num_of_receiver == 0) continue;
        int amount = total_value / num_of_receiver;
        myMap[sender] -= amount * num_of_receiver;
        for(int j=0; j<num_of_receiver; j++){
            string receiver;
            fin >> receiver;
            myMap[receiver] += amount;
        }
    }

    // for (auto const& pair : myMap) {
    //     fout << pair.first << " " << pair.second << endl;
    // }
    for (int i = 0; i < n; i++) {
		fout << names[i] << " " << myMap[names[i]] << endl;
	}
    return 0;
}
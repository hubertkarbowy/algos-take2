/* Problem Introduction
    You have n ads to place on a popular Internet page. For each ad, you know how
    much is the advertiser willing to pay for one click on this ad. You have set up n
    slots on your page and estimated the expected number of clicks per day for each
    slot. Now, your goal is to distribute the ads among the slots to maximize the
    total revenue.
    Problem Description
    Task. Given two sequences a1 , a2 , . . . , an (ai is the profit per click of the i-th ad) and b1 , b2 , . . . , bn (bi is
    the average number of clicks per day of the i-th slot), we need to partition them into n pairs (ai , bj )
    such that the sum of their products is maximized.
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

void print_error_and_exit(string msg) {
    cout << msg;
    exit(-1);
}

void print_vector(vector<int> &v) {
    for (unsigned int i=0; i<v.size(); i++) cout << "v=" << v[i] << " ";
    cout << endl;
}

bool sort_descending(int x, int y) {
    return (x>y);
}

int main(int argc, char** argv) {
    if (argc != 2) print_error_and_exit("Please provide input file as the first argument.\n");

    ifstream data(argv[1]);
    int numberOfSlots;
    vector<int> slots, ads;
    string line;

    if (!data.good()) print_error_and_exit("Cannot open file");
    data >> numberOfSlots;
    getline(data, line); // consume EOL from the first line
    cout << "Number of slots: " << numberOfSlots << endl;
    
    int cnt=0;
    while (getline(data,line)!=NULL) {
        stringstream ss;
        ss << line;
        cout << "Read " << (cnt==0 ? "slot clicks data: " : "ad revenues data: ") << line;
        while (!ss.eof()) {
            int val;
            ss >> val;
            if (cnt==0) slots.emplace_back(val);
            else if (cnt==1) ads.emplace_back(val);
        }
        cout << endl;
        cnt++;
    }
    sort(slots.begin(), slots.end(), sort_descending);
    sort(ads.begin(), ads.end(), sort_descending);
    
    cout << "Sorted slot clicks: "; print_vector(slots);
    cout << "Sorted ad revenues: "; print_vector(ads);
    
    long long result = 0;
    for (unsigned int i=0; i<slots.size(); i++) result += (long long)slots[i]*ads[i];
    cout << "Result = " << result << endl;
}

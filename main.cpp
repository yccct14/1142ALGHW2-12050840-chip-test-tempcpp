#include <iostream>
#include <vector>
using namespace std;

// report[i][j] = 晶片 i 對晶片 j 的判斷
// true  表示 i 說 j 是好晶片
// false 表示 i 說 j 是壞晶片

class ChipTester {
private:
    vector<vector<bool>> report;

public:
    ChipTester(const vector<vector<bool>>& r) : report(r) {}

    // 回傳一顆好晶片的索引；若無法找到則回傳 -1
    int findGoodChip(vector<int> chips) {
        // TODO:
        while (!chips.empty()) {
            if (chips.size() == 1) {
                return chips[0];
            }

            int A = chips[0];
            int n = chips.size();
            int V = 0;
            for (int i = 1; i < n; i++) {
                int B = chips[i];
                if (report[A][B] == true && report[B][A] == true) {
                    V++;
                }
            }
            if (V >= n / 2) {
                return A;
            }
            chips.erase(chips.begin());
        }
        return -1; // 請修改
    }
};

int main() {
    // 範例：6 顆晶片，編號 0~5
    // 假設好晶片多於壞晶片
    // 好晶片會誠實回答，壞晶片可任意回答

    vector<vector<bool>> report = {
        // 0    1    2    3    4    5
        {true, true, true, false, true, false},
        {true, true, true, false, true, false},
        {true, true, true, false, true, false},
        {true, false, true, true, false, true},
        {true, true, true, false, true, false},
        {false, true, false, true, true, true}
    };

    ChipTester tester(report);

    vector<int> chips = {0, 1, 2, 3, 4, 5};

    int goodChip = tester.findGoodChip(chips);

    if (goodChip != -1) {
        cout << "Found a good chip: chip " << goodChip << endl;
    } else {
        cout << "No good chip found." << endl;
    }

    return 0;
}

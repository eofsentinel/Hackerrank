// https://www.hackerrank.com/challenges/compare-the-triplets/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
vector<int> solve(vector<int> a, vector<int> b) {
	vector<int> result(2);
	result[0] = 0;
	result[1] = 0;
	for (vector<int>::iterator ita = a.begin(), itb = b.begin(); ita != a.end(); ita++, itb++) {
		if (*ita > *itb) {
			result[0] += 1;
		}
		else if (*itb > *ita) {
			result[1] += 1;
		}
	}
	return result;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(3);

    for (int i = 0; i < 3; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    string b_temp_temp;
    getline(cin, b_temp_temp);

    vector<string> b_temp = split_string(b_temp_temp);

    vector<int> b(3);

    for (int i = 0; i < 3; i++) {
        int b_item = stoi(b_temp[i]);

        b[i] = b_item;
    }

    vector<int> result = solve(a, b);

    for (int i = 0; i < result.size(); i++) {
        // fout << result[i];
		cout << result[i];

        if (i != result.size() - 1) {
            // fout << " ";
			cout << " ";
        }
    }

    // fout << "\n";
	cout << "\n";

    // fout.close();

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

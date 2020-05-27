#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string line;
    vector <string> scale = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

    getline(cin, line);

    while (line != "END") {
        string note;
        stringstream ss;
        ss << line;
        vector <string> notes;

        while (ss >> note) {
            notes.push_back(note);
        }
        string str = "";

        for (int p = 0; p < scale.size(); p++) {
            int counter = 0;
            for (int j = 0; j < notes.size(); j++) {
                if (notes[j] == scale[p % 12] || notes[j] == scale[(p + 2) % 12] || notes[j] == scale[(p + 4) % 12]
                    || notes[j] == scale[(p + 5) % 12] || notes[j] == scale[(p + 7) % 12] ||
                    notes[j] == scale[(p + 9) % 12] || notes[j] == scale[(p + 11) % 12]) {
                    counter++;
                } else
                    break;
            }

            if (counter == notes.size()) {
                cout << str << scale[p];
                str = " ";
            }
        }
        cout << endl;
        getline(cin, line);
    }

    return 0;
}

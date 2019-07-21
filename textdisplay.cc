#include "textdisplay.h"
using namespace std;

TextDisplay::TextDisplay() {
    for (int i = 0; i < GRIDSIZE; i++) {
        for (int j = 0; j < GRIDSIZE; j++) {
            if((i % 2 != 0 && j % 2 == 0) || (i % 2 == 0 && j % 2 != 0)) {
				theDisplay[i][j] = ' '; // White
			} else {
                theDisplay[i][j] = '_'; // White
            }
        }
    }
}
void TextDisplay::notify(char type, int x, int y) {
    if (type != 'E') { // Empty on this Cell
        theDisplay[x][y] = type;
    } else {
        if((x % 2 != 0 && y % 2 == 0) || (x % 2 == 0 && y % 2 != 0)) {
				theDisplay[x][y] = ' '; // White
			} else {
                theDisplay[x][y] = '_'; // White
            }
    }
}
ostream &operator<<(ostream &out, const TextDisplay &td) {
    // Print a newline first
    out << endl;
    for (int m = GRIDSIZE - 1; m >= 0; m--) {
        out << m + 1 << " "; // Print vertical indexes
        for (int n = 0; n < GRIDSIZE; n++) {
            out << td.theDisplay[n][m];
        }
        out << endl; // Newline after each row printed
    }
    out << endl; // Just one more newline to precise format
    out << "  abcdefgh";
    out << endl; // For beauty
    return out;
}

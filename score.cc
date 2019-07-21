#include "score.h"
using namespace std;

// Accessors and Mutators of private fields
double Score::getWhiteScore() {
    return this->whiteScore;
}
double Score::getBlackScore() {
    return this->blackScore;
}
// Member functions
void Score::updateWhiteScore(double score) {
    this->whiteScore += score;
}
void Score::updateBlackScore(double score) {
    this->blackScore += score;
}
string Score::printScore() {
    string final = "International Chess Game Final Score:\n";
    string white = "White Score: ";
    string black = "Black Score: ";
    return final + white + to_string(whiteScore) + "\n" + black + to_string(blackScore) + "\n";
}

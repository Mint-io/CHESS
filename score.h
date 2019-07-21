#ifndef SCORE_H
#define SCORE_H
#include <string>
#include <iostream>
#include <cmath>

class Score {
    double whiteScore;
    double blackScore;

public:
    // Accessors and Mutators of private fields
    double getWhiteScore();
    double getBlackScore();
    // Member functions
    void updateWhiteScore(double score);
    void updateBlackScore(double score);
    std::string printScore(); // Beautifully print the score
};

#endif

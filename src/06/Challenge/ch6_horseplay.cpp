// C++ Code Challenges, LinkedIn Learning

// Challenge #6: Horseplay
// Write a function that takes in the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// The locations are expressed as strings in algebraic notation.
// Print the list on the terminal.
// Don't worry about other pieces on the chessboard.

#include <iostream>
#include <vector>
#include <string>

// knight_moves()
// Summary: This function receives a string with the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// Arguments:
//           knight: The knight's location.
// Returns: An STL vector of strings with the possible locations to move.
std::vector<std::string> knight_moves(std::string knight){
    std::vector<std::string> moves;

    int h = (knight[0] - 96);
    int v = (knight[1] - 48);

    if (v < 7) {
        if (h < 8) {
            moves.push_back(std::string() + (char)(h+97) + (char)(v+50));
        }
    }

    if (v < 8) {
        if (h < 7) {
            moves.push_back(std::string() + (char)(h+98) + (char)(v+49));
        }
    }

    if (v > 1) {
        if (h < 7) {
            moves.push_back(std::string() + (char)(h+98) + (char)(v+47));
        }
    }

    if (v > 2) {
        if (h < 8) {
            moves.push_back(std::string() + (char)(h+97) + (char)(v+46));
        }
    }

    if (v > 2) {
        if (h > 1) {
            moves.push_back(std::string() + (char)(h+95) + (char)(v+46));
        }
    }

    if (v > 1) {
        if (h > 2) {
            moves.push_back(std::string() + (char)(h+94) + (char)(v+47));
        }
    }

    if (v < 8) {
        if (h > 2) {
            moves.push_back(std::string() + (char)(h+94) + (char)(v+49));
        }
    }

    if (v < 7) {
        if (h > 1) {
            moves.push_back(std::string() + (char)(h+95) + (char)(v+50));
        }
    }

    return moves;
}

// Main function
int main(){
    std::string knight;
    
    std::cout << "Enter the location of the knight: " << std::flush;
    std::cin >> knight;

    std::vector<std::string> the_moves = knight_moves(knight);
    std::cout << std::endl << "Possible moves from " << knight << ": ";

    for (auto element : the_moves)
        std::cout << element << " ";
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}
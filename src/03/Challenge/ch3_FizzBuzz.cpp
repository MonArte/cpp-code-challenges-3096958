// C++ Code Challenges, LinkedIn Learning

// Challenge #3: FizzBuzz
// Write an application that plays FizzBuzz.
// Print an integer number sequence starting at 1, replacing multiples of 3 by "Fizz", multiples of 5 by "Buzz", and multiples of 3 and 5 by "FizzBuzz".
// The user enters the last number in the sequence.

#include <iostream>

// FizzBuzz, main()
// Summary: This application runs on the main function.
int main(){
    int n; // How many numbers to include in the sequence.
    
    std::cout << "Enter a positive integer: " << std::flush;
    std::cin >> n;

    for (size_t i = 1; i <= n; ++i) {
        if (!(i%15)) {
            std::cout << "FizzBuzz " << std::flush;
        } else if (!(i%5)) {
            std::cout << "Buzz " << std::flush;
        }  else if (!(i%3)) {
            std::cout << "Fizz " << std::flush;
        } else {
            std::printf("%d ", i); std::cout << std::flush;
        }
    }
    
    
    std::cout << std::endl << std::flush;
    return 0;
}

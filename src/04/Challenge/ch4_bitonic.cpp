// C++ Code Challenges, LinkedIn Learning

// Challenge #4: Checking for Bitonic Sequences
// Write a function to check if a vector of integers is bitonic or not.
// Bitonic sequences have an ascending segment followed by a descending segment (sort of).
// Circular shifts of these sequences are also bitonic.

// Formally, a bitonic sequence is a sequence with x[0] <= ... <= x[k] >= ... >= x[n-1]
//           for some k between 0 and n-1, or a circular shift of such a sequence.

// Special bitonic cases: Monotonic sequences and sequences where all elements have the same value.

#include <iostream>
#include <vector>

// is_bitonic()
// Summary: This function receives an STL vector of integers and returns true if it contains a bitonic sequence, false otherwise.
// Arguments:
//           v: A reference to the vector to analyze.
// Returns: A boolean value: True for bitonic sequences, false otherwise.

// #define NA 0
// #define POS 1
// #define NEG 2
// #define POSNEG 3
// #define NEGPOS 4

bool is_bitonic(const std::vector<int> &v){
    int min, max;
    min = max = 0;

    for (size_t i = 1; i < v.size(); i++) {
        if (v[min] > v[i])
        {
            min = i;
        }
    }
    
    for (size_t i = 1; i < v.size(); i++) {
        if (v[max] < v[i])
        {
            max = i;
        }
    }

    if (min == max)
    {
        return true;
    }

    std::vector<int> posVec = {v[min]};
    std::vector<int> negVec = {v[max]};

    if (min > max)
    {
        for (size_t i = (max+1); i <= min; i++)
        {
            negVec.push_back(v[i]);
        }

        int j = min;
        for (size_t i = 0; i < (v.size()-(min - max)); i++)
        {
            ++j;
            if (j == v.size())
                j = 0;
            
            posVec.push_back(v[j]);
        }
    } else {
        for (size_t i = (min+1); i <= max; i++)
        {
            posVec.push_back(v[i]);
        }

        int j = max;
        for (size_t i = 0; i < (v.size()-(max - min)); i++)
        {
            ++j;
            if (j == v.size())
                j = 0;
            
            negVec.push_back(v[j]);
        }
    }

    for (size_t i = 1; i < posVec.size(); i++)
        if(posVec[i-1] > posVec[i])
            return false;

    for (size_t i = 1; i < negVec.size(); i++)
        if(negVec[i-1] < negVec[i])
            return false;

    return true;

    
    
    // int state = NA;
    
    // for (size_t i = 0; i < v.size(); i++)
    // {
    //     int j, input;

    //     if (i != (v.size()-1)) {
    //         j = (i+1);
    //     } else {
    //         j = 0;
    //         if (state == POSNEG)
    //             state = NEG;
    //         else if (state == NEGPOS)
    //             state = POS;
    //     }

    //     if (v[i] < v[j])
    //     {
    //         input = POS;
    //     } else if (v[i] > v[j])
    //     {
    //         input = NEG;
    //     }
        
    //     switch (state)
    //     {
    //     case NA:
    //         if (input == POS)
    //         {
    //             state = POS;
    //         } else if (input == NEG)
    //         {
    //             state = NEG;
    //         }
    //         break;

    //     case POS:
    //         if (input == NEG)
    //         {
    //             state = POSNEG;
    //         }
    //         break;

    //     case NEG:
    //         if (input == POS)
    //         {
    //             state = NEGPOS;
    //         }
    //         break;

    //     case POSNEG:
    //         if (input == POS)
    //         {
    //             return false;
    //         }
    //         break;

    //     case NEGPOS:
    //         if (input == NEG)
    //         {
    //             return false;
    //         }
    //         break;
        
    //     default:
    //         break;
    //     }
    // }

    // return true;
}

// Main function
int main(){
    // Uncomment one of these lines and make sure you get the result at the right. 
    
    std::vector<int> myvec = {1, 2, 5, 4, 3};  // Yes
    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic.\r\n" : "No, it is not bitonic.\r\n");

    myvec = {1, 1, 1, 1, 1};  // Yes
    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic.\r\n" : "No, it is not bitonic.\r\n");
    
    myvec = {3, 4, 5, 2, 2};  // Yes
    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic.\r\n" : "No, it is not bitonic.\r\n");
    
    myvec = {3, 4, 5, 2, 4};  // No
    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic.\r\n" : "No, it is not bitonic.\r\n");
    
    myvec = {1, 2, 3, 4, 5};  // Yes
    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic.\r\n" : "No, it is not bitonic.\r\n");
    
    myvec = {1, 2, 3, 1, 2};  // No
    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic.\r\n" : "No, it is not bitonic.\r\n");
    
    myvec = {5, 4, 6, 2, 6};  // No
    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic.\r\n" : "No, it is not bitonic.\r\n");
    
    myvec = {5, 4, 3, 2, 1};  // Yes
    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic.\r\n" : "No, it is not bitonic.\r\n");
    
    myvec = {5, 4, 3, 2, 6};  // Yes
    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic.\r\n" : "No, it is not bitonic.\r\n");
    
    myvec = {5, 4, 6, 5, 4};  // No
    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic.\r\n" : "No, it is not bitonic.\r\n");
    
    myvec = {5, 4, 6, 5, 5};  // Yes
    std::cout << (is_bitonic(myvec) == true ? "Yes, it is bitonic.\r\n" : "No, it is not bitonic.\r\n");

    std::cout << std::endl << std::endl << std::flush;
    return 0;
}

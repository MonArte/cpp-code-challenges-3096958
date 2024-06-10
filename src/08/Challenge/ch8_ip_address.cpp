// C++ Code Challenges, LinkedIn Learning

// Challenge #8: IP Address Validation
// Write an application that reads a string from the terminal and responds with a message indicating whether the string is a valid IP address or not.
// Assume decimal IP addresses.
// 158.25.0.33
// All numbers between 0 and 255.

#include <iostream>
#include <vector>
#include <string>

// is_valid_ip()
// Summary: This function validates an IP address.
// Arguments:
//           ip: The string to analyze with a potential ip address.
// Returns: A boolean value. True for valid ip addresses, false otherwise.
bool is_valid_ip(std::string ip){
    std::string sTemp;
    int iCnt = 0;
    std::string::const_iterator it = ip.begin();
    while (it != ip.end()) {
        if ((!std::isdigit(*it)) && (*it != '.'))
            return false;

        if (*it == '.') {
            if (sTemp.empty() || (std::stoi(sTemp) > 255))
                return false;
            
            sTemp = "";
            ++iCnt;
        } else {
            sTemp += *it;
        }
        
        ++it;
    }

    if (sTemp.empty() || (std::stoi(sTemp) > 255))
        return false;

    if (iCnt != 3)
        return false;

    // int i0, i1, i2, i3;
    // int pos = ip.find('.');
    // if(pos != std::string::npos) {
    //     try {
    //         i0 = std::stoi(ip.substr(0, pos), 0, 10);
    //     }
    //     catch (const std::invalid_argument& ia) {
    //         return false;
    //     }
    // } else
    //     return false;

    // ip = ip.substr(pos+1);

    return true;
}

// Main function
int main(){
    std::string s("126.1.34.158");
    
    //std::cout << std::endl << "Enter an IP address in decimal: " << std::flush;
    //std::getline(std::cin,s);
    std::cout << " \n" << s << (is_valid_ip(s) ? " is" : " is not" ) << " a valid IP address.\n\n";

    s = {"126.1.c4.158"};
    std::cout << " \n" << s << (is_valid_ip(s) ? " is" : " is not" ) << " a valid IP address.\n\n";

    s = {".1.34.158"};
    std::cout << " \n" << s << (is_valid_ip(s) ? " is" : " is not" ) << " a valid IP address.\n\n";

    s = {"51.34.158."};
    std::cout << " \n" << s << (is_valid_ip(s) ? " is" : " is not" ) << " a valid IP address.\n\n";

    s = {"51.34.158"};
    std::cout << " \n" << s << (is_valid_ip(s) ? " is" : " is not" ) << " a valid IP address.\n\n";

    return 0;
}

// HSA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct Member {
    std::string email;
    std::string fName;
    std::string lName;
};

int main()
{
    std::fstream fileIn;
    fileIn.open("HOSA Member List 24-25 - Form Responses 1.csv", std::ios::in);
    std::cout << fileIn.is_open();
    std::string line;
    std::vector<Member> rows = { Member{} };

    std::string temp;
    while (fileIn >> temp)
    {
        rows.clear();
        std::getline(fileIn, line);
        std::stringstream s(line);

        std::string email, fName, lName;
        int count = 0;
        std::cout << 1;

        while (std::getline(s, email, ',')) {
            rows[count].email = email;
            std::getline(s, fName, ',');
            rows[count].fName = fName;
            std::getline(s, lName, ',');
            rows[count].lName = lName;
            count++;
            rows.push_back(Member{});
            std::cout << 1;
        }
    }
    std::cout << rows[0].fName;
    fileIn.close();
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
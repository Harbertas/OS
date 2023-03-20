// MathLibrary.cpp : Defines the exported functions for the DLL.
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include "OSLAB2_DLL.h"

#include <utility>
#include <limits.h>
#include <cmath>
#include <chrono>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <omp.h>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#define SURNAME "Klangauskas"
#define NAME "Hubertas"
#define PATH "C:\\Users\\"
#define FOLDER "OS_LAB_2"

// DLL internal state variables:
std::chrono::time_point<std::chrono::high_resolution_clock> start_;   // Start time
std::chrono::time_point<std::chrono::high_resolution_clock> end_;     // End time
std::chrono::duration<double> elapsed_;                               // End time - Start time

class set {
public:
    double x;
    double y;
};

// Compare x ASC
bool compare_x(const set &a, const set &b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

std::ostream& operator << (std::ostream& out, set& d) {
    out << std::left << std::setw(10) << d.x << std::left << std::setw(15) << d.y << std::endl;
    return out;
}

// Start the timer
void startTimeCount()
{
    start_ = std::chrono::high_resolution_clock::now(); // a "timepoint" representing now
}

// End the timer and calculate elapsed time in seconds
double endTimeCount()
{
    end_ = std::chrono::high_resolution_clock::now(); // a "timepoint" representing now
    elapsed_ = end_ - start_;
    return elapsed_.count();
}

void studentID_3()
{
    const char* text = NULL;
    std::cout << "Enter a Number To Open One of The control panel components" << std::endl;
    std::cout << " 1 - Display \n 2 - Security \n 3 - Power \n 4 - Storage \n 5 - Update \n 0 - exit" << std::endl;
    unsigned int number;
    std::cin >> number;
    while (number != 0) {
        switch (number) {
        case 1:
            text = "start ms-settings:display";
            break;
        case 2:
            text = "start ms-settings:windowsdefender";
            break;
        case 3:
            text = "start ms-settings:powersleep";
            break;
        case 4:
            text = "start ms-settings:storagesense";
            break;
        case 5:
            text = "start ms-settings:windowsupdate";
            break;
        default:
            std::cout << "The input is not correct" << std::endl;
            std::cout << " 1 - Display \n 2 - Security \n 3 - Power \n 4 - Storage \n 5 - Update \n 0 - exit" << std::endl;
            text = NULL;
            break;
        }
        std::system(text);
        std::cin >> number;
    }
}

char* getName()
{
    char* username = nullptr;
    size_t len;
    errno_t err = _dupenv_s(&username, &len, "USERNAME");
    if (err == 0 && username != nullptr)
    {
        return username;
    }
    else
    {
        return username;
    }
}

double createFolders()
{
    startTimeCount();

    std::string name = getName();

    std::string str = "start powershell.exe - windowstyle hidden - command New - Item - ItemType Directory - Path " + std::string(PATH) + "$env:userName" + " -Name " + std::string(FOLDER);
    const char* input = str.c_str();
    std::system(input);

    str = "start powershell.exe -windowstyle hidden -command New-Item -ItemType Directory -Path " + std::string(PATH) + "$env:userName\\" + std::string(FOLDER) + " -Name " + std::string(SURNAME) + "; " + "New-Item -ItemType File -Path " + std::string(PATH) + "$env:userName\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\example.txt";
    input = str.c_str();
    std::system(input);

    for (int i = 1; i < 4; ++i) {
        str = "start powershell.exe -windowstyle hidden -command New-Item -ItemType Directory -Path " + std::string(PATH) + "$env:userName\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + " -Name " + std::string(SURNAME) + "" + char(48 + i) + "; " + "New-Item -ItemType File -Path " + std::string(PATH) + "$env:userName\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + char(48 + i) + "\\example.txt";
        input = str.c_str();
        std::system(input);
    }

    for (int j = 1; j < 4; ++j) {
        for (int i = 1; i < 4; ++i) {
            str = "start powershell.exe -windowstyle hidden -command New-Item -ItemType Directory -Path " + std::string(PATH) + "$env:userName\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + char(48 + j) + " -Name " + std::string(SURNAME) + "1" + std::string(NAME) + char(48 + i) + "; " + "New-Item -ItemType File -Path " + std::string(PATH) + "$env:userName\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + char(48 + j) + "\\" + std::string(SURNAME) + "1" + std::string(NAME) + char(48 + i) + "\\example.txt ";
            input = str.c_str();
            std::system(input);
        }
    }
    return endTimeCount();
}

double calculateTschirnhausenCubic(int F, double x0, double xn, double deltaX)
{
    startTimeCount();

    double y;
    double x = x0;

    char* name = getName();

    // Yup, I know it is bad
    std::string fileLoc1 = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\example.txt";
    std::string fileLoc2 = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + "1\\example.txt";
    std::string fileLoc3 = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + "2\\example.txt";
    std::string fileLoc4 = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + "3\\example.txt";
    std::string fileLoc5 = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + "1\\" + std::string(SURNAME) + "1" + std::string(NAME) + "1\\example.txt";
    std::string fileLoc6 = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + "1\\" + std::string(SURNAME) + "1" + std::string(NAME) + "2\\example.txt";
    std::string fileLoc7 = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + "1\\" + std::string(SURNAME) + "1" + std::string(NAME) + "3\\example.txt";
    std::string fileLoc8 = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + "2\\" + std::string(SURNAME) + "1" + std::string(NAME) + "1\\example.txt";
    std::string fileLoc9 = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + "2\\" + std::string(SURNAME) + "1" + std::string(NAME) + "2\\example.txt";
    std::string fileLoc10 = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + "2\\" + std::string(SURNAME) + "1" + std::string(NAME) + "3\\example.txt";
    std::string fileLoc11 = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + "3\\" + std::string(SURNAME) + "1" + std::string(NAME) + "1\\example.txt";
    std::string fileLoc12 = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + "3\\" + std::string(SURNAME) + "1" + std::string(NAME) + "2\\example.txt";
    std::string fileLoc13 = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + "3\\" + std::string(SURNAME) + "1" + std::string(NAME) + "3\\example.txt";


    std::ofstream rf1 (fileLoc1);
    std::ofstream rf2 (fileLoc2);
    std::ofstream rf3 (fileLoc3);
    std::ofstream rf4 (fileLoc4);
    std::ofstream rf5 (fileLoc5);
    std::ofstream rf6 (fileLoc6);
    std::ofstream rf7 (fileLoc7);
    std::ofstream rf8 (fileLoc8);
    std::ofstream rf9 (fileLoc9);
    std::ofstream rf10 (fileLoc10);
    std::ofstream rf11 (fileLoc11);
    std::ofstream rf12 (fileLoc12);
    std::ofstream rf13 (fileLoc13);


    int i = 1;
        // Beginning of parallel region
        //#pragma omp parallel //num_threads(2)
            while (x <= xn)
            {
                if (!isnan(sqrt(x * x * x + 3 * x * x + F)))
                {
                    if (i == 13) i = 1;
                    y = sqrt(x * x * x + 3 * x * x + F);
                    //pirmas << x << " " << y << std::endl;
                    //#pragma omp critical

                    // Yup, I know it is bad
                    if (i == 1) {
                        rf1 << x << " " << y << std::endl;
                    }
                    else if (i == 2) {
                        rf2 << x << " " << y << std::endl;
                    }
                    else if (i == 3) {
                        rf3 << x << " " << y << std::endl;
                    }
                    else if (i == 4) {
                        rf4 << x << " " << y << std::endl;
                    }
                    else if (i == 5) {
                        rf5 << x << " " << y << std::endl;
                    }
                    else if (i == 6) {
                        rf6 << x << " " << y << std::endl;
                    }
                    else if (i == 7) {
                        rf7 << x << " " << y << std::endl;
                    }
                    else if (i == 8) {
                        rf8 << x << " " << y << std::endl;
                    }
                    else if (i == 9) {
                        rf9 << x << " " << y << std::endl;
                    }
                    else if (i == 10) {
                        rf10 << x << " " << y << std::endl;
                    }
                    else if (i == 11) {
                        rf11 << x << " " << y << std::endl;
                    }
                    else if (i == 12) {
                        rf12 << x << " " << y << std::endl;
                    }
                    else if (i == 13) {
                        rf13 << x << " " << y << std::endl;
                    }
                    //#pragma omp critical
                    //rf << x << " " << -y << std::endl;
                    i++;
                }
                x += deltaX;
            }
            // Ending of parallel region

            rf1.close();
            rf2.close();
            rf3.close();
            rf4.close();
            rf5.close();
            rf6.close();
            rf7.close();
            rf8.close();
            rf9.close();
            rf10.close();
            rf11.close();
            rf12.close();
            rf13.close();

        std::cout << endTimeCount() << std::endl;
        return endTimeCount();
}

double mergeFiles(int F)
{
    startTimeCount();

    char* name = getName();


    // Yup, I know it is bad
    const std::string fileLoc1 = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\example.txt";
    const std::string fileLoc2 = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + "1\\example.txt";
    const std::string fileLoc3 = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + "2\\example.txt";
    const std::string fileLoc4 = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + "3\\example.txt";
    const std::string fileLoc5 = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + "1\\" + std::string(SURNAME) + "1" + std::string(NAME) + "1\\example.txt";
    const std::string fileLoc6 = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + "1\\" + std::string(SURNAME) + "1" + std::string(NAME) + "2\\example.txt";
    const std::string fileLoc7 = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + "1\\" + std::string(SURNAME) + "1" + std::string(NAME) + "3\\example.txt";
    const std::string fileLoc8 = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + "2\\" + std::string(SURNAME) + "1" + std::string(NAME) + "1\\example.txt";
    const std::string fileLoc9 = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + "2\\" + std::string(SURNAME) + "1" + std::string(NAME) + "2\\example.txt";
    const std::string fileLoc10 = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + "2\\" + std::string(SURNAME) + "1" + std::string(NAME) + "3\\example.txt";
    const std::string fileLoc11 = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + "3\\" + std::string(SURNAME) + "1" + std::string(NAME) + "1\\example.txt";
    const std::string fileLoc12 = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + "3\\" + std::string(SURNAME) + "1" + std::string(NAME) + "2\\example.txt";
    const std::string fileLoc13 = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + "\\" + std::string(SURNAME) + "3\\" + std::string(SURNAME) + "1" + std::string(NAME) + "3\\example.txt";


    std::ifstream rf1(fileLoc1);
    std::ifstream rf2(fileLoc2);
    std::ifstream rf3(fileLoc3);
    std::ifstream rf4(fileLoc4);
    std::ifstream rf5(fileLoc5);
    std::ifstream rf6(fileLoc6);
    std::ifstream rf7(fileLoc7);
    std::ifstream rf8(fileLoc8);
    std::ifstream rf9(fileLoc9);
    std::ifstream rf10(fileLoc10);
    std::ifstream rf11(fileLoc11);
    std::ifstream rf12(fileLoc12);
    std::ifstream rf13(fileLoc13);

    std::ifstream* files[13] = {
        &rf1,
        &rf2,
        &rf3,
        &rf4,
        &rf5,
        &rf6,
        &rf7,
        &rf8,
        &rf9,
        &rf10,
        &rf11,
        &rf12,
        &rf13
    };


    std::vector<std::string> splited;
    std::string eil;
    std::ifstream* df;

    // Read file data by lines and push it into vector
    for (int i = 0; i < 13; ++i)
    {
        df = files[i];
        while (df) {
            if (!df->eof()) {
                std::getline(*df, eil);
                //std::cout << eil << std::endl;
                splited.push_back(eil);
            }
            else break;
        }
        df->close();
    }

    double x, y;
    std::vector<set> pairs;
    set pair;
    std::stringstream ss;

    // Split vector data into stringstream and then push to a vector<set>
    for (auto& eilute : splited)
    {
        ss.str("");
        ss.clear();
        ss << eilute << "\n";
        ss >> x >> y;
        pair.x = x;
        pair.y = y;
        pairs.push_back(pair);
    }
    // Free memory
    splited.clear();
    ss.str("");
    ss.clear();

    // Sort by X, ASC order
    std::sort(pairs.begin(), pairs.end(), compare_x);

    std::ofstream fileF;
    std::string filePath = std::string(PATH) + name + "\\" + std::string(FOLDER) + "\\" + std::to_string(F) + ".txt";

    // Write sorted data into buffer
    fileF.open(filePath);
    for (auto& el : pairs) {
        ss << el;
    }
    // Write buffer into F.txt file
    fileF << ss.str();

    // Free memory
    pairs.clear();
    ss.str("");
    ss.clear();

    std::cout << endTimeCount() << std::endl;
    return endTimeCount();
}

double deleteFilesAndFolders()
{
    startTimeCount();
    
    std::string str = "start powershell.exe -windowstyle hidden -command Remove-Item " + std::string(PATH) + "$env:userName\\" + std::string(FOLDER) + "\\" + std::string(SURNAME) + " -Recurse";
    const char*input = str.c_str();
    std::system(input);

    return endTimeCount();
}
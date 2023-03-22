// MathClient.cpp : Client app for MathLibrary DLL.
// #include "pch.h" Uncomment for Visual Studio 2017 and earlier
#include <iostream>
#include "OSLAB2_DLL.h"

#define X0 -18
#define X1 3
#define DELTAX 0.000002110253

int main()
{
    double totalTime = 0;

    studentID_3(); // 2.3 requirement function

    createFolders(); // 3-rd requirement function
    
    //#pragma omp parallel for num_threads(4)
    for (int F = -2; F <= 2; ++F)
    {
        std::cout << "Computing when F = " << F << " ..." << std::endl;
        //#pragma omp critical
        totalTime += calculateTschirnhausenCubic(F, X0, X1, DELTAX); // 4-th requirement function
        std::cout << "Merging when F = " << F << " ..." << std::endl;
        //#pragma omp critical
        totalTime += mergeFiles(F); // 5-th requirement function
        totalTime += deleteFilesAndFolders(); // 6-th requirement function
    }

    printf("Total time elapsed: %f \n", totalTime);
    std::system("pause");
}
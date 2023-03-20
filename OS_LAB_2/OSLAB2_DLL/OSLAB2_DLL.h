// OSLAB2_DLL.h - Contains declarations of OS LAB2 functions
#pragma once

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

// This function must be called before any time function.
extern "C" MATHLIBRARY_API void startTimeCount();

// Get the elapsed time in seconds.
extern "C" MATHLIBRARY_API double endTimeCount();

// Opens one of the {Display, Security, Power, Storage, Update} control panel component.
extern "C" MATHLIBRARY_API void studentID_3();

// This function creates many folders in C:\\Users\\$env:UserName
extern "C" MATHLIBRARY_API double createFolders();

// This function computes TschirnhausenCubic function and distributes it's results to many files
extern "C" MATHLIBRARY_API double calculateTschirnhausenCubic(int F, double x0, double xn, double deltaX);

// This function gets the env variable %USERNAME%
extern "C" MATHLIBRARY_API char* getName();

// This function merges data generated by 'calculateTschirnhausenCubic' function into F.txt file
extern "C" MATHLIBRARY_API double mergeFiles(int F);

// This function deletes folders and files created by previous functions
extern "C" MATHLIBRARY_API double deleteFilesAndFolders();
﻿// Implementations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CompanionMatrixRootsFinder.h"
#include "FileReader.h"
#include "CATCH.h"
#include "ANCAS.h"

#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

double getCurrentTymeInMicroSec();
void runCatch(int degree);
void runAncas();
void startPrint();
void printResult(string algName, int degree, string testName, int numberOfPoints, double runTime, TCA tca);

int main()
{
    startPrint();
    runAncas();
    runCatch(14);
    runCatch(15);
    runCatch(16);
    runCatch(17);

    return 0;
}

void runCatch(int degree)
{
    //run catch
    CompanionMatrixRootsFinder rootsFinder(degree);
    CATCH c(&rootsFinder, degree);
    FileReader fr;
    sFileData fileData = fr.readDataFromFile("../../../SGP4/data/LEMUR2_COSMOS_GAUSS.csv");
    //printData(fileData);
    double* timePoints = fileData.timePoints;
    int lastPointIndex = fileData.size;
    double startTime, endTime;
    startTime = getCurrentTymeInMicroSec();
    TCA tca = c.runAlgorithm(fileData.data, timePoints, lastPointIndex);
    endTime = getCurrentTymeInMicroSec();
    //std::cout << "Catch result:\nTime: " << tca.time << "\nDistance:" << tca.distance << "\n";
    //std::cout << "Catch took:\n " << endTime - startTime << " micro seconds\n" << (endTime - startTime) / 1000000 << " seconds \n";
    printResult("CATCH", degree, "LEMUR2_COSMOS", lastPointIndex + 1, endTime - startTime, tca);
    if (fileData.data != nullptr)
    {
        delete[] fileData.data, fileData.timePoints;
    }
}
void runAncas()
{
    //run ancas
    ANCAS a;
    FileReader fr;
    sFileData fileData = fr.readDataFromFile("../../../SGP4/data/LEMUR2_COSMOS_CONST.csv");
    double* timePoints = fileData.timePoints;
    int lastPointIndex = fileData.size;
    double startTime, endTime;
    double temp;
    startTime = getCurrentTymeInMicroSec();
    TCA tca = a.runAlgorithm(fileData.data, timePoints, lastPointIndex);
    endTime = getCurrentTymeInMicroSec();
    //std::cout << "Ancas result:\nTime: " << tca.time << "\nDistance:" << tca.distance << "\n";
    //std::cout << "Ancas took:\n " << endTime - startTime << " micro seconds\n" << (endTime - startTime) / 1000000 << " seconds \n";
    printResult("ANCAS",3, "LEMUR2_COSMOS", lastPointIndex + 1, endTime - startTime, tca);
    if (fileData.data != nullptr)
    {
        delete[] fileData.data, fileData.timePoints;
    }
}

void printResult(string algName,int degree, string testName, int numberOfPoints, double runTime, TCA tca)
{
    std::cout << std::left << std::setw(15) << testName
        << "|" << std::left << std::setw(15) << algName
        << "|" << std::left << std::setw(15) << degree
        << "|" << std::left << std::setw(20) << numberOfPoints
        << "|" << std::left << std::setw(20) << runTime / 1000000
        << "|" << std::left << std::setw(20) << runTime
        << "|" << std::left << std::setw(15) << tca.distance
        << "|" << std::left << std::setw(15) << tca.time << std::endl;

}
void startPrint()
{
    std::cout << std::left << std::setw(15) << "testName"
        << "|" << std::left << std::setw(15) << "algName"
        << "|" << std::left << std::setw(15) << "degree"
        << "|" << std::left << std::setw(20) << "numberOfPoints"
        << "|" << std::left << std::setw(20) << "runTime(sec)"
        << "|" << std::left << std::setw(20) << "runTime(microSec)"
        << "|" << std::left << std::setw(15) << "TCA distance"
        << "|" << std::left << std::setw(15) << "TCA time" << std::endl;


    std::cout << std::left << std::setw(15) << std::setfill('-') << ""
        << "|" << std::left << std::setw(15) << ""
        << "|" << std::left << std::setw(15) << ""
        << "|" << std::left << std::setw(20) << ""
        << "|" << std::left << std::setw(20) << ""
        << "|" << std::left << std::setw(20) << ""
        << "|" << std::left << std::setw(15) << ""
        << "|" << std::left << std::setw(15) << "" << std::setfill(' ') << std::endl;

}
double getCurrentTymeInMicroSec()
{
    // Get the current time point
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

    // Get the duration in microseconds
    auto duration = now.time_since_epoch();
    auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
    return (double)microseconds;
}

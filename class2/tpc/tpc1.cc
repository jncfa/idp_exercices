/**
 * Interação e Deteção de Partículas 2021/2022
 * José Faria <github.com/jncfa>
 * 
 * Trabalho: Isotropic Generator 
 *  
*/
#define HEADER_NAME "Interação e Deteção de Partículas 2021/2022"
#define AUTHOR_NAME "José Faria <github.com/jncfa>"
#define WORK_DESCRIPTION "Isotropic Generator"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "TPCDirectionRandomizer.hh"

/**
 * Helper function used to print help on the console.
*/
static void print_help(std::string name)
{
    std::cout << "Usage: " << name << " [N] [seed] filename \n"
              << "Options:\n"
              << "\t- N (Default = 100): Amount of vectors to generate.\n"
              << "\t- seed (Default = Current time in seconds): Seed value for the C++ Standard Library RNG.\n"
              << "\t- filename: Name of the file to write the vectors to.\n"
              << "\nExample: " << name << " 100 0 values.log\n"
              << "To print help: " << name << " -h\n"
              << std::endl;
}

/**
 * Helper function used to parse strings into floating point values.
*/
bool to_double(std::string str, double& value){
    char* tempPtr;
    double tempValue = strtod(str.c_str(), &tempPtr);

    // Check if it parsed the entire string, return false if not
    if (tempPtr == str.c_str() + str.size()){
        value = tempValue;        
        return true;
    }
    else{
        return false;
    }
}

/**
 * Helper function used to parse strings into long integers.
*/
bool to_long(std::string str, long& value){
    char* tempPtr;
    long tempValue = strtol(str.c_str(), &tempPtr, 10);

    // Check if it parsed the entire string, return false if not
    if (tempPtr == str.c_str() + str.size()){
        value = tempValue;        
        return true;
    }
    else{
        return false;
    }
}

/**
 * Helper function used to parse strings into unsigned long integers.
*/
bool to_ulong(std::string str, unsigned long& value){
    char* tempPtr;
    unsigned long tempValue = strtoul(str.c_str(), &tempPtr, 10);

    // Check if it parsed the entire string, return false if not
    if (tempPtr == str.c_str() + str.size()){
        value = tempValue;        
        return true;
    }
    else{
        return false;
    }
}

/**
 * Entry point of the program.
*/
int main(int argc, char *argv[])
{
    printf("%s\n", HEADER_NAME);
    printf("%s\n\n", AUTHOR_NAME);
    printf("Trabalho: %s\n\n", WORK_DESCRIPTION);

    // Default values
    unsigned long seed = time(0);
    unsigned long numberCount = 100;
    std::string fileName = "";

    // Parse arguments passed to the program
    switch (argc)
    {
    case 2:
        // Print help
        if (!strcmp(argv[1], "-h"))
        {
            print_help(argv[0]);
            return EXIT_SUCCESS;
        }
        // Get filename
        else
        {
            fileName = argv[1];
        }
        break;
    case 3:
        // Print error message if failed to parse arguments
        if (!(to_ulong(argv[1], numberCount))){
            fprintf(stderr, "Error, could not parse the arguments. \n");
            print_help(argv[0]);

            return EXIT_FAILURE;
        }
        fileName = argv[2];
        break;
    
    case 4:
        // Print error message if failed to parse arguments
        if (!(to_ulong(argv[1], numberCount) && to_ulong(argv[2], seed))){
            fprintf(stderr, "Error, could not parse the arguments. \n");
            print_help(argv[0]);
            
            return EXIT_FAILURE;
        }

        fileName = argv[3];
        break;

    default:
        print_help(argv[0]);
        return EXIT_FAILURE;
    }

    // Print initial conditions
    printf("Initial Conditions:\n");
    printf("\t- Number of random numbers: %lu\n", numberCount);
    printf("\t- Seed: %lu\n", seed);

    // Get file descriptor to write to file
    std::ofstream outFile(fileName);

    // Initialize the system generator
    srand(seed);

    // Iteratively generate the random numbers and write them to the file
    printf("\nWriting numbers to file '%s'...\n", fileName.c_str());
    for (int i = 0; i < numberCount; i++)
    {
        // Obtain normalized random direction vector
        Vector3 randVector = generateRandomDirectionMarsaglia();
       
        // Write to the file
        outFile << randVector.x << "\t" << randVector.y << "\t" << randVector.z << std::endl;
    }

    // Flush and close file descriptor
    outFile.close();
    printf("Finished.\n");

    return EXIT_SUCCESS;
}

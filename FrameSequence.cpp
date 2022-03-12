#include "FrameSequence.h"
#include <string>
#include <iostream>
#include <fstream>
#include <ios>
#include <sstream>
// stores a single frame image
// imageSequence holds the entire "video" each element in the array is itself an array that regresents one frame in the "video"
// the element is a dynamically allocated unsigned char array
yrlnic001::FrameSequence::FrameSequence(void) : imageSequence() // initialises the vector
{
    // set vector to 0
}

yrlnic001::FrameSequence::~FrameSequence()
{
    // delete dynamic memory
    // run through imageSequcnce and delete each dynamic sub array. (by deleteing each chat in it?)
}

void yrlnic001::FrameSequence::setCoords(int x, int y, int xx, int yy)
{
    x1 = x;
    x2 = xx;
    y1 = y;
    y2 = yy;
}
void yrlnic001::FrameSequence::setRectSize(int w, int h)
{
    width = w;
    height = h;
}

void yrlnic001::FrameSequence::setOperations(char *ops[], int numArgs) // array of strings with operation,filename,operation,filename
{
    numArgs = numArgs - 11;
    int numOperations = numArgs / 2; // how many different operations should be done on the data
    // finish this
}

void yrlnic001::FrameSequence::addFrame(unsigned char **frame)
{
    yrlnic001::FrameSequence::imageSequence.push_back(frame);
}
int main(int argc, char *argv[]) // argv is a an array
{                                // check input for errors
    yrlnic001::FrameSequence myObj;
    std::string imageName = argv[1]; // the image to be passed in
    myObj.setCoords(std::stoi(argv[3]), std::stoi(argv[4]), std::stoi(argv[5]), std::stoi(argv[6]));
    myObj.setRectSize(std::stoi(argv[8]), std::stoi(argv[9]));
    myObj.setOperations(argv, argc);

    // read in file
    std::ifstream myFile;
    myFile.open(imageName, std::ios::binary); // reads the file in as binary
    std::string line;
    getline(myFile, line); // p5 always first in the file
    getline(myFile, line);

    while (line[0] == '#') // gets rid of comment lines
    {
        getline(myFile, line);
    }
    int rows, columns;
    std::stringstream ss(line); // this line holds the number of rows and columns of unsigned chars
    std::string word;
    ss >> word;
    rows = std::stoi(word);
    ss >> word;
    columns = std::stoi(word);

    getline(myFile, line);
    unsigned char frame[rows * columns]; // array holds one frame with rows*columns pixels
    int counter = 0;
    unsigned char i;
    while (!myFile.eof()) // add each unsigned chat (pixel) to array
    {
        myFile >> i >> std::ws;
        frame[counter] = i;
        counter++;
    }
    myObj.addFrame(frame) // move pointer of class variable to this array

    /*
        while (!myFile.eof())
        {

            while (line[0] == '#') // loop through comments
            {
                getline(myFile, line);
                // std::cout << line << std::endl;
            }
        }
    */
}
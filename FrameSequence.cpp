#include "FrameSequence.h"
#include <string>
#include <iostream>
#include <fstream>
#include <ios>
#include <sstream>

// stores a single frame image
//  imageSequence holds the entire "video" each element in the array is itself an array that regresents one frame in the "video"
//  the element is a dynamically allocated unsigned char array
yrlnic001::FrameSequence::FrameSequence(void) : imageSequence() // initialises the vector
{
    // set vector to 0
}

yrlnic001::FrameSequence::~FrameSequence()
{
    delete[] image; /*
     for (int i = 0; i < sizeof(imageSequence); i++)
     {
         delete imageSequence[i];
     }
     */
    // removes the image from memory
    // delete dynamic memory
    // run through imageSequcnce and delete each dynamic sub array. (by deleteing each chat in it?)
}

void yrlnic001::FrameSequence::setCoords(int x, int y, int xx, int yy)
{
    if (x > xx || y > yy)
    {
        std::cout << "The position of the start frame must be less than the position of the end frame" << std::endl;
        std::exit(0);
    }
    if (x < 0 || xx < 0 || y < 0 || yy < 0)
    {
        std::cout << "All coordinates must be positive integers" << std::endl;
    }
    std::cout << x1 << ":" << x2 << std::endl;
    x1 = x;
    x2 = xx;
    y1 = y;
    y2 = yy;
}
void yrlnic001::FrameSequence::setRectSize(int w, int h)
{
    if ()
        width = w;
    height = h;
}

void yrlnic001::FrameSequence::setOperations(char *args[], int numArgs) // array of strings with operation,filename,operation,filename
{
    numArgs = numArgs - 11;
    int numOperations = numArgs / 2; // how many different operations should be done on the data (operation, name)
    int counter = 0;
    while (numOperations >= 1)
    { // create a vector of structs with operand and file name
        struct w temp = {args[11 + counter], args[12 + counter]};
        operations.push_back(temp);
        counter += 2;
        --numOperations;
    }
}

void yrlnic001::FrameSequence::readInFile(std::string filename)
{
    std::ifstream myFile;

    myFile.open(filename, std::ios::binary); // reads the file in as binary
    std::string line;
    getline(myFile, line); // p5 always first in the file
    getline(myFile, line);
    while (line[0] == '#') // gets rid of comment lines
    {
        getline(myFile, line);
    }

    std::istringstream iss(line);
    int rows, columns;
    iss >> columns;
    iss >> rows;

    std::string temp;
    myFile >> temp >> std::ws;
    // pointer to the array that holds the image
    int size = rows * columns;
    image = new unsigned char[size]; // make this private in the future

    myFile.read((char *)image, size);
    if (myFile)
        std::cout << "all characters read successfully." << std::endl;
    myFile.close();

    /*
    std::ofstream outfile(operations[0].name + ".pgm" + counter, std::ofstream::binary);
    outfile << "P5\n"
            << columns << " " << rows << "\n"
            << "255"
            << "\n";
    outfile.write((char *)image, size);
    outfile.close();
    */
}

void yrlnic001::FrameSequence::processFrames()
{
    // operations[0].name
    int size = x2 - x1;
    for (int i = 0; i < size; i++)
    {
        std::ofstream outfile("test" + std::to_string(i) + ".pgm", std::ofstream::binary);
        outfile << "P5\n"
                << width << " " << height << "\n"
                << "255"
                << "\n";

        // outfile.write(FrameSequence[i], size);
        outfile.close();
    }
}
void yrlnic001::FrameSequence::createVideo(int c)
{ // starts the rect in the given pos and loops until it reaches the edge on the other end

    int size = width * height; // size of rectangle
    unsigned char *frame = new unsigned char[size];
    int counter = c;
    // std::cout << x1 << std::endl;
    for (int y = y1; y < y1 + height; y++)
    {

        for (int x = x1; x < x1 + width; x++)
        {
            frame[counter] = image[x1 * y1];
        }
    }

    addFrame(&frame);

    ++counter;
    if (x1 != x2 && y1 != y2)
    {

        ++x1;
        ++y1;
        createVideo(counter);
    }
    else
    {
        processFrames();
    }
}

void yrlnic001::FrameSequence::addFrame(unsigned char **frame)
{ // frame is a dynamically allocated 2d image frame
    yrlnic001::FrameSequence::imageSequence.push_back(frame);
}

void yrlnic001::FrameSequence::storeImage(std::ifstream &File) // recieve refernce to array that holds the image in unsigned chars
{
    std::string line;
    getline(File, line); // p5 always first in the file
}

int main(int argc, char *argv[]) // argv is a an array
{                                // check input for errors
    yrlnic001::FrameSequence myObj;
    std::string imageName = argv[1];                                                                 // the image to be passed in
    myObj.setCoords(std::stoi(argv[3]), std::stoi(argv[4]), std::stoi(argv[5]), std::stoi(argv[6])); // the start and end coordinates of the rectangle
    myObj.setRectSize(std::stoi(argv[8]), std::stoi(argv[9]));                                       // the size of the rectangle
    myObj.setOperations(argv, argc);                                                                 // the operations to be performed on the data and the names of the output files
    myObj.readInFile(imageName);                                                                     // read in the file
    // read in file
    int c = 0;
    myObj.createVideo(c);   // collect correct frames from start pos to end pos
    myObj.~FrameSequence(); // delete dynamically allocated memory to store image.
}
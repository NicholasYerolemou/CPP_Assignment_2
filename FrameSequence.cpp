#include "FrameSequence.h"
#include <string>
#include <iostream>
int main(int argc, char *argv[])
{
    std::string imageName = argv[1]; // the image to be passed in
    std::cout << imageName << std::endl;
}
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

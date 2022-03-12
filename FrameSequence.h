#ifndef FrameSequence_H
#define FrameSequence_H

#include <vector>

namespace yrlnic001
{
    class FrameSequence
    {
        // variables and methods
    public:
        int main(int, char);
        FrameSequence(void); // constructor
        ~FrameSequence();    // destructor

    private:
        std::vector<unsigned char **> imageSequence; // each position points to an array that holds an unsigned char at each position
    };
}

#endif
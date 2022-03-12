#ifndef FrameSequence_H
#define FrameSequence_H

#include <vector>
#include <string>
namespace yrlnic001
{
    class FrameSequence
    {
        // variables and methods
    public:
        int main(int, char);
        FrameSequence(void); // constructor
        ~FrameSequence();    // destructor
        void setCoords(int x, int y, int xx, int yy);
        void setRectSize(int w, int h);
        void setOperations(char *ops[], int numArgs);
        void addFrame(unsigned char **frame);

    private:
        std::vector<unsigned char **> imageSequence; // each position points to an array that holds an unsigned char at each position
        int x1, y1, x2, y2;
        int width, height;
        struct w
        {
            std::string operation; // operation to be done to data
            std::string name;      // output file name
        };
        std::vector<w> operations;
    };
}

#endif
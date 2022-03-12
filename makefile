CC = g++
CCFLAGS = -std=c++2a
FILES = FrameSequence.cpp


extractor: FrameSequence.o
	$(CC) $(CCFLags) FrameSequence.cpp -o extractor

FrameSequence.o: FrameSequence.cpp FrameSequence.h
	$(CC) $(CCFLAGS) -c FrameSequence.cpp

clean: 
	rm -f *.o
	rm extractor
	rm output.txt

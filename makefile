slidingBlock : slidingBlock.cpp Grid.h Piece.h Movement.h Snapshot.h
	g++ -std=c++11 -o slidingBlock  slidingBlock.cpp

OldslidingBlock : slidingBlock.cpp Grid.h Piece.h Movement.h 
	g++ -std=c++11 -o OldslidingBlock -g -O2 -fsanitize=undefined -fsanitize=leak -fsanitize=address slidingBlock.cpp

clean:
	rm -f slidingBlock *.o


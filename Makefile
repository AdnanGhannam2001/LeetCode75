CXX = clang
CXXFLAGS = -Wall -Wextra -std=c++17 -lstdc++ -g -lm

PROBLEMS_DIR= problems

%: %.cpp
	$(CXX) $(CXXFLAGS) -o problem.o $<

clean:
	rm -f *.out


#include <vector>
using namespace std;

class MovingAverage {
    
    vector<int> data;
    const int expectedSizeOfSlidingWindow;

    // alternative initializations to zero:
    // 'int variableName{0}' or 'int variableName{}'
    int currentSizeOfSlidingWindow = 0;
    int sumValues = 0;
    int index = 0;

public:
    explicit MovingAverage(int size) : expectedSizeOfSlidingWindow{size}{
        data.resize(expectedSizeOfSlidingWindow);
    }

    double next(int value) {
        if (currentSizeOfSlidingWindow < expectedSizeOfSlidingWindow) {
            ++currentSizeOfSlidingWindow;
        }

        sumValues += value - data[index % expectedSizeOfSlidingWindow];
        data[index % expectedSizeOfSlidingWindow] = value;
        ++index;

        return static_cast<double> (sumValues) / currentSizeOfSlidingWindow;
    }
};

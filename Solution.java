
public class MovingAverage {

    private final int[] data;
    private final int expectedSizeOfSlidingWindow;

    private int currentSizeOfSlidingWindow;
    private int sumValues;
    private int index;

    public MovingAverage(int size) {
        expectedSizeOfSlidingWindow = size;
        data = new int[expectedSizeOfSlidingWindow];
    }

    public double next(int value) {
        if (currentSizeOfSlidingWindow < expectedSizeOfSlidingWindow) {
            ++currentSizeOfSlidingWindow;
        }

        sumValues += value - data[index % expectedSizeOfSlidingWindow];
        data[index % expectedSizeOfSlidingWindow] = value;
        ++index;

        return (double) sumValues / currentSizeOfSlidingWindow;
    }
}

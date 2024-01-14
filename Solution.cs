
using System;

public class MovingAverage
{
    private readonly int[] data;
    private readonly int expectedSizeOfSlidingWindow;

    private int currentSizeOfSlidingWindow;
    private int sumValues;
    private int index;

    public MovingAverage(int size)
    {
        expectedSizeOfSlidingWindow = size;
        data = new int[expectedSizeOfSlidingWindow];
    }

    public double Next(int value)
    {
        if (currentSizeOfSlidingWindow < expectedSizeOfSlidingWindow)
        {
            ++currentSizeOfSlidingWindow;
        }

        sumValues += value - data[index % expectedSizeOfSlidingWindow];
        data[index % expectedSizeOfSlidingWindow] = value;
        ++index;

        return (double)sumValues / currentSizeOfSlidingWindow;
    }
}

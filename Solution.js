
/**
 * @param {number} size
 */
var MovingAverage = function (size) {
    this.expectedSizeOfSlidingWindow = size;
    this.data = new Array(this.expectedSizeOfSlidingWindow).fill(0);

    this.currentSizeOfSlidingWindow = 0;
    this.sumValues = 0;
    this.index = 0;
};

/** 
 * @param {number} value
 * @return {number}
 */
MovingAverage.prototype.next = function (value) {
    if (this.currentSizeOfSlidingWindow < this.expectedSizeOfSlidingWindow) {
        ++this.currentSizeOfSlidingWindow;
    }

    this.sumValues += value - this.data[this.index % this.expectedSizeOfSlidingWindow];
    this.data[this.index % this.expectedSizeOfSlidingWindow] = value;
    ++this.index;

    return this.sumValues / this.currentSizeOfSlidingWindow;
};

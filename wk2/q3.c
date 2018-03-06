// q3 - Alternatives to using an if/else block

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Original - if/else block
char *numToDay(int n)
{
    assert(0 <= n && n <= 6);
    char *day;
    if (n == 0) {
        day = "Sun";
    } else if (n == 1) {
        day = "Mon";
    } else if (n == 2) {
        day = "Tue";
    } else if (n == 3) {
        day = "Wed";
    } else if (n == 4) {
        day = "Thu";
    } else if (n == 5) {
        day = "Fri";
    } else if (n == 6) {
        day = "Sat";
    }
    return day;
}

// Using switch/case block
char *numToDaySwitch(int n) {
    assert(0 <= n && n <= 6);
    char *day;
    switch (n) {
        case 0: day = "Sun"; break;
        case 1: day = "Mon"; break;
        case 2: day = "Tue"; break;
        case 3: day = "Wed"; break;
        case 4: day = "Thu"; break;
        case 5: day = "Fri"; break;
        case 6: day = "Sat"; break;
    }
    return day;
}

























// Using an array for table lookup
char *numToDayArray(int n) {
    assert(0 <= n && n <= 6);
    char *days[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return days[n];
}

int main (int argc, char *argv[]) {
    assert(numToDay(0) == "Sun");
    assert(numToDay(1) == "Mon");
    assert(numToDay(2) == "Tue");
    assert(numToDay(3) == "Wed");
    assert(numToDay(4) == "Thu");
    assert(numToDay(5) == "Fri");
    assert(numToDay(6) == "Sat");
    
    assert(numToDaySwitch(0) == "Sun");
    assert(numToDaySwitch(1) == "Mon");
    assert(numToDaySwitch(2) == "Tue");
    assert(numToDaySwitch(3) == "Wed");
    assert(numToDaySwitch(4) == "Thu");
    assert(numToDaySwitch(5) == "Fri");
    assert(numToDaySwitch(6) == "Sat");

    assert(numToDayArray(0) == "Sun");
    assert(numToDayArray(1) == "Mon");
    assert(numToDayArray(2) == "Tue");
    assert(numToDayArray(3) == "Wed");
    assert(numToDayArray(4) == "Thu");
    assert(numToDayArray(5) == "Fri");
    assert(numToDayArray(6) == "Sat");

    printf("All tests passed!\n");
    return EXIT_SUCCESS;
}


#ifndef HYPERSLEEP_H
#define HYPERSLEEP_H

void hypersleep(unsigned int ms) {
    LARGE_INTEGER QPF, current;
    QueryPerformanceFrequency(&QPF), QueryPerformanceCounter(&current);
    long long int end = current.QuadPart + QPF.QuadPart * ms / 1000;
    while (current.QuadPart < end) {
        if (end - current.QuadPart > 200000) {
            Sleep(1);
        }
        else if (end - current.QuadPart > 100000) {
            timeBeginPeriod(8);
            Sleep(1);
            timeEndPeriod(8);
        }
        else if (end - current.QuadPart > 30000) {
            timeBeginPeriod(1);
            Sleep(1);
            timeEndPeriod(1);
        }
        QueryPerformanceCounter(&current);
    }
}

#endif

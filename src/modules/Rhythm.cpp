#include "Rhythm.h"

void Rhythm::clock() {
    position++;
    if(position >= length) {
        position = 0;
    }
}

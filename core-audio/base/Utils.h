#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <AudioToolbox/AudioToolbox.h>

struct AudioDeviceDetails {
    AudioDeviceID id;
    std::array<char, 256> localName;
    int inputStreams;
    int outputStreams;
    bool selected;
};

std::vector<AudioDeviceDetails> getAudioDeviceList();

#endif // UTILS_H

#include <iostream>
#include <iomanip>
#include "AudioCallback.h"

float alpha = 0.1f; 
float prevOutputL = 0.0f;
float prevOutputR = 0.0f;

OSStatus myAudioCallback(void *inRefCon,
                         AudioUnitRenderActionFlags *ioActionFlags,
                         const AudioTimeStamp *inTimeStamp,
                         UInt32 inBusNumber,
                         UInt32 inNumberFrames,
                         AudioBufferList *ioData) 
{
    AudioUnitRender((AudioUnit)inRefCon, ioActionFlags, inTimeStamp, 1, inNumberFrames, ioData);

    float* leftBuffer  = (float*)ioData->mBuffers[0].mData;
    float* rightBuffer = (float*)ioData->mBuffers[1].mData;

    for (UInt32 frame = 0; frame < inNumberFrames; ++frame) {
        // left channel
        float xL = leftBuffer[frame];
        std::cout << std::fixed << std::setprecision(6) << xL << std::endl;
        float yL = alpha * xL + (1.0f - alpha) * prevOutputL;
        prevOutputL = yL;
        leftBuffer[frame] = yL;
        
        // right channel
        float xR = rightBuffer[frame];
        float yR = alpha * xR + (1.0f - alpha) * prevOutputR;
        prevOutputR = yR;
        rightBuffer[frame] = yR;
    }
    
    return noErr;
}

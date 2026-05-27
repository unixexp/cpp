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
    float* leftBuffer  = (float*)ioData->mBuffers[0].mData;
    float* rightBuffer = (float*)ioData->mBuffers[1].mData;

    for (UInt32 frame = 0; frame < inNumberFrames; ++frame) {
        // Левый канал
        float xL = leftBuffer[frame];
        float yL = alpha * xL + (1.0f - alpha) * prevOutputL;
        prevOutputL = yL;
        leftBuffer[frame] = yL;
        
        // Правый канал
        float xR = rightBuffer[frame];
        float yR = alpha * xR + (1.0f - alpha) * prevOutputR;
        prevOutputR = yR;
        rightBuffer[frame] = yR;
    }
    
    return noErr;
}

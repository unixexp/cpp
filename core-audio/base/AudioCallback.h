#ifndef AUDIO_CALLBACK_H
#define AUDIO_CALLBACK_H

#include <AudioToolbox/AudioToolbox.h>

extern float alpha;
extern float prevOutputL;
extern float prevOutputR;

OSStatus myAudioCallback(void *inRefCon,
                         AudioUnitRenderActionFlags *ioActionFlags,
                         const AudioTimeStamp *inTimeStamp,
                         UInt32 inBusNumber,
                         UInt32 inNumberFrames,
                         AudioBufferList *ioData);

#endif // AUDIO_CALLBACK_H

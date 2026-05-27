#include <iostream>
#include <AudioToolbox/AudioToolbox.h>

#include "AudioCallback.h"

int main(int argc, const char* argv[]) {
    // Define audio component
    AudioComponentDescription desc;
    desc.componentType = kAudioUnitType_Output;
    desc.componentSubType = kAudioUnitSubType_HALOutput;
    desc.componentManufacturer = kAudioUnitManufacturer_Apple;
    desc.componentFlags = 0;
    desc.componentFlagsMask = 0;

    AudioComponent comp = AudioComponentFindNext(NULL, &desc);
    AudioUnit audioUnit;
    AudioComponentInstanceNew(comp, &audioUnit);

    UInt32 enabledIO = 1;
    AudioUnitSetProperty(audioUnit, kAudioOutputUnitProperty_EnableIO, kAudioUnitScope_Output, 0, &enabledIO, sizeof(enabledIO));
    AudioUnitSetProperty(audioUnit, kAudioOutputUnitProperty_EnableIO, kAudioUnitScope_Input, 1, &enabledIO, sizeof(enabledIO));

    AudioStreamBasicDescription streamFormat;
    streamFormat.mSampleRate = 44100.0;
    streamFormat.mFormatID = kAudioFormatLinearPCM;
    streamFormat.mFormatFlags = kAudioFormatFlagIsFloat | kAudioFormatFlagIsPacked | kAudioFormatFlagIsNonInterleaved;
    streamFormat.mBytesPerPacket = 4;
    streamFormat.mFramesPerPacket = 1;
    streamFormat.mBytesPerFrame = 4;
    streamFormat.mChannelsPerFrame = 2; // Stereo
    streamFormat.mBitsPerChannel = 32;  // float

    AudioUnitSetProperty(audioUnit, kAudioUnitProperty_StreamFormat, kAudioUnitScope_Output, 1, &streamFormat, sizeof(streamFormat));
    AudioUnitSetProperty(audioUnit, kAudioUnitProperty_StreamFormat, kAudioUnitScope_Input, 0, &streamFormat, sizeof(streamFormat));

    AudioUnitInitialize(audioUnit);
    AudioOutputUnitStart(audioUnit);

    std::cout << "CoreAudio engine started. Press return to exit... " << std::endl;
    std::cin.get();

    AudioOutputUnitStop(audioUnit);
    AudioUnitUninitialize(audioUnit);
    AudioComponentInstanceDispose(audioUnit);
    //AudioDeviceID defaultDevice = kAudioDeviceUnknown;

    return 0;
}


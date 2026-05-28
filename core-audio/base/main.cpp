#include <iomanip>
#include <iostream>
#include <AudioToolbox/AudioToolbox.h>

#include "AudioCallback.h"
#include "Utils.h"

void printDevices(const std::vector<AudioDeviceDetails>& devices) {
    const int id_w = 4;
    const int name_w = 32;
    const int streams_w = 4;
    const int selected_w = 4;

    std::cout
        << "Available audio devices:\n"
        << std::left
        << std::setw(id_w) << "id" << " | "
        << std::setw(name_w) << "name" << " | "
        << std::setw(streams_w) << "in" << " | "
        << std::setw(streams_w) << "out" << " | "
        << std::setw(selected_w) << "selected" << " |\n";
    
    std::cout << std::string(id_w + name_w + (streams_w * 2) + selected_w + 18, '-') << "\n";

    for (int i = 0; i < devices.size(); ++i) {
        AudioDeviceDetails dev = devices[i];
        std::cout
            << std::left
            << std::setw(id_w) << dev.id << " | "
            << std::setw(name_w) << dev.localName.data() << " | "
            << std::setw(streams_w) << dev.inputStreams << " | "
            << std::setw(streams_w) << dev.outputStreams << " | "
            << std::setw(selected_w + 4) << (dev.selected ? "+" : " ") << " | ";

        if (i < devices.size() - 1) {
            std::cout << "\n";
        }
    }
}

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

    // Show available audio devices
    std::vector<AudioDeviceDetails> devices = getAudioDeviceList();
    printDevices(devices);

    // Get audio device
    AudioDeviceID defaultDevice = kAudioDeviceUnknown;
    UInt32 propertySize = sizeof(defaultDevice);
    AudioObjectPropertyAddress propertyAddress = {
        kAudioHardwarePropertyDefaultOutputDevice,
        kAudioObjectPropertyScopeGlobal,
        kAudioObjectPropertyElementMain
    };
    AudioObjectGetPropertyData(kAudioObjectSystemObject, &propertyAddress, 0, NULL, &propertySize, &defaultDevice);

    // Attach audio device to audio unit
    AudioUnitSetProperty(audioUnit,
        kAudioOutputUnitProperty_CurrentDevice,
        kAudioUnitScope_Global,
        0,
        &defaultDevice,
        sizeof(defaultDevice));

    // Enable audio input/output
    UInt32 enabledIO = 1;
    AudioUnitSetProperty(audioUnit, kAudioOutputUnitProperty_EnableIO, kAudioUnitScope_Output, 0, &enabledIO, sizeof(enabledIO));
    AudioUnitSetProperty(audioUnit, kAudioOutputUnitProperty_EnableIO, kAudioUnitScope_Input, 1, &enabledIO, sizeof(enabledIO));

    // Define audio format
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

    // Set render callback to audio data processing
    AURenderCallbackStruct callbackStruct;
    callbackStruct.inputProc = myAudioCallback;
    callbackStruct.inputProcRefCon = NULL;
    AudioUnitSetProperty(audioUnit, kAudioUnitProperty_SetRenderCallback, kAudioUnitScope_Global, 0, &callbackStruct, sizeof(callbackStruct));

    AudioUnitInitialize(audioUnit);
    AudioOutputUnitStart(audioUnit);

    std::cout << "\n\n" << "CoreAudio engine started for device with id '" << defaultDevice << "'. Press return to exit... " << "\n\n";
    std::cin.get();

    AudioOutputUnitStop(audioUnit);
    AudioUnitUninitialize(audioUnit);
    AudioComponentInstanceDispose(audioUnit);

    return 0;
}


#include <iostream>
#include <array>
#include "Utils.h"

std::vector<AudioDeviceDetails> getAudioDeviceList() {
    // Get default device ID
    AudioDeviceID defaultID = kAudioDeviceUnknown;
    UInt32 defaultSize = sizeof(defaultID);
    AudioObjectPropertyAddress defaultAddress = {
        kAudioHardwarePropertyDefaultOutputDevice,
        kAudioObjectPropertyScopeGlobal,
        kAudioObjectPropertyElementMain
    };
    AudioObjectGetPropertyData(kAudioObjectSystemObject, &defaultAddress, 0, NULL, &defaultSize, &defaultID);

    // Get system audio device list
    AudioObjectPropertyAddress propertyAddress = {
        kAudioHardwarePropertyDevices,
        kAudioObjectPropertyScopeGlobal,
        kAudioObjectPropertyElementMain
    };

    UInt32 dataSize = 0;
    AudioObjectGetPropertyDataSize(kAudioObjectSystemObject, &propertyAddress, 0, NULL, &dataSize);
    int deviceCount = dataSize / sizeof(AudioDeviceID);

    std::vector<AudioDeviceID> deviceIDs(deviceCount);
    AudioObjectGetPropertyData(kAudioObjectSystemObject, &propertyAddress, 0, NULL, &dataSize, deviceIDs.data());

    // Get audio device list details
    std::vector<AudioDeviceDetails> devices(deviceCount);
    for (int i = 0; i < deviceCount; ++i) {
        AudioDeviceID devID = deviceIDs[i];

        CFStringRef deviceName = NULL;
        UInt32 nameSize = sizeof(CFStringRef);
        AudioObjectPropertyAddress nameAddress = {
            kAudioDevicePropertyDeviceNameCFString,
            kAudioObjectPropertyScopeGlobal,
            kAudioObjectPropertyElementMain
        };

        AudioObjectGetPropertyData(devID, &nameAddress, 0, NULL, &nameSize, &deviceName);

        // Convert CFStringRef to standard std:str
        std::array<char, 256> localName{};
        if (deviceName) {
            CFStringGetCString(deviceName, localName.data(), sizeof(localName), kCFStringEncodingUTF8);
            CFRelease(deviceName);
        }

        // Search inputs and outputs
        AudioObjectPropertyAddress streamAddress = {
            kAudioDevicePropertyStreams,
            kAudioDevicePropertyScopeInput,
            kAudioObjectPropertyElementMain
        };
        UInt32 streamSize = 0;
        AudioObjectGetPropertyDataSize(devID, &streamAddress, 0, NULL, &streamSize);
        int inputStreams = streamSize / sizeof(AudioStreamID);
        
        streamAddress.mScope = kAudioDevicePropertyScopeOutput;
        AudioObjectGetPropertyDataSize(devID, &streamAddress, 0, NULL, &streamSize);
        int outputStreams = streamSize / sizeof(AudioStreamID);

        devices[i] = {devID, localName, inputStreams, outputStreams, (devID == defaultID) ? true : false};
    }

    return devices;
}


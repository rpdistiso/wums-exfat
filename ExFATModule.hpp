#pragma once
#include <wums.h>
#include <memory>
#include <string>

class ExFATModule {
public:
    static ExFATModule& getInstance();
    bool mount();
    bool unmount();
    
private:
    ExFATModule() = default;
    ~ExFATModule() = default;
    
    bool mounted = false;
    std::string mountPoint = "exfat";
};
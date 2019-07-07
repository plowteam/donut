#pragma once

#include <string>
#include <memory>
#include <unordered_map>

namespace Donut::RAD {

class FileLoader;

class LoadManager {
public:
    void AddFileLoader(std::unique_ptr<FileLoader>, const std::string&);
protected:
    std::unordered_map<std::string, std::unique_ptr<FileLoader>> _fileLoaders;
};

} // namespace Donut::RAD

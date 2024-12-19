
#include "../utils/size.h"
#include<iostream>

Size::Size() : size(0) {
    currDir = fs::current_path();
}

Size::Size(fs::path path) : size(0) {
    currDir = path;
}

void Size::getSize() {
    size = 0;
    try {
        for (const auto& entry : fs::recursive_directory_iterator(
            currDir,
            fs::directory_options::skip_permission_denied
        )) {
            if (fs::is_regular_file(entry)) {
                size += fs::file_size(entry);
            }
        }
    } catch (const fs::filesystem_error&) {
    }
}

std::string Size::getSize(fs::path path) {
    long int fileSize = 0;
    try {
        if (!fs::exists(path)) {
            return "Path does not exist";
        }

        if (fs::is_regular_file(path)) {
            fileSize = fs::file_size(path);
        } else {
            for (const auto& entry : fs::recursive_directory_iterator(
                path,
                fs::directory_options::skip_permission_denied
            )) {
                if (fs::is_regular_file(entry)) {
                    fileSize += fs::file_size(entry);
                }
            }
        }
        
        const double KB = 1024;
        const double MB = KB * 1024;
        const double GB = MB * 1024;

        if (fileSize < KB) {
            return std::to_string(fileSize) + " B";
        } else if (fileSize < MB) {
            return std::to_string(static_cast<long>(fileSize / KB)) + " KB";
        } else if (fileSize < GB) {
            return std::to_string(static_cast<long>(fileSize / MB)) + " MB";
        } else {
            return std::to_string(static_cast<long>(fileSize / GB)) + " GB";
        }
    } catch (const fs::filesystem_error&) {
        return "Access denied";
    }
}


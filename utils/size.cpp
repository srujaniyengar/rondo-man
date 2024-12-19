
#include "size.h"
#include <cstdio>
#include <memory>
#include <array>

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
        // Skip inaccessible directories
    }
}

std::string Size::getSize(fs::path path) {
    if (path == "/") {
        std::array<char, 128> buffer;
        std::string result;
        std::unique_ptr<FILE, decltype(&pclose)> pipe(
            popen("df -B1 / | tail -n1 | awk '{print $3}'", "r"),
            pclose
        );
        
        if (pipe) {
            while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
                result += buffer.data();
            }
            try {
                long long size = std::stoll(result);
                const double KB = 1024;
                const double MB = KB * 1024;
                const double GB = MB * 1024;
                const double TB = GB * 1024;

                if (size < KB) {
                    return std::to_string(size) + " B";
                } else if (size < MB) {
                    return std::to_string(static_cast<long>(size / KB)) + " KB";
                } else if (size < GB) {
                    return std::to_string(static_cast<long>(size / MB)) + " MB";
                } else if (size < TB) {
                    return std::to_string(static_cast<long>(size / GB)) + " GB";
                } else {
                    return std::to_string(static_cast<long>(size / TB)) + " TB";
                }
            } catch (const std::exception&) {
                return "Unable to calculate root size";
            }
        }
        return "Unable to access root size information";
    }

    long long fileSize = 0;
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
        const double TB = GB * 1024;

        if (fileSize < KB) {
            return std::to_string(fileSize) + " B";
        } else if (fileSize < MB) {
            return std::to_string(static_cast<long>(fileSize / KB)) + " KB";
        } else if (fileSize < GB) {
            return std::to_string(static_cast<long>(fileSize / MB)) + " MB";
        } else if (fileSize < TB) {
            return std::to_string(static_cast<long>(fileSize / GB)) + " GB";
        } else {
            return std::to_string(static_cast<long>(fileSize / TB)) + " TB";
        }
    } catch (const fs::filesystem_error&) {
        return "Access denied";
    }
}


#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <array>
#include <filesystem>

namespace fs = std::filesystem;

namespace Logs {

class FileSink
{
public:
    FileSink(const std::string& file_name, std::size_t buffer_size = 4096u)
    : m_buffer(buffer_size), m_output(file_name), m_offset(0u)
    {
        if (!m_output.is_open()) {
            throw std::runtime_error("File was not created");
        }
    }

    void write(const std::string& data)
    {
        const std::size_t data_size = data.size();
        if (data_size + m_offset >= m_buffer.size()) {
            flush();
        }

        std::copy(begin(data), end(data), begin(m_buffer) + m_offset);
        m_offset += data_size;
    }

    ~FileSink()
    {
        flush();
    }
private:
    void flush()
    {
        if (m_offset != 0u) {
            m_output.write(m_buffer.data(), m_offset);
            m_offset = 0u;
        }
    }

private:
    std::vector<char> m_buffer;
    std::ofstream     m_output;
    std::size_t       m_offset;
};

class Logger
{
public:
    enum Level
    {
        TRACE_LEVEL,
        DEBUG_LEVEL,
        INFO_LEVEL,
        WARN_LEVEL,
        ERROR_LEVEL,
        FATAL_LEVEL
    };

    static inline std::array<std::string, Level::FATAL_LEVEL + 1u> LevelStr = {
        "TRACE", "DEBUG", "INFO", "WARN", "ERROR", "FATAL"
    };

public:
    Logger(const std::string& file_name) : m_sink(file_name) {}

    void log(Level level, const char* source, const std::string& message)
    {
        const std::string formated_message = "[" + LevelStr[level] + "] - " + source + " - " + message + "\n";
        m_sink.write(formated_message);
    }
private:
    FileSink m_sink;

};

} // namespace Logs

inline Logs::Logger& getGlobalLogger()
{
    #if defined(_WIN32) || defined(_WIN64)
        fs::create_directory("C:\\Logger");
        static Logs::Logger logger("C:\\Logger\\data.log");
        return logger;
    #else
        fs::create_directory("/tmp/Logger");
        static Logs::Logger logger("/tmp/Logger/data.log");
        return logger;
    #endif
}

#define STR_(x) #x
#define STR(x) STR_(x)

#define LOG_TRACE(message) getGlobalLogger().log(Logs::Logger::Level::TRACE_LEVEL, __FILE__ ":" STR(__LINE__), (message))
#define LOG_DEBUG(message) getGlobalLogger().log(Logs::Logger::Level::DEBUG_LEVEL, __FILE__ ":" STR(__LINE__), (message))
#define LOG_INFO(message) getGlobalLogger().log(Logs::Logger::Level::INFO_LEVEL, __FILE__ ":" STR(__LINE__), (message))
#define LOG_WARN(message) getGlobalLogger().log(Logs::Logger::Level::WARN_LEVEL, __FILE__ ":" STR(__LINE__), (message))
#define LOG_ERROR(message) getGlobalLogger().log(Logs::Logger::Level::ERROR_LEVEL, __FILE__ ":" STR(__LINE__), (message))
#define LOG_FATAL(message) getGlobalLogger().log(Logs::Logger::Level::FATAL_LEVEL, __FILE__ ":" STR(__LINE__), (message))

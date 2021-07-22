#ifndef CPP_UTILS_LOGGER_H
#define CPP_UTILS_LOGGER_H

#include <iostream>
#include <variant>
#include <mutex>
#include <fstream>

namespace poler::utils {
    enum LogLevel {
        NONE,
        ERROR,
        WARNING,
        INFO,
        DEBUG
    };

    struct Arg {
        enum Type { INT, FLOAT, DOUBLE, STRING, CSTRING };
    public:
        Type type;
        std::variant<int, float, double, std::string_view, const char*> v;

        Arg(int value) : type(INT) { v = value; }
        Arg(double value) : type(DOUBLE) { v = value; }
        Arg(float value) : type(FLOAT) { v = value; }
        Arg(const std::string& value) : type(STRING) { v = value; }
        Arg(const char* value) : type(CSTRING) { v = value; }
    };

    // Singleton logger class.
    // Supports logging levels and C#-like text formatting.
    // Works primarily with int, float, double and strings
    class Logger {
    public:
        Logger(const Logger&) = delete;
        void operator=(const Logger&) = delete;

        static Logger& getInstance();
        static void setImportance(LogLevel level);

        template<typename... Args>
        static void log(const std::string& path, const bool append, const std::string& msg, const Args&... args) {
            std::ofstream file;
            if (append) {
                file.open(path, std::ios_base::app);
            }
            else {
                file.open(path, std::ios_base::out);
            }
            if (file.good()){
                safeLog(msg, "",  file, args...);
            }
            file.close();
        }

        template<typename... Args>
        static void log(const std::string& path, const std::string& msg, const Args&... args) {
            log(path, true, msg, args...);
        }

        template<typename... Args>
        static void error(const std::string& msg, const Args&... args) {
            if (getInstance().level_ >= ERROR) {
                safeLog(msg, "[Error] : ",  std::cerr, args...);
            }
        }

        template <typename... Args>
        static void warning(const std::string& msg, Args... args) {
            if (getInstance().level_ >= WARNING) {
                safeLog(msg, "[Warning] : ", std::cout, args...);
            }
        }

        template <typename... Args>
        static void info(const std::string& msg, Args... args) {
            if (getInstance().level_ >= INFO) {
                safeLog(msg, "[Info] : ", std::cout, args...);
            }
        }

        template <typename... Args>
        static void debug(const std::string& msg, Args... args) {
            if (getInstance().level_ >= DEBUG) {
                safeLog(msg, "[Debug] : ", std::cout, args...);
            }
        }

    private:
        std::mutex mtx_;
        LogLevel level_;

        template <typename... Args>
        static void safeLog(const std::string& msg, const std::string& label, std::ostream& output, Args... args) {
            Arg argArray[] = {args...};
            getInstance().mtx_.lock();
            output << label;
            print(msg.c_str(), output, argArray, sizeof...(Args));
            getInstance().mtx_.unlock();
        }

        static void printValue(std::ostream& output, const Arg value);

        static void print(const char *msg, std::ostream& output, const Arg *args, size_t numArgs);

        explicit Logger(LogLevel level);
    };
}

#endif //CPP_UTILS_LOGGER_H

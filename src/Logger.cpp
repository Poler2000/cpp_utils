#include "Logger.h"

namespace poler::utils {
    Logger::Logger(LogLevel level) {
        level_ = level;
    }

    Logger &Logger::getInstance() {
        static Logger logger{INFO};
        return logger;
    }

    void Logger::setImportance(LogLevel level) {
        getInstance().level_ = level;
    }

    void Logger::print(const char *msg, std::ostream& output, const Arg *args, size_t numArgs) {
        while (*msg) {
            if (*msg == '\\') {
                msg++;
            }
            else if (*msg == '{') {
                if (*(msg + 1) == '}') {
                    msg += 2;
                }
                else {
                    int i = (int)*(msg + 1) - 48;
                    switch (args[i].type) {
                        case Arg::INT:
                            output << std::get<0>(args[i].v);
                            break;
                        case Arg::FLOAT:
                            output << std::get<1>(args[i].v);
                            break;
                        case Arg::DOUBLE:
                            output << std::get<2>(args[i].v);
                            break;
                        case Arg::STRING:
                            output << std::get<3>(args[i].v);
                            break;
                        case Arg::CSTRING:
                            output << std::get<4>(args[i].v);
                            break;
                    }
                    msg += 3;
                }
            }
            output << *msg++;
        }
        output << '\n';
    }
}
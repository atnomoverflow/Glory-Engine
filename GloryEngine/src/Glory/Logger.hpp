#pragma once
#include "spdlog/spdlog.h"
namespace Glory
{
    class Logger
    {
    private:
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
        static std::shared_ptr<spdlog::logger> s_CoreLogger;

    public:
        static void Init();
        inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }
    };

} // namespace Glory

#define GLORY_CORE_TRACE(...) ::Glory::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define GLORY_CORE_INFO(...) ::Glory::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define GLORY_CORE_WARN(...) ::Glory::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define GLORY_CORE_ERROR(...) ::Glory::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define GLORY_CORE_CRITICAL(...) ::Glory::Logger::GetCoreLogger()->critical(__VA_ARGS__)

#define GLORY_TRACE(...) ::Glory::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define GLORY_INFO(...) ::Glory::Logger::GetClientLogger()->info(__VA_ARGS__)
#define GLORY_WARN(...) ::Glory::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define GLORY_ERROR(...) ::Glory::Logger::GetClientLogger()->error(__VA_ARGS__)
#define GLORY_CRITICAL(...) ::Glory::Logger::GetClientLogger()->critical(__VA_ARGS__)
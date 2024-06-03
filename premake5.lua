workspace " GloryEngine"
    architecture "x64"

    configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir= {}

IncludeDir["GLFW"]  = "GloryEngine/vendor/GLFW/include"
IncludeDir["ImGui"] = "GloryEngine/vendor/imgui"


include "GloryEngine/vendor/GLFW"
include "GloryEngine/vendor/imgui"


project "GloryEngine"
    location "%{prj.name}"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "%{prj.name}")
    targetdir ("obj/" .. outputdir .. "%{prj.name}")

    pchheader "pchge.hpp" 
    pchsource "%{prj.name}/include/pchge.cpp" 

    files { "%{prj.name}/include/**.hpp", "%{prj.name}/src/**.cpp" }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.ImGui}"
    }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

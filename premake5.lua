workspace " GloryEngine"
    configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir= {}

IncludeDir["GLFW"]  = "GlodyEngine/vendor/GLFW/include"
IncludeDir["ImGui"] = "GlodyEngine/vendor/imgui"


include "GlodyEngine/vendor/GLFW"
include "GlodyEngine/vendor/imgui"


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

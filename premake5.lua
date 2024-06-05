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
    objdir ("bin-int/" .. outputdir .. "%{prj.name}")

    pchheader "pchge.hpp"
    pchsource "%{prj.name}/src/pchge.cpp" 

    files { "%{prj.name}/src/**.hpp","%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.ImGui}"
    }


    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
		systemversion "latest"

		defines
		{
			"GLORY_PLATFORM_WINDOWS",
			"GLORY_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}
    filter "system:lunix"
        defines {
            "GLORY_PLATFORM_LINUX",
            "GLORY_BUILD_SHARED",
        }
        cppdialect "C++20"
        staticruntime "On"
		systemversion "latest"
        postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp"
	}
    includedirs
    {
        "GloryEngine/vendor/spdlog/include",
        "GloryEngine/src",
    }
    links{
        "GloryEngine"
    }

	filter "system:linux"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GLORY_PLATFORM_LINUX"
		}
    filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GLORY_PLATFORM_WINDOWS"
		}

    filter "configurations:Debug"
    defines "GLORY_DEBUG"
    buildoptions "/MDd"
    symbols "On"

    filter "configurations:Release"
        defines "GLORY_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "GLORY_DIST"
        buildoptions "/MD"
        optimize "On"
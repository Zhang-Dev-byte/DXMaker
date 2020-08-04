workspace "DXMaker"
    architecture "x86_64"
    configurations
	{
		"Debug",
		"Release"
	}
	
	flags
	{
		"MultiProcessorCompile"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    include "deps/imgui"

    project "DXMaker"
        location "DXMaker"
        kind "SharedLib"
        language "C++"
        cppdialect "C++17"
        staticruntime "on"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        pchheader "dxpch.h"
        pchsource "DXMaker/src/DXMaker/dxpch.cpp"

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }

        links
        {
            "ImGui"
        }

        includedirs
        {
            "%{prj.name}/src",
            "deps/spdlog/include",
            "deps/imgui"
        }

        filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"DX_PLATFORM_WINDOWS",
			"DX_BUILD_DLL",
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

        filter "configurations:Debug"
            defines "DX_DEBUG"
            runtime "Debug"
            symbols "On"

        filter "configurations:Release"
            defines "DX_RELEASE"
            runtime "Release"
            optimize "On"

    project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"
        staticruntime "off"
        
        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }

        links
        {
            "DXMaker",
            "ImGui"
        }

        includedirs
        {
            "DXMaker/src",
            "deps/spdlog/include",
            "deps/imgui"
        }

        filter "system:windows"
		cppdialect "C++17"
        systemversion "latest"
        
        defines
		{
			"DX_PLATFORM_WINDOWS"
        }
        
        filter "configurations:Debug"
            defines "DX_DEBUG"
            runtime "Debug"
            symbols "On"

        filter "configurations:Release"
            defines "DX_RELEASE"
            runtime "Release"
            optimize "On"
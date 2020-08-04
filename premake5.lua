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
    include "deps/dxerr"
    include "deps/dxtex"

    project "DXMaker"
        location "DXMaker"
        kind "SharedLib"
        language "C++"
        cppdialect "C++17"
        staticruntime "on"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        pchheader "dxpch.h"
        pchsource "DXMaker/src/dxpch.cpp"

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }

        links
        {
            "ImGui",
            "DxErr",
            "DxTex"
        }

        includedirs
        {
            "%{prj.name}/src",
            "deps/spdlog/include",
            "deps/imgui",
            "deps/dxerr",
            "deps/dxtex"
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
        
        filter "system:windows"
            systemversion "latest"
            cppdialect "C++17"
            staticruntime "On"
            
        filter { "system:windows", "configurations:Release" }
            buildoptions "/MT"

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
            "ImGui",
            "DxErr",
            "DxTex"
        }

        includedirs
        {
            "DXMaker/src",
            "deps/spdlog/include",
            "deps/imgui",
            "deps/dxerr",
            "deps/dxtex"
        }

        filter "system:windows"
            cppdialect "C++17"
            systemversion "latest"
        
        defines
		{
			"DX_PLATFORM_WINDOWS"
        }
        
        filter "system:windows"
            systemversion "latest"
            cppdialect "C++17"
            staticruntime "On"
            
        filter { "system:windows", "configurations:Release" }
            buildoptions "/MT"
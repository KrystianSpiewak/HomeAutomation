workspace "HomeAutomation"
	architecture "x64"
	startproject "App"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}

project "HomeAutomation"
	location "HomeAutomation"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ha_pch.h"
	pchsource "HomeAutomation/src/ha_pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	defines {}

	includedirs
	{
		"%{prj.name}/src"
	}

	links
	{}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"HA_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "HA_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HA_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HA_DIST"
		runtime "Release"
		optimize "on"


project "App"
	location "App"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"HomeAutomation/src",
	}

	links
	{
		"HomeAutomation"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"HA_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HA_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HA_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HA_DIST"
		runtime "Release"
		optimize "on"


project "UnitTest"
	location "UnitTest"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"HomeAutomation/src",
	}

	links
	{
		"HomeAutomation"
	}

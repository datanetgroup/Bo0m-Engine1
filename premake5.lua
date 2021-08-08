workspace "BE"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Shipping"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


	project "Bo0m_Engine"

	location "Bo0m_Engine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" ..outputdir .."/%{prj.name}")
	objdir ("bin-int/" ..outputdir .."/%{prj.name}")

	pchheader "bepch.h"
	pchsource "Bo0m_Engine/Source/bepch.cpp"


	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"

	}

	includedirs
	{
		"%{prj.name}/Bo0m_Engine/Source",
		"Bo0m-Engine/Bo0m_Engine/Source/ThirdParty"

	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
		"BE_PLATFORM_WINDOWS",
		"BE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir .. "/SampleProject")

		}

		filter "configurations:Debug"
			defines "BE_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "BE_RELEASE"
			optimize "On"

		filter "configurations:Shipping"
			defines "BE_SHIPPING"
			optimize "On"


project "SampleProject"
	location "SampleProject"
	kind "ConsoleApp"
	language "C++"


	targetdir ("bin/" ..outputdir .."/%{prj.name}")
	objdir ("bin-int/" ..outputdir .."/%{prj.name}")

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp"

	}

	includedirs
	{
		"Bo0m_Engine/Source/ThirdParts/spdlog/include",
		"Bo0m_Engine/Source"

	}

	links
	{
		"Bo0m_Engine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
		"BE_PLATFORM_WINDOWS",
		}


		filter "configurations:Debug"
			defines "BE_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "BE_RELEASE"
			optimize "On"

		filter "configurations:Shipping"
			defines "BE_SHIPPING"
			optimize "On"
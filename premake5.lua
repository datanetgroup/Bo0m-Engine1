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
		"%{prj.name}/Engine/Source/**.h",
		"%{prj.name}/Engine/Source/**.cpp"

	}

	includedirs
	{
		"%{prj.name}/Bo0m_Engine/Source",
		"%{prj.name}/Bo0m_Engine/Source/ThirdParts/spdlog/include"

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
			("{COPY} %{cfg.buildtarget.repath} ../bin/" ..outputdir .. "/SampleProject")

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
		"%{prj.name}/Bo0m_Engine/Source/**.h",
		"%{prj.name}/Bo0m_Engine/Source/**.cpp"

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
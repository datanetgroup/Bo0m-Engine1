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

	files
	{
		"%{prj.name}/Engine/Source/**.h",
		"%{prj.name}/Engine/Source/**.cpp"

	}

	includedirs
	{
		"%{prj.name}Bo0m_Engine\Source\ThirdParts\spdlog\include;"

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
			definde "BE_DEBUG"
			sybols "On"

		filter "configurations:Release"
			definde "BE_RELEASE"
			optimized "On"

		filter "configurations:Shipping"
			definde "BE_SHIPPING"
			optimized "On"


project "SampleProject"
	location "SampleProject"
	kind "ConsoleApp"
	language "C++"


	targetdir ("bin/" ..outputdir .."/%{prj.name}")
	objdir ("bin-int/" ..outputdir .."/%{prj.name}")

	files
	{
		"%{prj.name}/Engine/Source/**.h",
		"%{prj.name}/Engine/Source/**.cpp"

	}

	includedirs
	{
		"%{prj.name}\Bo0m_Engine\Source\ThirdParts\spdlog\include;",
		"Bo0m_Engine\Source;"

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
			definde "BE_DEBUG"
			sybols "On"

		filter "configurations:Release"
			definde "BE_RELEASE"
			optimized "On"

		filter "configurations:Shipping"
			definde "BE_SHIPPING"
			optimized "On"
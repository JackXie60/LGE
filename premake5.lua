workspace "LEG"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "LEG"
	location "LEG"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "lgepch.h"
	pchsource "LEG/src/lgepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src"
	}

	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"LGE_PALTFORM_WINDOWS",
			"LGE_BUILD_DLL",
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "LGE_DEBUG"
		symbols "On"

	filter "configurations:Debug"
		defines "LGE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "LGE_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"

	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"LEG/vendor/spdlog/include",
		"LEG/src"
	}

	links
	{
		"LEG"
	}

	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"LGE_PALTFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "LGE_DEBUG"
		symbols "On"

	filter "configurations:Debug"
		defines "LGE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "LGE_DIST"
		optimize "On"
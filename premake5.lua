workspace "sqwack_math"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

startproject "Sandbox"


filter "configurations:Debug"
    defines "_DEBUG"
    symbols "on"

filter "configurations:Release"
    defines "_RELEASE"
    optimize "Speed"
    symbols "off"

warnings "Everything"
defines "SQ_MATH_SIMD"

	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"



project "sqwack_math"

	location "sqwack_math"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")
	debugdir ("bin/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/include/**.hpp",
		"%{prj.name}/include/**.hh",
		"%{prj.name}/include/**.hxx",
		"%{prj.name}/include/**.h",

		"%{prj.name}/export/%{prj.name}/**.hpp",
		"%{prj.name}/export/%{prj.name}/**.hh",
		"%{prj.name}/export/%{prj.name}/**.hxx",
		"%{prj.name}/export/%{prj.name}/**.h",

		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.c"
	}

	includedirs
	{
		"%{prj.name}/include"
	}


	    filter "system:windows"

	    systemversion "latest"
	    staticruntime "on"
	    flags {"MultiProcessorCompile"}




project "Sandbox"

	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")
	debugdir ("bin/" .. outputdir .. "/%{prj.name}")



	
	files
	{
		"%{prj.name}/**.hpp",
		"%{prj.name}/**.hh",
		"%{prj.name}/**.hxx",
		"%{prj.name}/**.h",

		"%{prj.name}/**.cpp",
		"%{prj.name}/**.c"
	}

	includedirs
	{
		"%{prj.name}/include",
		"sqwack_math/export",
		"sqwack_math/include"
	}

	links 
	{
		sqwack_math
	}

	    filter "system:windows"

	    systemversion "latest"
	    staticruntime "on"
	    flags {"MultiProcessorCompile"}






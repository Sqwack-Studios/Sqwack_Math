workspace "sqwack_math"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

	
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"



project "sqwack_math"

	location "sqwack_math"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")
	debugdir ("bin/" .. outputdir .. "/%{prj.name}")


	warnings "Everything"
    defines "SQ_MATH_SIMD"
	
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
		"%{prj.name}/include"
	}


		filter "system:windows"

		systemversion "latest"
		staticruntime "on"
		flags {"MultiProcessorCompile"}



		filter "configurations:Debug"
			defines "_DEBUG"
			symbols "on"

		filter "configurations:Release"
		    defines "_RELEASE"
		    optimize "Speed"
			symbols "off"

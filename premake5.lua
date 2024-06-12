workspace "sqwack_math"
	architecture "x86_64"

	configurations
	{
		"Debug",
		"Release"
	}

startproject "Sandbox"

local simd = true
local preprocessor_defines = {}

if simd then

--NOTE: We are targeting x86 so SSE2 is ALWAYS enabled...

-- 1: don't enable vector instructions
-- 2: SSE3
-- 3: SSSE3
-- 4: SSE41
-- 5: SSE42
-- 6: AVX
-- 7: AVX2
-- 8: AVX512

--NOTE: In MSVC, if we want to target SSE*, then we are forced to enable, at least, AVX.
	local try_enable_ISA = 4
	local ISA_map = {1, 6, 6, 6, 6, 6, 7, 8}
	local ISA_table = {"Default", "SSE3", "SSSE3", "SSE4.1", "SSE4.2", "AVX", "AVX2", "AVX512"} --AVX512 won't work ply

	vectorextensions(ISA_table[ISA_map[7]])

	local allow_AVX   = true
	local allow_AVX2  = true
	local allow_SSE42 = true
	local allow_SSE41 = true
	local allow_SSSE3 = true
	local allow_SSE3  = true
	local allow_SSE2  = true
	local allow_FMA   = true

	table.insert(preprocessor_defines, "SQM_ENABLE_SIMD")
	
	if allow_SSE2 then
		table.insert(preprocessor_defines, "SQM_ENABLE_SSE2")
	end

	if allow_SSE3 then
		table.insert(preprocessor_defines, "SQM_ENABLE_SSE3")
	end

	if allow_SSSE3 then
		table.insert(preprocessor_defines, "SQM_ENABLE_SSSE3")
	end

	if allow_SSE41 then
		table.insert(preprocessor_defines, "SQM_ENABLE_SSE41")
	end

	if allow_SSE42 then
		table.insert(preprocessor_defines, "SQM_ENABLE_SSE42")
	end

	if allow_FMA then
		table.insert(preprocessor_defines, "SQM_ENABLE_FMA")
	end

	if allow_AVX then
		table.insert(preprocessor_defines, "SQM_ENABLE_AVX")
	end

	if allow_AVX2 then
		table.insert(preprocessor_defines, "SQM_ENABLE_AVX2")
	end

end

defines(preprocessor_defines)

filter "configurations:Debug"
    defines "_DEBUG"
    symbols "on"

filter "configurations:Release"
    defines "_RELEASE"
    optimize "Speed"
    symbols "off"

warnings "Everything"







	
local outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"



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








workspace "LinearEngine"
	architecture "x64"
	startproject "Sandbox Game"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Engine"
	location "Engine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++14"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	-- pchheader "lgepch.h"
	-- pchsource "Engine/lgepch.cpp"

	files {
		"%{prj.name}/**.h",
		"%{prj.name}/**.hpp",
		"%{prj.name}/**.inl",
		"%{prj.name}/**.cpp",
		"%{prj.name}/**.c",
	}

	includedirs {
		"Libraries/include",
		"lmm",
		"Dear ImGUI",
	}

	libdirs {
		"Libraries/lib",
	}

	links {
		"glfw3_mt.lib",
		"glad.lib",
		"stb_image.lib",
		"lmm",
		"Dear ImGui",
	}

	defines {
		"LGE_BUILD_DLL",
	}

	-- - Something wrong with the "postbuildcommands" in Engine 
	--postbuildcommands {
	--	("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox Game/")
	--}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "LGE_DEBUG"
		symbols "on"
		runtime "Debug"

	filter "configurations:Release"
		defines "LGE_RELEASE"
		optimize "on"
		runtime "Release"

	filter "configurations:Dist"
		defines "LGE_DIST"
		optimize "on"
		runtime "Release"

project "Sandbox Game"
	location "Sandbox Game"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++14"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/**.h",
		"%{prj.name}/**.hpp",
		"%{prj.name}/**.inl",
		"%{prj.name}/**.cpp",
	}

	includedirs {
		"Libraries/include",
		"Engine",
		"Dear ImGui",
	}

	libdirs {
		"Libraries/lib",
	}

	links {
		"Engine",
		"Dear ImGui",
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "LGE_DEBUG"
		symbols "on"
		runtime "Debug"

	filter "configurations:Release"
		defines "LGE_RELEASE"
		optimize "on"
		runtime "Release"

	filter "configurations:Dist"
		defines "LGE_DIST"
		optimize "on"
		runtime "Release"

project "lmm"
	location "lmm"
	kind "StaticLib"
	language "C++"
	staticruntime "on"
	cppdialect "C++14"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/**.h",
		"%{prj.name}/**.c",
		"%{prj.name}/**.hpp",
		"%{prj.name}/**.inl",
		"%{prj.name}/**.cpp",
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "LMM_DEBUG"
		symbols "on"
		runtime "Debug"

	filter "configurations:Release"
		defines "LMM_RELEASE"
		optimize "on"
		runtime "Release"

	filter "configurations:Dist"
		defines "LMM_DIST"
		optimize "on"
		runtime "Release"

project "Dear ImGui"
	location "Dear ImGui"
	kind "StaticLib"
	language "C++"
	cppdialect "C++14"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	includedirs {
		"Libraries/include",
	}

	libdirs {
		"Libraries/lib",
	}

	links {
		"glfw3_mt.lib",
	}

	files {
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp",
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "IMGUI_DEBUG"
		symbols "on"
		runtime "Debug"

	filter "configurations:Release"
		defines "IMGUI_RELEASE"
		optimize "on"
		runtime "Release"

	filter "configurations:Dist"
		defines "IMGUI_DIST"
		optimize "on"
		runtime "Release"

-- premake5.lua
workspace "Sunflower2D"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "App"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "Sunflower-Core"
	include "Sunflower-Core/Build-Sunflower-Core.lua"
group ""

include "App/Build-App.lua"
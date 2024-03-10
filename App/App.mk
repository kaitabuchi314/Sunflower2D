##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=App
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=D:/Desktop/Sunflower2D
ProjectPath            :=D:/Desktop/Sunflower2D/App
IntermediateDirectory  :=../Binaries/Intermediates/windows-x86_64/Debug/App
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=kaida
Date                   :=3/10/2024
CodeLitePath           :="D:/Program Files/CodeLite"
LinkerName             :=clang++
SharedObjectLinkerName :=clang++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=../Binaries/windows-x86_64/Debug/App
OutputFile             :=../Binaries/windows-x86_64/Debug/App/App.exe
Preprocessors          :=$(PreprocessorSwitch)WINDOWS $(PreprocessorSwitch)DEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="App.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  -m64 ../Binaries/windows-x86_64/Debug/Sunflower-Core/Sunflower-Core.lib
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)Source $(IncludeSwitch)ImGui $(IncludeSwitch)../Sunflower-Core/Source $(IncludeSwitch)../Sunflower-Core/SDL2/include $(IncludeSwitch)../Sunflower-Extras/Source 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := ar rcus
CXX      := clang++
CC       := clang
CXXFLAGS :=  -m64 -g -std=c++20 /EHsc /Zc:preprocessor /Zc:__cplusplus $(Preprocessors)
CFLAGS   :=  -m64 -g /EHsc /Zc:preprocessor /Zc:__cplusplus $(Preprocessors)
ASFLAGS  := 
AS       := llvm-as


##
## User defined environment variables
##
CodeLiteDir:=D:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/ImGui_imgui_widgets.cpp$(ObjectSuffix) $(IntermediateDirectory)/ImGui_imgui_tables.cpp$(ObjectSuffix) $(IntermediateDirectory)/ImGui_imgui_draw.cpp$(ObjectSuffix) $(IntermediateDirectory)/ImGui_imgui_demo.cpp$(ObjectSuffix) $(IntermediateDirectory)/ImGui_imgui_impl_sdlrenderer2.cpp$(ObjectSuffix) $(IntermediateDirectory)/Source_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/ImGui_imgui_impl_sdl2.cpp$(ObjectSuffix) $(IntermediateDirectory)/ImGui_imgui.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d "..\.build-debug\Sunflower-Core" $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

"..\.build-debug\Sunflower-Core":
	@$(MakeDirCommand) "..\.build-debug"
	@echo stam > "..\.build-debug\Sunflower-Core"




MakeIntermediateDirs:
	@$(MakeDirCommand) "../Binaries/Intermediates/windows-x86_64/Debug/App"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "../Binaries/Intermediates/windows-x86_64/Debug/App"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/ImGui_imgui_widgets.cpp$(ObjectSuffix): ImGui/imgui_widgets.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Desktop/Sunflower2D/App/ImGui/imgui_widgets.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ImGui_imgui_widgets.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ImGui_imgui_widgets.cpp$(PreprocessSuffix): ImGui/imgui_widgets.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ImGui_imgui_widgets.cpp$(PreprocessSuffix) ImGui/imgui_widgets.cpp

$(IntermediateDirectory)/ImGui_imgui_tables.cpp$(ObjectSuffix): ImGui/imgui_tables.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Desktop/Sunflower2D/App/ImGui/imgui_tables.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ImGui_imgui_tables.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ImGui_imgui_tables.cpp$(PreprocessSuffix): ImGui/imgui_tables.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ImGui_imgui_tables.cpp$(PreprocessSuffix) ImGui/imgui_tables.cpp

$(IntermediateDirectory)/ImGui_imgui_draw.cpp$(ObjectSuffix): ImGui/imgui_draw.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Desktop/Sunflower2D/App/ImGui/imgui_draw.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ImGui_imgui_draw.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ImGui_imgui_draw.cpp$(PreprocessSuffix): ImGui/imgui_draw.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ImGui_imgui_draw.cpp$(PreprocessSuffix) ImGui/imgui_draw.cpp

$(IntermediateDirectory)/ImGui_imgui_demo.cpp$(ObjectSuffix): ImGui/imgui_demo.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Desktop/Sunflower2D/App/ImGui/imgui_demo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ImGui_imgui_demo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ImGui_imgui_demo.cpp$(PreprocessSuffix): ImGui/imgui_demo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ImGui_imgui_demo.cpp$(PreprocessSuffix) ImGui/imgui_demo.cpp

$(IntermediateDirectory)/ImGui_imgui_impl_sdlrenderer2.cpp$(ObjectSuffix): ImGui/imgui_impl_sdlrenderer2.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Desktop/Sunflower2D/App/ImGui/imgui_impl_sdlrenderer2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ImGui_imgui_impl_sdlrenderer2.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ImGui_imgui_impl_sdlrenderer2.cpp$(PreprocessSuffix): ImGui/imgui_impl_sdlrenderer2.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ImGui_imgui_impl_sdlrenderer2.cpp$(PreprocessSuffix) ImGui/imgui_impl_sdlrenderer2.cpp

$(IntermediateDirectory)/Source_main.cpp$(ObjectSuffix): Source/main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Desktop/Sunflower2D/App/Source/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Source_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Source_main.cpp$(PreprocessSuffix): Source/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Source_main.cpp$(PreprocessSuffix) Source/main.cpp

$(IntermediateDirectory)/ImGui_imgui_impl_sdl2.cpp$(ObjectSuffix): ImGui/imgui_impl_sdl2.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Desktop/Sunflower2D/App/ImGui/imgui_impl_sdl2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ImGui_imgui_impl_sdl2.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ImGui_imgui_impl_sdl2.cpp$(PreprocessSuffix): ImGui/imgui_impl_sdl2.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ImGui_imgui_impl_sdl2.cpp$(PreprocessSuffix) ImGui/imgui_impl_sdl2.cpp

$(IntermediateDirectory)/ImGui_imgui.cpp$(ObjectSuffix): ImGui/imgui.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Desktop/Sunflower2D/App/ImGui/imgui.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ImGui_imgui.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ImGui_imgui.cpp$(PreprocessSuffix): ImGui/imgui.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ImGui_imgui.cpp$(PreprocessSuffix) ImGui/imgui.cpp

##
## Clean
##
clean:
	$(RM) -r ../Binaries/Intermediates/windows-x86_64/Debug/App/



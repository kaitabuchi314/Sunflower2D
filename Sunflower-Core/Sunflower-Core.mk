##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Sunflower-Core
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=D:/Desktop/Sunflower2D
ProjectPath            :=D:/Desktop/Sunflower2D/Sunflower-Core
IntermediateDirectory  :=../Binaries/Intermediates/windows-x86_64/Debug/Sunflower-Core
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
OutputDirectory        :=../Binaries/windows-x86_64/Debug/Sunflower-Core
OutputFile             :=../Binaries/windows-x86_64/Debug/Sunflower-Core/Sunflower-Core.lib
Preprocessors          :=$(PreprocessorSwitch)DEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="Sunflower-Core.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  -m64 -lSDL.lib -lSDL_test.lib -lSDL_main.lib -lSDL_image.lib
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)Source $(IncludeSwitch)SDL2/include $(IncludeSwitch)../TestProject/Source 
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
Objects0=$(IntermediateDirectory)/Source_Core_Mouse.cpp$(ObjectSuffix) $(IntermediateDirectory)/Source_Core_GraphicsManager.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList)
	@$(MakeDirCommand) "D:\Desktop\Sunflower2D/.build-debug"
	@echo rebuilt > "D:\Desktop\Sunflower2D/.build-debug/Sunflower-Core"

MakeIntermediateDirs:
	@$(MakeDirCommand) "../Binaries/Intermediates/windows-x86_64/Debug/Sunflower-Core"


../Binaries/Intermediates/windows-x86_64/Debug/Sunflower-Core:
	@$(MakeDirCommand) "../Binaries/Intermediates/windows-x86_64/Debug/Sunflower-Core"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Source_Core_Mouse.cpp$(ObjectSuffix): Source/Core/Mouse.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Desktop/Sunflower2D/Sunflower-Core/Source/Core/Mouse.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Source_Core_Mouse.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Source_Core_Mouse.cpp$(PreprocessSuffix): Source/Core/Mouse.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Source_Core_Mouse.cpp$(PreprocessSuffix) Source/Core/Mouse.cpp

$(IntermediateDirectory)/Source_Core_GraphicsManager.cpp$(ObjectSuffix): Source/Core/GraphicsManager.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Desktop/Sunflower2D/Sunflower-Core/Source/Core/GraphicsManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Source_Core_GraphicsManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Source_Core_GraphicsManager.cpp$(PreprocessSuffix): Source/Core/GraphicsManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Source_Core_GraphicsManager.cpp$(PreprocessSuffix) Source/Core/GraphicsManager.cpp

##
## Clean
##
clean:
	$(RM) -r ../Binaries/Intermediates/windows-x86_64/Debug/Sunflower-Core/



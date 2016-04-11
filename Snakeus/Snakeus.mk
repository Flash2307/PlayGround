##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Snakeus
ConfigurationName      :=Debug
WorkspacePath          :=/home/gabriel/Prod/Programmation/PlayGround
ProjectPath            :=/home/gabriel/Prod/Programmation/PlayGround/Snakeus
IntermediateDirectory  :=./../bin/Snakeus/Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=gabriel
Date                   :=04/04/16
CodeLitePath           :=/home/gabriel/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Snakeus.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)./../OS/src 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)sfml-graphics $(LibrarySwitch)sfml-window $(LibrarySwitch)sfml-system 
ArLibs                 :=  "sfml-graphics" "sfml-window" "sfml-system" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall --std=c++14 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/Snakeus_CollisionGrid.cpp$(ObjectSuffix) $(IntermediateDirectory)/Snakeus_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Snakeus_Line.cpp$(ObjectSuffix) $(IntermediateDirectory)/Snakeus_Game.cpp$(ObjectSuffix) $(IntermediateDirectory)/Snakeus_SystemInput.cpp$(ObjectSuffix) $(IntermediateDirectory)/Snakeus_Player.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

PostBuild:
	@echo Executing Post Build commands ...
	cp ./../bin/Snakeus/Debug/Snakeus ./../games/Snakeus/game
	@echo Done

MakeIntermediateDirs:
	@test -d ./../bin/Snakeus/Debug || $(MakeDirCommand) ./../bin/Snakeus/Debug


$(IntermediateDirectory)/.d:
	@test -d ./../bin/Snakeus/Debug || $(MakeDirCommand) ./../bin/Snakeus/Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Snakeus_CollisionGrid.cpp$(ObjectSuffix): Snakeus/CollisionGrid.cpp $(IntermediateDirectory)/Snakeus_CollisionGrid.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gabriel/Prod/Programmation/PlayGround/Snakeus/Snakeus/CollisionGrid.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Snakeus_CollisionGrid.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Snakeus_CollisionGrid.cpp$(DependSuffix): Snakeus/CollisionGrid.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Snakeus_CollisionGrid.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Snakeus_CollisionGrid.cpp$(DependSuffix) -MM "Snakeus/CollisionGrid.cpp"

$(IntermediateDirectory)/Snakeus_CollisionGrid.cpp$(PreprocessSuffix): Snakeus/CollisionGrid.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Snakeus_CollisionGrid.cpp$(PreprocessSuffix) "Snakeus/CollisionGrid.cpp"

$(IntermediateDirectory)/Snakeus_main.cpp$(ObjectSuffix): Snakeus/main.cpp $(IntermediateDirectory)/Snakeus_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gabriel/Prod/Programmation/PlayGround/Snakeus/Snakeus/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Snakeus_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Snakeus_main.cpp$(DependSuffix): Snakeus/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Snakeus_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Snakeus_main.cpp$(DependSuffix) -MM "Snakeus/main.cpp"

$(IntermediateDirectory)/Snakeus_main.cpp$(PreprocessSuffix): Snakeus/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Snakeus_main.cpp$(PreprocessSuffix) "Snakeus/main.cpp"

$(IntermediateDirectory)/Snakeus_Line.cpp$(ObjectSuffix): Snakeus/Line.cpp $(IntermediateDirectory)/Snakeus_Line.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gabriel/Prod/Programmation/PlayGround/Snakeus/Snakeus/Line.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Snakeus_Line.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Snakeus_Line.cpp$(DependSuffix): Snakeus/Line.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Snakeus_Line.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Snakeus_Line.cpp$(DependSuffix) -MM "Snakeus/Line.cpp"

$(IntermediateDirectory)/Snakeus_Line.cpp$(PreprocessSuffix): Snakeus/Line.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Snakeus_Line.cpp$(PreprocessSuffix) "Snakeus/Line.cpp"

$(IntermediateDirectory)/Snakeus_Game.cpp$(ObjectSuffix): Snakeus/Game.cpp $(IntermediateDirectory)/Snakeus_Game.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gabriel/Prod/Programmation/PlayGround/Snakeus/Snakeus/Game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Snakeus_Game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Snakeus_Game.cpp$(DependSuffix): Snakeus/Game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Snakeus_Game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Snakeus_Game.cpp$(DependSuffix) -MM "Snakeus/Game.cpp"

$(IntermediateDirectory)/Snakeus_Game.cpp$(PreprocessSuffix): Snakeus/Game.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Snakeus_Game.cpp$(PreprocessSuffix) "Snakeus/Game.cpp"

$(IntermediateDirectory)/Snakeus_SystemInput.cpp$(ObjectSuffix): Snakeus/SystemInput.cpp $(IntermediateDirectory)/Snakeus_SystemInput.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gabriel/Prod/Programmation/PlayGround/Snakeus/Snakeus/SystemInput.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Snakeus_SystemInput.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Snakeus_SystemInput.cpp$(DependSuffix): Snakeus/SystemInput.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Snakeus_SystemInput.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Snakeus_SystemInput.cpp$(DependSuffix) -MM "Snakeus/SystemInput.cpp"

$(IntermediateDirectory)/Snakeus_SystemInput.cpp$(PreprocessSuffix): Snakeus/SystemInput.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Snakeus_SystemInput.cpp$(PreprocessSuffix) "Snakeus/SystemInput.cpp"

$(IntermediateDirectory)/Snakeus_Player.cpp$(ObjectSuffix): Snakeus/Player.cpp $(IntermediateDirectory)/Snakeus_Player.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/gabriel/Prod/Programmation/PlayGround/Snakeus/Snakeus/Player.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Snakeus_Player.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Snakeus_Player.cpp$(DependSuffix): Snakeus/Player.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Snakeus_Player.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Snakeus_Player.cpp$(DependSuffix) -MM "Snakeus/Player.cpp"

$(IntermediateDirectory)/Snakeus_Player.cpp$(PreprocessSuffix): Snakeus/Player.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Snakeus_Player.cpp$(PreprocessSuffix) "Snakeus/Player.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./../bin/Snakeus/Debug/



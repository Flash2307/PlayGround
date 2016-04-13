##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=DameUs
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\Benjamin\Documents\PlayGround\games\DameUs\DameUs\DameUs"
ProjectPath            := "C:\Users\Benjamin\Documents\PlayGround\games\DameUs\DameUs\DameUs"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Benjamin
Date                   :=12/04/2016
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
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
ObjectsFileList        :="DameUs.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  -O0
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch). $(LibraryPathSwitch)Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -Wall $(Preprocessors)
CFLAGS   :=   $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/BlackChip.cpp$(ObjectSuffix) $(IntermediateDirectory)/BlackChipKing.cpp$(ObjectSuffix) $(IntermediateDirectory)/Board.cpp$(ObjectSuffix) $(IntermediateDirectory)/DeadChipBuffer.cpp$(ObjectSuffix) $(IntermediateDirectory)/GameControls.cpp$(ObjectSuffix) $(IntermediateDirectory)/GameInfo.cpp$(ObjectSuffix) $(IntermediateDirectory)/GamePadControls.cpp$(ObjectSuffix) $(IntermediateDirectory)/Highlight.cpp$(ObjectSuffix) $(IntermediateDirectory)/KeyboardControlsPlayer1.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/main_game.cpp$(ObjectSuffix) $(IntermediateDirectory)/main_menu.cpp$(ObjectSuffix) $(IntermediateDirectory)/Move.cpp$(ObjectSuffix) $(IntermediateDirectory)/RedChip.cpp$(ObjectSuffix) $(IntermediateDirectory)/RedChipKing.cpp$(ObjectSuffix) $(IntermediateDirectory)/SystemInput.cpp$(ObjectSuffix) $(IntermediateDirectory)/TurnState.cpp$(ObjectSuffix) 



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

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/BlackChip.cpp$(ObjectSuffix): BlackChip.cpp $(IntermediateDirectory)/BlackChip.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Benjamin/Documents/PlayGround/games/DameUs/DameUs/DameUs/BlackChip.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BlackChip.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BlackChip.cpp$(DependSuffix): BlackChip.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BlackChip.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BlackChip.cpp$(DependSuffix) -MM "BlackChip.cpp"

$(IntermediateDirectory)/BlackChip.cpp$(PreprocessSuffix): BlackChip.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BlackChip.cpp$(PreprocessSuffix) "BlackChip.cpp"

$(IntermediateDirectory)/BlackChipKing.cpp$(ObjectSuffix): BlackChipKing.cpp $(IntermediateDirectory)/BlackChipKing.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Benjamin/Documents/PlayGround/games/DameUs/DameUs/DameUs/BlackChipKing.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BlackChipKing.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BlackChipKing.cpp$(DependSuffix): BlackChipKing.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BlackChipKing.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BlackChipKing.cpp$(DependSuffix) -MM "BlackChipKing.cpp"

$(IntermediateDirectory)/BlackChipKing.cpp$(PreprocessSuffix): BlackChipKing.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BlackChipKing.cpp$(PreprocessSuffix) "BlackChipKing.cpp"

$(IntermediateDirectory)/Board.cpp$(ObjectSuffix): Board.cpp $(IntermediateDirectory)/Board.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Benjamin/Documents/PlayGround/games/DameUs/DameUs/DameUs/Board.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Board.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Board.cpp$(DependSuffix): Board.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Board.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Board.cpp$(DependSuffix) -MM "Board.cpp"

$(IntermediateDirectory)/Board.cpp$(PreprocessSuffix): Board.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Board.cpp$(PreprocessSuffix) "Board.cpp"

$(IntermediateDirectory)/DeadChipBuffer.cpp$(ObjectSuffix): DeadChipBuffer.cpp $(IntermediateDirectory)/DeadChipBuffer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Benjamin/Documents/PlayGround/games/DameUs/DameUs/DameUs/DeadChipBuffer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DeadChipBuffer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DeadChipBuffer.cpp$(DependSuffix): DeadChipBuffer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DeadChipBuffer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/DeadChipBuffer.cpp$(DependSuffix) -MM "DeadChipBuffer.cpp"

$(IntermediateDirectory)/DeadChipBuffer.cpp$(PreprocessSuffix): DeadChipBuffer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DeadChipBuffer.cpp$(PreprocessSuffix) "DeadChipBuffer.cpp"

$(IntermediateDirectory)/GameControls.cpp$(ObjectSuffix): GameControls.cpp $(IntermediateDirectory)/GameControls.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Benjamin/Documents/PlayGround/games/DameUs/DameUs/DameUs/GameControls.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GameControls.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GameControls.cpp$(DependSuffix): GameControls.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GameControls.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GameControls.cpp$(DependSuffix) -MM "GameControls.cpp"

$(IntermediateDirectory)/GameControls.cpp$(PreprocessSuffix): GameControls.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GameControls.cpp$(PreprocessSuffix) "GameControls.cpp"

$(IntermediateDirectory)/GameInfo.cpp$(ObjectSuffix): GameInfo.cpp $(IntermediateDirectory)/GameInfo.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Benjamin/Documents/PlayGround/games/DameUs/DameUs/DameUs/GameInfo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GameInfo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GameInfo.cpp$(DependSuffix): GameInfo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GameInfo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GameInfo.cpp$(DependSuffix) -MM "GameInfo.cpp"

$(IntermediateDirectory)/GameInfo.cpp$(PreprocessSuffix): GameInfo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GameInfo.cpp$(PreprocessSuffix) "GameInfo.cpp"

$(IntermediateDirectory)/GamePadControls.cpp$(ObjectSuffix): GamePadControls.cpp $(IntermediateDirectory)/GamePadControls.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Benjamin/Documents/PlayGround/games/DameUs/DameUs/DameUs/GamePadControls.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GamePadControls.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GamePadControls.cpp$(DependSuffix): GamePadControls.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GamePadControls.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GamePadControls.cpp$(DependSuffix) -MM "GamePadControls.cpp"

$(IntermediateDirectory)/GamePadControls.cpp$(PreprocessSuffix): GamePadControls.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GamePadControls.cpp$(PreprocessSuffix) "GamePadControls.cpp"

$(IntermediateDirectory)/Highlight.cpp$(ObjectSuffix): Highlight.cpp $(IntermediateDirectory)/Highlight.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Benjamin/Documents/PlayGround/games/DameUs/DameUs/DameUs/Highlight.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Highlight.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Highlight.cpp$(DependSuffix): Highlight.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Highlight.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Highlight.cpp$(DependSuffix) -MM "Highlight.cpp"

$(IntermediateDirectory)/Highlight.cpp$(PreprocessSuffix): Highlight.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Highlight.cpp$(PreprocessSuffix) "Highlight.cpp"

$(IntermediateDirectory)/KeyboardControlsPlayer1.cpp$(ObjectSuffix): KeyboardControlsPlayer1.cpp $(IntermediateDirectory)/KeyboardControlsPlayer1.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Benjamin/Documents/PlayGround/games/DameUs/DameUs/DameUs/KeyboardControlsPlayer1.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/KeyboardControlsPlayer1.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/KeyboardControlsPlayer1.cpp$(DependSuffix): KeyboardControlsPlayer1.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/KeyboardControlsPlayer1.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/KeyboardControlsPlayer1.cpp$(DependSuffix) -MM "KeyboardControlsPlayer1.cpp"

$(IntermediateDirectory)/KeyboardControlsPlayer1.cpp$(PreprocessSuffix): KeyboardControlsPlayer1.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/KeyboardControlsPlayer1.cpp$(PreprocessSuffix) "KeyboardControlsPlayer1.cpp"

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Benjamin/Documents/PlayGround/games/DameUs/DameUs/DameUs/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/main_game.cpp$(ObjectSuffix): main_game.cpp $(IntermediateDirectory)/main_game.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Benjamin/Documents/PlayGround/games/DameUs/DameUs/DameUs/main_game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main_game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main_game.cpp$(DependSuffix): main_game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main_game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main_game.cpp$(DependSuffix) -MM "main_game.cpp"

$(IntermediateDirectory)/main_game.cpp$(PreprocessSuffix): main_game.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main_game.cpp$(PreprocessSuffix) "main_game.cpp"

$(IntermediateDirectory)/main_menu.cpp$(ObjectSuffix): main_menu.cpp $(IntermediateDirectory)/main_menu.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Benjamin/Documents/PlayGround/games/DameUs/DameUs/DameUs/main_menu.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main_menu.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main_menu.cpp$(DependSuffix): main_menu.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main_menu.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main_menu.cpp$(DependSuffix) -MM "main_menu.cpp"

$(IntermediateDirectory)/main_menu.cpp$(PreprocessSuffix): main_menu.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main_menu.cpp$(PreprocessSuffix) "main_menu.cpp"

$(IntermediateDirectory)/Move.cpp$(ObjectSuffix): Move.cpp $(IntermediateDirectory)/Move.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Benjamin/Documents/PlayGround/games/DameUs/DameUs/DameUs/Move.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Move.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Move.cpp$(DependSuffix): Move.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Move.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Move.cpp$(DependSuffix) -MM "Move.cpp"

$(IntermediateDirectory)/Move.cpp$(PreprocessSuffix): Move.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Move.cpp$(PreprocessSuffix) "Move.cpp"

$(IntermediateDirectory)/RedChip.cpp$(ObjectSuffix): RedChip.cpp $(IntermediateDirectory)/RedChip.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Benjamin/Documents/PlayGround/games/DameUs/DameUs/DameUs/RedChip.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RedChip.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RedChip.cpp$(DependSuffix): RedChip.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RedChip.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/RedChip.cpp$(DependSuffix) -MM "RedChip.cpp"

$(IntermediateDirectory)/RedChip.cpp$(PreprocessSuffix): RedChip.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RedChip.cpp$(PreprocessSuffix) "RedChip.cpp"

$(IntermediateDirectory)/RedChipKing.cpp$(ObjectSuffix): RedChipKing.cpp $(IntermediateDirectory)/RedChipKing.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Benjamin/Documents/PlayGround/games/DameUs/DameUs/DameUs/RedChipKing.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RedChipKing.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RedChipKing.cpp$(DependSuffix): RedChipKing.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RedChipKing.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/RedChipKing.cpp$(DependSuffix) -MM "RedChipKing.cpp"

$(IntermediateDirectory)/RedChipKing.cpp$(PreprocessSuffix): RedChipKing.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RedChipKing.cpp$(PreprocessSuffix) "RedChipKing.cpp"

$(IntermediateDirectory)/SystemInput.cpp$(ObjectSuffix): SystemInput.cpp $(IntermediateDirectory)/SystemInput.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Benjamin/Documents/PlayGround/games/DameUs/DameUs/DameUs/SystemInput.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SystemInput.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SystemInput.cpp$(DependSuffix): SystemInput.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SystemInput.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SystemInput.cpp$(DependSuffix) -MM "SystemInput.cpp"

$(IntermediateDirectory)/SystemInput.cpp$(PreprocessSuffix): SystemInput.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SystemInput.cpp$(PreprocessSuffix) "SystemInput.cpp"

$(IntermediateDirectory)/TurnState.cpp$(ObjectSuffix): TurnState.cpp $(IntermediateDirectory)/TurnState.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Benjamin/Documents/PlayGround/games/DameUs/DameUs/DameUs/TurnState.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TurnState.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TurnState.cpp$(DependSuffix): TurnState.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TurnState.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TurnState.cpp$(DependSuffix) -MM "TurnState.cpp"

$(IntermediateDirectory)/TurnState.cpp$(PreprocessSuffix): TurnState.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TurnState.cpp$(PreprocessSuffix) "TurnState.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/



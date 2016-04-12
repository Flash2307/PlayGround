#pragma once
#include "GameControls.h"
#include "Highlight.h"
#include "GameInfo.h"

class Chip;
class Board
{
public:
	Board();
	~Board();
	void initializeBoard(sf::RenderWindow* window);
	void load();
	Entity* getTexture();
	void addRedChip(int, int, Chip*);
	void addBlackChip(int, int, Chip*);
	void renderBoard(sf::RenderWindow* window);
	void setStartOfTurnHighlight();
	Chip* getRedChip(int j, int i);
	Chip* getBlackChip(int j, int i);
	void setHighlight(int j, int i);
	void removeAllHighlight();
	void removePreviousHighlight();
	void removeHighlight(int j, int i);
	void removeChip(int j, int i);
	void navigateRedChips();
	void navigateBlackChips();
	void navigateChips(Chip* chips[][8], Controls* controls);
	void chooseChip(Chip*[][8]);
	void unChooseChips(Chip* chips[][8], bool forceUnselection);
	bool hasNothing(int j, int i);
	bool hasRedChip(int j, int i);
	bool hasBlackChip(int j, int i);
	bool coordinatesExist(int j, int i);
	Chip* getSelectedChip();

private:
	Entity* texture;
	Chip* redChips[8][8];
	Chip* blackChips[8][8];
	Highlight* highlights[8][8];
};


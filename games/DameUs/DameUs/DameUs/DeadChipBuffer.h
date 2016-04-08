#pragma once

class Chip;

class DeadChipBuffer
{
public:
	static DeadChipBuffer* getInstance();
	~DeadChipBuffer();
	void addChipToBuffer(Chip*);
	void clearBuffer();
	int getBufferCount();

private:
	static DeadChipBuffer* instance;
	DeadChipBuffer();
	Chip* buffer[12];
	int index;
};



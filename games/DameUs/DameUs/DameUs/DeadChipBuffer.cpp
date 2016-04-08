#include "DeadChipBuffer.h"
#include "Chip.h"

DeadChipBuffer* DeadChipBuffer::instance = nullptr;
DeadChipBuffer::DeadChipBuffer()
{
	this->index = 0;
	for (int i = 0; i < 12; i++)
	{
		this->buffer[i] = nullptr;
	}
}

DeadChipBuffer* DeadChipBuffer::getInstance()
{
	if (DeadChipBuffer::instance == nullptr)
	{
		DeadChipBuffer::instance = new DeadChipBuffer();
	}
	return DeadChipBuffer::instance;

}

DeadChipBuffer::~DeadChipBuffer()
{
	delete this->instance;
}

void DeadChipBuffer::addChipToBuffer(Chip* chip)
{
	this->buffer[index++] = chip;
}

void DeadChipBuffer::clearBuffer()
{
	for (int i = 0; i < 12; i++)
	{
		this->buffer[i] = nullptr;
	}
	index = 0;
}

int DeadChipBuffer::getBufferCount()
{
	return this->index + 1;
}



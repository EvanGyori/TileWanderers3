#pragma once

#include "Chunk.h"

class AbandonedTownChunk : public Chunk
{
public:
	AbandonedTownChunk();
	AbandonedTownChunk(const Chunk&);
	
	Chunk* clone() const;

	const char* getName() const;
};

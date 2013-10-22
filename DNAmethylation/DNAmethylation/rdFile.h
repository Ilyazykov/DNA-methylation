#pragma once
#include "csvFile.h"

class rdFile
{
public:
	rdFile(void);
	~rdFile(void);

	csvFile convertToCsv();
};
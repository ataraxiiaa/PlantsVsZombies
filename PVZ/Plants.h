#pragma once

#ifndef Plants_H
#define Plants_H 

#include "Entity.h" // Include necessary header files
class Plants : public Entity
{
protected:
	float CoolDown; // Cool down between plants being used after one is placed
	int Cost; // Cost for buying plants
public:

};



#endif // PLants_H
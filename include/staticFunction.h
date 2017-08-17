/*
 * staticFunction.h
 *
 *  Created on: 18 мая 2017 г.
 *      Author: root
 */

#ifndef EXTLIBRARY_STATICFUNCTION_H_
#define EXTLIBRARY_STATICFUNCTION_H_

#include "stdlibrary.h"
#include "extlibrary.h"
#include "structures.h"

namespace staticfunction{
jsonMessage parseJsonString(std::string);

configObject parseConfigurationFile(std::string);
int parseArguments(configObject*, int, char**);
void printStringVectorArr(std::vector<std::string>);

std::string generateRandomHexString(long long _length);

}
#endif /* EXTLIBRARY_STATICFUNCTION_H_ */

#ifndef _OBJECT_DATA_PTR_H_
#define _OBJECT_DATA_PTR_H_

#include <memory>

struct ObjectData;

using ObjectDataPtr = std::shared_ptr< ObjectData >;

#endif
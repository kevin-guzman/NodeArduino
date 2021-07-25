#include <Arduino_JSON.h>
#ifndef jsonobject.h
#define jsonobject.h

void setupObject(JSONVar node);
void setMetric(String type, int value, String unity);
String getMessage();

#endif
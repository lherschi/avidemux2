// automatically generated by admSerialization.py, do not edit!
#include "ADM_default.h"
#include "ADM_paramList.h"
#include "ADM_coreJson.h"
#include "blur.h"
bool  blur_jserialize(const char *file, const blur *key){
admJson json;
json.addUint32("algorithm",key->algorithm);
json.addUint32("radius",key->radius);
return json.dumpToFile(file);
};
bool  blur_jdeserialize(const char *file, const ADM_paramList *tmpl,blur *key){
admJsonToCouple json;
CONFcouple *c=json.readFromFile(file);
if(!c) {ADM_error("Cannot read json file");return false;}
bool r= ADM_paramLoadPartial(c,tmpl,key);
delete c;
return r;
};
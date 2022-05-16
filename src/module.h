#include <boron/urlan.h>
#include "cdi.h"

struct StringTable;

typedef struct
{
    UBuffer entries;        // Master CDIEntry array
    UBuffer fileIndex;      // Master FNAM index into entries
    UBuffer modulePaths;    // Layer file names
    uint16_t pathCount;
    uint16_t pathIndex[5];  // Layer index into modulePaths
}
Module;

enum ModuleCategory
{
    MOD_UNKNOWN,
    MOD_FILE_PACKAGE,
    MOD_BASE,
    MOD_EXTENSION,
    MOD_SOUNDTRACK
};

// Order matches modi context in pack-xu4.b.
enum ModInfoValues
{
    MI_ABOUT,
    MI_AUTHOR,
    MI_RULES,
    MI_VERSION,

    MI_COUNT
};

#ifdef __cplusplus
extern "C" {
#endif

void            mod_init(Module*, int layers);
void            mod_free(Module*);
const char*     mod_addLayer(Module*, const char* filename,
                         const char* version,
                         const char* (*config)(FILE*, const CDIEntry*, void*),
                         void* user);
const char*     mod_path(const Module*, const CDIEntry* ent);
const CDIEntry* mod_findAppId(const Module*, uint32_t id);
const CDIEntry* mod_fileEntry(const Module*, const char* filename);

int             mod_query(const char* filename, StringTable* modi);

#ifdef __cplusplus
}
#endif

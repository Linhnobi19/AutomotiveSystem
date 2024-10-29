#ifndef HOMELIB_GLOBAL_H
#define HOMELIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(HOMELIB_LIBRARY)
#define HOMELIB_EXPORT Q_DECL_EXPORT
#else
#define HOMELIB_EXPORT Q_DECL_IMPORT
#endif

#endif // HOMELIB_GLOBAL_H

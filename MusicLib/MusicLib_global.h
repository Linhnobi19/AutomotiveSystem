#ifndef MUSICLIB_GLOBAL_H
#define MUSICLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MUSICLIB_LIBRARY)
#  define MUSICLIB_EXPORT Q_DECL_EXPORT
#else
#  define MUSICLIB_EXPORT Q_DECL_IMPORT
#endif

#endif // MUSICLIB_GLOBAL_H

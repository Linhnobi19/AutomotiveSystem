#ifndef VIDEOLIB_GLOBAL_H
#define VIDEOLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(VIDEOLIB_LIBRARY)
#define VIDEOLIB_EXPORT Q_DECL_EXPORT
#else
#define VIDEOLIB_EXPORT Q_DECL_IMPORT
#endif

#endif // VIDEOLIB_GLOBAL_H

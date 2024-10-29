#ifndef SETTINGLIB_GLOBAL_H
#define SETTINGLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SETTINGLIB_LIBRARY)
#define SETTINGLIB_EXPORT Q_DECL_EXPORT
#else
#define SETTINGLIB_EXPORT Q_DECL_IMPORT
#endif

#endif // SETTINGLIB_GLOBAL_H

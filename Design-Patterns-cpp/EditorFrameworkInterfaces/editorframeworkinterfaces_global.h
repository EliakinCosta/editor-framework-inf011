#ifndef EDITORFRAMEWORKINTERFACES_GLOBAL_H
#define EDITORFRAMEWORKINTERFACES_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(EDITORFRAMEWORKINTERFACES_LIBRARY)
#  define EDITORFRAMEWORKINTERFACESSHARED_EXPORT Q_DECL_EXPORT
#else
#  define EDITORFRAMEWORKINTERFACESSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // EDITORFRAMEWORKINTERFACES_GLOBAL_H
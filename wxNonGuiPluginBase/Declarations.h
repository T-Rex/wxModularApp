#ifndef _DECLARATIONS_H
#define _DECLARATIONS_H

#if defined(__WXMSW__)
#ifdef DEMO_PLUGIN_EXPORTS
#define DEMO_API __declspec(dllexport)
#else
#define DEMO_API __declspec(dllimport)
#endif
#else
#define DEMO_API
#endif

#endif // _DECLARATIONS_H

// 19 april 2019

#ifdef __cplusplus
extern "C" {
#endif

// init.c
extern const char **uiprivSysInitErrors(void);
extern int uiprivSysInit(void *options, uiInitError *err);
extern int uiprivInitReturnError(uiInitError *err, const char *msg);
extern int uiprivInitReturnErrorf(uiInitError *err, const char *msg, ...);

// alloc.c
extern void *uiprivAlloc(size_t n, const char *what);
extern void *uiprivRealloc(void *p, size_t old, size_t new, const char *what);
extern void uiprivFree(void *p);

// errors.c
extern void uiprivInternalError(const char *fmt, ...);
enum {
	uiprivProgrammerErrorWrongStructSize,		// arguments: size_t badSize, const char *structName
	uiprivProgrammerErrorIndexOutOfRange,	// arguments: int badIndex, __func__
	uiprivProgrammerErrorNullPointer,			// arguments: const char *paramDesc, __func__
	uiprivProgrammerErrorIntIDNotFound,		// arguments: const char *idDesc, int badID, __func__
	// TODO type mismatch
	uiprivProgrammerErrorBadSenderForEvent,	// arguments: const char *senderDesc, const char *eventDesc, __func__
	uiprivProgrammerErrorChangingEventDuringFire,		// arguments: __func__
	uiprivProgrammerErrorRecursiveEventFire,	// no arguments
	uiprivNumProgrammerErrors,
};
extern void uiprivProgrammerError(unsigned int which, ...);
extern void uiprivReportError(const char *prefix, const char *msg, const char *suffix, bool internal);

#ifdef __cplusplus
}
#endif

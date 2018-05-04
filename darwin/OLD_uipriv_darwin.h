// util.m
extern void disableAutocorrect(NSTextView *);

// entry.m
extern void finishNewTextField(NSTextField *, BOOL);
extern NSTextField *newEditableTextField(void);

// window.m
@interface libuiNSWindow : NSWindow
- (void)libui_doMove:(NSEvent *)initialEvent;
- (void)libui_doResize:(NSEvent *)initialEvent on:(uiWindowResizeEdge)edge;
@end
extern uiWindow *windowFromNSWindow(NSWindow *);

// alloc.m
extern NSMutableArray *delegates;
extern void initAlloc(void);
extern void uninitAlloc(void);

// autolayout.m
extern NSLayoutConstraint *mkConstraint(id view1, NSLayoutAttribute attr1, NSLayoutRelation relation, id view2, NSLayoutAttribute attr2, CGFloat multiplier, CGFloat c, NSString *desc);
extern void jiggleViewLayout(NSView *view);
struct singleChildConstraints {
	NSLayoutConstraint *leadingConstraint;
	NSLayoutConstraint *topConstraint;
	NSLayoutConstraint *trailingConstraintGreater;
	NSLayoutConstraint *trailingConstraintEqual;
	NSLayoutConstraint *bottomConstraintGreater;
	NSLayoutConstraint *bottomConstraintEqual;
};
extern void singleChildConstraintsEstablish(struct singleChildConstraints *c, NSView *contentView, NSView *childView, BOOL hugsTrailing, BOOL hugsBottom, int margined, NSString *desc);
extern void singleChildConstraintsRemove(struct singleChildConstraints *c, NSView *cv);
extern void singleChildConstraintsSetMargined(struct singleChildConstraints *c, int margined);

// area.m
extern int sendAreaEvents(NSEvent *);

// areaevents.m
extern BOOL fromKeycode(unsigned short keycode, uiAreaKeyEvent *ke);
extern BOOL keycodeModifier(unsigned short keycode, uiModifiers *mod);

// draw.m
extern uiDrawContext *newContext(CGContextRef, CGFloat);
extern void freeContext(uiDrawContext *);

// fontbutton.m
extern BOOL uiprivFontButtonInhibitSendAction(SEL sel, id from, id to);
extern BOOL uiprivFontButtonOverrideTargetForAction(SEL sel, id from, id to, id *override);
extern void uiprivSetupFontPanel(void);

// colorbutton.m
extern BOOL colorButtonInhibitSendAction(SEL sel, id from, id to);

// scrollview.m
struct scrollViewCreateParams {
	NSView *DocumentView;
	NSColor *BackgroundColor;
	BOOL DrawsBackground;
	BOOL Bordered;
	BOOL HScroll;
	BOOL VScroll;
};
struct scrollViewData;
extern NSScrollView *mkScrollView(struct scrollViewCreateParams *p, struct scrollViewData **dout);
extern void scrollViewSetScrolling(NSScrollView *sv, struct scrollViewData *d, BOOL hscroll, BOOL vscroll);
extern void scrollViewFreeData(NSScrollView *sv, struct scrollViewData *d);

// label.m
extern NSTextField *newLabel(NSString *str);

// image.m
extern NSImage *imageImage(uiImage *);

// winmoveresize.m
extern void doManualMove(NSWindow *w, NSEvent *initialEvent);
extern void doManualResize(NSWindow *w, NSEvent *initialEvent, uiWindowResizeEdge edge);

// future.m
extern CFStringRef *FUTURE_kCTFontOpenTypeFeatureTag;
extern CFStringRef *FUTURE_kCTFontOpenTypeFeatureValue;
extern CFStringRef *FUTURE_kCTBackgroundColorAttributeName;
extern void loadFutures(void);
extern void FUTURE_NSLayoutConstraint_setIdentifier(NSLayoutConstraint *constraint, NSString *identifier);
extern BOOL FUTURE_NSWindow_performWindowDragWithEvent(NSWindow *w, NSEvent *initialEvent);

// undocumented.m
extern CFStringRef UNDOC_kCTFontPreferredSubFamilyNameKey;
extern CFStringRef UNDOC_kCTFontPreferredFamilyNameKey;
extern void loadUndocumented(void);

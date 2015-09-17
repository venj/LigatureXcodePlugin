//
//  LPXcodeUtils.h
//  LigatureXcodePlugin
//
//  Created by Robert Vojta on 17.09.15.
//  Copyright © 2015 Robert Vojta. All rights reserved.
//

//
// Original headers by thurn available at:
//
//   https://github.com/thurn/DTXcodeUtils/blob/gh-pages/Pod/XcodeHeaders/DTXcodeHeaders.h
//
// I just removed unused stuff.
//

@import AppKit;
@import Cocoa;

@interface DVTTextStorage : NSTextStorage
- (void)invalidateLayoutForLineRange:(struct _NSRange)arg1;
- (void)delayedInvalidateDisplayForLineRange:(struct _NSRange)arg1;
- (void)invalidateDisplayForLineRange:(struct _NSRange)arg1;
- (void)invalidateDisplayInRange:(struct _NSRange)arg1;
- (void)updateAttributesInRange:(struct _NSRange)arg1;
- (void)fixAttributesInRange:(struct _NSRange)arg1;
- (void)fixSyntaxColoringInRange:(struct _NSRange)arg1;
- (void)fixAttachmentAttributeInRange:(struct _NSRange)arg1;
@end

@interface DVTCompletingTextView : NSTextView
@end

@interface DVTSourceTextView : DVTCompletingTextView
@end

@interface DVTViewController : NSViewController
@end

@interface IDEViewController : DVTViewController
@end

@class IDEEditorContext;

@interface IDEEditorArea : IDEViewController
@property(retain, nonatomic) IDEEditorContext *lastActiveEditorContext;
@end

@interface IDEEditor : IDEViewController
@end

@interface IDEEditorContext : IDEViewController
@property(retain, nonatomic) IDEEditor *editor;
@property(retain, nonatomic) IDEEditorArea *editorArea;
@end

@interface IDESourceCodeEditor : IDEEditor
@property(retain) DVTSourceTextView *textView;
@end

@interface IDEComparisonEditor : IDEEditor
@end

@interface IDESourceCodeComparisonEditor : IDEComparisonEditor
@property(readonly) DVTSourceTextView *keyTextView;
@end

@interface IDEWorkspaceWindowController : NSWindowController
@property(readonly) IDEEditorArea *editorArea;
@end

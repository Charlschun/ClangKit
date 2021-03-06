/*******************************************************************************
 * Copyright (c) 2012, Jean-David Gadina - www.xs-labs.com
 * All rights reserved.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/
 
/* $Id$ */

@class CKIndex;

@interface CKTranslationUnit: NSObject
{
@protected
    
    NSString          * _path;
    NSString          * _text;
    CXTranslationUnit   _cxTranslationUnit;
    CKIndex           * _index;
    char             ** _args;
    int                 _numArgs;
    NSArray           * _diagnostics;
    NSArray           * _tokens;
    void              * _tokensPointer;
    void              * _unsavedFile;
	NSLock            * _lock;
    
@private
    
    id __CKTranslationUnit_Reserved[ 5 ] __attribute__( ( unused ) );
}

@property( atomic, readonly          ) NSString        * path;
@property( atomic, readwrite, retain ) NSString        * text;
@property( atomic, readonly          ) CXTranslationUnit cxTranslationUnit;
@property( atomic, readonly          ) CKIndex         * index;
@property( atomic, readonly          ) NSArray         * diagnostics;
@property( atomic, readonly          ) NSArray         * tokens;
@property( atomic, readonly          ) CXFile            cxFile;

+ ( id )translationUnitWithPath: ( NSString * )path;
+ ( id )translationUnitWithPath: ( NSString * )path index: ( CKIndex * )index;
+ ( id )translationUnitWithPath: ( NSString * )path args: ( NSArray * )args;
+ ( id )translationUnitWithPath: ( NSString * )path index: ( CKIndex * )index args: ( NSArray * )args;
+ ( id )translationUnitWithText: ( NSString * )text language: ( CKLanguage )language;
+ ( id )translationUnitWithText: ( NSString * )text language: ( CKLanguage )language index: ( CKIndex * )index;
+ ( id )translationUnitWithText: ( NSString * )text language: ( CKLanguage )language args: ( NSArray * )args;
+ ( id )translationUnitWithText: ( NSString * )text language: ( CKLanguage )language index: ( CKIndex * )index args: ( NSArray * )args;
- ( id )initWithPath: ( NSString * )path;
- ( id )initWithPath: ( NSString * )path index: ( CKIndex * )index;
- ( id )initWithPath: ( NSString * )path args: ( NSArray * )args;
- ( id )initWithPath: ( NSString * )path index: ( CKIndex * )index args: ( NSArray * )args;
- ( id )initWithText: ( NSString * )text language: ( CKLanguage )language;
- ( id )initWithText: ( NSString * )text language: ( CKLanguage )language index: ( CKIndex * )index;
- ( id )initWithText: ( NSString * )text language: ( CKLanguage )language args: ( NSArray * )args;
- ( id )initWithText: ( NSString * )text language: ( CKLanguage )language index: ( CKIndex * )index args: ( NSArray * )args;
- ( void )reparse;
- ( NSArray * )completionResultsForLine: ( NSUInteger )line column: ( NSUInteger )column;

@end

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

/*!
 * @header          CKTypes.h
 * @author          Jean-David Gadina <macmade@digidna.net>
 * @copyright       (c) 2011-2012, DigiDNA
 * @abstract        Project public types
 * @description     The project obviously uses libclang headers, but there is
 *                  no reason for a project using ClangKit to include them.
 *                  This header contains typedefs for libclang internal types,
 *                  when no libclang headers are included. This way, we can
 *                  ensure the public ClangKit interfaces will compile even
 *                  if libclang headers are not included.
 */

#ifndef __CK_TYPES_H__
#define __CK_TYPES_H__

#ifndef CLANG_C_INDEX_H

/*!
 * @typedef         CXDiagnostic
 * @abstract        libclang type for diagnostic objects.
 */
typedef void * CXDiagnostic;

/*!
 * @typedef         CXIndex
 * @abstract        libclang type for index objects.
 */
typedef void * CXIndex;

/*!
 * @typedef         CXTranslationUnit
 * @abstract        libclang type for translation unit objects.
 */
typedef void * CXTranslationUnit;

/*!
 * @typedef         CXFile
 * @abstract        libclang type for file objects.
 */
typedef void * CXFile;

/*!
 * @typedef         CXCompletionString
 * @abstract        libclang type for completion strings.
 */
typedef void * CXCompletionString;

#endif

/*!
 * @typedef         CKLanguage
 * @abstract        Source code languages
 * @description     ClangKit can be used to parse strings and files. For a file,
 *                  the language is guessed from the file's extension. For
 *                  strings, the language must be specified using one of this
 *                  value.
 * @constant        CKLanguageNone      Unknown language
 * @constant        CKLanguageC         C source code
 * @constant        CKLanguageCPP       C++ source code
 * @constant        CKLanguageObjC      Objective-C source code
 * @constant        CKLanguageObjCPP    Objective-C++ source code
 */
typedef enum
{
    CKLanguageNone   = 0x00,
    CKLanguageC      = 0x01,
    CKLanguageCPP    = 0x02,
    CKLanguageObjC   = 0x03,
    CKLanguageObjCPP = 0x04
}
CKLanguage;

#endif /* __CK_TYPES_H__ */

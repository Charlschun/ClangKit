/*******************************************************************************
 * Copyright (c) 2012, Jean-David Gadina <macmade@eosgarden.com>
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

@interface CKSourceLocation: NSObject
{
@protected
    
    void       * _ptrData1;
    void       * _ptrData2;
    unsigned int _intData;
    NSString   * _fileName;
    
@private
    
    id __CKSourceLocation_Reserved[ 5 ] __attribute__( ( unused ) );
}

@property( atomic, readonly ) void       * ptrData1;
@property( atomic, readonly ) void       * ptrData2;
@property( atomic, readonly ) unsigned int intData;
@property( atomic, readonly ) NSString   * fileName;

+ ( id )sourceLocationWithPointerData1: ( void * )ptrData1 pointerData2: ( void * )ptrData2 intData: ( unsigned int )intData;
- ( id )initWithPointerData1: ( void * )ptrData1 pointerData2: ( void * )ptrData2 intData: ( unsigned int )intData;

@end
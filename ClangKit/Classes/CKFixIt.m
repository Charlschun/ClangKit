/*******************************************************************************
 * Copyright (c) 2012, Jean-David Gadina <macmade@eosgarden.com>
 * All rights reserved
 ******************************************************************************/
 
/* $Id$ */

#import "CKFixIt.h"
#import "CKDiagnostic.h"

@implementation CKFixIt

@synthesize string = _string;
@synthesize range  = _range;

+ ( NSArray * )fixItsForDiagnostic: ( CKDiagnostic * )diagnostic
{
    unsigned int     i;
    unsigned int     n;
    NSMutableArray * fixIts;
    CKFixIt        * fixIt;
    
    n      = clang_getDiagnosticNumFixIts( diagnostic );
    fixIts = [ NSMutableArray arrayWithCapacity: n ];
    
    for( i = 0; i < n; i++ )
    {
        fixIt = [ self fixItWithDiagnostic: diagnostic index: i ];
        
        if( fixIt != nil )
        {
            [ fixIts addObject: fixIt ];
        }
    }
    
    return [ NSArray arrayWithArray: fixIts ];
}

+ ( id )fixItWithDiagnostic: ( CKDiagnostic * )diagnostic index: ( NSUInteger )index
{
    return [ [ [ self alloc ] initWithDiagnostic: diagnostic index: index ] autorelease ];
}

- ( id )initWithDiagnostic: ( CKDiagnostic * )diagnostic index: ( NSUInteger )index
{
    CXSourceRange range;
    CXString      string;
    
    if( ( self = [ self init ] ) )
    {
        string  = clang_getDiagnosticFixIt( diagnostic.cxDiagnostic, ( unsigned int )index, &range );
        _string = [ [ NSString alloc ] initWithCString: clang_getCString( string ) encoding: NSUTF8StringEncoding ];
    }
    
    return self;
}

- ( void )dealloc
{
    RELEASE_IVAR( _string );
    
    [ super dealloc ];
}

- ( NSString * )description
{
    NSString * description;
    
    description = [ super description ];
    description = [ description stringByAppendingFormat: @"%@", self.string ];
    
    return description;
}

@end

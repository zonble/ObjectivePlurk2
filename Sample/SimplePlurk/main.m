#import <UIKit/UIKit.h>

int main(int argc, char *argv[])
{	
	NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
	NSLog(@"App Start!");
    int retVal = UIApplicationMain(argc, argv, nil, @"SimplePlurkAppDelegate");
	[pool release];
	return retVal;
}

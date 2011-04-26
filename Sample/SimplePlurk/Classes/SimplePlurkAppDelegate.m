//
//  SimplePlurkAppDelegate.m
//  SimplePlurk
//
//  Created by zonble on 12/12/09.
//  Copyright Lithoglyph Inc. 2009. All rights reserved.
//

#import "SimplePlurkAppDelegate.h"
#import "RootViewController.h"

@implementation SimplePlurkAppDelegate

#pragma mark -
#pragma mark Memory management

- (void)dealloc
{
	[navigationController release];
	[window release];
	[super dealloc];
}

#pragma mark -
#pragma mark Application lifecycle

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
	[ObjectivePlurk sharedInstance].APIKey = API_KEY;
	
	window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
	RootViewController *rootController = [[[RootViewController alloc] initWithStyle:UITableViewStylePlain] autorelease];
	navigationController = [[UINavigationController alloc] initWithRootViewController:rootController];
	window.rootViewController = navigationController;
    [window makeKeyAndVisible];
	
	rootController = [navigationController.viewControllers objectAtIndex:0];
	[rootController login:nil];
	return YES;
}


- (void)applicationWillTerminate:(UIApplication *)application
{
	// Save data if appropriate
}

@synthesize window;
@synthesize navigationController;


@end


//
//  AppController.h
//  gui_cocoa
//
//  Created by Moritz Ulrich on 19.11.08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "MapView.h"
#import "MainWindowController.h"

#import "game/game.h"
#import "game/game_controller.h"

@interface AppController : NSObject {
	NSWindowController *mainWindowController;
    NSViewController* mapViewController;
	
	MapView* mapView;
	
	CocoaMapWidget::ptr cocoaMapWidget;
	aw::game_controller::ptr gameController;
}

- (void)startNewGame;

@end
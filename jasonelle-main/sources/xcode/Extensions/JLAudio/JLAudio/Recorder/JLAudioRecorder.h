//
//  JLAudioRecorder.h
//  JLAudio
//
//  Copyright (c) Jasonelle.com
//
//  This file is part of Jasonelle Project <https://jasonelle.com>.
//  Jasonelle Project is dual licensed. You can choose between AGPLv3 or MPLv2.
//  MPLv2 is only valid if the software has a unique Jasonelle Key which was purchased in official channels.
//
//  == AGPLv3
//  Jasonelle is free software: you can redistribute it and/or modify it under the terms of the Affero GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
//  Jasonelle is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the Affero GNU General Public License for more details.
//  You should have received a copy of the Affero GNU General Public License along with Jasonelle. If not, see <https://www.gnu.org/licenses/>.
//
//  == MPLv2 (Only valid if purchased a Jasonelle Key)
//  This Source Code Form is subject to the terms
//  of the Mozilla Public License, v. 2.0.
//  If a copy of the MPL was not distributed
//  with this file, You can obtain one at
//
//  <https://mozilla.org/MPL/2.0/>.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <CoreAudio/CoreAudioTypes.h>
#import <JLKernel/JLKernel.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, JLAudioState) {
    JLAudioStateNone        = 1000,
    JLAudioStateIdle        = 1001,
    JLAudioStateRecording   = 1002,
    JLAudioStatePaused      = 1003
};

@interface JLAudioRecorder : NSObject<AVAudioRecorderDelegate>

@property (nonatomic, strong, nonnull) JLApplication * app;
@property (nonatomic, strong, nonnull) id<JLLoggerProtocol> logger;
@property (nonatomic, strong, nonnull) JLExtension * extension;

@property (nonatomic, strong, nullable) AVAudioRecorder * recorder;
@property (nonatomic, strong, nullable) NSTimer * timer;
@property (nonatomic, strong, nullable) NSURL * file;
@property (nonatomic) JLAudioState state;
@property (nonatomic) NSTimeInterval duration;
@property (nonatomic, strong, nonnull) NSDictionary * settings;

@property (nonatomic) BOOL isRecordPermissionGranted;

- (instancetype)initWithApplication:(JLApplication *)app andExtension:(nonnull JLExtension *)extension;

- (BOOL) authorizeWithCompletionHandler:(void (^)(BOOL granted))completionHandler showAlert: (BOOL) showAlert;

- (void) recordWithOptions: (JLJSParams *) options;
- (void) stop;
- (void) pause;
- (void) resume;

@end

NS_ASSUME_NONNULL_END

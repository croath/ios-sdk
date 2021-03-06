//
//  SPTTrack.h
//  Basic Auth
//
//  Created by Daniel Kennett on 19/11/2013.
/*
 Copyright 2013 Spotify AB

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */
#import <Foundation/Foundation.h>
#import "SPTJSONDecoding.h"
#import "SPTPartialAlbum.h"
#import "SPTRequest.h"

/** This class represents a track on the Spotify service. */
@interface SPTTrack : NSObject <SPTJSONObject>

/** Request the track at the given Spotify URI.

 @note This method takes Spotify URIs in the form `spotify:*`, NOT HTTP URLs.

 @param uri The Spotify URI of the track to request.
 @param session An authenticated session. Can be `nil`.
 @param block The block to be called when the operation is complete. The block will pass a Spotify SDK metadata object on success, otherwise an error.
 */
+(void)trackWithURI:(NSURL *)uri session:(SPTSession *)session callback:(SPTRequestCallback)block;

/** The name of the track. */
@property (nonatomic, readonly, copy) NSString *name;

/** The Spotify URI of the track. */
@property (nonatomic, readonly, copy) NSURL *uri;

/** The duration of the track. */
@property (nonatomic, readonly) NSTimeInterval duration;

/** An array of artists for the track, as `SPTPartialArtist` objects. */
@property (nonatomic, readonly, copy) NSArray *artists;

/** The album of the track. */
@property (nonatomic, readonly, strong) SPTPartialAlbum *album;

/** The track number of the track. I.e., if it's the first track on the album this will be `1`. */
@property (nonatomic, readonly) NSInteger trackNumber;

/** The popularity of the track as a value between 0.0 (least popular) to 1.0 (most popular). */
@property (nonatomic, readonly) double popularity;

/** Any external IDs of the track, such as the ISRC code. */
@property (nonatomic, readonly, copy) NSDictionary *externalIds;

/** `YES` if the track is available for playback, otherwise `NO`. */
@property (nonatomic, readonly) BOOL availableForPlayback;

/** An array of ISO 3166 country codes in which the album is available. */
@property (nonatomic, readonly, copy) NSArray *availableTerritories;

@end

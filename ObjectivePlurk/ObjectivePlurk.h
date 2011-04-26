//
// ObjectivePlurk.h
// ObjectivePlurk
//
// Copyright (c) 2009-2011 Weizhong Yang (http://zonble.net)
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of Weizhong Yang (zonble) nor the
//       names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY WEIZHONG YANG ''AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL WEIZHONG YANG BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#import <Foundation/Foundation.h>
#import "LFWebAPIKit.h"
#import "JSON.h"

@class ObjectivePlurk;

@protocol ObjectivePlurkDelegate <NSObject>

#pragma mark Users

- (void)plurk:(ObjectivePlurk *)plurk didLoggedIn:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailLoggingIn:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didUpdatePicture:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailUpdatingPicture:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didUpdateProfile:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailUpdatingProfile:(NSError *)error;


#pragma mark Polling

- (void)plurk:(ObjectivePlurk *)plurk didFetchPollingMessages:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailFetchingPollingMessages:(NSError *)error;

#pragma mark Timeline

- (void)plurk:(ObjectivePlurk *)plurk didFetchMessage:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailFetchingMessage:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didFetchMessages:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailFetchingMessages:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didFetchUnreadMessages:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailFetchingUnreadMessages:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didMuteMessages:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailMutingMessages:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didUnmuteMessages:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailUnmutingMessages:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didMarkMessagesAsRead:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailMarkingMessagesAsRead:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didAddMessage:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailAddingMessage:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didUploadPicture:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailUploadingPicture:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didDeleteMessage:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailDeletingMessage:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didEditMessage:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailEditingMessage:(NSError *)error;

#pragma mark Responses

- (void)plurk:(ObjectivePlurk *)plurk didFetchResponses:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailFetchingResponses:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didAddResponse:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailAddingResponse:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didDeleteResponse:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailDeletingResponse:(NSError *)error;

#pragma mark Profiles

- (void)plurk:(ObjectivePlurk *)plurk didFetchMyProfile:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailFetchingMyProfile:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didFetchPublicProfile:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailFetchingPublicProfile:(NSError *)error;

#pragma mark Friends and fans

- (void)plurk:(ObjectivePlurk *)plurk didFetchFriends:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailFetchingFriends:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didFetchFans:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailFetchingFans:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didFetchFollowingUsers:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailFetchingFollowingUsers:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didBecomeFriend:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailBecomingFriend:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didRemoveFriendship:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailRemovingFriendship:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didBecomeFan:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailBecomingFan:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didSetFollowingUser:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailSettingFollowingUser:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didFetchFriendsCompletionList:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailFetchingFriendsCompletionList:(NSError *)error;

#pragma mark Alerts

- (void)plurk:(ObjectivePlurk *)plurk didRetriveActiveAlerts:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailRetrivingActiveAlerts:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didRetriveHistory:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailRetrivingHistory:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didAddAsFan:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailAddingAsFan:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didAddAllAsFan:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailAddingAllAsFan:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didAddAsFriend:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailAddingAsFriend:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didAddAllAsFriend:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailAddingAllAsFriend:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didDenyFriendship:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailDenyingFriendship:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didRemoveNotification:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailRemovingNotification:(NSError *)error;

#pragma mark Search

- (void)plurk:(ObjectivePlurk *)plurk didSearchMessages:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailSearchingMessages:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didSearchUsers:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailSearchingUsers:(NSError *)error;

#pragma mark Emoticons

- (void)plurk:(ObjectivePlurk *)plurk didFetchEmoticons:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailFetchingEmoticons:(NSError *)error;

#pragma mark Blocks

- (void)plurk:(ObjectivePlurk *)plurk didFetchBlockedUsers:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailFetchingBlockedUsers:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didBlockUser:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailBlockingUser:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didUnblockUser:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailUnblockingUser:(NSError *)error;

#pragma mark Cliques

- (void)plurk:(ObjectivePlurk *)plurk didFetchCliques:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailFetchingCliques:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didCreateNewClique:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailCreatingNewClique:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didFetchClique:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailFetchingClique:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didRenameClique:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailRenamingClique:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didDeleteClique:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailDeletingClique:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didAddUserToClique:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailAddingUserToClique:(NSError *)error;

- (void)plurk:(ObjectivePlurk *)plurk didRemoveUserFromClique:(NSDictionary *)result;
- (void)plurk:(ObjectivePlurk *)plurk didFailRemovingUserFromClique:(NSError *)error;

@end

#pragma mark -

typedef enum {
	OPGenderNone = 0,
	OPGenderMale = 1,
	OPGenderFemale = 2
} OPGender;

typedef enum {
	OPPrivacyNone = 0,
	OPPrivacyWorld = 1,
	OPPrivacyOnlyFriends = 2,
	OPPrivacyOnlyMe = 3,
} OPPrivacy;

typedef enum {
	OPSmallUserProfileImageSize = 0,
	OPMediumUserProfileImageSize = 1,
	OPBigUserProfileImageSize = 2
} OPUserProfileImageSize;


typedef enum {
	OPEveryOneCanComment = 0,
	OPNoOneCanComment = 1,
	OPOnlyFriendsCanComment = 2
} OPCanComment;

extern NSString *const ObjectivePlurkCookiePreferenceName;
extern NSString *const ObjectivePlurkUserInfoPreferenceName;

extern NSString *const ObjectivePlurkAPIURLString;
extern NSString *const ObjectivePlurkErrorDomain;
extern NSString *const ObjectivePlurkUploadTempFilenamePrefix;

extern NSString *const OPAlertFriendshipRequestType;
extern NSString *const OPAlertFriendshipPendingType;
extern NSString *const OPAlertNewFanType;
extern NSString *const OPAlertFriendshipAcceptedType;
extern NSString *const OPAlertNewFriendType;

extern NSString *const OPLoginAction;
extern NSString *const OPUpdatePictureAction;
extern NSString *const OPUpdateProfileAction;

extern NSString *const OPRetrivePollingMessageAction;

extern NSString *const OPRetriveMessageAction;
extern NSString *const OPRetriveMessagesAction;
extern NSString *const OPRetriveUnreadMessagesAction;
extern NSString *const OPMuteMessagesAction;
extern NSString *const OPUnmuteMessagesAction;
extern NSString *const OPMarkMessageAsReadAction;
extern NSString *const OPAddMessageAction;
extern NSString *const OPUploadPictureAction;
extern NSString *const OPDeleteMessageAction;
extern NSString *const OPEditMessageAction;

extern NSString *const OPRetriveResponsesAction;
extern NSString *const OPAddResponsesAction;
extern NSString *const OPDeleteResponsesAction;

extern NSString *const OPFetchMyProfileAction;
extern NSString *const OPFetchPublicProfileAction;

extern NSString *const OPRetriveFriendAction;
extern NSString *const OPRetriveFansAction;
extern NSString *const OPRetriveFollowingAction;
extern NSString *const OPBecomeFriendAction;
extern NSString *const OPRemoveFriendshipAction;
extern NSString *const OPBecomeFanAction;
extern NSString *const OPSetFollowingAction;
extern NSString *const OPFetchFriendsCompletionListAction;

extern NSString *const OPRetriveActiveAlertsAction;
extern NSString *const OPRetriveHistoryAction;
extern NSString *const OPAddAsFanAction;
extern NSString *const OPAddAllAsFanAction;
extern NSString *const OPAddAsFriendAction;
extern NSString *const OPAddAllAsFriendAction;
extern NSString *const OPDenyFriendshipAction;
extern NSString *const OPRemoveNotificationAction;

extern NSString *const OPSearchMessagesAction;
extern NSString *const OPSearchUsersAction;

extern NSString *const OPFetchEmoticonsAction;

extern NSString *const OPFetchBlockedUsersAction;
extern NSString *const OPBlockuUserAction;
extern NSString *const OPUnblockuUserAction;

extern NSString *const OPFetchCliquesAction;
extern NSString *const OPCreateNewCliqueAction;
extern NSString *const OPFetchCliqueAction;
extern NSString *const OPRenameCliqueAction;
extern NSString *const OPDeleteCliqueAction;
extern NSString *const OPAddUserToCliqueAction;
extern NSString *const OPRemoveUserFromCliqueAction;



@interface ObjectivePlurk : NSObject
{
	NSString *APIKey;
	LFHTTPRequest *_request;
	NSMutableArray *_queue;
	NSArray *_qualifiers;
	NSDictionary *_langCodes;
	NSDictionary *_currentUserInfo;
	NSDateFormatter *_dateFormatter;
	NSDate *_expirationDate;
	NSDictionary *_receivedHeader;
	
	
	SBJSON *JSONParser;
}

+ (ObjectivePlurk *)sharedInstance;

- (NSString *)langCodeFromLocalIdentifier:(NSString *)locale;

- (void)cancelAllRequest;
- (void)cancelAllRequestWithDelegate:(id)delegate;
- (BOOL)resume;
- (void)logout;

- (NSString *)imageURLStringForUser:(id)identifier size:(OPUserProfileImageSize)size hasProfileImage:(BOOL)hasProfileImage avatar:(NSString *)avatar;

#pragma mark Users

- (void)loginWithUsername:(NSString *)username password:(NSString *)password delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)updatePictureWithFile:(NSString *)path delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)updateProfileWithOldPassword:(NSString *)oldPassword fullname:(NSString *)fullname newPassword:(NSString *)newPassword email:(NSString *)email displayName:(NSString *)displayName privacy:(OPPrivacy)privacy dateOfBirth:(NSString *)dateOfBirth delegate:(id)delegate userInfo:(NSDictionary *)userInfo;

#pragma mark Polling

- (void)fetchPollingMessagesWithDateOffset:(NSDate *)offsetDate delegate:(id)delegate userInfo:(NSDictionary *)userInfo;

#pragma mark Timeline

- (void)fetchMessageWithMessageIdentifier:(NSString *)identifer delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)fetchMessagesWithDateOffset:(NSDate *)offsetDate limit:(NSInteger)limit user:(NSString *)userID isResponded:(BOOL)isResponded isPrivate:(BOOL)isPrivate delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)fetchUnreadMessagesWithDateOffset:(NSDate *)offsetDate limit:(NSInteger)limit delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)muteMessagesWithMessageIdentifiers:(NSArray *)identifiers delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)unmuteMessagesWithMessageIdentifiers:(NSArray *)identifiers delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)markMessagesAsReadWithMessageIdentifiers:(NSArray *)identifiers delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)addNewMessageWithContent:(NSString *)content qualifier:(NSString *)qualifier othersCanComment:(OPCanComment)canComment lang:(NSString *)lang limitToUsers:(NSArray *)users delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)uploadPicture:(NSString *)path delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)deleteMessageWithMessageIdentifier:(NSString *)identifer delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)editMessageWithMessageIdentifier:(NSString *)identifer content:(NSString *)content delegate:(id)delegate userInfo:(NSDictionary *)userInfo;

#pragma mark Responses

- (void)fetchResponsesWithMessageIdentifier:(NSString *)identifer delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)addNewResponseWithContent:(NSString *)content qualifier:(NSString *)qualifier toMessages:(NSString *)identifer delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)deleteResponseWithMessageIdentifier:(NSString *)identifer responseIdentifier:(NSString *)responseIdentifier delegate:(id)delegate userInfo:(NSDictionary *)userInfo;

#pragma mark Profiles

- (void)fetchMyProfileWithDelegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)fetchPublicProfileWithUserIdentifier:(NSString *)userIdentifier delegate:(id)delegate userInfo:(NSDictionary *)userInfo;

#pragma mark Friends and fans

- (void)fetchFriendsOfUser:(NSString *)userIdentifier offset:(NSUInteger)offset delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)fetchFansOfUser:(NSString *)userIdentifier offset:(NSUInteger)offset delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)fetchFollowingUsersOfCurrentUserWithOffset:(NSUInteger)offset delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)becomeFriendOfUser:(NSString *)userIdentifier delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)removeFriendshipWithUser:(NSString *)userIdentifier delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)becomeFanOfUser:(NSString *)userIdentifier delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)setFollowingUser:(NSString *)userIdentifier follow:(BOOL)follow delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)fetchFriendsCompletionList:(id)delegate userInfo:(NSDictionary *)userInfo;

#pragma mark Alerts

- (void)fetchActiveAlertsWithDelegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)fetchHistoryWithDelegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)addAsFanWithUserIdentifier:(NSString *)userIdentifier delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)addAllAsFanWithDelegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)addAsFriendWithUserIdentifier:(NSString *)userIdentifier delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)addAllAsFriendWithDelegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)denyFriendshipWithUserIdentifier:(NSString *)userIdentifier delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)removeNotificationWithDelegate:(id)delegate userInfo:(NSDictionary *)userInfo;

#pragma mark Search

- (void)searchMessagesWithQuery:(NSString *)query offset:(NSUInteger)offset delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)searchUsersWithQuery:(NSString *)query offset:(NSUInteger)offset delegate:(id)delegate userInfo:(NSDictionary *)userInfo;

#pragma mark Emoticons

- (void)fetchEmoticonsWithDelegate:(id)delegate userInfo:(NSDictionary *)userInfo;

#pragma mark Blocks

- (void)fetchBlockedUsersWithDelegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)blockUser:(NSString *)userIdentifier delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)unblockUser:(NSString *)userIdentifier delegate:(id)delegate userInfo:(NSDictionary *)userInfo;

#pragma mark Cliques

- (void)fetchCliquesWithDelegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)createNewCliqueWithName:(NSString *)cliqueName delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)fetchCliqueWithName:(NSString *)cliqueName delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)renameCliqueWithOldName:(NSString *)oldName newName:(NSString *)newName delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)deleteCliqueWithName:(NSString *)cliqueName delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)addUser:(NSString *)userIdentifier toClique:(NSString *)cliqueName delegate:(id)delegate userInfo:(NSDictionary *)userInfo;
- (void)removeUser:(NSString *)userIdentifier fromClique:(NSString *)cliqueName delegate:(id)delegate userInfo:(NSDictionary *)userInfo;

@property (retain, nonatomic) NSString *APIKey;
@property (readonly) NSArray *qualifiers;
@property (readonly) NSDictionary *langCodes;
@property (readonly, getter=isLoggedIn) BOOL loggedIn;
@property (copy, nonatomic) NSDictionary *currentUserInfo;
@property (readonly) NSDate *expirationDate;
@property (assign) BOOL shouldWaitUntilDone;

@end

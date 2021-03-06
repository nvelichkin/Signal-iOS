//
//  Copyright (c) 2020 Open Whisper Systems. All rights reserved.
//

#import "TSGroupModel.h"
#import "TSThread.h"

NS_ASSUME_NONNULL_BEGIN

@class SDSAnyReadTransaction;
@class SDSAnyWriteTransaction;
@class TSAttachmentStream;

extern NSString *const TSGroupThreadAvatarChangedNotification;
extern NSString *const TSGroupThread_NotificationKey_UniqueId;

@interface TSGroupThread : TSThread

// --- CODE GENERATION MARKER

// This snippet is generated by /Scripts/sds_codegen/sds_generate.py. Do not manually edit it, instead run `sds_codegen.sh`.

// clang-format off

- (instancetype)initWithGrdbId:(int64_t)grdbId
                      uniqueId:(NSString *)uniqueId
           conversationColorName:(ConversationColorName)conversationColorName
                    creationDate:(nullable NSDate *)creationDate
                      isArchived:(BOOL)isArchived
            lastInteractionRowId:(int64_t)lastInteractionRowId
                    messageDraft:(nullable NSString *)messageDraft
                  mutedUntilDate:(nullable NSDate *)mutedUntilDate
           shouldThreadBeVisible:(BOOL)shouldThreadBeVisible
                      groupModel:(TSGroupModel *)groupModel
NS_SWIFT_NAME(init(grdbId:uniqueId:conversationColorName:creationDate:isArchived:lastInteractionRowId:messageDraft:mutedUntilDate:shouldThreadBeVisible:groupModel:));

// clang-format on

// --- CODE GENERATION MARKER

@property (nonatomic, readonly) TSGroupModel *groupModel;

// This method should only be called by GroupManager.
- (instancetype)initWithGroupModelPrivate:(TSGroupModel *)groupModel;

+ (nullable instancetype)fetchWithGroupId:(NSData *)groupId
                              transaction:(SDSAnyReadTransaction *)transaction
    NS_SWIFT_NAME(fetch(groupId:transaction:));

+ (NSString *)threadIdFromGroupId:(NSData *)groupId;

@property (nonatomic, readonly) NSString *groupNameOrDefault;
@property (nonatomic, readonly, class) NSString *defaultGroupName;

- (BOOL)isLocalUserInGroup;

// all group threads containing recipient as a member
+ (NSArray<TSGroupThread *> *)groupThreadsWithAddress:(SignalServiceAddress *)address
                                          transaction:(SDSAnyReadTransaction *)transaction;

- (void)leaveGroupWithTransaction:(SDSAnyWriteTransaction *)transaction;

#pragma mark - Avatar

// GroupsV2 TODO: Remove.
- (void)updateAvatarWithAttachmentStream:(TSAttachmentStream *)attachmentStream;
- (void)updateAvatarWithAttachmentStream:(TSAttachmentStream *)attachmentStream
                             transaction:(SDSAnyWriteTransaction *)transaction;

#pragma mark - Update With...

// GroupsV2 TODO: We need to ensure this is only called by GroupManager.
- (void)updateWithGroupModel:(TSGroupModel *)groupModel transaction:(SDSAnyWriteTransaction *)transaction;

#pragma mark -

+ (ConversationColorName)defaultConversationColorNameForGroupId:(NSData *)groupId;

@end

NS_ASSUME_NONNULL_END

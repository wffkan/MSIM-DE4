//
//  MSProfileInfo.h
//  BlackFireIM
//
//  Created by benny wang on 2021/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class Profile;
@class Spark;
@interface MSProfileInfo : NSObject

@property(nonatomic,copy) NSString *user_id;

@property(nonatomic,assign) NSInteger update_time;

@property(nonatomic,copy) NSString *nick_name;

@property(nonatomic,copy) NSString *avatar;

@property(nonatomic,assign) BOOL gold;

@property(nonatomic,assign) BOOL verified;

/** 是否通过审核*/
@property(nonatomic,assign) BOOL approved;

/** 是否被后台标记为删除*/
@property(nonatomic,assign) BOOL deleted;

@property(nonatomic,assign) NSInteger gender;

@property(nonatomic,copy) NSString *pic;

@property(nonatomic,copy) NSString *custom;

+ (MSProfileInfo *)createWithProto:(Profile *)profile;

+ (MSProfileInfo *)createWithSpark:(Spark *)spark;

@end

NS_ASSUME_NONNULL_END

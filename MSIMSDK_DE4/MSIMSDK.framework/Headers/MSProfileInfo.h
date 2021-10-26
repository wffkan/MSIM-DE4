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

@property(nonatomic,assign) NSInteger gender;

@property(nonatomic,assign) BOOL gold;

@property(nonatomic,assign) BOOL verified;

/** 决定与他产生的会话是否需要隐藏*/
@property(nonatomic,assign) BOOL hidden;

@property(nonatomic,copy) NSString *pic;

@property(nonatomic,copy) NSString *custom;

+ (MSProfileInfo *)createWithProto:(Profile *)profile;

+ (MSProfileInfo *)createWithSpark:(Spark *)spark;

@end

NS_ASSUME_NONNULL_END

//
//  MSMessageProvider.h
//  MSIMSDK
//
//  Created by benny wang on 2021/11/3.
//

#import <Foundation/Foundation.h>
#import <MSIMSDK/MSIMMessage.h>


NS_ASSUME_NONNULL_BEGIN

@interface MSMessageProvider : NSObject

///单例
+ (instancetype)provider NS_SWIFT_NAME(shared());

/// 根据msg_sign查询某一条消息实体
- (nullable MSIMMessage *)searchMessage:(NSString *)partner_id msg_sign:(NSInteger)msg_sign;


@end

NS_ASSUME_NONNULL_END

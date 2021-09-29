//
//  MSCacheProvider.h
//  MSIMSDK
//
//  Created by benny wang on 2021/9/29.
//
//
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MSCacheProvider : NSObject

///单例
+ (instancetype)provider NS_SWIFT_NAME(shared());

/// 向某张表中缓存一条数据
- (BOOL)cacheValue:(NSString *)value forKey:(NSString *)key inTable:(NSString *)tableName;

/// 从某一张表中取出一条数据
- (NSString *)valueForKey:(NSString *)key fromTable:(NSString *)tableName;

/// 从某一张表中删除一条数据
- (BOOL)deleteRowForKey:(NSString *)key fromTable:(NSString *)tableName;

/// 删除一张表
- (BOOL)deleteTable:(NSString *)tableName;


@end

NS_ASSUME_NONNULL_END

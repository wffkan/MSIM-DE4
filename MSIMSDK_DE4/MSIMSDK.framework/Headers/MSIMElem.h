//
//  MSIMElem.h
//  BlackFireIM
//
//  Created by benny wang on 2021/2/26.
//

#import <UIKit/UIKit.h>
#import <MSIMSDK/MSIMConst.h>


NS_ASSUME_NONNULL_BEGIN

@interface MSIMElem : NSObject<NSCopying>


/** 判断本地消息的连续性*/
@property(nonatomic,assign) NSInteger block_id;

/** 扩展字段，用于数据库存储*/
- (NSData *)extData;

@end

/////////////////////////////////////////////////////////////////////////////////
//
//                      文本消息 Elem
//
/////////////////////////////////////////////////////////////////////////////////
@interface MSIMTextElem : MSIMElem

@property(nonatomic,copy) NSString *text;

@end

/////////////////////////////////////////////////////////////////////////////////
//
//                      图片消息 Elem
//
/////////////////////////////////////////////////////////////////////////////////
@interface MSIMImageElem : MSIMElem

/** 图片 ID，内部标识，可用于外部缓存key*/
@property(nonatomic,copy,nullable) NSString *uuid;
/** 图片大小*/
@property(nonatomic,assign) NSInteger size;
/** 图片宽*/
@property(nonatomic,assign) NSInteger width;
/** 图片高*/
@property(nonatomic,assign) NSInteger height;
/** 下载URL*/
@property(nonatomic,copy,nullable) NSString *url;
/** 待发送的图片*/
@property(nonatomic,strong,nullable) UIImage *image;
/** 保存在沙盒中的地址*/
@property(nonatomic,copy,nullable) NSString *path;
/** 图片上传的进度 0 ~ 1*/
@property(nonatomic,assign) CGFloat progress;

@end

/////////////////////////////////////////////////////////////////////////////////
//
//                      音频消息 Elem
//
/////////////////////////////////////////////////////////////////////////////////
@interface MSIMVoiceElem : MSIMElem

/** 语音本地地址*/
@property(nonatomic,copy,nullable) NSString * path;
/** 语音远程地址*/
@property(nonatomic,copy,nullable) NSString *url;

/** 语音数据大小*/
@property(nonatomic,assign) NSInteger dataSize;

/** 语音长度（秒）*/
@property(nonatomic,assign) NSInteger duration;

@end

/////////////////////////////////////////////////////////////////////////////////
//
//                      视频消息 Elem
//
/////////////////////////////////////////////////////////////////////////////////
@interface MSIMVideoElem : MSIMElem

/** 视频 ID，内部标识，可用于外部缓存key*/
@property(nonatomic,copy,nullable) NSString *uuid;
/** 视频本地地址*/
@property(nonatomic,copy,nullable) NSString *videoPath;
/** 视频上传完成的远程地址*/
@property(nonatomic,copy,nullable) NSString *videoUrl;
/** 封面图片*/
@property(nonatomic,strong,nullable) UIImage *coverImage;
/** 封面上传成功远程地址*/
@property(nonatomic,copy,nullable) NSString *coverUrl;
/** 封面本地坡地*/
@property(nonatomic,copy,nullable) NSString *coverPath;
/** 视频文件大小*/
@property(nonatomic,assign) NSInteger size;
/** 视频宽*/
@property(nonatomic,assign) NSInteger width;
/** 视频高*/
@property(nonatomic,assign) NSInteger height;
/** 视频的时长  秒*/
@property(nonatomic,assign) NSInteger duration;
/** 视频上传的进度 0 ~ 1*/
@property(nonatomic,assign) CGFloat progress;

@end

/////////////////////////////////////////////////////////////////////////////////
//
//                      flash Elem(闪照图片消息)
//
/////////////////////////////////////////////////////////////////////////////////
@interface MSIMFlashElem : MSIMElem

/** 图片 ID，内部标识，可用于外部缓存key*/
@property(nonatomic,copy,nullable) NSString *uuid;
/** 图片大小*/
@property(nonatomic,assign) NSInteger size;
/** 图片宽*/
@property(nonatomic,assign) NSInteger width;
/** 图片高*/
@property(nonatomic,assign) NSInteger height;
/** 下载URL*/
@property(nonatomic,copy,nullable) NSString *url;
/** 待发送的图片*/
@property(nonatomic,strong,nullable) UIImage *image;
/** 保存在沙盒中的地址*/
@property(nonatomic,copy,nullable) NSString *path;
/** 图片上传的进度 0 ~ 1*/
@property(nonatomic,assign) CGFloat progress;
/** from_uid已读*/
@property(nonatomic,assign) BOOL from_see;
/** to_uid已读*/
@property(nonatomic,assign) BOOL to_see;

@end

/////////////////////////////////////////////////////////////////////////////////
//
//      业务消息 Elem
// 11 ~ 30 预留给用户可以发送的消息类型
// 32 ~ 63 预留给用户只能接收的消息类型
//  对应的消息type 11 ~ 30 and 32 ~ 63
/////////////////////////////////////////////////////////////////////////////////
@interface MSBusinessElem : MSIMElem

@property(nonatomic,assign) NSInteger businessType;

@property(nonatomic,copy,nullable) NSString *body;

@property(nonatomic,copy,nullable) NSString *title;

@property(nonatomic,copy,nullable) NSString *thumb;

@property(nonatomic,assign) NSInteger width;

@property(nonatomic,assign) NSInteger height;

@property(nonatomic,assign) NSInteger duration;

@property(nonatomic,assign) double lat;

@property(nonatomic,assign) double lng;

@property(nonatomic,assign) NSInteger zoom;

@end

/////////////////////////////////////////////////////////////////////////////////
//
// 透传的指令消息 Elem
// type = 100
/////////////////////////////////////////////////////////////////////////////////
@interface MSSignalElem : MSIMElem

@property(nonatomic,copy,nullable) NSString *body;

@property(nonatomic,copy,nullable) NSString *title;

@property(nonatomic,copy,nullable) NSString *thumb;

@property(nonatomic,assign) NSInteger width;

@property(nonatomic,assign) NSInteger height;

@property(nonatomic,assign) NSInteger duration;

@property(nonatomic,assign) double lat;

@property(nonatomic,assign) double lng;

@property(nonatomic,assign) NSInteger zoom;

@end

/////////////////////////////////////////////////////////////////////////////////
//
//                      自定义消息 Elem
//
/////////////////////////////////////////////////////////////////////////////////
@class MSIMPushInfo;
@interface MSIMCustomElem: MSIMElem

/** 自定义消息 自定义的json字符串*/
@property(nonatomic,copy) NSString *jsonStr;

/** 指明是哪种自定义消息，是否会影响未读数，是否可撤回等等*/
@property(nonatomic,assign) MSIMCustomOption option;

/** 推送相关的配置*/
@property(nonatomic,strong,nullable) MSIMPushInfo *pushExt;

@property(nonatomic,assign,readonly) BOOL canCount;

@property(nonatomic,assign,readonly) BOOL canRecall;

@end


/** 配置推送显示的内容，只会对自定义消息*/
@interface MSIMPushInfo: NSObject

/** 离线推送展示的标题*/
@property(nonatomic,copy) NSString *title;

/** 离线推送展示的内容*/
@property(nonatomic,copy) NSString *body;

/** 接收时会不会播放声音，默认有声音*/
@property(nonatomic,assign) BOOL isMute;

/** sound为空时，接收时播放系统声音。如果需要自定义音效，需要先把语音文件链接进 Xcode 工程，然后把语音文件名（带后缀）设置给 sound。*/
@property(nonatomic,copy,nullable) NSString *sound;

@end

NS_ASSUME_NONNULL_END

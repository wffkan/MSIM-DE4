//
//  MSIMHeader.h
//  BlackFireIM
//
//  Created by benny wang on 2021/3/19.
//

#ifndef MSIMHeader_h
#define MSIMHeader_h

//IM网络连接状态通知
#define MSUIKitNotification_ConnListener @"MSUIKitNotification_ConnListener"
//用户登录状态通知
#define MSUIKitNotification_UserStatusListener @"MSUIKitNotification_UserStatusListener"

//会话列表有变更通知
#define MSUIKitNotification_ConversationUpdate @"MSUIKitNotification_ConversationUpdate"

//会话列表同步ga开始通知
#define MSUIKitNotification_ConversationSyncStart @"MSUIKitNotification_ConversationSyncStart"
//会话列表同步完成通知
#define MSUIKitNotification_ConversationSyncFinish @"MSUIKitNotification_ConversationSyncFinish"

//会话被删除时的通知
#define MSUIKitNotification_ConversationDelete @"MSUIKitNotification_ConversationDelete"

//会话总未读数变化时的通知
#define MSUIKitNotification_ConversationUnreadCountChange @"MSUIKitNotification_ConversationUnreadCountChange"

//有新消息通知
#define MSUIKitNotification_MessageListener @"MSUIKitNotification_MessageListener"

//有指令消息通知
#define MSUIKitNotification_SignalMessageListener @"MSUIKitNotification_SignalMessageListener"

//消息有变更通知
#define MSUIKitNotification_MessageUpdate @"MSUIKitNotification_MessageUpdate"

//收到一条消息被删除的通知
#define MSUIKitNotification_MessageRecieveDelete @"MSUIKitNotification_MessageRecieveDelete"
//收到对方消息已读的通知
#define MSUIKitNotification_MessageReceipt @"MSUIKitNotification_MessageReceipt"

//用户信息更新通知
#define MSUIKitNotification_ProfileUpdate @"MSUIKitNotification_ProfileUpdate"

#endif /* MSIMHeader_h */

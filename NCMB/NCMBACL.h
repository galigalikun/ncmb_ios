/*******
 Copyright 2014 NIFTY Corporation All Rights Reserved.
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 **********/

#import <Foundation/Foundation.h>

@class NCMBUser;
@class NCMBRole;

/**
 NCMBACLクラスは、オブジェクトに対する読込書込権限を管理するクラスです。
 
 NCMBObject毎にNCMBACLを持ち、ユーザのグループであるロールや特定の個別ユーザなどにも付与することができます。
 
 例えば、全てのユーザに読込権限を与え、特定のユーザには読込権限に加え書込権限を与えるといったことができます。
 */
@interface NCMBACL : NSObject

/**
 ACLの情報を辞書型で保持する
 */
@property (nonatomic,strong) NSMutableDictionary *dicACL;

/**
 NCMBACLのインスタンスを生成。デフォルトでは全ての権限が許可されている。
 */
+ (NCMBACL *)ACL;

/**
 指定したユーザのみ読込書込権限が許可されたNCMBACLのインスタンスを生成。
 @param user 権限を設定するユーザ
 */
+ (NCMBACL *)ACLWithUser:(NCMBUser *)user;

/**
 
 オブジェクト生成時にACLが指定されなかった場合のデフォルトACLをaclで指定したアクセス権限に設定する。currentUserAccessがYESの場合は、さらにオブジェクトを生成したユーザーに読込書込権限を設定する。NOの場合はaclで指定されたアクセス権限のみが設定される。
 @param acl アクセス権限情報
 @param currentUserAccess YESの場合は、aclで指定されたアクセス権限に加えてオブジェクトを生成したユーザーに読込書込権限を設定、
 NOの場合は、aclで指定されたアクセス権限のみを設定する。
 */
+ (void)setDefaultACL:(NCMBACL *)acl withAccessForCurrentUser:(BOOL)currentUserAccess;



/** @name Public Access */

/**
 パブリックな読込権限を設定
 @param allowed 読込権限の設定（YES:許可／NO:許可取り消し）
 */
- (void)setPublicReadAccess:(BOOL)allowed;

/**
 パブリックな読込権限の有無を取得
 */
- (BOOL)isPublicReadAccess;

/**
 パブリックな書込権限を設定
 @param allowed 書込権限の設定（YES:許可／NO:許可取り消し）
 */
- (void)setPublicWriteAccess:(BOOL)allowed;

/**
 パブリックな書込権限の有無を取得
 */
- (BOOL)isPublicWriteAccess;



/** @name Role Access */

/**
 指定した名前を持つロールの読込権限の有無を取得
 @param name 読込権限の有無を調べるロール名
 */
- (BOOL)isReadAccessForRoleWithName:(NSString *)name;

/**
 指定した名前を持つロールの読込権限を設定
 @param allowed 読込権限の設定（YES:許可／NO:許可取り消し）
 @param name 読込権限を設定するロール名
 */
- (void)setReadAccess:(BOOL)allowed forRoleWithName:(NSString *)name;

/**
 指定した名前を持つロールの書込権限の有無を取得
 @param name 書込権限の有無を調べるロール名
 */
- (BOOL)isWriteAccessForRoleWithName:(NSString *)name;

/**
 指定した名前を持つロールの書込権限を設定
 @param allowed 書込権限の設定（YES:許可／NO:許可取り消し）
 @param name 書込権限を設定するロール名
 */
- (void)setWriteAccess:(BOOL)allowed forRoleWithName:(NSString *)name;

/**
 指定したロールの読込権限の有無を取得
 @param  role 読込権限の有無を調べるロール
 */
- (BOOL)isReadAccessForRole:(NCMBRole *)role;

/**
 指定したロールの読込権限を設定
 @param allowed 読込権限の設定（YES:許可／NO:許可取り消し）
 @param role 読込権限を設定するロール
 */
- (void)setReadAccess:(BOOL)allowed forRole:(NCMBRole *)role;

/**
 指定したロールの書込権限の有無を取得
 @param role 書込権限の有無を調べるロール
 */
- (BOOL)isWriteAccessForRole:(NCMBRole *)role;

/**
 指定したロールの書込権限を設定
 @param allowed 書込権限の設定（YES:許可／NO:許可取り消し）
 @param role 書込権限を設定するロール
 */
- (void)setWriteAccess:(BOOL)allowed forRole:(NCMBRole *)role;


/** @name User Access */

/**
 指定したIDに対応するユーザーの読込権限を設定
 @param allowed 読込権限の設定（YES:許可／NO:許可取り消し）
 @param userId 読込権限を設定するユーザID
 */
- (void)setReadAccess:(BOOL)allowed forUserId:(NSString *)userId;

/**
 指定したIDに対応するユーザーの読込権限の有無を取得
 @param userId 読込権限の有無を調べるユーザID
 */
- (BOOL)isReadAccessForUserId:(NSString *)userId;

/**
 指定したIDに対応するユーザーの書込権限を設定
 @param allowed 書込権限の設定（YES:許可／NO:許可取り消し）
 @param userId 書込権限を設定するユーザID
 */
- (void)setWriteAccess:(BOOL)allowed forUserId:(NSString *)userId;

/**
 指定したIDに対応するユーザーの書込権限の有無を取得
 @param userId 書込権限の有無を調べるユーザID
 */
- (BOOL)isWriteAccessForUserId:(NSString *)userId;

/**
 指定したユーザーの読込権限を設定
 @param allowed 読込権限の設定（YES:許可／NO:許可取り消し）
 @param user 読込権限を設定するユーザ
 */
- (void)setReadAccess:(BOOL)allowed forUser:(NCMBUser *)user;

/**
 指定したユーザーの読込権限の有無を取得
 @param user 読込権限の有無を調べるユーザ
 */
- (BOOL)isReadAccessForUser:(NCMBUser *)user;

/**
 指定したユーザーの書込権限を設定
 @param allowed 書込権限の設定（YES:許可／NO:許可取り消し）
 @param user 書込権限を設定するユーザ
 */
- (void)setWriteAccess:(BOOL)allowed forUser:(NCMBUser *)user;

/**
 指定したユーザーの書込権限の有無を取得
 @param user 書込権限の有無を調べるユーザ
 */
- (BOOL)isWriteAccessForUser:(NCMBUser *)user;

@end
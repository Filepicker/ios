//
//  FPLibrary.h
//  FPPicker
//
//  Created by Liyan David Chang on 6/20/12.
//  Copyright (c) 2012 Filepicker.io (Cloudtop Inc), All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MobileCoreServices/MobileCoreServices.h>
#import <UIKit/UIKit.h>
#import <AssetsLibrary/AssetsLibrary.h>

typedef void (^FPUploadAssetSuccessBlock)(id JSON);
typedef void (^FPUploadAssetFailureBlock)(NSError *error, id JSON);
typedef void (^FPUploadAssetProgressBlock)(float progress);
typedef void (^FPUploadAssetSuccessWithLocalURLBlock)(id JSON, NSURL *localurl);
typedef void (^FPUploadAssetFailureWithLocalURLBlock)(NSError *error, id JSON, NSURL *localurl);

// The following 2 typedefs should be actually part of FPAFJSONRequestOperation / FPAFNetworking

typedef void (^FPARequestOperationSuccessBlock)(NSURLRequest*, NSHTTPURLResponse*, id);
typedef void (^FPARequestOperationFailureBlock)(NSURLRequest *request, NSHTTPURLResponse *response, NSError *error, id JSON);

@interface FPLibrary : NSObject

//For the camera
+ (void)uploadImage:(UIImage*)image
         ofMimetype:(NSString*)mimetype
        withOptions:(NSDictionary*)options
       shouldUpload:(BOOL)shouldUpload
            success:(FPUploadAssetSuccessWithLocalURLBlock)success
            failure:(FPUploadAssetFailureWithLocalURLBlock)failure
           progress:(FPUploadAssetProgressBlock)progress;

+ (void)uploadVideoURL:(NSURL*)url
           withOptions:(NSDictionary*)options
          shouldUpload:(BOOL)shouldUpload
               success:(FPUploadAssetSuccessWithLocalURLBlock)success
               failure:(FPUploadAssetFailureWithLocalURLBlock)failure
              progress:(FPUploadAssetProgressBlock)progress;

//For uploading local images on open (Camera roll)
+ (void)uploadAsset:(ALAsset*)asset
        withOptions:(NSDictionary*)options
       shouldUpload:(BOOL)shouldUpload
            success:(FPUploadAssetSuccessWithLocalURLBlock)success
            failure:(FPUploadAssetFailureWithLocalURLBlock)failure
           progress:(FPUploadAssetProgressBlock)progress;

//For saveas
+ (void)uploadData:(NSData*)filedata
             named:(NSString *)filename
            toPath:(NSString*)path
        ofMimetype:(NSString*)mimetype
       withOptions:(NSDictionary*)options
           success:(FPUploadAssetSuccessBlock)success
           failure:(FPUploadAssetFailureBlock)failure
          progress:(FPUploadAssetProgressBlock)progress;

+ (void)uploadDataURL:(NSURL*)filedataurl
                named:(NSString *)filename
               toPath:(NSString*)path
           ofMimetype:(NSString*)mimetype
          withOptions:(NSDictionary*)options
              success:(FPUploadAssetSuccessBlock)success
              failure:(FPUploadAssetFailureBlock)failure
             progress:(FPUploadAssetProgressBlock)progress;

+ (NSString*)urlEscapeString:(NSString *)unencodedString;
+ (NSString*)addQueryStringToUrlString:(NSString *)urlString withDictionary:(NSDictionary *)dictionary;

+ (NSBundle *)frameworkBundle;

+ (id)JSONObjectWithData:(NSData *)data;
+ (NSData *)dataWithJSONObject:(id)object;

+ (BOOL)mimetype:(NSString *)mimetype instanceOfMimetype:(NSString *)supermimetype;

+ (NSString *)formatTimeInSeconds:(int)timeInSeconds;

+ (NSString *)genRandStringLength:(int)len;

@end
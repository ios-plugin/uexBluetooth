//
//  uexBLEInstance.h
//  EUExBluetoothLE
//
//  Created by Cerino on 15/7/22.
//  Copyright (c) 2015年 AppCan. All rights reserved.
//



#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <CoreBluetooth/CBService.h>
#import <CoreBluetooth/CBCharacteristic.h>



@protocol uexBlueToothLEDelegate <NSObject>

@optional


@end
extern NSString *const uexBLEServiceKey;
extern NSString *const uexBLECharacteristicKey;
extern NSString *const uexBLEDescripterKey;
extern NSString *const uexBLEValue;


@class EBrowserView;


@interface uexBLEInstance : NSObject
@property(nonatomic,weak) EBrowserView *callback;
+ (instancetype)sharedInstance;
-(void)log:(NSString *)str;


-(void)scanDevice:(NSArray *)UUIDs;
-(void)stopScanDevice;
-(void)connect:(NSString *)identifier;
-(void)disconnect;
-(void)searchForCharacteristic:(NSString*)serviceUUID;
-(void)searchForDescriptor:(NSString*)serviceUUID characteristic:(NSString*)characteristicUUID;
-(void)readCharacteristic:(NSString*)characteristicUUID
                inService:(NSString *)serviceUUID;
-(void)writeCharacteristic:(NSString*)characteristicUUID
                 inService:(NSString *)serviceUUID
            withDataString:(NSString*)dataStr;

-(void)readDescriptor:(NSString*)descriptorUUID
     inCharacteristic:(NSString*)characteristicUUID
            inService:(NSString*)serviceUUID;

-(void)writeDescriptor:(NSString*)descriptorUUID
      inCharacteristic:(NSString*)characteristicUUID
             inService:(NSString*)serviceUUID
            dataString:(NSString *)dataStr;

@end

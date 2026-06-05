// swift-tools-version:5.6
import PackageDescription

let package = Package(
    name: "HVCrashGuard",
    platforms: [.iOS(.v13)],

    products: [
        .library(
            name: "HVCrashGuard",
            targets: ["HVCrashGuard"]
        )
    ],

    targets: [
        .binaryTarget(
            name: "HVCrashGuard",
            url: "https://hvsdk.s3.ap-south-1.amazonaws.com/ios/release/hvcrashguard/2.1.0/HVCrashGuard-2.1.0-XCFramework.zip",
            checksum: "375214887cf2b819f1d71c80050a999b87ab3a268418aa3769970aca25fe9f09"
        )
    ]
)

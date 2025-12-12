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
            url: "https://hvsdk.s3.ap-south-1.amazonaws.com/ios/release/hvcrashguard/2.0.0/HVCrashGuard-2.0.0-XCFramework.zip",
            checksum: "99293ace371d1cd7778e97cb46730416b4f87ba408e33bcfb5447180989f66ee"
        )
    ]
)

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
            checksum: "dc6d0201c1490024336caa51023d9dc5e63b003958fa8b8ca46465d3d9452ddc"
        )
    ]
)

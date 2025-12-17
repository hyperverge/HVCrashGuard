// swift-tools-version:5.6
import PackageDescription

let package = Package(
    name: "HVCrashGuard",
    platforms: [.iOS(.v13)],

    products: [
        .library(
            name: "HVCrashGuard",
            type: .static,
            targets: ["HVCrashGuard"]
        )
    ],

    targets: [
        .binaryTarget(
            name: "HVCrashGuard",
            url: "https://hvsdk.s3.ap-south-1.amazonaws.com/ios/release/hvcrashguard/2.0.0/HVCrashGuard-2.0.0-XCFramework.zip",
            checksum: "45114278007e36c475badc56e7c4e05d18c8628c2686db99be1fbb8b61585f58"
        )
    ]
)

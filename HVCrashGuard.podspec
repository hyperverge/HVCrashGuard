Pod::Spec.new do |s|
    s.name         = 'HVCrashGuard'
    s.version      = '1.0.0'
    s.summary      = "HyperVerge's iOS Framework for capturing documents and faces to be used with our AI Engines"
    s.description  = <<-DESC
                   HVCrashGuard is an internal crash reporting library to catch and report crashes.
                    DESC
                    
    s.homepage     = 'https://github.com/hyperverge/HVCrashGuard'
    s.author       = 'HyperVerge'
    s.license      = {
                        :type => 'Custom',
                        :file => 'LICENSE'
                     }
    s.source       = {
                        :git => "https://github.com/hyperverge/HVCrashGuard.git",
                        :tag => "#{s.version}"
                     }

    s.static_framework = true
    s.platform     = :ios
    s.ios.deployment_target  = '11.0'
    s.swift_version = '5.4'
    s.vendored_frameworks = 'HVCrashGuard.xcframework'
    s.static_framework = true
   


end

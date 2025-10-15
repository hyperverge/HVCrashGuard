Pod::Spec.new do |s|
  s.name             = 'HVCrashGuard'
  s.version          = '1.0.0'

  # ≤ 140 chars
  s.summary          = 'HyperVerge’s internal iOS crash-reporting framework.'
  s.description      = <<-DESC
    HVCrashGuard captures, stores, and forwards crash reports produced inside
    HyperVerge SDK integrations.
  DESC

  s.homepage         = 'https://github.com/hyperverge/HVCrashGuard'
  s.license          = { :type => 'Custom', :file => 'LICENSE' }
  s.author           = { 'HyperVerge' => 'nivedita@hyperverge.co' }

  s.source           = {
    :git => 'https://github.com/hyperverge/HVCrashGuard.git',
    :tag => s.version.to_s
  }

  s.static_framework = true
  s.platform         = :ios, '11.0'
  s.swift_version    = '5.9'     

  s.vendored_frameworks = 'HVCrashGuard.xcframework'
end

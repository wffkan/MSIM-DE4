Pod::Spec.new do |spec|

  spec.name         = "MSIMSDK_DE4"
  spec.version      = "1.3.4"
  spec.summary      = "MSIM for de4......................................"

  spec.homepage     = "https://github.com/wffkan/MSIM-DE4"

  spec.license      = "MIT"

  spec.author       = { "wffkan" => "409322456@qq.com" }
  
  spec.source       = { :git => "https://github.com/wffkan/MSIM-DE4.git", :tag => spec.version }
   
  spec.ios.deployment_target = "11.0"

  spec.source_files = 'MSIMSDK_DE4/MSIMSDK.framework/Headers/*.h'
  spec.public_header_files = 'MSIMSDK_DE4/MSIMSDK.framework/Headers/*.h'
  spec.vendored_frameworks = 'MSIMSDK_DE4/MSIMSDK.framework'

  spec.xcconfig = { 'HEADER_SEARCH_PATHS' => '${PODS_ROOT}/MSIMSDK_DE4/MSIMSDK.framework/Headers/'}
  spec.pod_target_xcconfig = {
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }
  spec.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
end

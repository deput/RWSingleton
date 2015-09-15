Pod::Spec.new do |s|
  s.name         = "RWSingleton"
  s.version      = "0.0.2"
  s.summary      = "A macro to create singleton class quickly in ObjC"
  s.homepage     = "https://github.com/deput/RWSingleton"

  s.source       = { :git => "https://github.com/deput/RWSingleton.git", :tag => "0.0.2" }
  s.source_files  = "*.{h,m}"
end

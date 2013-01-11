;;
;; Stub make file for building xforty-drupal. Copy this file and add
;; site-specific components for your project.
;;

;----------------------------------------
; base make file
;----------------------------------------

includes[] = http://github.com/xforty/xforty-drupal/raw/7.x-2.0.0/base.make

;----------------------------------------
; base make file overrides
;----------------------------------------



;----------------------------------------
; distro features
;----------------------------------------



;----------------------------------------
; distro libraries
;----------------------------------------



;----------------------------------------
; distro modules
;----------------------------------------



;----------------------------------------
; distro profiles
;----------------------------------------

projects[xforty][type] = profile
projects[xforty][download][type] = git
projects[xforty][download][url] = git://github.com/xforty/xforty-drupal.git
projects[xforty][download][tag] = 7.x-2.0.0

; <PROJECT_PROFILE_GOES_HERE>

;----------------------------------------
; distro themes
;----------------------------------------



;----------------------------------------
; distro make file overrides
;----------------------------------------

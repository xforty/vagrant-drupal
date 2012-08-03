;;
;; Stub makefile to building xforty-drupal
;;

;----------------------------------------
; base make file
;----------------------------------------

; If you want to use the latest HEAD from 7.x branch
;includes[] = http://github.com/xforty/xforty-drupal/raw/7.x/xforty-com.make

; If you want to use a specific tag instead (recommended)
includes[] = http://github.com/xforty/xforty-drupal/raw/7.x-1.0.0/xforty-com.make

;----------------------------------------
; features
;----------------------------------------



;----------------------------------------
; libraries
;----------------------------------------



;----------------------------------------
; modules
;----------------------------------------



;----------------------------------------
; profiles
;----------------------------------------

; Default behavior is to download the HEAD of the 7.x branch.
; When creating your own site's distro.make, comment out the
; download branch line and un-comment out the download tag line.
projects[xforty][type] = profile
projects[xforty][download][type] = git
projects[xforty][download][url] = git://github.com/xforty/xforty-drupal.git
;projects[xforty][download][branch] = 7.x
projects[xforty][download][tag] = 7.x-1.0.0

;----------------------------------------
; themes
;----------------------------------------



;----------------------------------------
; Include base make file overrides below
;----------------------------------------

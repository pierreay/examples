;;; Bootstrap use-package

(unless (package-installed-p 'use-package)
  (package-refresh-contents)
  (package-install 'use-package))

(eval-when-compile
  (require 'use-package))

(setq package-archives
      '(("GNU ELPA"     . "https://elpa.gnu.org/packages/")
        ("NonGNU ELPA"  . "https://elpa.nongnu.org/nongnu/")
        ("MELPA Stable" . "https://stable.melpa.org/packages/")
        ("MELPA"        . "https://melpa.org/packages/"))
      package-archive-priorities
      '(("MELPA"        . 5)
        ("GNU ELPA"     . 4)
        ("NonGNU ELPA"  . 3)
        ("MELPA Stable" . 2)
        ))

;;; Load the tested package

;; Use either use-package for an official version:
;; (use-package ox-bb)

;; Or use a local clone of the package for a development version:
(add-to-list 'load-path (expand-file-name (concat (print default-directory) "ox-bb")))
(require 'ox-bb)

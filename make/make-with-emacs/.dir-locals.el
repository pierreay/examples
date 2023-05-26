;;; Directory Local Variables
;;; For more information see (info "(emacs) Directory Variables")

;; In your init.el:
;; ===============

;; (require 'cl)
;; (defun* get-closest-pathname (&optional (file "Makefile"))
;;   "Determine the pathname of the first instance of FILE starting from the current directory towards root.
;; This may not do the correct thing in presence of links. If it does not find FILE, then it shall return the name
;; of FILE in the current directory, suitable for creation."
;;   (let ((root (expand-file-name "/")))
;;     (expand-file-name file
;; 		              (cl-loop
;; 			           for d = default-directory then (expand-file-name ".." d)
;; 			           if (file-exists-p (expand-file-name file d))
;; 			           return d
;; 			           if (equal d root)
;; 			           return nil))))

((nil . ((compile-command . (format "make -f %s " (get-closest-pathname "Makefile.emacs")))
         (compilation-read-command . nil))))

;;; -*- lexical-binding: t -*-
(with-no-warnings (require 'cl))

(require 'package)

(setq package-archives
     '(("org"          . "https://orgmode.org/elpa/")
       ("MELPA"        . "https://melpa.org/packages/")
       ("MELPA Stable" . "https://stable.melpa.org/packages/")
       ("gnu"          . "https://elpa.gnu.org/packages/"))
     package-archive-priorities
     '(("org"          . 10)
       ("MELPA"        . 9)
       ("MELPA Stable" . 5)
       ("gnu"          . 1)))

(package-initialize)

(unless (package-installed-p 'use-package)
  (package-refresh-contents)
  (package-install 'use-package))
(require 'use-package-ensure)
(setq use-package-always-ensure t)

(use-package org
  :pin org      
  :ensure org-plus-contrib
  :commands org-babel-do-load-languages org-next-visible-heading org-previous-visible-heading
  :commands org-cycle org-global-cycle org-store-link org-timer-stop org-timer-pause-or-continue)

(use-package s)

(require 'ox-extra)
(ox-extras-activate '(ignore-headlines))

(custom-set-variables
 '(safe-local-variable-values
   (quote
    ((eval add-to-list
           (quote org-latex-classes)
           (quote
            ("book-noparts" "\\documentclass{book}"
             ("\\chapter{%s}" . "\\chapter*{%s}")
             ("\\section{%s} \\paragraph{}" . "\\section*{%s} \\paragraph{}")
             ("\\subsection{%s} \\paragraph{}" . "\\subsection*{%s} \\paragraph{}")
             ("\\subsubsection{%s} \\paragraph{}" . "\\subsubsection*{%s} \\paragraph{}")
             ("\\paragraph{%s}" . "\\paragraph*{%s}")
             ("\\subparagraph{%s}" . "\\subparagraph*{%s}"))))
     (org-export-allow-bind-keywords . t)))))

(set-language-environment "UTF-8")

(setq-default bibtex-dialect 'biblatex)

(setq org-confirm-babel-evaluate nil)

(org-babel-do-load-languages
 'org-babel-load-languages
 '((awk . t)
   (C . t)
   (R . t)
   (ditaa . t)
   (emacs-lisp . t)
   (gnuplot . t)
   (java . t)
   (js . t)
   (latex . t)
   (lisp . t)
   (makefile . t)
   (org . t)
   (perl . t)
   (python . t)
   (ruby . t)
   (shell . t)
   (sql . t)))

(setq org-latex-listings 'minted)

(add-to-list 'org-latex-packages-alist '("newfloat" "minted"))

(setq org-latex-pdf-process '("%latex -shell-escape -interaction nonstopmode -output-directory %o %f"
                              "%latex -shell-escape -interaction nonstopmode -output-directory %o %f"
                              "%latex -shell-escape -interaction nonstopmode -output-directory %o %f"))

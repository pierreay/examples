; Prend un nom de fichier et renvoie une liste de chaînes de caractères
; représentant chaque ligne dans ce fichier.
(defun lines-list(file)
  (with-open-file (str file :direction :input)
    (do ((line (read-line str nil nil)
               (read-line str nil nil))
         (acc nil (cons line acc)))
      ((not line) (nreverse acc)))))

; Prends deux noms de fichiers et écrit dans le second fichier une copie du premier sans les commentaires.
; Ne prend que en compte les commentaires qui commence au début de la ligne.
(defun copy_without_comment (file_in file_out &optional (comment #\%))
  (with-open-file (str_in file_in :direction :input)
    (with-open-file (str_out file_out :direction :output)
      (do ((line (read-line str_in nil nil)
                 (read-line str_in nil nil)))
        ((eql line nil) 'done)
        (unless (char= (char line 0) comment)
          (format str_out "~A~%" line))))))

; Appels possibles :
;   (copy_without_comment "exo5_in.txt" "exo5_out.txt")
;   (copy_without_comment "exo5_in.txt" "exo5_out.txt" #\-)
;   (copy_without_comment "exo5_in.txt" "exo5_out.txt" #\%)

; Prends deux noms de fichiers et écrit dans le second fichier une copie du premier sans les commentaires.
; Prend en compte tout les commentaires (même ceux au milieu d'une ligne).
(defun remove_comments(fin fout &optional (cchar #\%))
  (with-open-file (s-in fin :direction :input)
    (with-open-file (s-out fout :direction :output)
      (do ((line (read-line s-in nil nil)
                 (read-line s-in nil nil)))
        ((not line))
        (let ((cp (position cchar line)))
          (format s-out "~A~%"
                  (if cp (subseq line 0 cp) line)))))))

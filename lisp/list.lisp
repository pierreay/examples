; Renvoie sous forme d'un couple le minimum et le maximum d'un vecteur de nombres.
(defun min_max(vec)
  (if (equal (length vec) 1)
    (list (svref vec 0) (svref vec 0))
    (let ((lst (min_max(subseq vec 1))))
      (list 
        (min (car lst) (svref vec 0))
        (max (cadr lst) (svref vec 0))
        )
      ) 
    )
  )

; Prends un objet et un vecteur et renvoie une liste de tous les objets qui précèdent immédiatement obj dans v.
;; Version récursive.
(defun precede_rec(obj vec)
  (if (< 1 (length vec))
    (if (equal obj (aref vec 1))
      (cons (aref vec 0) (precede_rec obj (subseq vec 1)))
      (precede_rec obj (subseq vec 1))
      )
    )
  )
; Version itérative.
(defun precede_it(obj vec) 
  (let ((lst))
    (do ((i 1 (+ i 1)))
      ((>= i (length vec)) 'done)
      (if (equal obj (aref vec i))
        (setf lst (cons (aref vec (- i 1)) lst))
        )
      )
    lst
    )
  )

; Prends une liste et renvoie une liste dont les éléments sont ceux de la liste initiale augmentées de leurs positions respectaient.
;; Version itérative.
(defun pos+_it (ls)
  (do ((ls1 ls (cdr ls1))
       (i 0 (+ i 1))
       (acc nil (cons (+ i (car ls1)) acc)))
    ((not ls1) (reverse acc))))
;; Version récursive.
(defun pos+_rec (ls)
  (pos+_rec2 ls 0))
(defun pos+_rec2(ls i)
  (if ls
    (cons (+ i (car ls)) (pos+_rec2 (cdr ls) (+ i 1)))))
;; Version mapcar.
(defun pos+_map (ls)
  (let ((i -1))
    (mapcar #'(lambda(x) (+ x (incf i))) ls)))

; Prend un objecta et une liste et renvoie une nouvelle liste dans laquelle l'objet apparaît entre chaque paire d'éléments de la liste initiale.
;; Version itérative.
(defun interspace_it (obj ls)
  (do ((ls1 (reverse (cdr ls)) (cdr ls1))
       (ls2 nil (cons obj (cons (car ls1) ls2))))
    ((not ls1) (cons (car ls) ls2))))
;; Version récursive.
(defun interspace_rec (obj ls)
  (cons (car ls) (interspace_rec2 obj (reverse (cdr ls)) nil)))
(defun interspace_rec2 (obj ls acc)
  (if ls
    (interspace_rec2 obj (cdr ls) (cons obj (cons (car ls) acc))) acc))

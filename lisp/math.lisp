; a) Récursif :

; Renvoie le nombre d'occurence de nombres consécutifs dont la différence est 1 :
(defun test_diff(lst)
  (if (null (car (cdr lst)))
    0
    (let ((X (car lst)) (Y (car (cdr lst))))
      (if (= (- X Y) 1)
        (+ 1 (test_diff (cdr lst)))
        (test_diff (cdr lst))
      )
    )
  )
)

; Renvoie vrai si deux nombres consécutifs ont pour différence 1 :
(defun test_diff(lst)
  (if (null (car (cdr lst)))
    nil
    (let ((X (car lst)) (Y (car (cdr lst))))
      (if (= (- X Y) 1)
        t
        (test_diff (cdr lst))
      )
    )
  )
)

; b) Itératif :

(defun test_diff(lst)
  (do ((i 0 (+ i 1)))
    ((null (car (cdr lst))) nil)
    (let ((X (car lst)) (Y (car (cdr lst))))
      (if (= (- X Y) 1)
        (return t)
        (setf lst (cdr lst))
      )
    )
  )
)

; Renvoie le carré d'un nombre inférieur à 5.
(defun my_square(x)
  (if (and (<= x 5) (> x 0))
    x
    (* x x)
  )
)

; Affiche le plus petit et le plus élément d'une liste.
(defun min_max(lst)
  (let ((var_min (car lst)) (var_max (car lst)))
    (dolist (x lst)
      (if (< x var_min) (setf var_min x))
      (if (> x var_max) (setf var_max x))
      )
    (format t "Min : ~A -- Max : ~A" var_min var_max)
    )
  )

; > (min_max (list 4 9 2 95))
; Min : 2 -- Max : 95
; NIL

; Calcule le produit des deux plus grands nombres d'une liste.
(defun maxi(lst)
  (let ((max_a (car lst)) (max_b (car lst)))
    (dolist (x lst)
      (if (> x max_a)
        (progn
          (setf max_b max_a)
          (setf max_a x)
          )
        )
      (if (> x max_b) (setf max_b x))
      )
    (format t "Max * Max-1 : ~A" (* max_a max_b))
    )
  )

; > (maxi (list 3 5 7 2 4 6 3 10 4 5 10))
; Max * Max-1 : 100
; NIL

; Inverse tout les éléments d'une liste.
(defun rever(lst)
  (if (null lst)
    (car lst)
    (cons (rever (cdr lst)) (list (car lst)))
    )
  )

; Test l'égalité de deux arguments.
(defun my_equal(x y)
  (cond ((and (atom x) (atom y)) ; Integer, Strings
         (equal x y))
        ((and (listp x) (listp y)) ; Lists
         (car (maplist #'equal x y)))
        )
  ; Different type -> NIL
  )

; Prends n'importe quel nombre d'arguments et renvoie le nombre des arguments
; qui lui sont effectivement passé.
(defun nbr_arg(&rest args)
  (length args))

; Prends un argument, un nombre, et renvoie le plus grand argument qui lui soit
; passé jusqu'à maintenant.
(let (mx)
  (defun plus-grand-arg (n)
    (if (or (not mx) (< mx n))
      (setf mx n)
      mx)))

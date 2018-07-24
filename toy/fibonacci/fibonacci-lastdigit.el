(defun fibonacci (n n_2 n_1)
 (if (= n 0) n_2
   (if (= n 1) n_1
     (fibonacci (- n 1) n_1 (+ n_2 n_1)))))

(defun fibonacci-last-digit (n n_2 n_1)
 (if (= n 0) n_2
   (if (= n 1) n_1
     (fibonacci-last-digit (- n 1) (mod n_1 10) (mod (+ n_2 n_1) 10)))))


; use with seed values like this:
; (fibonacci 80 0 1)
;
; For the last digit, increase allowable recursion depth first:
; (progn (setq max-lisp-eval-depth 10000) (fibonacci-last-digit 331 0 1))




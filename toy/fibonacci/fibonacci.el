(defun fibonacci (n n_2 n_1)
 (if (= n 0) n_2
   (if (= n 1) n_1
     (fibonacci (- n 1) n_1 (+ n_2 n_1)))))

; use with seed values like this:
; (fibonacci 10 0 1)

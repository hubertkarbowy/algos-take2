(defun euclid-gcd (a b)
  "Emacs Lisp implementation of the Euclidean algorithm"
  (if (= (mod a b) 0) b (euclid-gcd b (mod a b))))

; Example:
; (euclid-gcd 28851538 1183019)

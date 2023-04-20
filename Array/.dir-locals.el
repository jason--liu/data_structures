;;; Directory Local Variables
;;; For more information see (info "(emacs) Directory Variables")

((c-mode . ((compile-command . (concat "gcc -g "
				                         (file-name-only)
                                         " -o "
				                         (file-name-only-noext)))
	          )))

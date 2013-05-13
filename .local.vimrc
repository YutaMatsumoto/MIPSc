
" let g:debug_dir = "" " relative to project root
" let proot=system("gitroot") " project root
" let &makeprg="make -C ".system("gitroot")."/".g:debug_dir

" let &path=&path.",".proot."/src/**"

" for f in split( globpath(proot, "src/**") )
" 	if isdirectory(f)		
" 		echo f
" 		set path+=expand(f)
" 	endif
" endfor

let g:debug_dir = "" " relative to project root
let proot=system("git rev-parse --show-toplevel 2>/dev/null")
let proot=substitute(proot, "\n", "", "")

let &makeprg="make -C ".proot."/".g:debug_dir
let &path=&path.",".proot."/src/**"


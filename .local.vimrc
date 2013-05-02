
let g:debug_dir = "" " relative to project root
let proot=system("gitroot") " project root
let &makeprg="make -C ".system("gitroot")."/".g:debug_dir

let &path=&path.",".proot."/src/**"

" for f in split( globpath(proot, "src/**") )
" 	if isdirectory(f)		
" 		echo f
" 		set path+=expand(f)
" 	endif
" endfor

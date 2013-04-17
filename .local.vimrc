
let g:debug_dir = "" " relative to project root
let proot=system("gitroot") " project root
let &makeprg="make -C ".system("gitroot")."/".g:debug_dir


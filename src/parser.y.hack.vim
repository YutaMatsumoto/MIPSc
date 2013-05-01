"
" Hack parser.y to spit out reduction taken
"
" Main : AppendCoutGrammarAction()
"
" Cleanup is needed before/after AppendCoutGrammarAction()
"
"	comment on production lines
"
"	existing action on production lines
"

" ----------------------------------------------------------------------------

function! IsOnProductionLine(lnum)
	return match( getline(a:lnum), '\v^\s*(\||:)\s*(.*)' ) != -1
endfunction

function! GetLeftHandSide(lnum)
" Assumes IsOnProductionLine is true on the line
	exe a:lnum
	let nomatch = 0
	let lefthandside_lnum = search('\v^\h', 'bn')		
	return ( lefthandside_lnum == nomatch ) ? "" : getline(lefthandside_lnum)
endfunction

function! GetRightHandSide(lnum)
	return substitute( getline(a:lnum), '\v^\s*(\||:)\s*(.*)', '\2', '')
endfunction

" ----------------------------------------------------------------------------

function! AppendCoutGrammarAction()
	for lnum in range(1, line('$'))
		if IsOnProductionLine(lnum)
			let line = getline(lnum)
			let append = '"'."Reduction: " . GetRightHandSide(lnum) . ' -> '  . GetLeftHandSide(lnum) . '"'
			let append = '{ std::cout << '.append.' << std::endl << std::endl; }'
			call setline(lnum, line.' '.append)
		endif
	endfor
endfunction

" ----------------------------------------------------------------------------

function! DebugGetRightHandSide()
	for lnum in range(1, line('$'))	
		if IsOnProductionLine(lnum)
			echo "ON THE LINE : ".getline(lnum)
			echo GetRightHandSide(lnum)
		endif
	endfor
endfunction

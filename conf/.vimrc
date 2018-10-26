" ###	Settings	###
syntax on
set nomodeline
set backspace=2
set nu
set cindent
set smartindent
set showcmd
set showmatch
set ruler
set hlsearch
set ignorecase
"set expandtab

set t_kb=
set t_kD=

" How many spaces can be shown by '\t' value
set tabstop=4
" by indent or >> / << key
set shiftwidth=4
" How many spaces can be shown by tab key
set softtabstop=4
"set expandtab

set foldlevel=99
set foldmethod=syntax


" #####	Key Settings #####
let mapleader=","
nnoremap <leader>qw :q!<CR>
nnoremap <leader>q :bp<CR>
nnoremap <leader>w :bn<CR>
nnoremap <leader>t :TagbarToggle<CR>
nnoremap <leader>n :NERDTreeToggle<CR>
nnoremap <leader>sr :SyntasticReset<CR>

nnoremap <F2> :set invpaste paste?<CR>
set pastetoggle=<F2>

" ##### Resize Window #####
nnoremap <silent> <leader>[ :resize -3"<CR>
nnoremap <silent> <leader>] :resize +3"<CR>



" ###	Vundle	###
set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'

" The following are examples of different formats supported.
" Keep Plugin commands between vundle#begin/end.
" plugin on GitHub repo

" My Plugin

Plugin 'tpope/vim-fugitive'
Plugin 'The-NERD-tree'
Plugin 'unite.vim'
Plugin 'snipMate'
Plugin 'Tagbar'
Plugin 'The-NERD-Commenter'
Plugin 'bling/vim-airline'
Plugin 'scrooloose/syntastic'
Plugin 'Raimondi/delimitMate'
Plugin 'terryma/vim-multiple-cursors'
Plugin 'terryma/vim-smooth-scroll'
"Plugin 'shougo/neocomplete.vim'

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line

" --- Taglist configuration   ---

" taglist window to the right
let Tlist_Use_Right_Window = 1
" NERD-tree window to the left
let NERDTreeWinPos = "left"
" taglist  ??
let Tlist_Use_SingleClick = 1
" taglist window width
let Tlist_WinWidth = 40
"-------------------------------


" ##### vim-multiple-cursor #####
let g:multi_cursor_use_default_mapping=0
" Default
let g:multi_cursor_next_key='<C-n>'
let g:multi_cursor_prev_key='<C-p>'
let g:multi_cursor_skip_key='<C-x>'
let g:multi_cursor_quit_key='<Esc>'

" ##### vim-smooth-scroll #####
noremap <silent> <PageUp> :call smooth_scroll#up(&scroll*2, 10, 5)<CR>
noremap <silent> <PageDown> :call smooth_scroll#down(&scroll*2, 10, 5)<CR>
noremap <silent> <c-u> :call smooth_scroll#up(&scroll, 10, 3)<CR>
noremap <silent> <c-d> :call smooth_scroll#down(&scroll, 10, 3)<CR>




" ##### NERD Commenter
" Add spaces after comment delimiters by default
let g:NERDSpaceDelims = 1
" Use compact syntax for prettified multi-line comments
let g:NERDCompactSexyComs = 1
" Align line-wise comment delimiters flush left instead of following code indentation
let g:NERDDefaultAlign = 'left'
" Set a language to use its alternate delimiters by default
let g:NERDAltDelims_java = 1
" Add your own custom formats or override the defaults
let g:NERDCustomDelimiters = { 'c': { 'left': '/**','right': '*/' } }
" Allow commenting and inverting empty lines (useful when commenting a region)
let g:NERDCommentEmptyLines = 1
" Enable trimming of trailing whitespace when uncommenting
let g:NERDTrimTrailingWhitespace = 1

" customize keymapping
map <Leader>cc <plug>NERDComToggleComment
map <Leader>c<space> <plug>NERDComComment


" color
hi Pmenu        ctermbg=blue
hi PmenuSel     ctermbg=yellow ctermbg=white
hi PmenuSbar    ctermbg=blue

hi StatusLine   term=standout ctermfg=0 ctermbg=11 guifg=Blue guibg=Yellow
hi ModeMsg    term=bold ctermfg=6 guifg=DarkCyan
hi TagListTagName term=standout ctermfg=0 ctermbg=3 guifg=Blue guibg=Yellow
hi Search ctermfg=0 ctermbg=11 guifg=Black guibg=Yellow

"-------------------------------

" ---	Syntastic	---
set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
let g:syntastic_check_on_open = 1
let g:syntastic_check_on_wq = 0
"-------------------------------
"CSCOPE
set csto=0
set cst
set nocsverb

if filereadable("./cscope.out")
    cs add cscope.out
else
    cs add /home/tjchoi/project/ysera-sdk/zaram/package/omcid/dl/src/cscope.out
endif
set csverb


set tags=./tags

"##############################################################################


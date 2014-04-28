set nu
set nocompatible
"colorscheme morning
filetype off

set backspace=indent,eol,start

"preference {
set guifont=DejaVu\ Sans\ Mono\ 12
set guioptions-=m	"隐藏gvim菜单和工具栏
set guioptions-=T
set columns=95
set go-=r	"去除左右两边的滚动条
set go-=L
"}

"tab setting {
set formatoptions=tcmM
set nowrap
set colorcolumn=63
set textwidth=63
"set wrap
set conceallevel=3
set cindent
set shiftwidth=2 "设置indent为2 代替原来的8
set tabstop=4	"设置tab为4个空格宽度"
"set shiftwidth=2
"set softtabstop=2
"set expandtab
set noexpandtab	"不扩展tab为空格，expandtab则扩展
"}

set fileformats=unix,dos,mac
set fileencodings=utf-8,cp936,gb18030,latin1
set autoindent
set incsearch
set hlsearch
"set showmatch
set ignorecase	"大小写敏感，小写匹配所有，大写精确匹配
set laststatus=2
set cmdheight=2

set hidden
set noswapfile
set autochdir
set nobackup

let mapleader=","
nmap <leader>ee : e ~/.vimrc <cr>
nmap <leader>ss : s ~/.vimrc <cr>
nmap - :res <cr>
nnoremap <leader><space> :noh<cr>	"取消搜索高亮
autocmd! bufwritepost .vimrc source %
imap <A-j> <Down>
imap <A-k> <Up>
imap <A-h> <Left>
imap <A-l> <Right>

nnoremap <A-1> 1gt
nnoremap <A-2> 2gt
nnoremap <A-3> 3gt
nnoremap <A-4> 4gt

"setlocal noexpandtab
" Despite promise somewhere alignment is done only using tabs. Thus setting 
" &tabstop is a requirement.

""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"Vundle Settingsss{
set rtp+=~/.vim/bundle/vundle/
call vundle#rc()

"""""man.vim
"vim里使用Man
source $VIMRUNTIME/ftplugin/man.vim

Bundle 'gmarik/vundle'

Bundle 'The-NERD-tree'
  "nmap <leader>nt :NERDTree<cr>:set rnu<cr>
  nmap <F3> :NERDTree<cr>
  nmap <F4> :NERDTreeClose<cr>
  let NERDTreeShowBookmarks=1
  let NERDTreeShowFiles=1
  let NERDTreeShowHidden=1
  let NERDTreeIgnore=['\.$','\~$']
  let NERDTreeShowLineNumbers=1
  let NERDTreeWinPos=1
  let NERDTreeWinPos='left'
  let NERDTreeWinSize=25

Bundle 'Valloric/youCompleteMe'
	nnoremap <F5> :YcmForceCompileAndDiagnostics<CR>
	nnoremap <leader>gt :YcmCompleter GoToDefinition<CR>
	nnoremap <leader>gd :YcmCompleter GoToDeclaration<CR>
  let g:ycm_key_list_select_completion = ['<Enter>', '<Down>']
  let g:ycm_add_preview_to_completeopt = 0
	"{ Fix Tab Key Error With UltiSnippets
	"let g:ycm_key_list_select_completion=['<C-Tab>','<Down>']
	"let g:SuperTabDefaultCompletionType = '<C-Tab>'
	"}

	"let g:ycm_global_ycm_extra_conf = '~/.ycm_c_conf.py'
	let g:ycm_global_ycm_extra_conf = '~/.ycm_cpp_conf.py'
	let g:ycm_confirm_extra_conf = 0

"Bundle 'Lokaltog/powerline'
  "python from powerline.vim import setup as powerline_setup
  "python powerline_setup()
  "python del powerline_setup
  "set rtp+=~/.vim/bundle/powerline/bindings/vim
  "call vam#ActivateAddons(['powerline'])

Bundle 'Lokaltog/vim-powerline'
"  let g:Powerline_symbols = 'fancy'

"Bundle 'mbbill/code_complete'

Bundle 'bufexplorer.zip'

"Bundle 'StringsStar/A'
"有个跟leader快捷键重复的问题，fixing

Bundle 'StringsStar/ConqueShell'

"Bundle 'StringsStar/SuperTab'
Bundle 'StringsStar/vim-colors-solarized'

Bundle 'StringsStar/vim-notes'
	let g:notes_directories=['~/notes']
	"let g:notes_suffix='.txt'
Bundle 'StringsStar/vim-misc'

Bundle 'StringsStar/UltiSnips'
if !exists("g:UltiSnipsJumpForwardTrigger")
    "let g:UltiSnipsJumpForwardTrigger = "<tab>"
    let g:UltiSnipsJumpForwardTrigger = "<c-j>"
endif
if !exists("g:UltiSnipsJumpBackwardTrigger")
    let g:UltiSnipsJumpBackwardTrigger = "<c-k>"
endif
"}

"filetype plugin indent on
syntax on
set background=light
"set background=dark
colorscheme solarized

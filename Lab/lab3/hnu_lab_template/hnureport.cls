%%%%%%%%%%湖南大学%%%%%%%%%%%%
\ProvidesClass{HNUreport}
\LoadClass[a4paper,12pt]{ctexart}
\RequirePackage{graphicx}
\usepackage[margin=2.5cm]{geometry}
\usepackage{fontspec}
\usepackage{fancyhdr}
\usepackage{lipsum}
\usepackage{zhlipsum}
\usepackage{amsbsy}
\usepackage{amsfonts}
\usepackage{amsgen}
\usepackage{amsmath}
\usepackage{amsopn}
\usepackage{hyperref}
\usepackage{listings}
\usepackage{xcolor}
\usepackage{caption}
\usepackage{bm}
\usepackage{graphics}
\usepackage{abstract}
\usepackage{xcolor-patch}
\usepackage{graphicx} 
\usepackage{subfigure}
\setlength{\absleftindent}{0pt}
\setlength{\absrightindent}{0pt}
\setmainfont{Times New Roman}
\bibliographystyle{IEEEtran}


%\geometry{top=2.54cm,bottom=2.54cm,left=3.18cm,right=3.18cm}%与word中A4默认页边距保持一致   %自选

%页眉页脚
\pagestyle{plain}
%fancy
%\fancyhead[L]{\@name}
%\fancyhead[C]{\@expname}
%\fancyhead[R]{\@stuid}

%代码lst的rgb设置
\lstset{
  frame=tb,
  aboveskip=3mm,
  belowskip=3mm,
  showstringspaces=false,
  columns=flexible,
  framerule=1pt,
  rulecolor=\color{black},
  backgroundcolor=\color{white},
  basicstyle={\normalsize\ttfamily},
  keywordstyle=\color{magenta},
  commentstyle=\color{teal},
  stringstyle=\color{blue},
  breaklines=true,
  breakatwhitespace=true,
  tabsize=3,
}
% 目录
\hypersetup{
colorlinks=true,
linkcolor=black
}

% 封面
\newcommand{\makecover}{
  \thispagestyle{empty}
  \begin{center}
    \begin{center}
      \includegraphics[width=7cm]{Figure/HNUlogo.pdf}
    \end{center}
    \vspace{1cm}
    \bfseries\huge{\@course}\\
    \vspace{0.5cm}
    \bfseries\Large{标题：\@expname}
    \vspace{2cm}
    \begin{center}
      \large
      \renewcommand\arraystretch{1.6}
      \begin{tabular}{cc}
        \bfseries{姓名：} & \@name   \\ \cline{2-2}
        \bfseries{学院：} & \@college \\ \cline{2-2}
        \bfseries{专业：} & \@major  \\ \cline{2-2}
        \bfseries{学号：} & \@stuid  \\ \cline{2-2}
        \bfseries{老师：} & \@teacher  \\ \cline{2-2}
      \end{tabular}
    \end{center}
    \vfill
    \Large{\@date}
  \end{center}
  \newpage
}

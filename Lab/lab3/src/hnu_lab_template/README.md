# Hunan-University-Coursework-LaTeX-Template

![image-20210320174856449](https://i.loli.net/2021/03/20/zYZiqB6LRuMvnEx.png)
```
.
├── abstract.tex
├── appendix.tex
├── Conclusion.tex
├── Contents.tex
├── Environment.tex
├── Experience.tex
├── Figure
│   ├── bit_logo.png
│   ├── fig1.pdf
│   ├── fig2.pdf
│   ├── HNUlogo.pdf
│   ├── latex.txt
│   └── logo_slogan.png
├── hnureport.cls
├── main.pdf
├── main.synctex.gz
├── main.tex
├── README.md
├── reference.tex
├── Results.tex
├── Steps.tex
└── Target.tex
```
这是湖南大学课程大作业LaTeX模板，版本：1.0

设计这个模板的出众是湖南大学各种课程群散落的word模板参差不齐，格式各不相同。作为一个LaTeX重度爱好者，设计此套模板，该套模板参考了许多前辈们设计的课程论文模板。

在此鸣谢：

西北农林科技大学 信息工程学院 耿楠老师


由于这个模板是第一次设计，没有经过大规模普及及测试，因此代码还有各种问题没有暴露出来，欢迎各位湖南大学的同学能够提出一些意见或是一起维护这个模板！

使用该模板的配置：

1.texlive 2020及以上版本

2.有一个合适的编译器


3.对于基本的LaTeX语句有了解，可以自如套用

模板的梗概：

1.设计了一个简洁的封面，选择使用湖南大学红色logo，假如不满意亦可以使用自己的logo.

2.重新定义了texlive自带的摘要页。假如不满意可以自己定义字体及字号。

3.模板已经自带几个section，可以根据自己的想法随意加减section。

4.该模板面向一些初学者，考虑到biblatex的复杂性,模板没有引入biblatex的参考文献，取而代之使用更简单的thebibliography，利用bibtem也能轻松得到效果较好的参考文献。

5.附录可以自定义，模板中给出的例子是插入计算机代码，考虑到minted宏包需要配置python环境，于是我们采用更普遍的lstlisting宏包，由于本人对于颜色的搭配确实不太懂，偷了个小懒没有去查RGB表，因此对于关键字与注释等代码高亮的颜色随意选取，使用者可以根据自己的喜好及习惯自由更改高亮配色！

本模板是1.0版本，希望能一直维护下去，欢迎各位同学使用！


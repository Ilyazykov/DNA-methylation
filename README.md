DNA-methylation
===============
Повторить проделанное в статье Complex networks analysis of obstructive nephropathy data.

*Заметки
1)
vector<Graph> graphs;
for (int i = 0; i < 9000; ++i)

graphs.push_back(Graph(i));

если у тебя компилер поддерживает C++11, то вместо push_back лучше использовать emplace_back
___________________________________________________________________________________________
2) https://code.google.com/p/gource/ - возможно подойдёт для визуализации

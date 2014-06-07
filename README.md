DNA-methylation
===============
[Исходные данные](https://tcga-data.nci.nih.gov/tcga/)

-------------------------------
Достигнутая точность - 98%
_________________________

*Заметки <br>

`vector<Graph> graphs;` <br>
`for (int i = 0; i < 9000; ++i)` <br>
`    graphs.push_back(Graph(i));` <br>

<p>если у тебя компилер поддерживает C++11, то вместо push_back лучше использовать emplace_back</p>
___________________________________________________________________________________________
[С++11](http://habrahabr.ru/post/182920/)

____________________________________________________________________

[Расшифровка TCGA баркода](https://wiki.nci.nih.gov/display/TCGA/TCGA+Barcode)

______________________________________________________________________________
Код в R <br>

`setwd("C:\\Users\\user\\Google Диск\\Zykov\\data")` <br>
`load("phenDataTCGABRCA.rd")` <br>
`write.csv(phen, file="phenData.csv")` <br>
`View(phen)` <br>

SELECT  Sno, AVG(Grade)
FROM  SC
GROUP BY Sno
HAVING AVG(Grade)>=86;

SELECT * FROM SC

--错误的使用：

--SELECT Sno, AVG(Grade)
--FROM  SC
--WHERE AVG(Grade)>=90
--GROUP BY Sno;

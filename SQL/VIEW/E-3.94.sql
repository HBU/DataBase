SELECT *
FROM  (SELECT Sno,AVG(Grade)
       FROM  SC
       GROUP BY Sno) AS S_G(Sno,Gavg)
WHERE Gavg>=86;

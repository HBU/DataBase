--不相关子查询
SELECT Sno, Sname, Sdept
FROM Student
WHERE Sdept  IN
	(SELECT Sdept
	FROM Student
	WHERE Sname= '刘晨');

--连接查询（自身连接）
SELECT S1.Sno, S1.Sname,S1.Sdept
FROM Student S1,Student S2
WHERE S1.Sdept = S2.Sdept AND S2.Sname = '刘晨';

--可以用带EXISTS谓词的子查询替换：
SELECT Sno,Sname,Sdept
FROM Student S1
WHERE EXISTS
      (SELECT *
        FROM Student S2
         WHERE S2.Sdept = S1.Sdept AND S2.Sname = '刘晨');

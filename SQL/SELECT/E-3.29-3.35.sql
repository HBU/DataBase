--[例3.29]  查询学号为201215121的学生的详细情况。
      SELECT *    
     FROM  Student  
     WHERE  Sno LIKE '201215121';

--等价于： 
       SELECT  * 
      FROM  Student 
      WHERE Sno = ' 201215121 ';

--[例3.30]  查询所有姓刘学生的姓名、学号和性别。
       SELECT Sname, Sno, Ssex
      FROM Student
      WHERE  Sname LIKE '刘%';

--[例3.31]  查询姓"欧阳"且全名为三个汉字的学生的姓名。
       SELECT Sname
      FROM   Student
      WHERE  Sname LIKE '欧阳_ _';
--【注】数据库字符集为ASCII时，一个汉字需要两个_
--      数据库字符集为 GBK 时，一个汉字需要一个_

--[例3.32]  查询名字中第2个字为"阳"字的学生的姓名和学号。
      SELECT Sname,Sno
      FROM     Student
      WHERE  Sname LIKE '_ _阳%';

--[例3.33]  查询所有不姓刘的学生姓名、学号和性别。
      SELECT Sname, Sno, Ssex
      FROM     Student
      WHERE  Sname NOT LIKE '刘%';
	  --[例3.34]  查询DB_Design课程的课程号和学分。
      SELECT Cno,Ccredit
      FROM     Course
      WHERE  Cname LIKE 'DB\_Design' ESCAPE '\' ;
--[例3.35]  查询以"DB_"开头，且倒数第3个字符为 i的课程的详细情况。
      SELECT  *
      FROM    Course
      WHERE  Cname LIKE  'DB\_%i__' ESCAPE '\' ;
	
	--ESCAPE '＼' 表示“ ＼” 为换码字符
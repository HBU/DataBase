
--[例3.36]  某些学生选修课程后没有参加考试，所以有选课记录，但没 有考试成绩。查询缺少成绩的学生的学号和相应的课程号。
	  SELECT Sno,Cno
      FROM    SC
      WHERE  Grade IS NULL
--[例3.37]  查所有有成绩的学生学号和课程号。
      SELECT Sno,Cno
      FROM     SC
      WHERE  Grade IS NOT NULL;
--[例3.38]  查询计算机系年龄在20岁以下的学生姓名。
      SELECT Sname
       FROM  Student
       WHERE Sdept= 'CS' AND Sage<20;

--改写[例3.27]
--[例3.27]  查询计算机科学系（CS）、数学系（MA）和信息系（IS）学生的姓名和性别。
SELECT Sname, Ssex
FROM     Student
WHERE  Sdept IN ('CS ','MA ','IS');
--可改写为：
SELECT Sname, Ssex
FROM     Student
WHERE  Sdept= ' CS' OR Sdept= ' MA' OR Sdept= 'IS ';





--[例3.19]  查全体学生的姓名及其出生年份。
SELECT Sname,2016-Sage          /*假设当时为2016年*/
FROM Student;

--[例3.20] 查询全体学生的姓名、出生年份和所在的院系，要求用小写字母表示系名。
SELECT Sname,'Year of Birth: ',2014-Sage,LOWER(Sdept)
FROM Student;

--[例3.21]  查询选修了课程的学生学号。
SELECT Sno   FROM SC;
--等价于：
SELECT ALL  Sno  FROM SC;



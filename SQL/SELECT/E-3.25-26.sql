--[例3.25] 查询年龄在20~23岁（包括20岁和23岁）之间的学生的姓名、系别和年龄
SELECT Sname, Sdept, Sage
FROM     Student
WHERE   Sage BETWEEN 20 AND 23; 

--[例3.26]  查询年龄不在20~23岁之间的学生姓名、系别和年龄
SELECT Sname, Sdept, Sage
FROM    Student
WHERE Sage NOT BETWEEN 20 AND 23; 

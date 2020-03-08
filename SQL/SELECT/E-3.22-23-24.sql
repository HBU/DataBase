--[例3.22] 查询计算机科学系全体学生的名单。
SELECT Sname
FROM     Student
WHERE  Sdept='CS'; 

--[例3.23]查询所有年龄在20岁以下的学生姓名及其年龄。
SELECT Sname,Sage 
FROM     Student    
WHERE  Sage < 20;

--[例3.24]查询考试成绩有不及格的学生的学号。
SELECT DISTINCT Sno
FROM  SC
WHERE Grade<60; 

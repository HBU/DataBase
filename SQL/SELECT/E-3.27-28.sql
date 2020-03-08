--[例3.27]查询计算机科学系（CS）、数学系（MA）和信息系（IS）学生的姓名和性别。
SELECT Sname, Ssex
FROM  Student
WHERE Sdept IN ('CS','MA','IS');

--[例3.28]查询既不是计算机科学系、数学系，也不是信息系的学生的姓名和性别。
SELECT Sname, Ssex
FROM Student
WHERE Sdept NOT IN ('IS','MA','CS');
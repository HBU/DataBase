--[例3.41]  查询学生总人数。
SELECT COUNT(*)
FROM  Student; 
--[例3.42]  查询选修了课程的学生人数。
SELECT COUNT(DISTINCT Sno)
FROM SC;
--[例3.43]  计算1号课程的学生平均成绩。
SELECT AVG(Grade)
FROM    SC
WHERE Cno= '1';
--[例3.44]  查询选修1号课程的学生最高分数。
SELECT MAX(Grade)
FROM SC
WHERE Cno='1';
--[例3.45] 查询学生201215012选修课程的总学分数。
SELECT SUM(Ccredit)
FROM  SC,Course
WHERE Sno='201215012' AND SC.Cno=Course.Cno; 

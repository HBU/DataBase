--[例3.39]查询选修了3号课程的学生的学号及其成绩，查询结果按分数降序排列。
        SELECT Sno, Grade
        FROM    SC
        WHERE  Cno= '3'
        ORDER BY Grade DESC;

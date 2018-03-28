SELECT Student.Sno, Sname, Cname, Grade
FROM Student, SC, Course    /*/*多表连接*/*/
WHERE Student.Sno = SC.Sno AND SC.Cno = Course.Cno;


SELECT *
FROM Student, SC, Course    /*/*多表连接*/*/
WHERE Student.Sno = SC.Sno AND SC.Cno = Course.Cno;

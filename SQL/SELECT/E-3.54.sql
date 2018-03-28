SELECT Student.Sno, Sname, Cname, Grade
FROM Student, SC, Course    /*¶à±íÁ¬½Ó*/
WHERE Student.Sno = SC.Sno AND SC.Cno = Course.Cno;


SELECT *
FROM Student, SC, Course    /*¶à±íÁ¬½Ó*/
WHERE Student.Sno = SC.Sno AND SC.Cno = Course.Cno;

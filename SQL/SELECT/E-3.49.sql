
--µÈÖµÁ¬½Ó
SELECT  Student.*, SC.*
FROM     Student, SC
WHERE  Student.Sno = SC.Sno;


--×ÔÈ»Á¬½Ó
SELECT  Student.Sno,Sname,Ssex,Sage,Sdept,Cno,Grade
FROM     Student,SC
WHERE  Student.Sno = SC.Sno;


--µÈÖµÁ¬½Ó
SELECT  *
FROM     Student, SC
WHERE  Student.Sno = SC.Sno;

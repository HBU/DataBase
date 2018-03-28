
SELECT Sname
FROM     Student
WHERE NOT EXISTS
	(SELECT *
	FROM SC
	WHERE Sno = Student.Sno AND Cno='1');

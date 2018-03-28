SELECT Sname,Sage
FROM    Student
WHERE Sage < ANY (	SELECT  Sage
					FROM    Student
					WHERE Sdept= 'CS')
     AND Sdept <> 'CS';           /*父查询块中的条件 */



SELECT Sname,Sage
FROM   Student
WHERE Sage < 
			(SELECT MAX(Sage)
			FROM Student
			WHERE Sdept= 'CS ')
       AND Sdept <> 'CS';

SELECT * FROM Student

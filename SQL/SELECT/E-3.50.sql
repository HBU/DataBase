--[例 3.50]  对[例 3.49]用自然连接完成。
 SELECT  Student.Sno,Sname,Ssex,Sage,Sdept,Cno,Grade
 FROM     Student,SC
 WHERE  Student.Sno = SC.Sno;

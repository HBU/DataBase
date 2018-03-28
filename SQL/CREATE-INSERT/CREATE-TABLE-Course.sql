CREATE TABLE  Course
(Cno       CHAR(4) PRIMARY KEY,
Cname  CHAR(40),            
Cpno     CHAR(4),               	                      
Ccredit  SMALLINT,
FOREIGN KEY (Cpno) REFERENCES  Course(Cno) 
); 

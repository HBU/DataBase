/*  程序功能：
加载时，从数据库读“省”的名字，写入combox1（“省”的名字）；
combox1（“省”的名字）选项发生变化时，combox2（“市”的名字）填写内容。
 
 * 首先要在SQLserver中完成以下操作：
 
1. 建立数据库 MrDavid
2. 建立基本表 city
    CREATE TABLE city(P_Name nchar(10) ,	C_Name nchar(10) ) 
3.插入内容：
    P_Name   C_Name
    河北         保定        
    河北        	石家庄       
    河北        	唐山        
    北京        	东城区       
    北京        	西城区       
    北京        	朝阳区       
    天津        	河东区       
    天津        	河西区       

注意事项：数据库连接字符串要改成自己的相应参数
*/
<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="Login_sql_injection.Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
    <style type="text/css">
        .auto-style1 {
            height: 24px;
        }
        .auto-style2 {
            text-decoration: underline;
        }
        .auto-style3 {
            font-size: xx-large;
            text-align: center;
        }
        .auto-style4 {
            height: 27px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <div style="height: 402px; width: 827px">
                <table style="width:100%;">
                    <tr>
                        <td class="auto-style3" colspan="2">SQL injection</td>
                    </tr>
                    <tr>
                        <td class="auto-style4">
                            <asp:Label ID="Label1" runat="server" Text="User Name:"></asp:Label>
                        </td>
                        <td class="auto-style4">
                            <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
                        </td>
                    </tr>
                    <tr>
                        <td>
                            <asp:Label ID="Label2" runat="server" Text="Password:"></asp:Label>
                        </td>
                        <td>
                            <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
                        </td>
                    </tr>
                    <tr>
                        <td>&nbsp;</td>
                        <td>
                            <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Login" Width="109px" />
                        </td>
                    </tr>
                    <tr>
                        <td class="auto-style1">
                            <asp:CheckBox ID="CheckBox1" runat="server" Checked="True" Text="SQL injection" />
                        </td>
                        <td class="auto-style1">
                            <asp:Label ID="Label3" runat="server" Text="Please input user name and password"></asp:Label>
                        </td>
                    </tr>
                    <tr>
                        <td class="auto-style1">&nbsp;</td>
                        <td class="auto-style1">&nbsp;</td>
                    </tr>
                    <tr>
                        <td class="auto-style1" colspan="2">Use <span class="auto-style2"><strong>&#39; or &#39;1&#39;=&#39;1</strong></span> replace your password, push button &quot;ok&quot;, and check the result.</td>
                    </tr>
                    <tr>
                        <td class="auto-style1" colspan="2">
                            <p style="margin: 10px auto; padding: 0px; text-indent: 0px; color: rgb(0, 0, 0); font-family: Verdana, Arial, Helvetica, sans-serif; font-size: 12px; font-style: normal; font-variant-ligatures: normal; font-variant-caps: normal; font-weight: 400; letter-spacing: normal; orphans: 2; text-align: left; text-transform: none; white-space: normal; widows: 2; word-spacing: 0px; -webkit-text-stroke-width: 0px; background-color: rgb(255, 255, 255); text-decoration-style: initial; text-decoration-color: initial;">
                                SQL语句变成了select * from Users Where rg_LoginName=&#39;admin&#39; and rg_LoginPwd=&#39;&#39; or &#39;1&#39;=&#39;1&#39;</p>
                            <p style="margin: 10px auto; padding: 0px; text-indent: 0px; color: rgb(0, 0, 0); font-family: Verdana, Arial, Helvetica, sans-serif; font-size: 12px; font-style: normal; font-variant-ligatures: normal; font-variant-caps: normal; font-weight: 400; letter-spacing: normal; orphans: 2; text-align: left; text-transform: none; white-space: normal; widows: 2; word-spacing: 0px; -webkit-text-stroke-width: 0px; background-color: rgb(255, 255, 255); text-decoration-style: initial; text-decoration-color: initial;">
                                我们查询原本的意思是：select * from Users Where rg_LoginName=用户名 and rg_LoginPwd=密码</p>
                            <p style="margin: 10px auto; padding: 0px; text-indent: 0px; color: rgb(0, 0, 0); font-family: Verdana, Arial, Helvetica, sans-serif; font-size: 12px; font-style: normal; font-variant-ligatures: normal; font-variant-caps: normal; font-weight: 400; letter-spacing: normal; orphans: 2; text-align: left; text-transform: none; white-space: normal; widows: 2; word-spacing: 0px; -webkit-text-stroke-width: 0px; background-color: rgb(255, 255, 255); text-decoration-style: initial; text-decoration-color: initial;">
                                而现在的意思就变成了 select * from Users Where rg_LoginName=&#39;admin&#39; and rg_LoginPwd=空 or &#39;1&#39;=&#39;1&#39;</p>
                            <p style="margin: 10px auto; padding: 0px; text-indent: 0px; color: rgb(0, 0, 0); font-family: Verdana, Arial, Helvetica, sans-serif; font-size: 12px; font-style: normal; font-variant-ligatures: normal; font-variant-caps: normal; font-weight: 400; letter-spacing: normal; orphans: 2; text-align: left; text-transform: none; white-space: normal; widows: 2; word-spacing: 0px; -webkit-text-stroke-width: 0px; background-color: rgb(255, 255, 255); text-decoration-style: initial; text-decoration-color: initial;">
                                简单的说就是相当于用户通过输入的密码中带有SQL语义的值，变相修改了我们的查询语句，在本例中，无论用户是否知道密码，他只要在密码中输入&#39; or &#39;1&#39;=&#39;1&#39;，就一定能够登录成功，因为有了 or &#39;1&#39;=&#39;1&#39;的恒成立，所以前面的判断语句统统失效。这就是非常典型的SQL注入攻击，通过此种方法，可以进入后台，篡改数据等操作。</p>
                        </td>
                    </tr>
                </table>
            </div>
        </div>
    </form>
</body>
</html>
